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

#ifndef _AVRA_H_
#define _AVRA_H_

#include <stdio.h>
#include <time.h>
#include <stdint.h>

#define IS_HOR_SPACE(x)	((x == ' ') || (x == 9))
#define IS_LABEL(x)	(isalnum(x) || (x == '%') || (x == '_'))
#define IS_END_OR_COMMENT(x)	((x == ';') || (x == 10) || (x == 13) || (x == '\0') || (x == 12))
#define IS_ENDLINE(x)	((x == 10) || (x == 13) || (x == '\0') || (x == 12))
#define IS_SEPARATOR(x)	((x == ' ') || (x == ',') || (x == '[') || (x == ']'))

#ifndef VERSION
#define VERSION "undefined"
#endif

#define LINEBUFFER_LENGTH 4096
#define MAX_NESTED_MACROLOOPS 256

#define MAX_MACRO_ARGS 10

/* warning switches */

/* Option enumeration */
enum {
	ARG_DEFINE = 0,		/* --define, -D            */
	ARG_INCLUDEPATH,	/* --includedir, -I        */
	ARG_LISTMAC,		/* --listmac               */
	ARG_MAX_ERRORS,		/* --max_errors            */
	ARG_COFF,		/* --coff                  */
	ARG_DEVICES,		/* --devices               */
	ARG_VER,		/* --version               */
	ARG_HELP,		/* --help, -h              */
	ARG_WRAP,		/* --wrap                  */
	ARG_WARNINGS,		/* --warn, -W              */
	ARG_FILEFORMAT,		/* --filetype              */
	ARG_LISTFILE,		/* --listfile              */
	ARG_OUTFILE,		/* --outfile   */
	ARG_MAPFILE,		/* --mapfile   */
	ARG_DEBUGFILE,		/* --debugfile */
	ARG_EEPFILE,		/* --eepfile   */
	ARG_OVERLAP,		/* -O [w|e|i]  */
	ARG_COUNT
};

enum {
	MSGTYPE_ERROR = 0,
	MSGTYPE_WARNING,
	MSGTYPE_MESSAGE,
	MSGTYPE_OUT_OF_MEM,
	MSGTYPE_MESSAGE_NO_LF, /* Like MSGTYPE_MESSAGE, but without /n */
	MSGTYPE_APPEND         /* Print Message without any header and without /n. To append messages */
};

enum {
	PASS_1 = 0,
	PASS_2
};

enum {
	SEGMENT_CODE = 0,
	SEGMENT_DATA,
	SEGMENT_EEPROM
};

enum {
	OVERLAP_UNDEFINED = -1,
	OVERLAP_DEFAULT = 0,
	OVERLAP_IGNORE,
	OVERLAP_WARNING,
	OVERLAP_ERROR
};

enum {
	SEG_DONT_OVERLAP = 0,
	SEG_ALLOW_OVERLAP
};

enum {
	TERM_END = 0,
	TERM_SPACE,
	TERM_COMMA,
	TERM_EQUAL,
	TERM_DASH,
	TERM_DOUBLEQUOTE,
	TERM_COLON
};

/* Structures */

struct prog_info;

extern const int SEG_BSS_DATA;

struct segment_info {
	const char *name;
	char ident;	  /* C, D, E */
	long addr;    /* address in cells */
	long count;   /* length in cells  */
	long lo_addr; /* lowest addr supported */
	long hi_addr; /* one past highest addr supported */
	int	cellsize; /* 1 for data/eeprom, 2 for flash  */
	int flags;	  /* SEG_BSS_DATA */

	struct prog_info *pi;
	struct hex_file_info *hfi;
	struct orglist *first_orglist;
	struct orglist *last_orglist;

	const char *cellname;  /* byte  / word  */
	const char *cellnames; /* bytes / words */
};

