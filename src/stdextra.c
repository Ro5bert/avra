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
#include <ctype.h>

#include "misc.h"

/* Case insensetive strcmp() */
int
nocase_strcmp(const char *s, const char *t)
{
	int i;

	for (i = 0; tolower(s[i]) == tolower(t[i]); i++)
		if (s[i] == '\0')
			return (0);
	return (tolower(s[i]) - tolower(t[i]));
}

/* Case insensetive strncmp() */
int
nocase_strncmp(char *s, char *t, int n)
{
	int i;

	for (i = 0; (tolower(s[i]) == tolower(t[i])); i++, n--)
		if ((s[i] == '\0') || (n == 1))
			return (0);
	return (tolower(s[i]) - tolower(t[i]));
}

/* Case insensetive strstr() */
char *
nocase_strstr(char *s, char *t)
{
	int i = 0, j, found = False;

	while ((s[i] != '\0') && !found)	{
		j = 0;
		while (tolower(t[j]) == tolower(s[i + j])) {
			j++;
			if (t[j] == '\0') {
				found = True;
				break;
			} else if (s[i + j] == '\0')
				break;
		}
		i++;
	}
	i--;
	if (found)
		return (&s[i]);
	return (NULL);
}

/* Convert ascii to hex. Ignores "0x". */
int
atox(char *s)
{
	int i = 0, ret = 0;

	while (s[i] != '\0') {
		ret <<= 4;
		if ((s[i] <= 'F') && (s[i] >= 'A'))
			ret |= s[i] - 'A' + 10;
		else if ((s[i] <= 'f') && (s[i] >= 'a'))
			ret |= s[i] - 'a' + 10;
		else if ((s[i] <= '9') && (s[i] >= '0'))
			ret |= s[i] - '0';
		i++;
	}
	return (ret);
}

/* n ascii chars to int. */
int
atoi_n(char *s, int n)
{
	int i = 0, ret = 0;

	while ((s[i] != '\0') && n) {
		ret = 10 * ret + (s[i] - '0');
		i++;
		n--;
	}
	return (ret);
}

/* n ascii chars to hex, where 0 < n <= 8. Ignores "0x". */
int
atox_n(char *s, int n)
{
	int i = 0, ret = 0;

	while ((s[i] != '\0') && n) {
		ret <<= 4;
		if ((s[i] <= 'F') && (s[i] >= 'A'))
			ret |= s[i] - 'A' + 10;
		else if ((s[i] <= 'f') && (s[i] >= 'a'))
			ret |= s[i] - 'a' + 10;
		else if ((s[i] <= '9') && (s[i] >= '0'))
			ret |= s[i] - '0';
		i++;
		n--;
	}
	return (ret);
}


/* My own strlwr function since this one only exists in win. */
char *
my_strlwr(char *in)
{
	int i;

	for (i = 0; in[i] != '\0'; i++)
		in[i] = tolower(in[i]);

	return (in);
}


/* My own strupr function since this one only exists in win. */
char *
my_strupr(char *in)
{
	int i;

	for (i = 0; in[i] != '\0'; i++)
		in[i] = toupper(in[i]);

	return (in);
}

static int
snprint(char **buf, size_t *limit, const char *const str)
{
	int rc;
	rc = snprintf(*buf, *limit, "%s", str);
	if (rc <= (int)*limit)
		*buf += rc, *limit -= rc;
	else
		*limit = 0;
	return rc;
}

char *
snprint_list(char *buf, size_t limit, const char *const str_list[])
{
	int i, rc;
	char *ptr = buf;
	if (str_list[0] != NULL)
		if (str_list[1] != NULL)
			snprint(&ptr, &limit, "either ");
	for (i = 0; str_list[i] != NULL; i++) {
		if (i > 0) {
			if (str_list[i+1] == NULL)
				snprint(&ptr, &limit, " or ");
			else
				snprint(&ptr, &limit, ", ");
		}
		rc = snprintf(ptr, limit, "\"%s\"", str_list[i]);
		if (rc <= (int)limit)
			ptr += rc, limit -= rc;
		else
			limit = 0;
	}
	return buf;
}

void
test_print_list(void)
{
	static const char *const test_value[] = {
		"DEFAULT",
		"IGNORE",
		"ERROR",
		"ABCD",
		"123",
		"QQ",
		"Z",
		NULL
	};
	char buf[73] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	int i;
	for (i = 0; i < sizeof(buf); i++)
		fprintf(stderr, "(%s)\n", snprint_list(buf, i, test_value));
}
/* stdextra.c */

