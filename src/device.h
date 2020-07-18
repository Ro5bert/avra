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

/* Device flags */
#define DF_NO_MUL    0x0001 /* No {,F}MUL{,S,SU} */
#define DF_NO_JMP    0x0002 /* No JMP, CALL */
#define DF_NO_XREG   0x0004 /* No X register */
#define DF_NO_YREG   0x0008 /* No Y register */
#define DF_TINY1X    0x0010 /* AT90S1200, ATtiny11/12  set: No ADIW, SBIW,
                             * IJMP, ICALL, LDD, STD, LDS, STS, PUSH, POP */
#define DF_NO_LPM    0x0020 /* No LPM instruction */
#define DF_NO_LPM_X  0x0040 /* No LPM Rd,Z or LPM Rd,Z+ instruction */
#define DF_NO_ELPM   0x0080 /* No ELPM instruction */
#define DF_NO_ELPM_X 0x0100 /* No ELPM Rd,Z or LPM Rd,Z+ instruction */
#define DF_NO_SPM    0x0200 /* No SPM instruction */
#define DF_NO_ESPM   0x0400 /* No ESPM instruction */
#define DF_NO_MOVW   0x0800 /* No MOVW instruction */
#define DF_NO_BREAK  0x1000 /* No BREAK instruction */
#define DF_NO_EICALL 0x2000 /* No EICALL instruction */
#define DF_NO_EIJMP  0x4000 /* No EIJMP instruction */
#define DF_AVR8L     0x8000 /* Also known as AVRrc (reduced core)?
                             * ATtiny4,5,9,10,20,40,102,104: No ADIW, SBIW;
                             * one word LDS/STS */
/* If more flags are added, the size of the flag field in struct device must
 * be increased! C ints are only guaranteed to be at least 16 bits, and we're
 * currently using all of them. */

struct device {
	char *name;
	long flash_size;
	long ram_start;
	long ram_size;
	long eeprom_size;
	int flag;
};

/* device.c */
struct device *get_device(struct prog_info *pi,char *name);
int predef_dev(struct prog_info *pi);
void list_devices(void);
