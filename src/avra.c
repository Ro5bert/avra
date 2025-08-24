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
#include <stdarg.h>
#include <inttypes.h>
#include <string.h>

#include "misc.h"
#include "args.h"
#include "avra.h"
#include "device.h"

#define debug 0

const char *title = "AVRA: advanced AVR macro assembler (version %s)\n";

const char *usage =
    "usage: avra [-f][O|M|I|G] output file type\n"
    "            [-o <filename>] output file name\n"
    "            [-d <filename>] debug file name\n"
    "            [-e <filename>] file name to output EEPROM contents\n"
    "            [-l <filename>] generate list file\n"
    "            [-m <mapfile>] generate map file\n"
    "            [--define <symbol>[=<value>]]\n"
    "            [-I <dir>] [--listmac]\n"
    "            [--max_errors <number>] [--devices] [--version]\n"
    "            [-O e|w|i]\n"
    "            [-h] [--help] general help\n"
    "            <file to assemble>\n"
    "\n"
    "   --listfile    -l : Create list file\n"
    "   --mapfile     -m : Create map file\n"
    "   --define      -D : Define symbol.\n"
    "   --includedir  -I : Additional include paths. Default: %s\n"
    "   --listmac        : List macro expansion in listfile.\n"
    "   --max_errors     : Maximum number of errors before exit\n"
    "                      (default: 10)\n"
    "   --devices        : List out supported devices.\n"
    "   --version        : Version information.\n"
    "   -O e|w|i         : Issue error/warning/ignore overlapping code.\n"
    "   --help, -h       : This help text.\n";

const struct dataset overlap_choice[4] = {
	{ OVERLAP_ERROR,   "e"},
	{ OVERLAP_WARNING, "w"},
	{ OVERLAP_IGNORE,  "i"},
	{ -1, NULL}
};

const int SEG_BSS_DATA = 0x01;

static struct prog_info PROG_INFO;
static struct segment_info CODE_SEG;
static struct segment_info DATA_SEG;
static struct segment_info EEPROM_SEG;

