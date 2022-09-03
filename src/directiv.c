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
#include <inttypes.h>
#include <ctype.h>

#include "misc.h"
#include "args.h"
#include "avra.h"
#include "device.h"

enum {
	DIRECTIVE_BYTE = 0,
	DIRECTIVE_CSEG,
	DIRECTIVE_CSEGSIZE,
	DIRECTIVE_DB,
	DIRECTIVE_DEF,
	DIRECTIVE_DEVICE,
	DIRECTIVE_DSEG,
	DIRECTIVE_DW,
	DIRECTIVE_ENDM,
	DIRECTIVE_ENDMACRO,
	DIRECTIVE_EQU,
	DIRECTIVE_ESEG,
	DIRECTIVE_EXIT,
	DIRECTIVE_INCLUDE,
	DIRECTIVE_INCLUDEPATH,
	DIRECTIVE_LIST,
	DIRECTIVE_LISTMAC,
	DIRECTIVE_MACRO,
	DIRECTIVE_NOLIST,
	DIRECTIVE_ORG,
	DIRECTIVE_SET,
	DIRECTIVE_DEFINE,
	DIRECTIVE_UNDEF,
	DIRECTIVE_IFDEF,
	DIRECTIVE_IFNDEF,
	DIRECTIVE_IF,
	DIRECTIVE_ELSE,
	DIRECTIVE_ELSEIF,			/* The Atmel AVR Assembler version 1.71 and later use ELSEIF and not ELIF */
	DIRECTIVE_ELIF,
	DIRECTIVE_ENDIF,
	DIRECTIVE_MESSAGE,
	DIRECTIVE_WARNING,
	DIRECTIVE_ERROR,
	DIRECTIVE_PRAGMA,
	DIRECTIVE_OVERLAP,
	DIRECTIVE_NOOVERLAP,
	DIRECTIVE_COUNT
};

static const char *const directive_list[] = {
	"BYTE",
	"CSEG",
	"CSEGSIZE",
	"DB",
	"DEF",
	"DEVICE",
	"DSEG",
	"DW",
	"ENDM",
	"ENDMACRO",
	"EQU",
	"ESEG",
	"EXIT",
	"INCLUDE",
	"INCLUDEPATH",
	"LIST",
	"LISTMAC",
	"MACRO",
	"NOLIST",
	"ORG",
	"SET",
	"DEFINE",
	"UNDEF",
	"IFDEF",
	"IFNDEF",
	"IF",
	"ELSE",
	"ELSEIF",		/* The Atmel AVR Assembler version 1.71 and later use ELSEIF and not ELIF */
	"ELIF",
	"ENDIF",
	"MESSAGE",
	"WARNING",
	"ERROR",
	"PRAGMA",
	"OVERLAP",
	"NOOVERLAP",
	NULL
};

enum {
	PRAGMA_OVERLAP,
	PRAGMA_COUNT
};

static const char *const pragma_list[] = {
	"OVERLAP",
	NULL
};

static const char *const overlap_value[] = {
	"DEFAULT",
	"IGNORE",
	"WARNING",
	"ERROR",
	NULL
};

/* caller has to free result */
static char *
joinpaths(const char *dirname, const char *fname)
{
	char *res;
	int len;

	len = strlen(dirname);
	res = malloc(len + strlen(fname) + 2);
	if (!res) {
		return NULL;
	}
	strcpy(res, dirname);
	if ((res[len - 1] != '\\') && (res[len - 1] != '/'))
		res[len++] = '/';
	strcpy(&res[len], fname);
	return res;
}

