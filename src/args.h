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

#ifndef _args_h_
#define _args_h_

enum {
	ARGTYPE_BOOLEAN = 0,       /* boolean Value (0 = False) */
	ARGTYPE_STRING,            /* Stringpointer in Data     */
	ARGTYPE_STRING_MULTI,      /* List of strings in Data   */
	ARGTYPE_STRING_MULTISINGLE, /* List of strings in Data. requires an option for each element */
	ARGTYPE_CHAR_ATTACHED,
	ARGTYPE_CHOICE,
	ARGTYPE_NUMERIC
};

#define GET_ARG_I(args, argnum) (args->arg[argnum].data.i)
#define SET_ARG_I(args, argnum, value) (args->arg[argnum].data.i = (value))
#define GET_ARG_P(args, argnum) (args->arg[argnum].data.p)
#define SET_ARG_P(args, argnum, value) (args->arg[argnum].data.p = (value))
#define GET_ARG_LIST(args, argnum) (args->arg[argnum].data.dl)
#define SET_ARG_LIST(args, argnum, value) (args->arg[argnum].data.dl = (value))

struct args {
	struct arg *arg;
	int    count;
	struct data_list *first_data;
};

struct dataset {
	int   dset_value;
	const char *const dset_name;
};

struct arg {
	int   type;
	char  letter;
	char *longarg;
	union {
		int i;
		const char *p;
		struct data_list *dl;
	} data;
	const struct dataset *dataset;
};

struct data_list {
	struct data_list *next;
	const char *data;
};

struct args *alloc_args(int arg_count);
int read_args(struct args *args, int argc, const char *argv[]);
int add_arg(struct data_list **last_data, const char *argv);
void free_args(struct args *args);
void define_arg(struct args *args, int index, int type, char letter, char *longarg, const char *def_value, const struct dataset dataset[]);
void define_arg_int(struct args *args, int index, int type, char letter, char *longarg, int def_value, const struct dataset dataset[]);

#endif /* end of args.h */