int
main(int argc, const char *argv[])
{
	int show_usage = False;
	struct prog_info *pi;
	struct args *args;
	unsigned char c;

#if debug == 1
	int i;
	for (i = 0; i < argc; i++) {
		printf(argv[i]);
		printf("\n");
	}
#endif

	printf(title, VERSION);

	args = alloc_args(ARG_COUNT);
	if (args) {
		define_arg(args, ARG_DEFINE,      ARGTYPE_STRING_MULTISINGLE,  'D', "define",      NULL, NULL);
		define_arg(args, ARG_INCLUDEPATH, ARGTYPE_STRING_MULTISINGLE,  'I', "includedir",  NULL, NULL);
		define_arg(args, ARG_LISTMAC,     ARGTYPE_BOOLEAN,              0,  "listmac",     "1",  NULL);
		define_arg_int(args, ARG_MAX_ERRORS,  ARGTYPE_NUMERIC,               0,  "max_errors",  10, NULL);
		define_arg(args, ARG_COFF,        ARGTYPE_BOOLEAN,              0,  "coff",        NULL, NULL);
		define_arg(args, ARG_DEVICES,     ARGTYPE_BOOLEAN,              0,  "devices",     NULL, NULL);
		define_arg(args, ARG_VER,         ARGTYPE_BOOLEAN,              0,  "version",     NULL, NULL);
		define_arg(args, ARG_HELP,        ARGTYPE_BOOLEAN,             'h', "help",        NULL, NULL);
		define_arg(args, ARG_WRAP,        ARGTYPE_BOOLEAN,             'w', "wrap",        NULL, NULL);	/* Not implemented ? B.A. */
		define_arg(args, ARG_WARNINGS,    ARGTYPE_STRING_MULTISINGLE,  'W', "warn",        NULL, NULL);
		define_arg(args, ARG_FILEFORMAT,  ARGTYPE_CHAR_ATTACHED,       'f', "filetype",    "0",	 NULL);	/* Not implemented ? B.A. */
		define_arg(args, ARG_LISTFILE,    ARGTYPE_STRING,              'l', "listfile",    NULL, NULL);
		define_arg(args, ARG_OUTFILE,     ARGTYPE_STRING,              'o', "outfile",     NULL, NULL);
		define_arg(args, ARG_MAPFILE,     ARGTYPE_STRING,              'm', "mapfile",     NULL, NULL);
		define_arg(args, ARG_DEBUGFILE,   ARGTYPE_STRING,              'd', "debugfile",   NULL, NULL);
		define_arg(args, ARG_EEPFILE,     ARGTYPE_STRING,              'e', "eepfile",     NULL, NULL);
		define_arg_int(args, ARG_OVERLAP, ARGTYPE_CHOICE,              'O', "overlap",     OVERLAP_ERROR, overlap_choice);


		c = read_args(args, argc, argv);

		if (c != 0) {
			if (!GET_ARG_I(args, ARG_HELP) && (argc != 1))	{
				if (!GET_ARG_I(args, ARG_VER)) {
					if (!GET_ARG_I(args, ARG_DEVICES)) {
						pi = init_prog_info(&PROG_INFO, args);
						if (pi) {
							get_rootpath(pi, args);  /* get assembly root path */
							if (assemble(pi) != 0) { /* the main assembly call */
								exit(EXIT_FAILURE);
							}
							free_pi(pi);             /* free all allocated memory */
						}
					} else {
						list_devices();            /* list all supported devices */
					}
				}
			} else
				show_usage = True;
		}
		free_args(args);
	} else {
		show_usage = True;
		printf("\n");
	}
	if (show_usage) {
#ifdef DEFAULT_INCLUDE_PATH
		printf(usage, DEFAULT_INCLUDE_PATH);
#else
		printf(usage, ".");
#endif
	}
	exit(EXIT_SUCCESS);
	return (0);
}

void
get_rootpath(struct prog_info *pi, struct args *args)
{
	int i;
	int j;
	char c;
	struct data_list *data;

	data = args->first_data;
	if (!data)
		return;
	while (data->next) data = ((data)->next);

	if (data != NULL) {
		i = strlen((char *)data->data);
		if (i > 0) {
			pi->root_path = malloc(i + 1);
			strcpy(pi->root_path,(char *)data->data);
			j = 0;
			do {
				c = pi->root_path[i];
				if (c == '\\' || c == '/') {
					j = i + 1;
					break;
				}
			} while (i-- > 0);
			pi->root_path[j] = '\0';
			return;
		}
	}
	pi->root_path = "";
}


int
assemble(struct prog_info *pi)
{
	unsigned char c;

	if (pi->args->first_data) {
		printf("Pass 1...\n");
		if (load_arg_defines(pi)==False)
			return -1;
		if (predef_dev(pi)==False)
			return -1;

		/*** FIRST PASS ***/
		def_orglist(pi->cseg);
		c = parse_file(pi, pi->args->first_data->data);
		fix_orglist(pi->segment);
		test_orglist(pi->cseg);
		test_orglist(pi->dseg);
		test_orglist(pi->eseg);

		if (c != False) {
			/* if there are no further errors, we can continue with 2nd pass */
			if (pi->error_count == 0) {
				pi->segment = pi->cseg;
				rewind_segments(pi);
				pi->pass=PASS_2;
				if (load_arg_defines(pi)==False)
					return -1;
				if (predef_dev(pi)==False)
					return -1;
				/*** SECOND PASS ***/
				c = open_out_files(pi, pi->args->first_data->data,
				                   GET_ARG_P(pi->args, ARG_OUTFILE),
				                   GET_ARG_P(pi->args, ARG_DEBUGFILE),
				                   GET_ARG_P(pi->args, ARG_EEPFILE));
				if (c != 0) {
					printf("Pass 2...\n");
					parse_file(pi, pi->args->first_data->data);
					printf("done\n\n");
					if (pi->list_file)
						fprint_segments(pi->list_file, pi);
					if (pi->coff_file && pi->error_count == 0) {
						write_coff_file(pi);
					}
					write_map_file(pi);
					if (pi->error_count) {
						printf("\nAssembly aborted with %d errors and %d warnings.\n", pi->error_count, pi->warning_count);
						unlink_out_files(pi, pi->args->first_data->data);
					} else {
						if (pi->warning_count)
							printf("\nAssembly complete with no errors (%d warnings).\n", pi->warning_count);
						else
							printf("\nAssembly complete with no errors.\n");
						close_out_files(pi);
					}
				}
			} else	{
				unlink_out_files(pi, pi->args->first_data->data);
			}
		}
	} else {
		printf("Error: You need to specify a file to assemble\n");
	}
	return pi->error_count;
}