int
parse_directive(struct prog_info *pi)
{
	int directive, pragma;
	int ok = True;
	int64_t i;
	char *next, *data, buf[140];
	struct file_info *fi_bak;

	struct def *def;
	struct data_list *incpath, *dl;

	next = get_next_token(pi->fi->scratch, TERM_SPACE);

	my_strupr(pi->fi->scratch);
	directive = lookup_keyword(directive_list, pi->fi->scratch + 1, True);
	if (directive == -1) {
		print_msg(pi, MSGTYPE_ERROR, "Unknown directive: %s", pi->fi->scratch);
		return (True);
	}
	switch (directive) {
	case DIRECTIVE_BYTE:
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, ".BYTE needs a size operand");
			return (True);
		}
		if (pi->segment == pi->cseg) {
			print_msg(pi, MSGTYPE_ERROR, ".BYTE directive cannot be used within the code segment (.CSEG)");
			return False;
		}
		get_next_token(next, TERM_END);
		if (!get_expr(pi, next, &i))
			return (False);
		if (i < 0) {
			print_msg(pi, MSGTYPE_ERROR, ".BYTE directive must have nonnegative operand");
			return False;
		}
		if ((pi->pass == PASS_2) && pi->list_line && pi->list_on) {
			fprintf(pi->list_file, "%c:%06lx    %s\n",
			        pi->segment->ident, pi->segment->addr, pi->list_line);
			pi->list_line = NULL;
		}
		advance_ip(pi->segment, i);
		break;
	case DIRECTIVE_CSEG:
		fix_orglist(pi->segment);
		def_orglist(pi->cseg);
		break;
	case DIRECTIVE_CSEGSIZE:
		break;
	case DIRECTIVE_DB:
		if ((pi->pass == PASS_2) && pi->list_line && pi->list_on) {
			fprintf(pi->list_file, "          %s\n", pi->list_line);
			pi->list_line = NULL;
		}
		return (parse_db(pi, next));
	/* Directive .def */
	case DIRECTIVE_DEF:
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, ".DEF needs an operand");
			return (True);
		}
		data = get_next_token(next, TERM_EQUAL);
		if (!(data && (tolower(data[0]) == 'r') && isdigit(data[1]))) {
			print_msg(pi, MSGTYPE_ERROR, "%s needs a register (e.g. .def BZZZT = r16)", next);
			return (True);
		}
		i = atoi(&data[1]);
		/* check range of given register */
		if (i > 31)
			print_msg(pi, MSGTYPE_ERROR, "R%d is not a valid register", i);
		/* check if this reg is already assigned */
		for (def = pi->first_def; def; def = def->next) {
			if (def->reg == i && pi->pass == PASS_1 && !pi->NoRegDef) {
				print_msg(pi, MSGTYPE_WARNING, "r%d is already assigned to '%s'!", i, def->name);
				return (True);
			}
		}
		/* check if this regname is already defined */
		for (def = pi->first_def; def; def = def->next) {
			if (!nocase_strcmp(def->name, next)) {
				if (pi->pass == PASS_1 && !pi->NoRegDef) {
					print_msg(pi, MSGTYPE_WARNING, "'%s' is already assigned as r%d but will now be set to r%i!", next, def->reg, i);
				}
				def->reg = i;
				return (True);
			}
		}
		/* Check, if symbol is already defined as a label or constant */
		if (pi->pass == PASS_2) {
			if (get_label(pi,next,NULL))
				print_msg(pi, MSGTYPE_WARNING, "Name '%s' is used for a register and a label", next);
			if (get_constant(pi,next,NULL))
				print_msg(pi, MSGTYPE_WARNING, "Name '%s' is used for a register and a constant", next);
		}

		def = malloc(sizeof(struct def));
		if (!def) {
			print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
			return (False);
		}
		def->next = NULL;
		if (pi->last_def)
			pi->last_def->next = def;
		else
			pi->first_def = def;
		pi->last_def = def;
		def->name = malloc(strlen(next) + 1);
		if (!def->name) {
			print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
			return (False);
		}
		strcpy(def->name, next);
		def->reg = i;
		break;
	case DIRECTIVE_DEVICE:
		if (pi->pass == PASS_2)
			return (True);
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, ".DEVICE needs an operand");
			return (True);
		}
		if (pi->device->name != NULL) { /* Check for multiple device definitions */
			print_msg(pi, MSGTYPE_ERROR, "More than one .DEVICE definition");
		}
		if (pi->cseg->count || pi->dseg->count || pi->eseg->count) {
			/* Check if something was already assembled */
			print_msg(pi, MSGTYPE_ERROR, ".DEVICE definition must be before any code lines");
		} else {
			if ((pi->cseg->addr != pi->cseg->lo_addr)
			        || (pi->dseg->addr != pi->dseg->lo_addr)
			        || (pi->eseg->addr != pi->eseg->lo_addr)) {
				/* Check if something was already assembled */
				print_msg(pi, MSGTYPE_ERROR, ".DEVICE definition must be before any .ORG directive");
			}
		}

		get_next_token(next, TERM_END);
		pi->device = get_device(pi,next);
		if (!pi->device) {
			print_msg(pi, MSGTYPE_ERROR, "Unknown device: %s", next);
			pi->device = get_device(pi,NULL); /* Fix segmentation fault if device is unknown */
		}

		/* Now that we know the device type, we can
		 * start memory allocation from the correct offsets.
		 */
		fix_orglist(pi->segment);

		init_segment_size(pi, pi->device); 	/* Resync. ...->lo_addr variables */
		def_orglist(pi->segment);
		break;
	case DIRECTIVE_DSEG:
		fix_orglist(pi->segment);
		def_orglist(pi->dseg);
		if (pi->dseg->hi_addr == 0) {
			/* XXX move to emit */
			print_msg(pi, MSGTYPE_ERROR, "Can't use .DSEG directive because device has no RAM");
		}
		break;
	case DIRECTIVE_DW:
		if (pi->segment->flags & SEG_BSS_DATA) {
			print_msg(pi, MSGTYPE_ERROR, "Can't use .DW directive in data segment (.DSEG)");
			return (True);
		}
		while (next) {
			data = get_next_token(next, TERM_COMMA);
			if (pi->pass == PASS_2) {
				if (!get_expr(pi, next, &i))
					return (False);
				if ((i < -32768) || (i > 65535))
					print_msg(pi, MSGTYPE_WARNING, "Value %d is out of range (-32768 <= k <= 65535). Will be masked", i);
			}
			if (pi->pass == PASS_2) {
				if (pi->list_line && pi->list_on) {
					fprintf(pi->list_file, "          %s\n", pi->list_line);
					pi->list_line = NULL;
					fprintf(pi->list_file, "%c:%06lx %04"PRIx64"\n",
					        pi->segment->ident, pi->segment->addr, i);
				}
				if (pi->segment == pi->eseg) {
					write_ee_byte(pi, pi->eseg->addr, (unsigned char)i);
					write_ee_byte(pi, pi->eseg->addr + 1, (unsigned char)(i >> 8));
				}
				if (pi->segment == pi->cseg) {
					write_prog_word(pi, pi->cseg->addr, i);
				}
			}
			if (pi->segment == pi->eseg)
				advance_ip(pi->eseg, 2);
			if (pi->segment == pi->cseg)
				advance_ip(pi->cseg, 1);
			next = data;
		}
		break;
	case DIRECTIVE_ENDM:
	case DIRECTIVE_ENDMACRO:
		print_msg(pi, MSGTYPE_ERROR, "No .MACRO found before .ENDMACRO");
		break;
	case DIRECTIVE_EQU:
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, ".EQU needs an operand");
			return (True);
		}
		data = get_next_token(next, TERM_EQUAL);
		if (!data) {
			print_msg(pi, MSGTYPE_ERROR, "%s needs an expression (e.g. .EQU BZZZT = 0x2a)", next);
			return (True);
		}
		get_next_token(data, TERM_END);
		if (!get_expr(pi, data, &i))
			return (False);
		if (test_label(pi,next,"%s have already been defined as a label")!=NULL)
			return (True);
		if (test_variable(pi,next,"%s have already been defined as a .SET variable")!=NULL)
			return (True);
		/* Forward references allowed. But check, if everything is ok ... */
		if (pi->pass==PASS_1) { /* Pass 1 */
			if (test_constant(pi,next,"Can't redefine constant %s, use .SET instead")!=NULL)
				return (True);
			if (def_const(pi, next, i)==False)
				return (False);
		} else { /* Pass 2 */
			int64_t j;
			if (get_constant(pi, next, &j)==False) {  /* Defined in Pass 1 and now missing ? */
				print_msg(pi, MSGTYPE_ERROR, "Constant %s is missing in pass 2", next);
				return (False);
			}
			if (i != j) {
				print_msg(pi, MSGTYPE_ERROR, "Constant %s changed value from %"PRId64" in pass1 to %"PRId64" in pass 2", next,j,i);
				return (False);
			}
			/* OK. Definition is unchanged */
		}
		if ((pi->pass == PASS_2) && pi->list_line && pi->list_on) {
			fprintf(pi->list_file, "          %s\n", pi->list_line);
			pi->list_line = NULL;
		}
		break;
	case DIRECTIVE_ESEG:
		fix_orglist(pi->segment);
		def_orglist(pi->eseg);
		if (pi->device->eeprom_size == 0) { /* XXX */
			print_msg(pi, MSGTYPE_ERROR, "Can't use .ESEG directive because device has no EEPROM");
		}
		break;
	case DIRECTIVE_EXIT:
		pi->fi->exit_file = True;
		break;
	case DIRECTIVE_INCLUDE:
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, "Nothing to include");
			return (True);
		}
		next = term_string(pi, next);
		if ((pi->pass == PASS_2) && pi->list_line && pi->list_on) {
			fprintf(pi->list_file, "          %s\n", pi->list_line);
			pi->list_line = NULL;
		}
		/* Test if include is in local directory */
		ok = test_include(next);
		data = NULL;
		if (!ok) {
#ifdef DEFAULT_INCLUDE_PATH
			data = joinpaths(DEFAULT_INCLUDE_PATH, next);
			ok = test_include(data);
#endif
			for (incpath = GET_ARG_LIST(pi->args, ARG_INCLUDEPATH); incpath && !ok; incpath = incpath->next) {
				if (data != NULL) {
					free(data);
				}
				data = joinpaths(incpath->data, next);
				if (data == NULL) {
					print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
					return (False);
				}
				ok = test_include(data);
			}
		}
		if (ok) {
			fi_bak = pi->fi;
			ok = parse_file(pi, data ? data : next);
			pi->fi = fi_bak;
		} else
			print_msg(pi, MSGTYPE_ERROR, "Cannot find include file: %s", next);
		if (data)
			free(data);
		break;
	case DIRECTIVE_INCLUDEPATH:
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, ".INCLUDEPATH needs an operand");
			return (True);
		}
		data = get_next_token(next, TERM_SPACE);
		if (data) {
			print_msg(pi, MSGTYPE_ERROR, ".INCLUDEPATH needs an operand!!!");
			get_next_token(data, TERM_END);
			if (!get_expr(pi, data, &i))
				return (False);
		}
		next = term_string(pi, next);
		/* get arg list start pointer */
		incpath = GET_ARG_LIST(pi->args, ARG_INCLUDEPATH);

		data = malloc(strlen(next)+1);

		if (data) {
			strcpy(data, next);

			/* search for last element */
			if (incpath == NULL) {
				dl = malloc(sizeof(struct data_list));
				
				if (dl) {
					dl->next = NULL;
					dl->data = data;
					SET_ARG_LIST(pi->args, ARG_INCLUDEPATH, dl);
				} else {
					printf("Error: Unable to allocate memory\n");
					return (False);
				}
			} else {
				add_arg(&incpath, data);
			}
		} else {
			printf("Error: Unable to allocate memory\n");
			return (False);
		}
		break;
	case DIRECTIVE_LIST:
		if (pi->pass == PASS_2)
			if (pi->list_file)
				pi->list_on = True;
		break;
	case DIRECTIVE_LISTMAC:
		if (pi->pass == PASS_2)
			SET_ARG_I(pi->args, ARG_LISTMAC, True);
		break;
	case DIRECTIVE_MACRO:
		return (read_macro(pi, next));
	case DIRECTIVE_NOLIST:
		if (pi->pass == PASS_2)
			pi->list_on = False;
		break;
	case DIRECTIVE_ORG:
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, ".ORG needs an operand");
			return (True);
		}
		get_next_token(next, TERM_END);
		if (!get_expr(pi, next, &i))
			return (False);
		fix_orglist(pi->segment);
		pi->segment->addr = i; /* XXX advance */
		def_orglist(pi->segment);
		if (pi->fi->label)
			pi->fi->label->value = i;
		if ((pi->pass == PASS_2) && pi->list_line && pi->list_on) {
			fprintf(pi->list_file, "          %s\n", pi->list_line);
			pi->list_line = NULL;
		}
		break;
	case DIRECTIVE_SET:
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, ".SET needs an operand");
			return (True);
		}
		data = get_next_token(next, TERM_EQUAL);
		if (!data) {
			print_msg(pi, MSGTYPE_ERROR, "%s needs an expression (e.g. .SET BZZZT = 0x2a)", next);
			return (True);
		}
		get_next_token(data, TERM_END);
		if (!get_expr(pi, data, &i))
			return (False);

		if (test_label(pi,next,"%s have already been defined as a label")!=NULL)
			return (True);
		if (test_constant(pi,next,"%s have already been defined as a .EQU constant")!=NULL)
			return (True);
		return (def_var(pi, next, i));
	case DIRECTIVE_DEFINE:
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, ".DEFINE needs an operand");
			return (True);
		}
		data = get_next_token(next, TERM_SPACE);
		if (data) {
			get_next_token(data, TERM_END);
			if (!get_expr(pi, data, &i))
				return (False);
		} else
			i = 1;
		if (test_label(pi,next,"%s have already been defined as a label")!=NULL)
			return (True);
		if (test_variable(pi,next,"%s have already been defined as a .SET variable")!=NULL)
			return (True);
		/* Forward references allowed. But check, if everything is ok ... */
		if (pi->pass==PASS_1) { /* Pass 1 */
			if (test_constant(pi,next,"Can't redefine constant %s, use .SET instead")!=NULL)
				return (True);
			if (def_const(pi, next, i)==False)
				return (False);
		} else { /* Pass 2 */
			int64_t j;
			if (get_constant(pi, next, &j)==False) {  /* Defined in Pass 1 and now missing ? */
				print_msg(pi, MSGTYPE_ERROR, "Constant %s is missing in pass 2", next);
				return (False);
			}
			if (i != j) {
				print_msg(pi, MSGTYPE_ERROR, "Constant %s changed value from %"PRId64" in pass1 to %"PRId64" in pass 2", next,j,i);
				return (False);
			}
			/* OK. Definition is unchanged */
		}
		if ((pi->pass == PASS_2) && pi->list_line && pi->list_on) {
			fprintf(pi->list_file, "          %s\n", pi->list_line);
			pi->list_line = NULL;
		}
		break;
	case DIRECTIVE_NOOVERLAP:
		if (pi->pass == PASS_1) {
			fix_orglist(pi->segment);
			pi->segment_overlap = SEG_DONT_OVERLAP;
			def_orglist(pi->segment);
		}
		break;
	case DIRECTIVE_OVERLAP:
		if (pi->pass == PASS_1) {
			fix_orglist(pi->segment);
			pi->segment_overlap = SEG_ALLOW_OVERLAP;
			def_orglist(pi->segment);
		}
		break;
	case DIRECTIVE_PRAGMA:
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, "PRAGMA needs an operand, %s should be specified",
			          snprint_list(buf, sizeof(buf), pragma_list));
			return (True);
		}
		my_strupr(next);
		data = get_next_token(next, TERM_SPACE);
		pragma = lookup_keyword(pragma_list, next, False);
		switch (pragma) {

		case PRAGMA_OVERLAP:
			if (pi->pass == PASS_1) {
				int overlap_setting = OVERLAP_UNDEFINED;
				if (data) {
					my_strupr(data);
					overlap_setting = lookup_keyword(overlap_value, data, False);
				};
				switch (overlap_setting) {
				case OVERLAP_DEFAULT:
					pi->effective_overlap = GET_ARG_I(pi->args, ARG_OVERLAP);
					break;

				case OVERLAP_IGNORE:
				case OVERLAP_WARNING:
				case OVERLAP_ERROR:
					pi->effective_overlap = overlap_setting;
					break;

				default:
					print_msg(pi, MSGTYPE_ERROR, "For PRAGMA %s directive"
					          " %s should be specified as the parameter", next,
					          snprint_list(buf, sizeof(buf), overlap_value));
					return (False);
				}
			}
			return (True);
			break;
		default:
			if (pi->pass == PASS_2)
				print_msg(pi, MSGTYPE_MESSAGE, "PRAGMA %s directive currently ignored", next);
			return (True);
		}
		break;
	case DIRECTIVE_UNDEF: /* TODO */
		break;
	case DIRECTIVE_IFDEF:
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, ".IFDEF needs an operand");
			return True;
		}
		get_next_token(next, TERM_END);
		/* Store location of ifdef (line number and file number) if the condition
		 * fails on pass 1 so that we do not reinterpret it as succeeding on pass 2. */
		if ((pi->pass==PASS_1 && get_symbol(pi, next, NULL)) || (pi->pass==PASS_2 && !ifdef_is_blacklisted(pi))) {
			pi->conditional_depth++;
		} else {
			if (pi->pass==PASS_1) {
				/* Blacklist this ifdef. */
				if (!ifdef_blacklist(pi)) {
					return False;
				}
			}
			if (!spool_conditional(pi, False)) {
				return False;
			}
		}
		break;
	case DIRECTIVE_IFNDEF:
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, ".IFNDEF needs an operand");
			return True;
		}
		get_next_token(next, TERM_END);
		/* Store location of ifndef (line number and file number) if the condition
		 * fails on pass 1 so that we do not reinterpret it as succeeding on pass 2. */
		if ((pi->pass==PASS_1 && !get_symbol(pi, next, NULL)) || (pi->pass==PASS_2 && !ifndef_is_blacklisted(pi))) {
			pi->conditional_depth++;
		} else {
			if (pi->pass==PASS_1) {
				/* Blacklist this ifndef. */
				if (!ifndef_blacklist(pi)) {
					return False;
				}
			}
			if (!spool_conditional(pi, False)) {
				return False;
			}
		}
		break;
	case DIRECTIVE_IF:
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, ".IF needs an expression");
			return (True);
		}
		get_next_token(next, TERM_END);
		if (!get_expr(pi, next, &i))
			return (False);
		if (i)
			pi->conditional_depth++;
		else {
			if (!spool_conditional(pi, False))
				return (False);
		}
		break;
	case DIRECTIVE_ELSE:
	case DIRECTIVE_ELIF:
	case DIRECTIVE_ELSEIF:
		if (!spool_conditional(pi, True))
			return (False);
		break;
	case DIRECTIVE_ENDIF:
		if (pi->conditional_depth == 0)
			print_msg(pi, MSGTYPE_ERROR, "Too many .ENDIF");
		else
			pi->conditional_depth--;
		break;
	case DIRECTIVE_MESSAGE:
		if (pi->pass == PASS_1)
			return (True);
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, "No message parameter supplied");
			return (True);
		}
		print_msg(pi, MSGTYPE_MESSAGE_NO_LF, NULL); 	/* Prints Line Header (filename, linenumber) without trailing \n */
		while (next) {
			data = get_next_token(next, TERM_COMMA);
			if (next[0] == '\"') { 	/* string parsing */
				next = term_string(pi, next);
				print_msg(pi, MSGTYPE_APPEND,"%s",next);
				while (*next != '\0') {
					next++;
				}
			} else {
				if (!get_expr(pi, next, &i)) {
					print_msg(pi, MSGTYPE_APPEND,"\n"); /* Add newline */
					return (False);
				}
				print_msg(pi, MSGTYPE_APPEND,"0x%02X",i);
			}
			next = data;
		}
		print_msg(pi, MSGTYPE_APPEND,"\n"); /* Add newline */
		break;
	case DIRECTIVE_WARNING:
		if (pi->pass == PASS_1)
			return (True);
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, "No warning string supplied");
			return (True);
		}
		next = term_string(pi, next);
		print_msg(pi, MSGTYPE_WARNING, next);
		break;
	case DIRECTIVE_ERROR:
		if (!next) {
			print_msg(pi, MSGTYPE_ERROR, "No error string supplied");
			return (True);
		}
		next = term_string(pi, next);
		print_msg(pi, MSGTYPE_ERROR, "%s", next);
		pi->error_count = pi->max_errors;
		if (pi->pass == PASS_1)
			return (True);
		break;
	}
	return (ok);
}


