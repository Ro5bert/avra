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
#include <string.h>
#include <inttypes.h>
#include "avra.h"
#include "args.h"

char *Space(char *n);

void
write_map_file(struct prog_info *pi)
{
	FILE *fp;
	struct label *label;
	char Filename[200];

	if (!pi->map_on) {
		return;
	}

	strcpy(Filename, GET_ARG_P(pi->args, ARG_MAPFILE));
	fp = fopen(Filename,"w");
	if (fp == NULL) {
		fprintf(stderr,"Error: cannot create map file\n");
		return;
	}
	for (label = pi->first_constant; label; label = label->next)
		fprintf(fp,"%s%sC\t%04"PRIx64"\t%"PRId64"\n",label->name,Space(label->name),label->value,label->value);

	for (label = pi->first_variable; label; label = label->next)
		fprintf(fp,"%s%sV\t%04"PRIx64"\t%"PRId64"\n",label->name,Space(label->name),label->value,label->value);

	for (label = pi->first_label; label; label = label->next)
		fprintf(fp,"%s%sL\t%04"PRIx64"\t%"PRId64"\n",label->name,Space(label->name),label->value,label->value);

	fprintf(fp,"\n");
	fclose(fp);
	return;
}

char *
Space(char *n)
{
	int i;

	i = strlen(n);
	if (i < 1) return "\t\t\t";
	if (i < 8) return "\t\t";
	return "\t";
}

/* end of map.c */