int
load_arg_defines(struct prog_info *pi)
{
	int64_t i;
	char *expr;
	char buff[256];
	struct data_list *define;

	for (define = GET_ARG_LIST(pi->args, ARG_DEFINE); define; define = define->next) {
		strcpy(buff, define->data);
		expr = get_next_token(buff, TERM_EQUAL);
		if (expr) {
			/* we reach this, when there is actually a value passed.. */
			if (!get_expr(pi, expr, &i)) {
				return (False);
			}
		} else {
			/* if user didnt specify a value, we default to 1 */
			i = 1;
		}
		/* Forward references allowed. But check, if everything is ok... */
		if (pi->pass==PASS_1) { /* Pass 1 */
			if (test_constant(pi,buff,NULL)!=NULL) {
				fprintf(stderr,"Error: Can't define symbol %s twice\n", buff);
				return (False);
			}
			if (def_const(pi, buff, i)==False)
				return (False);
		} else { /* Pass 2 */
			int64_t j;
			if (get_constant(pi, buff, &j)==False) {  /* Defined in Pass 1 and now missing ? */
				fprintf(stderr,"Constant %s is missing in pass 2\n",buff);
				return (False);
			}
			if (i != j) {
				fprintf(stderr,"Constant %s changed value from %" PRId64 " in pass1 to %" PRId64 " in pass 2\n",buff,j,i);
				return (False);
			}
			/* OK. Definition is unchanged */
		}
	}
	return (True);
}

void
rewind_segments(struct prog_info *pi)
{
	pi->cseg->addr = pi->cseg->lo_addr;
	pi->dseg->addr = pi->dseg->lo_addr;
	pi->eseg->addr = pi->eseg->lo_addr;
}

void
init_segment_size(struct prog_info *pi, struct device *device)
{
	pi->cseg->hi_addr = device->flash_size;
	pi->cseg->cellsize = 2;

	pi->dseg->lo_addr = device->ram_start;
	pi->dseg->hi_addr = device->ram_size+device->ram_start;
	pi->dseg->cellsize = 1;

	pi->eseg->hi_addr = device->eeprom_size;
	pi->eseg->cellsize = 1;
	rewind_segments(pi);
}


