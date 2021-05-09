# AVRA Usage

To compile a source file, run `avra mysource.S`. You will end up with a
compiled version of the file in Intel HEX format at `mysource.S.hex`. You can
control the output filename with `-o`. See `--help` for more options (not all
options work).

## Warning Supression

There is a possibility to supress certain warnings. 
Currently only register reassignment warnings can be supressed:

	avra -W NoRegDef

## Using Directives

AVRA offers a number of directives that are not part of Atmel's assembler.
These directives should help you in creating versatile and more modular code.

### Directive `.define`

To define a constant, use `.define`. This does the same thing as `.equ`;
it is just a little more C style. Keep in mind that AVRA is not case
sensitive. The `.define` directive is not to be confused with `.def`, which is
used to assign registers only. This is due to backward compatibility with
Atmel's AVRASM32. Here is an example on how `.define` can be used:

    .define network 1

Now `network` is set to the value 1. You can also define names without values:

	.define network

Both versions are equivalent, as AVRA will implicitly define `network` to be 1
in the second case. (Although, if you really want `network` to be 1, you
should use the first version.) You may want to assemble a specific part of your
code depeding on a define or switch setting. You can test your defined word on
existence (`.ifdef` and `.ifndef`) as well as on the value it represents. The
following code shows a way to prevent error messages due to testing undefined
constants:

    .ifndef network
    .define network 0
    .endif

### Directives `.if` and `.else`

The three lines in the last example set the default value of `network`.
Now we could use the `.if` and `.else` directives test whether, e.g., network
support is to be included into the assembly process:

    .if network == 1
    .include "include\tcpip.asm"
    .else
    .include "include\dummynet.asm"
    .endif

There is also an `.elif` ("else if") directive, which does what you think.

### Directive `.error`

The `.error` directive can be used to throw an error during the assembly
process. The following example shows how we can stop the assembler if a
particular value has not been previously set:

    .ifndef network
    .error "network is not configured!" ; the assembler stops here
	.endif

### Directives `.nolist` and `.list`

The ouput to the list file can be paused and resumed by the `.nolist` and
`.list` directives.  After AVRA discovers a `.nolist` while assembling, it
stops output to the list file. After a `.list` directive is detected, AVRA
continues the normal list file output.

### Directive `.includepath`

By default, any file that is included from within the source file must
either be a single filename or an absolute path. With the directive
`.includepath` you can set an additional include path. Furthermore, you can 
set as many include paths as you want. To avoid ambiguity, be sure not to use
the same filename in separate included directories.

## Using Include Files

To avoid multiple inclusion of include files, you can use some directives, as
shown in the following example:

    .ifndef _MYFILE_ASM_ ; Avoid multiple inclusion of myfile.asm
    .define _MYFILE_ASM_
  
    ; Anything here will only be included once.

    .endif

## Using Build Date Meta Tags

You can use some special tags that AVRA supports to implement compiler build
time and date into your program:
    
    %MINUTE%  is replaced by the current minute (00-59)
    %HOUR%    is replaced by the current hour (00-23)
    %DAY%     is replaced by the current day of month (01-31)
    %MONTH%   is replaced by the current month (01-12)
    %YEAR%    is replaced by the current year (2004-9999)

For example, these tags can be used as follows:

    buildtime: .db "Release date %DAY%.%MONTH%.%YEAR% %HOUR%:%MINUTE%"
    
This line will then be assembled by AVRA into:
    
    buildtime: .db "Release date 10.05.2004 19:54"
   
As another example, you can create an automatically-updating serial number with
meta tags:
    
    .define serialnumber %DAY% + %MONTH%*31 + (%YEAR% - 2000) *31*12

The `%TAG%` is translated before any other parsing happens. The real output can
be found in the list file.

## Macro Features

Sometimes you have to work with 16 bit or greater variables stored
in 8 bit registers. AVRA provides enhanced macro support that allows you to
write short and flexible macros that simplify access to big variables. The
enhanced macro features are active when you use square brackets [ ] to wrap
macro parameters. See the following examples.

### Automatic Type Conversion For Macros

Values representing more than 8 bits are usualy kept in a set of byte wide
registers. To simplify 16 bit operations, words can be written as `r16:r17`. In
this example, `r16` contains the most significant byte and register `r17`
contains the least significant byte. In the same way, a 24 bit value stored
across 3 registers can be written as `r16:r17:r18`, for example (in this case,
`r16` is the most significant and `r18` is the least significant). In fact, up
to 8 registers can be used with this syntax.

### Macro Data Types

There are 3 data types that can be used in macro definitions. The data types
are specified by appending one of the following codes that start with an
underscore to the end of a macro name:

	immediate values  _i
	registers         _8,_16,_24,_32,_40,_48,_56,_64
	void parameter    _v

See the following section for examples on how these types work.

Within square brackets, the two words `src` and `dst` are interpreted as
`YH:YL` and `ZH:ZL`, respectively. Normal code outside of the macro parameter
square brackets can still make use of the special key words `src` and `dst`
without any side effects.

### Examples For Automatic Type Conversion and Macro Overloading

To simplify the examples below, we redefine some registers:

	.def a = r16  ; general purpose registers
	.def b = r17
	.def c = r18
	.def d = r19

	.def w = r20  ; working registers
	.def v = r21

If we substract the 16 bit value `c:d` from `a:b`, we usually have to use the
following command sequence:

	sub b,d
	sbc a,c

