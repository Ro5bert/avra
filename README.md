# AVRA

*Assember for the Atmel AVR microcontroller family*

AVRA is an assembler for Atmel AVR microcontrollers, and it is almost
compatible with Atmel's own assembler AVRASM32. The programming
principles and conceptions are based on the ANSI programming language "C".

## Differences between AVRA and AVRASM32

There are some differences between the original Atmel assembler AVRASM32 and
AVRA. Basically AVRA is designed to replace AVRASM32 without special changes in
your current Atmel AVR Studio enviroment.  Command line options have been
adapted as far as it was possible until now. Jumping to fault containing line
directly by double-clicking on the error message in the output window does work
as with AVRASM32.

### The differences in detail

#### Support for some extra preprocessor directives.

.define, .undef, .ifdef, .ifndef, .if, .else, .endif, .elif, .elseif, .warning

#### Not all command line options are supported. 

Specifying an eeprom file (-e) is not supported. All eeprom data is
put out into a file called program.eep.hex and always Intel hex
format. Other hex file formats than Intel are currently not supported.

#### Forward references not supported for .ifdef and .ifndef directives.

This makes sure, that directives like .ifdef and .undef are working 
properly. If you are familiar with the C programming language, you
should get easily into AVRA. See chapter "Programming techniques" for
more information about how to write proper code.

#### Enhanced macro support

AVRA has some new features for writing flexible macros. This should
increase the ability to reuse code e.g. build your own library.

#### Debugging support

AVRA creates a coff file everytime the assembly was sucessful. This
file allows AVR Studio or any coff compatible debugger to simulate
or emulate the program.

#### Meta tags for assembly time

This helps you tracking versions of your software and can also be
used to generate customer specific serial numbers.

## Compatibility

Since AVRA is written in ANSI C, it should be possible to compile it on
most system platforms. If you have problems compiling AVRA, please open an
issue in the tracker.

## History

The initial version of AVRA was written by John Anders Haugum. He released
all versions until v0.7. Tobias Weber later took over, followed by Burkhard
Arenfeld (v1.2) then Jerry Jacobs (v1.3).

After a long 8 years of inactivity, I (Virgil Dupras), took over, preparing a
v1.4 release and onwards.

See AUTHORS for a complete list of contributors.

## Build

To build the `avra` executable, look at the list of makefiles available in
`src/makefiles`. Choose the appropriate one afor your platform, then from `src`,
run `make -f makefiles/Makefile.<platform>`.

You will end up with a usable `avra` executable in `src`.

## Usage

See [USAGE.md](USAGE.md).

## Change log

See [CHANGELOG.md](CHANGELOG.md).
