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

#include "misc.h"
#include "args.h"


struct args *alloc_args(int arg_count)
{
	struct args *args;

	args = malloc(sizeof(struct args));
	if (args) {
		args->arg = malloc(sizeof(struct arg) * arg_count);
		if (args->arg) {
			args->count = arg_count;
			args->first_data = NULL;
			return (args);
		}
		free(args);
	}
	printf("Error: Unable to allocate memory\n");
	return (NULL);
}

const struct dataset *
match_dataset(const struct dataset datasets[], const char *key)
{
	const struct dataset *ds;
	for (ds = datasets;
	        ds->dset_name != NULL; ds++) {
		if (strncmp(key, ds->dset_name,
		            strlen(ds->dset_name)) == 0) {
			return ds;
		}
	}
	return NULL;
}

void
print_dataset(const struct dataset datasets[])
{
	const struct dataset *ds;
	printf("either ");
	for (ds = datasets;
	        ds->dset_name != NULL; ds++) {
		if (ds != datasets) {
			if (ds[1].dset_name == NULL)
				printf(" or ");
			else
				printf(", ");
		}
		printf("\"%s\"", ds->dset_name);
	}
	printf(".\n");
}

int
process_optvalue(const char *optname, struct arg *cur, const char *optval)
{
	int ok = True;
	long numeric;
	char *endptr;
	const struct dataset *ds;
	switch (cur->type) {
	case ARGTYPE_NUMERIC:
		if ((numeric = strtol(optval, &endptr, 10)) == 0) {
			if (endptr == optval) {
				printf("Error: %s needs a numeric argument (given %s)\n", optname, optval);
				ok = False;
				break;
			}
			cur->data.i = (int)numeric;
		}
		break;
	case ARGTYPE_STRING:
		cur->data.p = optval;
		break;
	case ARGTYPE_STRING_MULTISINGLE:
		ok = add_arg(&cur->data.dl, optval);
		break;
	case ARGTYPE_CHOICE:
		ds = match_dataset(cur->dataset, optval);
		if (ds) {
			cur->data.i = ds->dset_value;
		} else {
			printf("Error: Illegal value for %s: %s, should be ", optname, optval);
			print_dataset(cur->dataset);
			ok = False;
		}
	}
	return ok;
}

int
read_args(struct args *args, int argc, const char *argv[])
{
	int i, j, k, ok, i_old;
	struct data_list **last_data;

	ok = True;
	args->first_data = NULL;

	last_data = &args->first_data;

	for (i = 1; (i < argc) && ok; i++) {
		if (argv[i][0] == '-') {
			last_data = &args->first_data;
			if (argv[i][1] == 0) {
				printf("Error: Unknown option: -\n");
				ok = False;
			} else if (argv[i][1] == '-') {
				j = 0;
				while ((j != args->count) && strcmp(&argv[i][2], args->arg[j].longarg)) {
					j++;
				}
				if (j == args->count) {
					printf("Error: Unknown option: %s\n", argv[i]);
					ok = False;
				} else {
					switch (args->arg[j].type) {
					case ARGTYPE_STRING:
					case ARGTYPE_STRING_MULTISINGLE:
					case ARGTYPE_NUMERIC:
					case ARGTYPE_CHOICE:
						/* if argument is a string parameter we will do this: */
						if ((i + 1) == argc) {
							printf("Error: No argument supplied with option: %s\n", argv[i]);
							ok = False;
						} else {
							ok = process_optvalue(argv[i], &args->arg[j], argv[i+1]);
							i++;
						}
						break;
					case ARGTYPE_BOOLEAN:
						args->arg[j].data.i = True;
						break;
					case ARGTYPE_STRING_MULTI:
						last_data = &args->arg[j].data.dl;
						break;
					}
				}
			} else {
				for (k = 1, i_old = i; (argv[i][k] != '\0') && ok && (i == i_old); k++) {
					j = 0;
					while ((j != args->count) && (argv[i][k] != args->arg[j].letter))
						j++;
					if (j == args->count) {
						printf("Error: Unknown option: -%c\n", argv[i][k]);
						ok = False;
					} else {
						switch (args->arg[j].type) {
						case ARGTYPE_STRING:
						case ARGTYPE_STRING_MULTISINGLE:
						case ARGTYPE_NUMERIC:
						case ARGTYPE_CHOICE:
							if (argv[i][k + 1] != '\0') {
								printf("Error: Option -%c must be followed by it's argument\n", argv[i][k]);
								ok = False;
							} else {
								if ((i + 1) == argc) {
									printf("Error: No argument supplied with option: -%c\n", argv[i][k]);
									ok = False;
								} else
									ok = process_optvalue(argv[i], &args->arg[j], argv[i+1]);
								i++;
							}
							break;
						case ARGTYPE_BOOLEAN:
							args->arg[j].data.i = True;
							break;
						case ARGTYPE_STRING_MULTI:
							last_data = &args->arg[j].data.dl;
							break;
						/* Parameters that have only one char attached */
						case ARGTYPE_CHAR_ATTACHED:
							if ((i + 1) == argc) {
								printf("Error: missing arguments: asm file");
								ok = False;
							} else {
								switch (argv[i][++k]) {
								case 'O':
									args->arg[j].data.i = AVRSTUDIO;
									break;
								case 'G':
									args->arg[j].data.i = GENERIC;
									break;
								case 'I':
									args->arg[j].data.i = INTEL;
									break;
								case 'M':
									args->arg[j].data.i = MOTOROLA;
									break;
								default:
									printf("Error: wrong file type '%c'",argv[i][2]);
									ok = False;
								}
							}
						}
					}
				}
			}
		} else
			ok = add_arg(last_data, argv[i]);
	}
	return (ok);
}


int
add_arg(struct data_list **last_data, const char *argv)
{
	struct data_list *data;

	while (*last_data)
		last_data = &((*last_data)->next);

	data = malloc(sizeof(struct data_list));
	if (data) {
		data->next = NULL;
		data->data = argv;
		*last_data = data;
		last_data = &data->next;
	} else {
		printf("Error: Unable to allocate memory\n");
		return (False);
	}
	return (True);
}


void
free_args(struct args *args)
{
	int i;
	struct data_list *data, *temp;

	for (data = args->first_data; data;) {
		temp = data;
		data = data->next;
		free(temp);
	}
	for (i = 0; i != args->count; i++)
		if ((args->arg[i].type == ARGTYPE_STRING_MULTI)
		        || (args->arg[i].type == ARGTYPE_STRING_MULTISINGLE))
			for (data = args->arg[i].data.dl; data;) {
				temp = data;
				data = data->next;
				free(temp);
			}
	free(args);
}


void
define_arg(struct args *args, int index, int type, char letter, char *longarg, const char *def_value, const struct dataset dataset[])
{
	args->arg[index].type = type;
	args->arg[index].letter = letter;
	args->arg[index].longarg = longarg;
	args->arg[index].data.p = def_value;
	args->arg[index].dataset = dataset;
}

void
define_arg_int(struct args *args, int index, int type, char letter, char *longarg, int def_value, const struct dataset dataset[])
{
	args->arg[index].type = type;
	args->arg[index].letter = letter;
	args->arg[index].longarg = longarg;
	args->arg[index].data.i = def_value;
	args->arg[index].dataset = dataset;
}

/* end of args.c */