int
lookup_keyword(const char *const keyword_list[], const char *const keyword, int strict)
{
	int i;

	for (i = 0; keyword_list[i] != NULL; i++) {
		if (strict) {
			if (!strcmp(keyword, keyword_list[i]))
				return (i);
		} else {
			if (!strncmp(keyword, keyword_list[i], strlen(keyword_list[i])))
				return (i);
		}
	}
	return (-1);
}

char *
term_string(struct prog_info *pi, char *string)
{
	int i;

	if (string[0] != '\"') {
		print_msg(pi, MSGTYPE_ERROR, "String must be enclosed in \"-signs");
	} else {
		string++;
	}
	/* skip to the end of the string*/
	for (i = 0; (string[i] != '\"') && !((string[i] == 10) || (string[i] == 13) || (string[i] == '\0')); i++);
	if ((string[i] == 10) || (string[i] == 13) || (string[i] == '\0')) {
		print_msg(pi, MSGTYPE_ERROR, "String is missing a closing \"-sign");
	}
	string[i] = '\0'; /* and terminate it where the " was */
	return (string);
}

/* Parse data byte directive */
int
parse_db(struct prog_info *pi, char *next)
{
	int64_t i;
	int count;
	char *data;
	char prev = 0;

	/* check if .db is allowed in this segment type */
	if (pi->segment->flags & SEG_BSS_DATA) {
		print_msg(pi, MSGTYPE_ERROR, "Can't use .DB directive in data segment (.DSEG) !");
		return True ;
	}

	count = 0;
	if (pi->pass == PASS_2 && pi->list_on) {
		fprintf(pi->list_file, "%c:%06lX ", pi->segment->ident, pi->segment->addr);
	}
	/* get each db token */
	while (next) {
		data = get_next_token(next, TERM_COMMA);
		/* string parsing */
		if (next[0] == '\"') {
			next = term_string(pi, next);
			while (*next != '\0') {
				count++;
				write_db(pi, *next, &prev, count);
				if (pi->pass == PASS_2 && pi->list_on)
					fprintf(pi->list_file, "%02X", (unsigned char)*next);
				if ((unsigned char)*next > 127 && pi->pass == PASS_2)
					print_msg(pi, MSGTYPE_WARNING, "Found .DB string with characters > code 127. Be careful !"); /* Print warning for codes > 127 */
				next++;
			}
		} else {
			if (pi->pass == PASS_2) {
				if (!get_expr(pi, next, &i))
					return (False);
				if ((i < -128) || (i > 255))
					print_msg(pi, MSGTYPE_WARNING, "Value %"PRId64" is out of range (-128 <= k <= 255). Will be masked", i);
				if (pi->list_on) fprintf(pi->list_file, "%02"PRIX64, i);
			}
			count++;
			write_db(pi, (char)i, &prev, count);
		}
		next = data;
	}
	if (pi->segment == pi->cseg) { /* XXX PAD */
		if ((count % 2) == 1) {
			if (pi->pass == PASS_2)  {
				if (pi->list_on) fprintf(pi->list_file, "00 ; zero byte added");
				write_prog_word(pi, pi->segment->addr, prev & 0xFF);
				print_msg(pi, MSGTYPE_WARNING, "A .DB segment with an odd number of bytes is detected. A zero byte is added.");
			}
			advance_ip(pi->cseg, 1);
		}
	}
	if (pi->pass == PASS_2 && pi->list_on) {
		fprintf(pi->list_file, "\n");
		pi->list_line = NULL;
	}
	return True;
}


