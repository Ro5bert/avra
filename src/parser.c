/***********************************************************************
 *
 *  AVRA - Assembler for the Atmel AVR microcontroller series
 *
 *  Copyright (C) 1998-2020 The AVRA Authors
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; see the file COPYING.  If not, write to
 *  the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 *  Boston, MA 02111-1307, USA.
 *
 *
 *  Authors of AVRA can be reached at:
 *     email: jonah@omegav.ntnu.no, tobiw@suprafluid.com
 *     www: https://github.com/Ro5bert/avra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "misc.h"
#include "avra.h"
#include "args.h"


/* Special fgets. Like fgets, but with better check for CR, LF and FF and without the ending \n char */
/* size must be >=2. No checks for s=NULL, size<2 or stream=NULL.  B.A. */
char *
fgets_new(struct prog_info *pi, char *s, int size, FILE *stream)
{
	int c;
	char *ptr=s;
	do {
		if ((c=fgetc(stream))==EOF || IS_ENDLINE(c)) 	/* Terminate at chr$ 10,12,13,0 and EOF */
			break;
		/* concatenate lines terminated with \ only... */
		if (c == '\\') {
			/* only newline and cr may follow... */
			if ((c=fgetc(stream))==EOF)
				break;

			if (!IS_ENDLINE(c)) {           /* Terminate at chr$ 10,12,13,0 and EOF */
				*ptr++ = '\\';              /* no concatenation, insert it */
			} else {
				/* mit be additional LF (DOS) */
				c=fgetc(stream);
				if (IS_ENDLINE(c))
					c=fgetc(stream);

				if (c == EOF)
					break;
			}
		}

		*ptr++=c;
	} while (--size);
	if ((c==EOF) && (ptr==s))				/* EOF and no chars read -> that's all folks */
		return NULL;
	if (!size) {
		print_msg(pi, MSGTYPE_ERROR, "Line too long");
		return NULL;
	}
	*ptr=0;
	if (c==12)						/* Check for Formfeed */
		print_msg(pi, MSGTYPE_WARNING, "Found Formfeed char. Please remove it.");
	if (c==13) { 						/* Check for CR LF sequence (DOS/ Windows line termination) */
		if ((c=fgetc(stream)) != 10) {
			ungetc(c,stream);
		}
	}
	return s;
}


/* Parse given assembler file. */
int
parse_file(struct prog_info *pi, const char *filename)
{
#if debug == 1
	printf("parse_file\n");
#endif
	int ok;
	int loopok;
	struct file_info *fi;
	struct include_file *include_file;
	ok = True;
	if ((fi=malloc(sizeof(struct file_info)))==NULL) {
		print_msg(pi, MSGTYPE_OUT_OF_MEM,NULL);
		return (False);
	}
	pi->fi = fi;
	if (pi->pass == PASS_1) {
		if ((include_file = malloc(sizeof(struct include_file)))==NULL) {
			print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
			free(fi);
			return (False);
		}
		include_file->next = NULL;
		if (pi->last_include_file) {
			pi->last_include_file->next = include_file;
			include_file->num = pi->last_include_file->num + 1;
		} else {
			pi->first_include_file = include_file;
			include_file->num = 0;
		}
		pi->last_include_file = include_file;
		if ((include_file->name = malloc(strlen(filename) + 1))==NULL) {
			print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
			free(fi);
			return (False);
		}
		strcpy(include_file->name, filename);
	} else { /* PASS 2 */
		for (include_file = pi->first_include_file; include_file; include_file = include_file->next) {
			if (!strcmp(include_file->name, filename))
				break;
		}
	}
	if (!include_file) {
		print_msg(pi, MSGTYPE_ERROR, "Internal assembler error");
		free(fi);
		return (False);
	}
	fi->include_file = include_file;
	fi->line_number = 0;
	fi->exit_file = False;
#if debug == 1
	printf("Opening %s\n",filename);
#endif
	if ((fi->fp = fopen(filename, "r"))==NULL) {
		perror(filename);
		free(fi);
		return (False);
	}
	loopok = True;
	while (loopok && !fi->exit_file) {
		if (fgets_new(pi,fi->buff, LINEBUFFER_LENGTH, fi->fp)) {
			fi->line_number++;
			pi->list_line = fi->buff;
			ok = parse_line(pi, fi->buff);
#if debug == 1
			printf("parse_line was %i\n", ok);
#endif
			if (ok) {
				if ((pi->pass == PASS_2) && pi->list_line && pi->list_on)
					fprintf(pi->list_file, "         %s\n", pi->list_line);
				if (pi->error_count >= pi->max_errors) {
					print_msg(pi, MSGTYPE_MESSAGE, "Maximum error count reached. Exiting...");
					loopok = False;
				}
			} else {
				loopok = False;
			}
		} else {
			loopok = False;
			if (!feof(fi->fp)) {
				ok = False;
				perror(filename);
			}
		}
	}
	fclose(fi->fp);
	free(fi);
	return (ok);
}

