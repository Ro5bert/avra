# AVRA

*Assember for the Atmel AVR microcontroller family*

AVRA is an assembler for Atmel AVR microcontrollers, and it is almost
compatible with Atmel's own assembler, AVRASM32. AVRA is written in C99.

## Differences between AVRA and AVRASM32

There are some differences between the original Atmel assembler AVRASM32 and
AVRA. Basically, AVRA is designed to replace AVRASM32 without special changes
in your current Atmel AVR Studio enviroment. Command line options have been
adapted as far as possible. Jumping to fault-containing lines directly by
double-clicking on the error message in the output window does work as with
AVRASM32.

### The differences in detail

#### Support for some extra preprocessor directives

.define, .undef, .ifdef, .ifndef, .if, .else, .endif, .elif, .elseif, .warning

#### Not all command line options are supported 

Specifying an eeprom file (-e) is not supported. All eeprom data is
put out into a file called program.eep.hex and is always in Intel hex
format. Other hex file formats are currently not supported.

#### Forward references not supported for .ifdef and .ifndef directives

This makes sure that directives like .ifdef and .undef are working as you
probably expect. If you are familiar with the C programming language, you
should get easily into AVRA.

#### Enhanced macro support

AVRA has some new features for writing flexible macros. This should
increase the ability to reuse code, e.g., build your own library.

#### Debugging support

AVRA creates a coff file everytime assembly is sucessful. This
file allows AVR Studio or any coff compatible debugger to simulate
or emulate the program.

#### Meta tags for assembly time

This helps you tracking versions of your software and can also be
used to generate customer specific serial numbers.

## Compatibility

It should be possible to compile AVRA on most system platforms.
If you have problems compiling AVRA, please open an issue in the tracker.

## History

The initial version of AVRA was written by John Anders Haugum. He released
all versions until v0.7. Tobias Weber later took over, followed by Burkhard
Arenfeld (v1.2) then Jerry Jacobs (v1.3).

After a long 8 years of inactivity, Virgil Dupras took over, preparing a
v1.4 release.

See AUTHORS for a complete list of contributors.

## Build

To build the `avra` executable, cd into the project's root directory and run
`make`. A `src/avra` binary will be produced. You can install it with `make
install`.

By default, make runs under the `linux` OS, which assumes a typical GNU
toolchain. If that doesn't work for you, look at the available platforms
available in `src/makefiles` and override `OS` when you call `make`. Note that
those platforms aren't all well tested. Please open an issue in the tracker if
you notice a platform not working.

To compile in Windows with MS Visual Studio 2019, you will need additional
files. Please see
[here](https://gist.github.com/hack-tramp/b19b7675670bb5463bb763c602b5bc05).

## Usage

See [USAGE.md](USAGE.md).

## Change log

See [CHANGELOG.md](CHANGELOG.md).