struct prog_info {
	struct args *args;
	struct device *device;
	struct file_info *fi;
	struct macro_call *macro_call;
	struct macro_line *macro_line;
	FILE *list_file;
	int list_on;
	int map_on;
	char *list_line;
	char *root_path;
	FILE *obj_file;
	struct segment_info *segment;
	struct segment_info *cseg;
	struct segment_info *dseg;
	struct segment_info *eseg;
	int error_count;
	int max_errors;
	int warning_count;
	struct include_file *last_include_file;
	struct include_file *first_include_file;
	struct def *first_def;
	struct def *last_def;
	struct label *first_label;
	struct label *last_label;
	struct label *first_constant;
	struct label *last_constant;
	struct label *first_variable;
	struct label *last_variable;
	struct location *first_ifdef_blacklist;
	struct location *last_ifdef_blacklist;
	struct location *first_ifndef_blacklist;
	struct location *last_ifndef_blacklist;
	struct macro *first_macro;
	struct macro *last_macro;
	struct macro_call *first_macro_call;
	struct macro_call *last_macro_call;
	struct orglist *first_orglist;	/* List of used memory segments. Needed for overlap-check */
	struct orglist *last_orglist;
	int effective_overlap; /* as specified by #pragma overlap */
	int segment_overlap;   /* set by .NOOVERLAP, .OVERLAP     */
	int conditional_depth;
	time_t time;			/* Use a global timestamp for listing header and %hour% ... tags */
	/* coff additions */
	FILE *coff_file;
	/* Warning additions */
	int NoRegDef;
	int pass;
};

struct file_info {
	FILE *fp;
	struct include_file *include_file;
	char buff[LINEBUFFER_LENGTH];
	char scratch[LINEBUFFER_LENGTH];
	int line_number;
	int exit_file;
	struct label *label;
};

struct hex_file_info {
	FILE *fp;
	int count;
	int linestart_addr;
	int segment;
	unsigned char hex_line[16];
};

struct include_file {
	struct include_file *next;
	char *name;
	int num;
};

struct def {
	struct def *next;
	char *name;
	int reg;
};

struct label {
	struct label *next;
	char *name;
	int64_t value;
};

struct macro {
	struct macro *next;
	char *name;
	struct include_file *include_file;
	int first_line_number;
	struct macro_line *first_macro_line;
	struct macro_label *first_label;
};

struct macro_label {
	char *label;
	struct macro_label *next;
	int running_number;
	int flags;
};
extern	const int ML_DEFINED;

struct macro_line {
	struct macro_line *next;
	char *line;
};

struct macro_call {
	struct macro_call *next;
	int line_number;
	struct include_file *include_file;
	struct macro_call *prev_on_stack;
	struct macro *macro;
	int line_index;
	int prev_line_index;
	int nest_level;
	struct label *first_label;
	struct label *last_label;
};

struct orglist {
	struct orglist *next;
	struct segment_info *segment;
	int start;
	int length;
	int segment_overlap;
};

struct location {
	struct location *next;
	int line_num;
	int file_num;
};

/* Prototypes */
/* avra.c */
int assemble(struct prog_info *pi);
int load_arg_defines(struct prog_info *pi);
struct prog_info *init_prog_info(struct prog_info *,struct args *args);
void free_pi(struct prog_info *pi);
void print_msg(struct prog_info *pi, int type, char *fmt, ...);
void get_rootpath(struct prog_info *pi, struct args *args);

void init_segment_size(struct prog_info *pi, struct device *device);
void rewind_segments(struct prog_info *pi);
void advance_ip(struct segment_info *si, int offset);

int def_const(struct prog_info *pi, const char *name, int64_t value);
int def_var(struct prog_info *pi, char *name, int value);
int def_orglist(struct segment_info *si);
int fix_orglist(struct segment_info *si);
void fprint_orglist(FILE *file, struct segment_info *si, struct orglist *orglist);
void fprint_sef_orglist(FILE *file, struct segment_info *si);
void fprint_segments(FILE *file, struct prog_info *pi);
int test_orglist(struct segment_info *si);
int get_label(struct prog_info *pi,char *name,int64_t *value);
int get_constant(struct prog_info *pi,char *name,int64_t *value);
int get_variable(struct prog_info *pi,char *name,int64_t *value);
struct label *test_label(struct prog_info *pi,char *name,char *message);
struct label *test_constant(struct prog_info *pi,char *name,char *message);
struct label *test_variable(struct prog_info *pi,char *name,char *message);
struct label *search_symbol(struct prog_info *pi,struct label *first,char *name,char *message);
int ifdef_blacklist(struct prog_info *pi);
int ifndef_blacklist(struct prog_info *pi);
int ifdef_is_blacklisted(struct prog_info *pi);
int ifndef_is_blacklisted(struct prog_info *pi);
int search_location(struct location *first, int line_num, int file_num);
void free_defs(struct prog_info *pi);
void free_labels(struct prog_info *pi);
void free_constants(struct prog_info *pi);
void free_ifdef_blacklist(struct prog_info *pi);
void free_ifndef_blacklist(struct prog_info *pi);
void free_variables(struct prog_info *pi);
void free_orglist(struct prog_info *pi);