struct prog_info *
init_prog_info(struct prog_info *pi, struct args *args)
{
	struct data_list *warnings;

	memset(pi, 0, sizeof(struct prog_info));
	pi->args = args;
	pi->device = get_device(pi,NULL);
	if (GET_ARG_P(args, ARG_LISTFILE) == NULL) {
		pi->list_on = False;
	} else {
		pi->list_on = True;
	}
	if (GET_ARG_P(args, ARG_MAPFILE) == NULL) {
		pi->map_on = False;
	} else {
		pi->map_on = True;
	}
	for (warnings = GET_ARG_LIST(args, ARG_WARNINGS); warnings; warnings = warnings->next) {
		if (!nocase_strcmp(warnings->data, "NoRegDef"))
			pi->NoRegDef = 1;
	}

	pi->cseg = &CODE_SEG;
	pi->dseg = &DATA_SEG;
	pi->eseg = &EEPROM_SEG;
	memset(pi->cseg, 0, sizeof(struct segment_info));
	memset(pi->dseg, 0, sizeof(struct segment_info));
	memset(pi->eseg, 0, sizeof(struct segment_info));

	pi->cseg->name = "code";
	pi->dseg->name = "data";
	pi->eseg->name = "EEPROM";
	pi->cseg->ident = 'C';
	pi->dseg->ident = 'D';
	pi->eseg->ident = 'E';

	pi->dseg->flags = SEG_BSS_DATA;

	pi->cseg->cellname = "word";
	pi->dseg->cellname = "byte";
	pi->eseg->cellname = "byte";
	pi->cseg->cellnames = "words";
	pi->dseg->cellnames = "bytes";
	pi->eseg->cellnames = "bytes";

	init_segment_size(pi, pi->device);

	pi->cseg->pi = pi;
	pi->dseg->pi = pi;
	pi->eseg->pi = pi;

	pi->segment = pi->cseg;

	pi->max_errors = GET_ARG_I(args, ARG_MAX_ERRORS);
	pi->pass=PASS_1;
	pi->time=time(NULL);
	pi->effective_overlap = GET_ARG_I(pi->args, ARG_OVERLAP);
	pi->segment_overlap = SEG_DONT_OVERLAP;
	return (pi);
}

void
free_pi(struct prog_info *pi)
{
	free_defs(pi);
	free_labels(pi);
	free_constants(pi);
	free_variables(pi);
	free_ifdef_blacklist(pi);
	free_ifndef_blacklist(pi);
	free_orglist(pi);
}

void
advance_ip(struct segment_info *si, int offset)
{
	si->addr += offset;
	if (si->pi->pass == PASS_1)
		si->count += offset;
}

void
print_msg(struct prog_info *pi, int type, char *fmt, ...)
{
	char *pc;
	if (type == MSGTYPE_OUT_OF_MEM) {
		fprintf(stderr, "Error: Unable to allocate memory!\n");
	} else {
		if (type != MSGTYPE_APPEND) {
			if ((pi->fi != NULL) && (pi->fi->include_file->name != NULL)) {
				/* check if adding path name is needed */
				pc = strstr(pi->fi->include_file->name, pi->root_path);
				if (pc == NULL) {
					fprintf(stderr, "%s%s(%d) : ", pi->root_path,pi->fi->include_file->name, pi->fi->line_number);
				} else {
					fprintf(stderr, "%s(%d) : ", pi->fi->include_file->name, pi->fi->line_number);
				}
			}
		}
		switch (type) {
		case MSGTYPE_ERROR:
			pi->error_count++;
			fprintf(stderr, "Error   : ");
			break;
		case MSGTYPE_WARNING:
			pi->warning_count++;
			fprintf(stderr, "Warning : ");
			break;
		case MSGTYPE_MESSAGE:
			/*			case MSGTYPE_MESSAGE_NO_LF:
						case MSGTYPE_APPEND: */
			break;
		}
		if (type != MSGTYPE_APPEND) {
			if (pi->macro_call) {
				fprintf(stderr, "[Macro: %s: %d:] ", pi->macro_call->macro->include_file->name,
				        pi->macro_call->line_index + pi->macro_call->macro->first_line_number);
			}
		}
		if (fmt != NULL) {
			va_list args;
			va_start(args, fmt);
			vfprintf(stderr, fmt, args);
			va_end(args);
		}

		if ((type != MSGTYPE_APPEND) && (type != MSGTYPE_MESSAGE_NO_LF))
			fprintf(stderr, "\n");
	}
}


