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
// #if debug == 1
// 			printf("parse_line was %i\n", ok);
// #endif
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

/* Preprocess one line. */
int
preprocess_line(struct prog_info *pi, char *line)
{
	char *ptr, *next, *data, *param, *next_param;
	int params_cnt, args_cnt, macro_expanded;
	struct item_list *params, *first_param, *last_param, *first_arg, *last_arg, *args_ptr;
	struct preproc_macro *macro;
	char *macro_begin, *macro_end, *par_begin, *par_end;
	char *arg_mem, *arg, *next_arg;
	char temp[LINEBUFFER_LENGTH];

	do {
		macro_expanded = False;
		ptr = line;

		while (IS_HOR_SPACE(*ptr)) ptr++;
		if (IS_END_OR_COMMENT(*ptr))
			return (PREPROCESS_NEXT_LINE);
		if (ptr != line)
			memmove(line, ptr, line+LINEBUFFER_LENGTH-1-ptr);
		strcpy(temp, line);

		if (*temp == '#') {
			next = get_next_token(temp, TERM_SPACE);
			if (!nocase_strcmp(temp+1, "define")) {	/* #define */
				/* #define name [value] */
				/* #define name(arg, ...) [value] */
				if (!next) {
					print_msg(pi, MSGTYPE_ERROR, "#define needs an operand");
					return (PREPROCESS_NEXT_LINE);
				}
				/* Is it an object-like or a function-like macro? */
				param = funcall_token(next);
				if (!param) {
					/* Object-like macro definition */
					data = get_next_token(next, TERM_SPACE);
					if (!data)
						data = "1";	/* No value part provided, defaults to 1 */
					else
						get_next_token(data, TERM_END);
#if debug == 1
					printf("preprocess_line obj next \"%s\" data \"%s\"\n", next, data);
#endif
					if (pi->pass == PASS_1) {
						if (test_preproc_macro(pi, next, "Preprocessor macro %s has already been defined") != NULL)
							return (PREPROCESS_NEXT_LINE);
						if (def_preproc_macro(pi, next, PREPROC_MACRO_OBJECT_LIKE, NULL, data) == False)
							return (PREPROCESS_FATAL_ERROR);
					} else {
						/* Pass 2 */
					}
				} else {
					/* Function-like macro definition */
#if debug == 1
					printf("preprocess_line fun next \"%s\"\n", next);
#endif
					/* Collect params */
					first_param = last_param = NULL;
					while ((next_param = get_next_token(param, TERM_COMMA))) {
#if debug == 1
						printf("preprocess_line fun param \"%s\"\n", param);
#endif
						if (!is_label(param)) {
							print_msg(pi, MSGTYPE_ERROR, "Function-like macro %s with invalid parameter %s", next, param);
							return (PREPROCESS_NEXT_LINE);
						}
						if (!collect_paramarg(pi, param, &first_param, &last_param))
							return (PREPROCESS_FATAL_ERROR);
						param = next_param;
					}
					data = get_next_token(param, TERM_CLOSING_PAREN);
					if (!data) {
						print_msg(pi, MSGTYPE_ERROR, "Fuction-like macro %s misses value", next);
						return (PREPROCESS_NEXT_LINE);
					} else
						get_next_token(data, TERM_END);
					if (!*param) {
						print_msg(pi, MSGTYPE_ERROR, "Function-like macro %s misses a parameter", next);
						return (PREPROCESS_NEXT_LINE);
					}
#if debug == 1
					printf("preprocess_line fun param \"%s\"\n", param);
					printf("preprocess_line fun data \"%s\"\n", data);
#endif
					if (!is_label(param)) {
						print_msg(pi, MSGTYPE_ERROR, "Function-like macro %s with invalid parameter %s", next, param);
						return (PREPROCESS_NEXT_LINE);
					}
					if (!collect_paramarg(pi, param, &first_param, &last_param))
						return (PREPROCESS_FATAL_ERROR);
					if (pi->pass == PASS_1) {
						if (test_preproc_macro(pi, next, "Preprocessor macro %s has already been defined") != NULL)
							return (PREPROCESS_NEXT_LINE);
						if (def_preproc_macro(pi, next, PREPROC_MACRO_FUNCTION_LIKE, first_param, data) == False)
							return (PREPROCESS_FATAL_ERROR);
					} else {
						/* Pass 2 */
					}
				}
				if ((pi->pass == PASS_2) && pi->list_line && pi->list_on) {
					fprintf(pi->list_file, "          %s\n", pi->list_line);
					pi->list_line = NULL;
				}
				return (PREPROCESS_NEXT_LINE);	/* #define successfully parsed, continue with next line */
			} else if (!nocase_strcmp(temp+1, "undef")) {	/* #undef */
				print_msg(pi, MSGTYPE_ERROR, "#undef is not supported at the moment");
				return (PREPROCESS_NEXT_LINE);
			} else {
				/* Rest of the preprocessor macros to be handled by the original code */
			}
		} else {
			/* Expand preprocessor macros */
			for (macro = pi->first_preproc_macro; macro;) {
				if (macro->type == PREPROC_MACRO_OBJECT_LIKE) {
					/* Object-like macro */
					while ((macro_begin = locate_macro_call(line, macro->name, &macro_end))) {
						if (!inplace_replace(line, macro_begin, macro_end, macro->value, LINEBUFFER_LENGTH)) {
							print_msg(pi, MSGTYPE_ERROR, "Expanded macro %s with value %s too big", macro->name, macro->value);
							return (PREPROCESS_NEXT_LINE);
						}
						macro_expanded = True;
					}
				} else {
					/* Function-like macro */
					while ((macro_begin = locate_funcall_expr(line, macro->name, &macro_end))) {
						if (pi->pass == PASS_2 && pi->list_line && pi->list_on) {
							fprintf(pi->list_file, "%c:%06lx   +  %s\n",
									pi->cseg->ident, pi->cseg->addr, pi->list_line);
							// pi->list_line = NULL;
						}
						arg_mem = arg = strdup_section(macro_begin + strlen(macro->name) +1, macro_end-1);
						if (!arg_mem) {
							print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
							return (PREPROCESS_FATAL_ERROR);
						}
#if debug == 1
						printf("preprocess_line arg \"%s\"\n", arg);
#endif
						/* Collect args */
						first_arg = last_arg = NULL;
						while ((next_arg = get_next_token(arg, TERM_COMMA))) {
#if debug == 1
						printf("preprocess_line arg 1+ \"%s\"\n", arg);
#endif
							if (!is_label(arg)) {
								print_msg(pi, MSGTYPE_ERROR, "Function-like macro %s with invalid argument %s", macro->name, arg);
								free(arg_mem);
								return (PREPROCESS_NEXT_LINE);
							}
							if (!collect_paramarg(pi, arg, &first_arg, &last_arg))
								return (PREPROCESS_FATAL_ERROR);
							arg = next_arg;
						}
						get_next_token(arg, TERM_END);
#if debug == 1
						printf("preprocess_line arg 1  \"%s\"\n", arg);
#endif
						if (!collect_paramarg(pi, arg, &first_arg, &last_arg))
							return (PREPROCESS_FATAL_ERROR);
						free(arg_mem);
						/* Parameter vs. argument list length check */
						params_cnt = item_list_length(macro->params);
						args_cnt = item_list_length(first_arg);
						if (params_cnt != args_cnt) {
							print_msg(pi, MSGTYPE_ERROR, "Function-like macro %s called with %d arguments, however is defined with %d parameters", macro->name, args_cnt, params_cnt);
							return (PREPROCESS_NEXT_LINE);
						}
						strcpy(temp, macro->value);
#if debug == 1
						printf("preprocess_line temp \"%s\"\n", temp);
#endif
						for (params = macro->params, args_ptr = first_arg; params; params = params->next, args_ptr = args_ptr->next) {
							while ((par_begin = locate_macro_call(temp, params->value, &par_end))) {
								if (!inplace_replace(temp, par_begin, par_end, args_ptr->value, LINEBUFFER_LENGTH)) {
									print_msg(pi, MSGTYPE_ERROR, "Expanded macro parameter %s with value %s too big", params->value, args_ptr->value);
									return (PREPROCESS_NEXT_LINE);
								}
#if debug == 1
								printf("preprocess_line temp \"%s\"\n", temp);
#endif
							}
						}
						free_item_list(first_arg);
#if debug == 1
						printf("preprocess_line line (before inplace_replace) \"%s\"\n", line);
#endif
						if (!inplace_replace(line, macro_begin, macro_end, temp, LINEBUFFER_LENGTH)) {
							print_msg(pi, MSGTYPE_ERROR, "Expanded macro %s with value %s too big", macro->name, temp);
							return (PREPROCESS_NEXT_LINE);
						}
#if debug == 1
						printf("preprocess_line line (after inplace_replace) \"%s\"\n", line);
#endif
						apply_preproc_macro_opers(line);
#if debug == 1
						printf("preprocess_line line (after apply_preproc_macro_opers) \"%s\"\n", line);
#endif
						macro_expanded = True;
					}
				}
				macro = macro->next;
			}
		}

	} while (macro_expanded);
	return (PREPROCESS_PARSE_LINE);
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

	/* Preprocess the line. */
	switch (preprocess_line(pi, line)) {
		case PREPROCESS_PARSE_LINE:
			break;
		case PREPROCESS_NEXT_LINE:
			return (True);
		default:
		case PREPROCESS_FATAL_ERROR:
			return (False);
	}

	/* Filter out .stab debugging information */
	/* .stabs sometimes contains colon : symbol - might be interpreted as label */
	if (*line == '.') {					/* minimal slowdown of existing code */
		if (strncmp(line,".stabs ",7) == 0) {		/* compiler output is always lower case */
			strcpy(temp,line);			/* TODO : Do we need this temp variable ? Please check */
			return parse_stabs(pi, temp);
		}
		if (strncmp(line,".stabn ",7) == 0) {
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
	case TERM_CLOSING_PAREN:
		/* Skip to next ) or EOL or start of comment. */
		while ((data[i] != ')') && !IS_END_OR_COMMENT(data[i])) i++;
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

/* Check whether the pointed token is a function call.
 * If so, terminate the name and return a pointer to the next token or end. */
char *
funcall_token(char *token) {
	if (*token != '%' && *token != '_' && !isalpha(*token))	return NULL;
	while (IS_LABEL(*token))	token++;
	if (*token == '(') {
		*token++ = '\0';	/* Null-out paren, so we get the name */
		while (IS_HOR_SPACE(*token)) token++;	/* Skip whitespace after paren */
		return (token);		/* Return a pointer to the next token or end */
	}
	return (NULL);
}

/* Locate the first occurence of a macro call in a line.
 * Intended to be called repetitively to exhaust all possibilities.
 * Returns NULL in case there is no occurence. 
 * Otherwise returns the pointer to the beginning of the macro call and sets the end ptr.*/
char *
locate_macro_call(char *line, char *name, char **end)
{
	char *macro_call, *macro_call_end, *comment, *ptr;
	char *funcall_begin, *funcall_end;
	int name_len, inside_defined;
	comment = strchr(line, ';');
	name_len = strlen(name);
	while (1) {
		macro_call = nocase_strstr(line, name);
		if (!macro_call)
			return (NULL);
		if (comment && comment < macro_call)
			return (NULL);
		macro_call_end = macro_call + name_len - 1;
		if (macro_call == line || IS_END_OR_COMMENT(*(macro_call_end + 1)))
			break;
		if (IS_LABEL(*(macro_call - 1)) || IS_LABEL(*(macro_call_end + 1))) {
			while (IS_LABEL(*macro_call_end)) macro_call_end++;
			line = macro_call_end;
			continue;
		}
		ptr = line;
		inside_defined = False;
		while (!inside_defined && 
				(funcall_begin = locate_funcall_expr(ptr, "defined", &funcall_end))) {
			if (funcall_begin < macro_call && macro_call_end < funcall_end)
				inside_defined = True;
			ptr = funcall_end + 1;
		}
		if (!inside_defined)
			break;
		line = funcall_end + 1;
	}
	if (end) *end = macro_call_end;
	return (macro_call);
}

/* Locate the first occurence of the function call expression in a line.
 * Intended to be called repetitively to exhaust all possibilities.
 * Returns NULL in case there is no occurence. 
 * Otherwise returns the pointer to the beginning of the expr. and sets the end ptr.*/
char *
locate_funcall_expr(char *line, char *name, char **end)
{
	char *expr, *expr_end, *comment, *ptr;
	int len;
	expr = nocase_strstr(line, name);
	if (expr) {
		ptr = expr + strlen(name);
		if (*ptr == '(') {
			len = par_length(ptr + 1);
			if (len >= 0) {
				expr_end = ptr + 1 + len;
				comment = strchr(line, ';');
				if (!comment || expr_end < comment) {
					if (expr == line || !IS_LABEL(*(expr - 1))) {
						if (end) *end = expr_end;
						return (expr);
					}
				}
			}
		}
	}
	return (NULL);
}

/* Checks whether the given word is a label.
 * Returns true, when it is a label. False otherwise. */
int
is_label(char *word)
{
	if (word == NULL)
		return (False);
	do {
		if (!IS_LABEL(*word))
			return (False);
	} while(*++word);
	return (True);
}

/* Collect parameters or arguments into the supplied list.
 * Signals error and returns False in case of memory full. */
int
collect_paramarg(struct prog_info *pi, char *paramarg, struct item_list **first_paramarg, struct item_list **last_paramarg)
{
	struct item_list *new_paramarg;
	new_paramarg = malloc(sizeof(struct item_list));
	if (!new_paramarg) {
		print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
		return (False);
	}
	new_paramarg->next = NULL;
	new_paramarg->value = malloc(strlen(paramarg)+1);
	if (!new_paramarg->value) {
		print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
		return (False);
	}
	strcpy(new_paramarg->value, paramarg);

	if (*last_paramarg)
		(*last_paramarg)->next = new_paramarg;
	else
		*first_paramarg = new_paramarg;
	*last_paramarg = new_paramarg;
	return (True);
}

/* Replace the range of characters in line between begin and end with value.
 * Returns False in case the result would not fit into the line buffer. */
int
inplace_replace(char *line, char *begin, char *end, char *value, int buff_len)
{
	int value_len, rest_len, range_len;
	value_len = strlen(value);
	rest_len = strlen(end + 1);
	range_len = end - begin +1;
	if (strlen(line) +1 - range_len + value_len > buff_len)
		return (False);
	if (range_len != value_len)
		memmove(begin + value_len, end + 1, rest_len + 1);
	memmove(begin, value, value_len);
	return (True);
}

/* Apply the preprocessor macro operators. */
void
apply_preproc_macro_opers(char *line)
{
	char *begin, *end;

	while ((begin = strstr(line, "##"))) {	/* Apply Concatenation (##) operator */
		end = begin + 2;
		while (begin - 1 > line && IS_HOR_SPACE(*(begin - 1))) begin--;
		while (IS_HOR_SPACE(*end)) end++;
		memmove(begin, end, strlen(end) + 1);
	}
}

/* end of parser.c */

