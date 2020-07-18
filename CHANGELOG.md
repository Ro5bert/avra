# ARVA Change log

## Release 1.4.2 (2020-07-18, by Burkhard Arenfeld, Robert Russell, and others)

- Remove bug with wrong start of DSEG for processors with SRAM start != 0x60
- Fix segment check for SRAM. End address wasn't correct calculated
- Fix wrong flash size of ATtiny20 and ATmega2560
- Fix wrong RAM size and flags of ATtiny10
- Add support for ATmega164P/PA, ATmega324P/PA, ATmega644P/PA, ATmega1284P/PA,
  ATmega8A, ATtiny261A, ATtiny461A, ATtiny861A, ATtiny4, ATtiny5, ATtiny9,
  ATmega128A, ATmega48A/P/PA, ATmega88A/P/PA, ATmega168A/P/PA, ATmega328/P/PB
- Changed width of name column for nicer printing in --devices
- Add some device definitions in include directory
- Fix ifdef and ifndef (again)
- Fix DSEG overlap detection with .BYTE directives
- Enhance regression testing system
- Remove long copyright notice from command line title

## Release 1.4.1 (2019-04-24)

- Add support for ATtiny48/88
- Improve build process for MacOs

## Release 1.4.0 (2019-02-26)

- Fix broken .ifndef logic.
- Define X, Y, Z 16-bit register pairs.
- Don't clear register alias definitions before pass 2 of the assembly.
- Improve build system.
- Improve listfile output.
- Improve overlapping code processing.
- Add support for Attiny20 with AVR8L core.
- Add support for ATMega1280 and ATMega2560.
- Improve command line processing.
- Don't generate empty COFF files.
- Improve .BYTE directive checks that it's in a proper section.
- Don't erase values of variables when entering second pass.
- Fix long name of -I option, should be --includedir.
- Handle long lines properly.
- Allow forward references to labels within macros.
- Make output filename control command line flags (-o, -e, -d) effective.
- Add automated tests.
- Add default include path defined at compile time.

## Release 1.3.0 (2010-06-28, by Jerry Jacobs)

- Added new targets, ATtiny13A, ATtiny24/A, ATtiny44/A, ATtiny84, ATtiny2313A, ATtiny4313, ATmega328P
- Added mingw32 support for building windows binairies from linux host
- Removed obsolete Dev-C++ for windows building
- Updated documentation and rewritten in asciidoc markup language
- FIXED: 1934647: Handle also # directives because include files don’t use . directives.
- FIXED: 1970530: Make whitespace character possible between function name and open bracket.
- FIXED: 1970630: Make line continuation possible with backslash as the last character of a line.
- FIXED: 2929406: Change incorrect argument --includedir to includepath.

## Release 1.2.3 (2007-11-15, bug fix by Burkhard Arenfeld)

- Fix bug 1697037 (Error with single character ';')
- Better check for line termination. Now a single CR or a FF generates an warning message. Code with bad CR
  termination could appear, if you edit CR-LF terminated files (WIN/DOS) with linux (LF only) editors.
- Fix bug 1462900 (Segfault, if error in -D parameter)
- Fix bug 1742436 (Error in .dseg size check)
- Fix bug 1742437 (Error in EEPROM presence check)
- Add patch 1604128 from Jim Galbraith (New devices ATtiny25/45/85, small fix for ATmega8 (no jmp, call instruction))
- Fix bug in handling of special tags (%HOUR% ...). A % without a special tag was replaced by previous tag value.
- Use a global timestamp for all functions which needs a time (pi->time).
- Fix bug in handling of unknown args (E.g.: avra --abc -> Segfault).
- Fix segfault if .error directive without parameter is used.
- Add a warning, if characters with code > 127 are used in .db strings and fix listing output.
- Take a look at Testcode_avra-1_2_3.asm, which demonstrate some differences between 1.2.3 and previous releases
- AVR000.zip contains some header files for different devices.
- Included avra binary was created with ubuntu 7.10 linux

## Release 1.2.2 (2007-05-11, better error checks by Burkhard Arenfeld)
- Check in print_msg() if filename is NULL. Avoid printing a NULL-Pointer.
- Warning, if no .DEVICE was found, because address range check doesn't work without it
- Error, if more than one .DEVICE was found.
- Error, if .DEVICE is after any assembled code or .ORG directive, because .DEVICE resets the address 
  counters and the assembler builds wrong code.
- Create a list of program segments (see orglist). Every .ORG, .DEVICE, .?SEG is stored, so the 
  assembler now can check for overlapping segments. Now overlapped segments in Flash, Data or EEPROM memory 
  are detected. Very usefull, if .ORG is used to build tables or bootloader code at specific addresses.
- Better check for exceeding device space in RAM, Flash or EEPROM memory. Now not the total count of
  assembled memory is used, instead every assembled address range is checked.
- .DSEG and .ESEG now generates an error, if device has no RAM / EEPROM.
- Now a warning appears, if a .DEF name is already used as constant or label. Atmel assembler generates this
  warning, too.
- Fix a small bug in the example program.

## Release 1.2.1 (2006-11-17, bug fix by Roland Riegel)

- Some of the high end AVRs use the SRAM adress range from 0x60 to 0x100 for IO extension.
  Avra so far used to start with SRAM Usage at 0x60. This is now set from case by case.

## Release 1.2.0 (2006-10-15, released by Burkhard Arenfeld)

- Patch segfault, if .error is given without parameter
- Patch segfault, if .device is given with an invalid parameter
- Check in predef_dev() if symbol is already defined. Can happens, if someone
  tries to define the symbol with the -D parameter. E.g.: `avra -D __ATMEGA8__ Test.asm`
  now generate error message, because `__ATMEGA8__` is reserved
