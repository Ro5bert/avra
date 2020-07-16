/***********************************************************************
 *
 *  avra - Assembler for the Atmel AVR microcontroller series
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
 *  Authors of avra can be reached at:
 *     email: jonah@omegav.ntnu.no, tobiw@suprafluid.com
 *     www: https://github.com/Ro5bert/avra
 */

/* Device flags */
#define DF_NO_MUL    0x00000001
#define DF_NO_JMP    0x00000002	// No JMP, CALL
#define DF_NO_XREG   0x00000004	// No X register
#define DF_NO_YREG   0x00000008	// No Y register
#define DF_TINY1X    0x00000010	/* AT90S1200, ATtiny10-12  set: No ADIW, SBIW,
				   IJMP, ICALL, LDD, STD, LDS, STS, PUSH, POP */
#define DF_NO_LPM    0x00000020	// No LPM instruction
#define DF_NO_LPM_X  0x00000040 // No LPM Rd,Z or LPM Rd,Z+ instruction
#define DF_NO_ELPM   0x00000080	// No ELPM instruction
#define DF_NO_ELPM_X 0x00000100 // No ELPM Rd,Z or LPM Rd,Z+ instruction
#define DF_NO_SPM    0x00000200 // No SPM instruction
#define DF_NO_ESPM   0x00000400 // No ESPM instruction
#define DF_NO_MOVW   0x00000800 // No MOVW instruction
#define DF_NO_BREAK  0x00001000 // No BREAK instruction
#define DF_NO_EICALL 0x00002000 // No EICALL instruction
#define DF_NO_EIJMP  0x00004000 // No EIJMP instruction
#define DF_AVR8L     0x00008000	/* ATtiny10, 20, 40 set No ADIW, SBIW, one word LDS/STS */

struct device {
	char *name;
	int flash_size;
	int ram_start;
	int ram_size;
	int eeprom_size;
	int flag;
};

/* device.c */
struct device *get_device(struct prog_info *pi,char *name);
int predef_dev(struct prog_info *pi);
void list_devices(void);