/* Parse one line. */
int
parse_line(struct prog_info *pi, char *line)
{
	char *ptr=NULL;
	int k;
	int flag=0, i;
	int global_label = False;
	char temp[LINEBUFFER_LENGTH];
	struct label *label = NULL;
	struct macro_call *macro_call;
	int len;

	while (IS_HOR_SPACE(*line)) line++;			/* At first remove leading spaces / tabs */
	if (IS_END_OR_COMMENT(*line))				/* Skip comment line or empty line */
		return (True);
	/* Filter out .stab debugging information */
	/* .stabs sometimes contains colon : symbol - might be interpreted as label */
	if (*line == '.') {					/* minimal slowdown of existing code */
		if (strncmp(temp,".stabs ",7) == 0) {		/* compiler output is always lower case */
			strcpy(temp,line);			/* TODO : Do we need this temp variable ? Please check */
			return parse_stabs(pi, temp);
		}
		if (strncmp(temp,".stabn ",7) == 0) {
			strcpy(temp,line);
			return parse_stabn(pi, temp);
		}
	}
	/* Meta information translation */
	ptr=line;
	k=0;
	len = strlen(ptr);
	while ((ptr=strchr(ptr, '%')) != NULL) {
		if (!strncmp(ptr, "%MINUTE%", 8)) {		/* Replacement always shorter than tag -> no length check */
			k=strftime(ptr, 3, "%M", localtime(&pi->time));
			memmove(ptr+k, ptr+8, len - (ptr+8 - line) + 1);
			ptr += k;
			len -= 8-k;
		} else if (!strncmp(ptr, "%HOUR%", 6)) {
			k=strftime(ptr, 3, "%H", localtime(&pi->time));
			memmove(ptr+k, ptr+6, len - (ptr+6 - line) + 1);
			ptr += k;
			len -= 6-k;
		} else if (!strncmp(ptr, "%DAY%", 5)) {
			k=strftime(ptr, 3, "%d", localtime(&pi->time));
			memmove(ptr+k, ptr+5, len - (ptr+5 - line) + 1);
			ptr += k;
			len -= 5-k;
		} else if (!strncmp(ptr, "%MONTH%", 7)) {
			k=strftime(ptr, 3, "%m", localtime(&pi->time));
			memmove(ptr+k, ptr+7, len - (ptr+7 - line) + 1);
			ptr += k;
			len -= 7-k;
		} else if (!strncmp(ptr, "%YEAR%", 6)) {
			k=strftime(ptr, 5, "%Y", localtime(&pi->time));
			memmove(ptr+k, ptr+6, len - (ptr+6 - line) + 1);
			ptr += k;
			len -= 6-k;
		} else {
			ptr++;
		}
	}

	strcpy(pi->fi->scratch,line);

	for (i = 0; IS_LABEL(pi->fi->scratch[i]) || (pi->fi->scratch[i] == ':'); i++)
		if (pi->fi->scratch[i] == ':') {	/* it is a label */
			pi->fi->scratch[i] = '\0';
			if (pi->pass == PASS_1) {
				for (macro_call = pi->macro_call; macro_call; macro_call = macro_call->prev_on_stack) {
					for (label = pi->macro_call->first_label; label; label = label->next) {
						if (!nocase_strcmp(label->name, &pi->fi->scratch[0])) {
							print_msg(pi, MSGTYPE_ERROR, "Can't redefine local label %s", &pi->fi->scratch[0]);
							break;
						}
					}
				}
				if (test_label(pi,&pi->fi->scratch[0],"Can't redefine label %s")!=NULL)
					break;
				if (test_variable(pi,&pi->fi->scratch[0],"%s have already been defined as a .SET variable")!=NULL)
					break;
				if (test_constant(pi,&pi->fi->scratch[0],"%s has already been defined as a .EQU constant")!=NULL)
					break;
				label = malloc(sizeof(struct label));
				if (!label) {
					print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
					return (False);
				}
				label->next = NULL;
				label->name = malloc(strlen(&pi->fi->scratch[0]) + 1);
				if (!label->name) {
					print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
					return (False);
				}
				strcpy(label->name, &pi->fi->scratch[0]);
				label->value = pi->segment->addr;

				if (pi->macro_call && !global_label) {
					if (pi->macro_call->last_label)
						pi->macro_call->last_label->next = label;
					else
						pi->macro_call->first_label = label;
					pi->macro_call->last_label = label;
				} else {
					if (pi->last_label)
						pi->last_label->next = label;
					else
						pi->first_label = label;
					pi->last_label = label;
				}
			}
			i++;
			while (IS_HOR_SPACE(pi->fi->scratch[i]) && !IS_END_OR_COMMENT(pi->fi->scratch[i])) i++;
			if (IS_END_OR_COMMENT(pi->fi->scratch[i])) {
				if ((pi->pass == PASS_2) && pi->list_on) { /* Diff tilpassing */
					fprintf(pi->list_file, "          %s\n", pi->list_line);
					pi->list_line = NULL;
				}
				return (True);
			}
			memmove(pi->fi->scratch, &pi->fi->scratch[i], strlen(&pi->fi->scratch[i])+1);
			break;
		}

	if ((pi->fi->scratch[0] == '.') || (pi->fi->scratch[0] == '#')) {
		pi->fi->label = label;
		flag = parse_directive(pi);
		if ((pi->pass == PASS_2) && pi->list_on && pi->list_line) { /* Diff tilpassing */
			fprintf(pi->list_file, "          %s\n", pi->list_line);
			pi->list_line = NULL;
		}
		return (flag);
	} else {
		return parse_mnemonic(pi);
	}
}