- Add .elseif directive. It's the same like .elif. (Original Atmel assembler use .elseif
  and not .elif)
- In .db lines strings can now contain ',' and ';' characters.
- Allow forward declaration of constants (.equ) except for .ifdef and .ifndef.
  Invalid forward declarations are checked now. (In the first pass undefined Symbols in
  .ifdef and .ifndef parameters are stored in a 'blacklist' and checked in the second pass)
- Extend the .message directive for better debugging. Now it accept not only a String.
  You can use a list of expressions like in a .db directive as parameter.
- The assembler 'pass' variable moved into the pi struct. I deleted the pass variable from
  a lot of functions.
- New functions in avra.c. It was easier for me, to understand the code without the 
  for(label = first; ...)-loops. Replaced a lot of for(label = ...) -loops by one of this
  functions.

## Release 1.1.1 (2006-09-06)

- right shift operator bug
- LPM is supported on ATtiny26 but avra say it isn't
- bugfix for jmp/call opcode
- crash due to a strcmp with null pointer when parsing the cmd line args

## Release 1.1.0 (2005-12-27, released by Tobias Weber)

- .DW defines were missing in the listfile.
- Support for mega8515.
- Fix for generic register names and extended macro syntax.
- Makefile for lcc-win32 Compiler.
- Changed "global" keyword to ".global".
- Added .includepath directive that allows setting include path.
- segfault when not passing any sourcefiles.
- --define FOO=2 does not work as claimed by the documentation.
- Added return value, indicating whether avra failed or succeded.
- Added support for automake utilities. See manual for more info.
- if no code is present, eeprom hex file will be written anyway.
- added -W NoRegDef for suppressing Register assignment warnings.
- .db values were sometimes wrong printed in lst file with 6 leading F.
- Added BYTE1() function equivalent to LOW().
- The character " (pharentesis) could not be use as single character like '"'

## Release 1.0.1 (2004-06-10, released by Tobias Weber)

- Added meta tags for time and date.
- Expression of .elif was cutted off in list file - fixed.
- .equ, .org, .defines added to list file output.
- Values and expressions of .db assignemts are now listed in listfile.
- Added Support for ATmega48, ATmega88 and ATmega168.
- Added .include error file name print out.
- Fixed seg fault that could happen while using .LIST directive with no
  listfile switched on.
- Error when using comments within macros that made use of sign @ fixed.
- Listfile lines are now prefixed with the current segment C,D,E for
  code, data and eeprom.

## Release 1.0.0 (2004-02-14, released by Tobias Weber)

- Added support for ATtiny13 and ATtiny2313
- List file command line syntax now AVRASM compatible
- Map file command line syntax now  AVRASM compatible
- Fixed problem with limited macro label running numbers
- Now multiple labels can be used within macros
- Fixed error output line number for included files
- code cleaned up

## Release 0.9.1 (2003-06-02, released by Tobias Weber)

- fixed code for Linux compiler
- fixed nested macro labels
- code cleaned up

## Release 0.9 (2003-05-23, released by Tobias Weber)

- Added labels to macros
- Added special codes 'dst' and 'src'
- Added directive .endmacro, only .endm was allowed so far
- Added a return(0); at the end of main() to quiet the Borland C++ 5.5
  compiler (Jim Galbraith)
- Fixed wrong flash size calculation (Jim Galbraith)
- In device.c, added ATtiny26 to struct device device_list[] (Jim Galbraith)

## Release 0.8 (2003-03-07, released by Tobias Weber)

- Added new macro assembler coding facilities
- Added error description for .include directives

## Release 0.7 (2000-02-17)

- Added supported() function to check in a .if if a instruction is
  supported (From Lesha Bogdanow <boga@inbox.ru>).
- Added checking of which mnemonic that work on the different AVRs
  (From Lesha Bogdanow <boga@inbox.ru>).
- Added constants `__DEVICE__`, `__FLASH_SIZE__`, `__RAM_SIZE__` and
  `__EEPROM_SIZE__` (From Lesha Bogdanow <boga@inbox.ru>).
- Added tiny devices (From Lesha Bogdanow <boga@inbox.ru>).
- Changed error on constant out of range into a warning.
- Added support for instructions: (E)LPM Rd,Z(+), SPM, ESPM, BREAK,
  MOVW, MULS, MULSU, FMUL, FMULS, FMULSU
- Added support for new devices: ATmega8, ATmega16, ATmega32,
  ATmega128, ATmega162, ATmega163, ATmega323, AT94K
- Added --devices switch to list all supported devices.
- Fixed bug in map file name when the name had more than one . (dot)
- Added option --includedirs to add additional include dirs in
  search path.
- Added support for creation of intel hex 32 files to be able to
  address memory above 64KB. Uses 02 records for addresses up to 1MB
  and 04 record for addresses above 1MB.

## Release 0.6 (2000-01-24)

- Added COFF support from Bob Harris <rth@McLean.Sparta.Com>

## Release 0.5 (1999-03-31)

- Bugfix: a inline string copy did not terminate string.
- Fixed bug causing --define symbol=value not to work.
- Added output of memory usage.
- Fixed bug when there was a { in a comment.
- Fixed count for data segment.
- Fix to make a forward referenced label in .db/.dw work.
- Added ATmega161 and ATtiny15 in list.
- rjmp and rcall now wraps around with 4k word devices.
- Fixed bug when branching backwards with BRBS or BRBC
 
## Release 0.4 (1999-02-02)

- Added support for global keyword to use on labels in macros.
- Fixed get_next_token to handle commas inside ' '
- Fixed bug when searching for correct macro_call, so recursive
  and nested macros will work.
- Now handles commas in strings.
- Added fix to handle semi colon in a string.
- Improved mnemonic parsing for ld and st