int
def_const(struct prog_info *pi, const char *name, int64_t value)
{
	struct label *label;
	label = malloc(sizeof(struct label));
	if (!label) {
		print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
		return (False);
	}
	label->next = NULL;
	if (pi->last_constant)
		pi->last_constant->next = label;
	else
		pi->first_constant = label;
	pi->last_constant = label;
	label->name = malloc(strlen(name) + 1);
	if (!label->name) {
		print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
		return (False);
	}
	strcpy(label->name, name);
	label->value = value;
	return (True);
}

int
def_var(struct prog_info *pi, char *name, int value)
{
	struct label *label;

	for (label = pi->first_variable; label; label = label->next)
		if (!nocase_strcmp(label->name, name)) {
			label->value = value;
			return (True);
		}
	label = malloc(sizeof(struct label));
	if (!label) {
		print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
		return (False);
	}
	label->next = NULL;
	if (pi->last_variable)
		pi->last_variable->next = label;
	else
		pi->first_variable = label;
	pi->last_variable = label;
	label->name = malloc(strlen(name) + 1);
	if (!label->name) {
		print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
		return (False);
	}
	strcpy(label->name, name);
	label->value = value;
	return (True);
}

/* Store programmed areas for later check */
int
def_orglist(struct segment_info *si)
{
	struct orglist *orglist;

	si->pi->segment = si;
	if (si->pi->pass != PASS_1)
		return (True);
	orglist = malloc(sizeof(struct orglist));
	if (!orglist) {
		print_msg(si->pi, MSGTYPE_OUT_OF_MEM, NULL);
		return (False);
	}
	orglist->next = NULL;
	if (si->last_orglist)
		si->last_orglist->next = orglist;
	else
		si->first_orglist = orglist;
	si->last_orglist = orglist;
	orglist->segment = si;
	orglist->start = si->addr;
	orglist->length = 0;
	orglist->segment_overlap = si->pi->segment_overlap;
	return True;
}

/* Fill length entry of last orglist */
int
fix_orglist(struct segment_info *si)
{
	if (si->pi->pass != PASS_1)
		return (True);
	if ((si->last_orglist == NULL) || (si->last_orglist->length!=0)) {
		fprintf(stderr,"Internal Error: fix_orglist\n");
		return (False);
	}
	si->last_orglist->segment = si;
	si->last_orglist->length = si->addr - si->last_orglist->start;
	return True;
}

void
fprint_orglist(FILE *file, struct segment_info *si, struct orglist *orglist)
{
	fprintf(file, "   %-6s    :  Start = 0x%04X, End = 0x%04X, Length = 0x%04X (%d %s), "
	        "Overlap=%c\n",
	        si->name,
	        orglist->start,
	        orglist->start + orglist->length - 1,
	        orglist->length,
	        orglist->length,
	        orglist->length == 1 ? si->cellname : si->cellnames,
	        orglist->segment_overlap == SEG_ALLOW_OVERLAP ? 'Y' : 'N');
}

void
fprint_seg_orglist(FILE *file, struct segment_info *si)
{
	struct orglist *orglist;

	for (orglist = si->first_orglist;
	        orglist != NULL; orglist = orglist->next) {
		if (orglist->length > 0)
			fprint_orglist(file, si, orglist);
	}
}

void
fprint_segments(FILE *file, struct prog_info *pi)
{
	fprintf(file, "Used memory blocks:\n");
	fprint_seg_orglist(file, pi->cseg);
	fprint_seg_orglist(file, pi->dseg);
	fprint_seg_orglist(file, pi->eseg);
}