void
write_db(struct prog_info *pi, char byte, char *prev, int count)
{
	if (pi->segment == pi->eseg)	{
		if (pi->pass == PASS_2) {
			write_ee_byte(pi, pi->eseg->addr, byte);
		}
		advance_ip(pi->eseg, 1);
	}
	if (pi->segment == pi->cseg) {
		if ((count % 2) == 0) {
			if (pi->pass == PASS_2) {
				write_prog_word(pi, pi->cseg->addr, (byte << 8) | (*prev & 0xff));
			}
			advance_ip(pi->cseg, 1);
		} else {
			*prev = byte;
		}
	}
}


int
spool_conditional(struct prog_info *pi, int only_endif)
{
	int current_depth = 0, do_next;

	if (pi->macro_line) {
		while ((pi->macro_line = pi->macro_line->next)) {
			pi->macro_call->line_index++;
			if (check_conditional(pi, pi->macro_line->line, &current_depth,  &do_next, only_endif)) {
				if (!do_next)
					return (True);
			} else
				return (False);
		}
		print_msg(pi, MSGTYPE_ERROR, "Found no closing .ENDIF in macro");
	} else {
		if ((pi->pass == PASS_2) && pi->list_line && pi->list_on)
			fprintf(pi->list_file, "          %s\n", pi->list_line);
		while (fgets_new(pi,pi->fi->buff, LINEBUFFER_LENGTH, pi->fi->fp)) {
			pi->fi->line_number++;
			if (check_conditional(pi, pi->fi->buff, &current_depth,  &do_next, only_endif)) {
				if (!do_next)
					return (True);
			} else
				return (False);
		}
		if (feof(pi->fi->fp)) {
			print_msg(pi, MSGTYPE_ERROR, "Found no closing .ENDIF");
			return (True);
		} else {
			perror(pi->fi->include_file->name);
			return (False);
		}
	}
	return (True);
}