/* parser.c */
int parse_file(struct prog_info *pi, const char *filename);
int parse_line(struct prog_info *pi, char *line);
char *get_next_token(char *scratch, int term);
char *fgets_new(struct prog_info *pi, char *s, int size, FILE *stream);

/* expr.c */
int get_expr(struct prog_info *pi, char *data, int64_t *value);
int get_symbol(struct prog_info *pi, char *label_name, int64_t *data);
int par_length(char *data);

/* mnemonic.c */
int parse_mnemonic(struct prog_info *pi);
int get_mnemonic_type(struct prog_info *pi);
int get_register(struct prog_info *pi, char *data);
int get_bitnum(struct prog_info *pi, char *data, int64_t *ret);
int get_indirect(struct prog_info *pi, char *operand);
int is_supported(struct prog_info *pi, char *name);
int count_supported_instructions(int flags);

/* directiv.c */
int parse_directive(struct prog_info *pi);
int lookup_keyword(const char *const keyword_list[], const char *const keyword, int strict);
char *term_string(struct prog_info *pi, char *string);
int parse_db(struct prog_info *pi, char *next);
void write_db(struct prog_info *pi, char byte, char *prev, int count);
int spool_conditional(struct prog_info *pi, int only_endif);
int check_conditional(struct prog_info *pi, char *buff, int *current_depth, int *do_next, int only_endif);
int test_include(const char *filename);

/* macro.c */
int read_macro(struct prog_info *pi, char *name);
struct macro *get_macro(struct prog_info *pi, char *name);
struct macro_label *get_macro_label(char *line, struct macro *macro);
int expand_macro(struct prog_info *pi, struct macro *macro, char *rest_line);


/* file.c */
int open_out_files(struct prog_info *pi, const char *basename, const char *outputfile,
                   const char *debugfile, const char *eepfile);
void close_out_files(struct prog_info *pi);
struct hex_file_info *open_hex_file(const char *filename);
void close_hex_file(struct hex_file_info *hfi);
void write_ee_byte(struct prog_info *pi, int address, unsigned char data);
void write_prog_word(struct prog_info *pi, int address, int data);
void do_hex_line(struct hex_file_info *hfi);
FILE *open_obj_file(struct prog_info *pi, const char *filename);
void close_obj_file(struct prog_info *pi, FILE *fp);
void write_obj_record(struct prog_info *pi, int address, int data);
void unlink_out_files(struct prog_info *pi, const char *filename);

/* map.c */
void write_map_file(struct prog_info *pi);
char *Space(char *n);

/* stdextra.c */
char *nocase_strcmp(const char *s, const char *t);
char *nocase_strncmp(char *s, char *t, int n);
char *nocase_strstr(char *s, char *t);
int atox(char *s);
int atoi_n(char *s, int n);
int atox_n(char *s, int n);
char *my_strlwr(char *in);
char *my_strupr(char *in);
char *snprint_list(char *buf, size_t limit, const char *const list[]);

/* coff.c */
FILE *open_coff_file(struct prog_info *pi, char *filename);
void write_coff_file(struct prog_info *pi);
void write_coff_eeprom(struct prog_info *pi, int address, unsigned char data);
void write_coff_program(struct prog_info *pi, int address, unsigned int data);
void close_coff_file(struct prog_info *pi, FILE *fp);
int parse_stabs(struct prog_info *pi, char *p);
int parse_stabn(struct prog_info *pi, char *p);

#endif /* end of avra.h */