/* Test for overlapping segments and device space */
int
test_orglist(struct segment_info *si)
{
	struct orglist *orglist, *orglist2;

	int error_count=0;
	if (si->pi->device->name == NULL) {
		fprintf(stderr,"Warning : No .DEVICE definition found. Cannot make useful address range check !\n");
		si->pi->warning_count++;
	}

	for (orglist = si->first_orglist;
	        orglist != NULL;
	        orglist=orglist->next) {
		if (orglist->length > 0) {
			/* Make sure address area is valid */
			if (orglist->start < si->lo_addr) {
				fprintf(stderr, "Segment start below allowed start address: 0x%04lX",
				        si->lo_addr);
				fprint_orglist(stderr, si, orglist);
				error_count ++;
			}
			if (orglist->start + orglist->length > si->hi_addr) {
				fprintf(stderr, "Segment start above allowed high address: 0x%04lX",
				        si->hi_addr);
				fprint_orglist(stderr, si, orglist);
				error_count ++;
			}

			/* Overlap-test */
			if ((si->pi->effective_overlap != OVERLAP_IGNORE) &&
			        (orglist->segment_overlap == SEG_DONT_OVERLAP)) {
				for (orglist2 = orglist->next; orglist2 != NULL; orglist2 = orglist2->next) {
					if ((orglist != orglist2) && (orglist2->length > 0)
					        && (orglist2->segment_overlap == SEG_DONT_OVERLAP)) {

						if ((orglist->start  < (orglist2->start + orglist2->length)) &&
						        (orglist2->start < (orglist->start +  orglist->length))) {
							fprintf(stderr,"%s: Overlapping %s segments:\n",
							        si->pi->effective_overlap == OVERLAP_ERROR ? "Error" : "Warning",
							        si->name);
							fprint_orglist(stderr, si, orglist);
							fprint_orglist(stderr, si, orglist2);
							fprintf(stderr,"Please check your .ORG directives !\n");
							if (si->pi->effective_overlap == OVERLAP_ERROR)
								error_count++;
							else
								si->pi->warning_count++;
						}
					}
				}
			} /* Overlap-test */
		}
	}
	si->pi->error_count += error_count;
	return (error_count > 0 ? False : True);
}

/* Get the value of a label. Return FALSE if label was not found */
int
get_label(struct prog_info *pi,char *name,int64_t *value)
{
	struct label *label=search_symbol(pi,pi->first_label,name,NULL);
	if (label==NULL) return False;
	if (value!=NULL)	*value=label->value;
	return True;
}

int
get_constant(struct prog_info *pi,char *name,int64_t *value)
{
	struct label *label=search_symbol(pi,pi->first_constant,name,NULL);
	if (label==NULL) return False;
	if (value!=NULL)	*value=label->value;
	return True;
}

int
get_variable(struct prog_info *pi,char *name,int64_t *value)
{
	struct label *label=search_symbol(pi,pi->first_variable,name,NULL);
	if (label==NULL) return False;
	if (value!=NULL)	*value=label->value;
	return True;
}

/* Test, if label exists. Return NULL -> not defined, else return the pointer to label struct */
/* If message != NULL print error message if symbol is defined */
struct label *test_label(struct prog_info *pi,char *name,char *message)
{
	return search_symbol(pi,pi->first_label,name,message);
}

struct label *test_constant(struct prog_info *pi,char *name,char *message)
{
	return search_symbol(pi,pi->first_constant,name,message);
}

struct label *test_variable(struct prog_info *pi,char *name,char *message)
{
	return search_symbol(pi,pi->first_variable,name,message);
}

/* Search in label,constant,variable,blacklist - list for a matching entry */
/* Use first = pi->first_label,first_constant,first_variable,first_blacklist to select list */
/* If message != NULL Print error message if symbol is defined */
struct label *search_symbol(struct prog_info *pi,struct label *first,char *name,char *message)
{
	struct label *label;
	for (label = first; label; label = label->next)
		if (!nocase_strcmp(label->name, name)) {
			if (message) {
				print_msg(pi, MSGTYPE_ERROR, message, name);
			}
			return (label);
		}
	return (NULL);
}