int
check_conditional(struct prog_info *pi, char *pbuff, int *current_depth, int *do_next, int only_endif)
{
	int64_t i = 0;
	char *next;
	char linebuff[LINEBUFFER_LENGTH];

	strcpy(linebuff, pbuff); /* avoid cutting of the end of .elif line */

	*do_next = False;
	while (IS_HOR_SPACE(linebuff[i]) && !IS_END_OR_COMMENT(linebuff[i])) i++;
	if ((linebuff[i] == '.') || (linebuff[i] == '#')) {
		i++;
		if (!nocase_strncmp(&linebuff[i], "if", 2))
			(*current_depth)++;
		else if (!nocase_strncmp(&linebuff[i], "endif", 5)) {
			if (*current_depth == 0)
				return (True);
			(*current_depth)--;
		} else if (!only_endif && (*current_depth == 0)) {
			if ((!nocase_strncmp(&linebuff[i], "else", 4)) && (nocase_strncmp(&linebuff[i], "elseif", 6))) {
				pi->conditional_depth++;
				return (True);
			}	else if ((!nocase_strncmp(&linebuff[i], "elif", 4)) || (!nocase_strncmp(&linebuff[i], "elseif", 6))) {
				next = get_next_token(&linebuff[i], TERM_SPACE);
				if (!next) {
					print_msg(pi, MSGTYPE_ERROR, ".ELSEIF / .ELIF needs an operand");
					return (True);
				}
				get_next_token(next, TERM_END);
				if (!get_expr(pi, next, &i))
					return (False);
				if (i)
					pi->conditional_depth++;
				else {
					if (!spool_conditional(pi, False))
						return (False);
				}
				return (True);
			}
		}
	}
	*do_next = True;
	return (True);
}

int
test_include(const char *filename)
{
	FILE *fp;
	fp = fopen(filename, "r");
	if (fp) {
		fclose(fp);
		return (True);
	} else
		return (False);
}

/* end of directiv.c */