/* Get the next token, and terminate the last one.
 * Termination identifier is specified. */
char *
get_next_token(char *data, int term)
{
	int i = 0, j, anti_comma = False;
	/* XXX: this does the same thing for TERM_END and TERM_COMMA? */
	switch (term) {
	case TERM_END:
		/* Skip to next comma or EOL or start of comment, taking into account
		 * the possibility for ',' or ';' to be inside quotes. */
		while (((data[i] != ',') || anti_comma) && ((data[i] != ';') || anti_comma) && !IS_ENDLINE(data[i]))  {
			if ((data[i] == '\'') || (data[i] == '"'))
				anti_comma = anti_comma ? False : True;
			i++;
		}
		break;
	case TERM_SPACE:
		/* Skip to next horizontal space or EOL or start of comment. */
		while (!IS_HOR_SPACE(data[i]) && !IS_END_OR_COMMENT(data[i])) i++;
		break;
	case TERM_WORD:
		/* Skip to end of word. */
		while (IS_LABEL(data[i]) || data[i] == '.') i++;
		if (!isblank(data[i])) {
			int k = strlen(data);
			for (; k != i-1; k--) data[k+1] = data[k];
			data[i] = ' ';
		}
		break;
	case TERM_DASH:
		/* Skip to next dash or EOL or start of comment. */
		while ((data[i] != '-') && !IS_END_OR_COMMENT(data[i])) i++;
		break;
	case TERM_COLON:
		/* Skip to next colon or EOL. */
		while ((data[i] != ':') && !IS_ENDLINE(data[i])) i++;
		break;
	case TERM_DOUBLEQUOTE:
		/* Skip to next double quote or EOL. */
		while ((data[i] != '"') && !IS_ENDLINE(data[i])) i++;
		break;
	case TERM_COMMA:
		/* Skip to next comma or EOL or start of comment, taking into account
		 * the possibility for ',' or ';' to be inside quotes. */
		while (((data[i] != ',') || anti_comma) && ((data[i] != ';') || anti_comma) && !IS_ENDLINE(data[i])) {
			if ((data[i] == '\'') || (data[i] == '"'))
				anti_comma = anti_comma ? False : True;
			i++;
		}
		break;
	case TERM_EQUAL:
		/* Skip to next equals or EOL or start of comment. */
		while ((data[i] != '=') && !IS_END_OR_COMMENT(data[i])) i++;
		break;
	}
	/* If we hit EOL or a comment, return null. */
	if (IS_END_OR_COMMENT(data[i])) {
		/* Null-out the EOL/start of comment. */
		data[i--] = '\0';
		/* Null-out everything until the first non-horizontal whitespace
		 * character. */
		while (IS_HOR_SPACE(data[i])) data[i--] = '\0';
		return (0);
	}
	j = i - 1;
	/* Null-out all horizontal whitespace before the terminator. */
	while (IS_HOR_SPACE(data[j])) data[j--] = '\0';
	/* Null-out the terminator itself. */
	data[i++] = '\0';
	/* Skip over all horizontal whitespace after the terminator. */
	while (IS_HOR_SPACE(data[i]) && !IS_END_OR_COMMENT(data[i])) i++;
	/* If we hit EOL or a comment, return null. */
	if (IS_END_OR_COMMENT(data[i]))
		return (0);
	/* i should now be the index of the first non-whitespace character after
	 * the terminator. */
	return (&data[i]);
}

/* end of parser.c */