int
ifdef_blacklist(struct prog_info *pi)
{
	struct location *loc;
	loc = malloc(sizeof(struct location));
	if (!loc) {
		print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
		return False;
	}
	loc->next = NULL;
	if (pi->last_ifdef_blacklist) {
		pi->last_ifdef_blacklist->next = loc;
	} else {
		pi->first_ifdef_blacklist = loc;
	}
	pi->last_ifdef_blacklist = loc;
	loc->line_num = pi->fi->line_number;
	loc->file_num = pi->fi->include_file->num;
	return True;
}

int
ifndef_blacklist(struct prog_info *pi)
{
	struct location *loc;
	loc = malloc(sizeof(struct location));
	if (!loc) {
		print_msg(pi, MSGTYPE_OUT_OF_MEM, NULL);
		return False;
	}
	loc->next = NULL;
	if (pi->last_ifndef_blacklist) {
		pi->last_ifndef_blacklist->next = loc;
	} else {
		pi->first_ifndef_blacklist = loc;
	}
	pi->last_ifndef_blacklist = loc;
	loc->line_num = pi->fi->line_number;
	loc->file_num = pi->fi->include_file->num;
	return True;
}

int
ifdef_is_blacklisted(struct prog_info *pi)
{
	return search_location(pi->first_ifdef_blacklist, pi->fi->line_number, pi->fi->include_file->num);
}

int
ifndef_is_blacklisted(struct prog_info *pi)
{
	return search_location(pi->first_ifndef_blacklist, pi->fi->line_number, pi->fi->include_file->num);
}

int
search_location(struct location *first, int line_num, int file_num)
{
	struct location *loc;
	for (loc = first; loc; loc = loc->next) {
		if (loc->line_num == line_num && loc->file_num == file_num) {
			return True;
		}
	}
	return False;
}

void
free_defs(struct prog_info *pi)
{
	struct def *def, *temp_def;
	for (def = pi->first_def; def;) {
		temp_def = def;
		def = def->next;
		free(temp_def->name);
		free(temp_def);
	}
	pi->first_def = NULL;
	pi->last_def = NULL;
}

void
free_labels(struct prog_info *pi)
{
	struct label *label, *temp_label;
	for (label = pi->first_label; label;) {
		temp_label = label;
		label = label->next;
		free(temp_label->name);
		free(temp_label);
	}
	pi->first_label = NULL;
	pi->last_label = NULL;
}

void
free_constants(struct prog_info *pi)
{
	struct label *label, *temp_label;
	for (label = pi->first_constant; label;) {
		temp_label = label;
		label = label->next;
		free(temp_label->name);
		free(temp_label);
	}
	pi->first_constant = NULL;
	pi->last_constant = NULL;
}

void
free_ifdef_blacklist(struct prog_info *pi)
{
	struct location *loc, *temp_loc;
	for (loc = pi->first_ifdef_blacklist; loc;) {
		temp_loc = loc;
		loc = loc->next;
		free(temp_loc);
	}
	pi->first_ifdef_blacklist = NULL;
	pi->last_ifdef_blacklist = NULL;
}

void
free_ifndef_blacklist(struct prog_info *pi)
{
	struct location *loc, *temp_loc;
	for (loc = pi->first_ifndef_blacklist; loc;) {
		temp_loc = loc;
		loc = loc->next;
		free(temp_loc);
	}
	pi->first_ifndef_blacklist = NULL;
	pi->last_ifndef_blacklist = NULL;
}

void
free_variables(struct prog_info *pi)
{
	struct label *label, *temp_label;
	for (label = pi->first_variable; label;) {
		temp_label = label;
		label = label->next;
		free(temp_label->name);
		free(temp_label);
	}
	pi->first_variable = NULL;
	pi->last_variable = NULL;
}

void
free_orglist(struct prog_info *pi)
{
	struct orglist *orglist, *temp_orglist;
	for (orglist = pi->first_orglist; orglist;) {
		temp_orglist = orglist;
		orglist = orglist->next;
		free(temp_orglist);
	}
	pi->first_orglist = NULL;
	pi->last_orglist = NULL;
}


/* avra.c */