Now we can use macros to simplify subtraction with 16 bit values:

	.macro subs
		.message "no parameters specified"
	.endm

	.macro subs_16_16
		sub @1,@3
		sbc @0,@2 
	.endm

	.macro subs_16_8
		sub  @1,@2
		sbci @0,0
	.endm

	; Now we can write a 16 bit minus 16 bit subtraction as:

	subs [a:b,c:d]

	; Or, for a 16 bit minus 8 bit subtraction:

	subs [a:b,c]

Note that we have essentially overloaded the `subs` macro to accept arguments
of different types.
Another example of macro overloading follows.

	.macro load
		; This message is shown if you use the macro within your code
		; specifying no parameters. If your macro allows the case where
		; no parameters are given, exchange .message with your code.
		.message "no parameters specified"
	.endm

	; Here we define the macro "load" for the case it is being used
	; with two registers as first parameter and an immediate (constant)
	; value as second parameter:

	.macro load_16_i
		ldi @0,high(@2)
		ldi @1,low(@2)
	.endm

	; The same case, but now with a 32 bit register value as first
	; parameter:

	.macro load_32_i
		ldi @0,BYTE4(@4)
		ldi @1,BYTE3(@4)
		ldi @2,high(@4)
		ldi @3,low(@4)
	.endm

	; Now these macros can be invoked as follows:

	load [a:b,15]     ; Uses macro load_16_i to load immediate.

	load [a:b:c:d,15] ; Uses macro load_32_i to load immediate.


### More Examples

       .dseg
       counter: .byte 2

       .cseg

       .macro   poke
       .message "no parameters"
       .endm

       .macro   poke_i_16_i
       ldi      @1,high(@3)
       sts      @0+0,@1
       ldi      @2,low(@3)
       sts      @0+1,@2
       .endm

       .macro   poke_i_i
       ldi      w,@1
       sts      @0+0,w
       .endm

       .macro   poke_i_v_i
       ldi      w,high(@3)
       sts      @0+0,w
       ldi      w,low(@3)
       sts      @0+1,w
       .endm

       .macro   poke_i_v_v_v_i
       ldi      w,high(@3)
       sts      @0+0,w
       ldi      w,low(@3)
       sts      @0+1,w
       ldi      w,BYTE3(@3)
       sts      @0+2,w
       ldi      w,BYTE4(@3)
       sts      @0+3,w
       .endm


       ; This writes 9999 into the memory at 'counter' using only the working
	   ; register for transfering the values.

       poke [counter,w:w,9999]

       ; This works the same as above, but the transferred value 9999 is also
       ; kept in the pair of registers a:b.

       poke [counter,a:b,9999]

       ; In this design 'w' is always a working register, which implies that
       ; it cannot be used for normal variables. The following example
       ; uses poke_i_i because the parameter contains two immediate values.

       poke [counter,9999] ;uses poke_i_i

       ; To be able to choose between a 8, 16, or 32 bit operation, you just
       ; add a void parameter.

       poke [counter,,9999] ;uses poke_i_v_i

       ; And the same for 32 bit pokes:

       poke [counter,,,,9999] ;uses poke_i_v_v_v_i

### Loops Within Macros

One problem you may have experienced is that labels defined within macros
are defined twice, for example, if you call the macro two times. You can use
labels for macro loops by appending "_%" to the label. The "%" symbol is
replaced by a running number.

#### Loop Example

	; Definition of the macro

	.macro write_8_8
	write_%:
		st   Z+,@0
		dec  @1
		brne write_%
	.endm

	; Use in user code

	write [a,b]
	write [c,d]

	; After assembling this code, the result looks like this:

	write_1:
		st   Z+,a
		dec  b
		brne write_1
	write_2:
		st   Z+,c
		dec  d
		brne write_2

## Warnings and Errors

Here are some frequently asked questions about common errors.

### Constant Out of Range

This warning occurs if a value exceeds the byte or word value of a assignment.
Read the comment posted by Jim Galbraith:

The expression (~0x80) is a Bitwise Not operation.  This operator returns the
input expression with all its bits inverted.  If 0x80 represents -128, then
0x7f, or +127 should be ok.  If this is considered as a 32-bit expression (AVRA
internal representation), then it appears to be more like oxffffffff-0x80 or
0xffffffff^0x80.  The result would then be 0xffffff7f.  The assembler would
then have to be told or it would have to decide, based on context, how much
significance to assign to the higher bits.  I have also encountered such
conditions with various assemblers, including AVRA.  To make sure the assembler
does what I really want, I use a construct like 0xff-0x80 or 0xff^0x80.  This
way the bit significance cannot extend beyond bit-7 and there cannot be any
misunderstanding.   

### Can't Use `.DB` Directive in Data Segment

The `.DB` and `.DW` directives are only used to assign constant data in the
eeprom or code space. Using these directives within the data segment is
forbidden because you cannot set ram content at assembly time. You can only
allocate memory for your variables using labels and the `.byte` directive:

    .dseg
    my_string: .byte 15

### The `.byte` Directive

The `.byte` directive can only be used in data segment (`.dseg`).

This directive cannot be used in the code or eeprom regions because this only
allocates memory without assigning specific values to it. Instead, use `.db`
or `.dw` for data in the code or eeprom segments.

### Internal Assembler Error

If you get an "internal assembler error" please contact the project maintainer
via the [GitHub issue tracker](https://github.com/Ro5bert/avra/issues). Be sure
to include a code example and a description of your working enviroment.

