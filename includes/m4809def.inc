;***** THIS IS A MACHINE GENERATED FILE - DO NOT EDIT ********************

;*************************************************************************
;* A P P L I C A T I O N   N O T E   F O R   T H E   A V R   F A M I L Y
;*
;* Number            : AVR000
;* File Name         : m4809def.inc
;* Title             : Register/Bit Definitions for the ATmega4809
;* Created           : 2021-07-13 10:39
;* Version           : 1.00
;* Support e-mail    : avr@atmel.com
;* Target MCU        : ATmega4809
;*
;* DESCRIPTION
;* When including this file in the assembly program file, all I/O register
;* names and I/O register bit names appearing in the data book can be used.
;* In addition, the six registers forming the three data pointers X, Y and
;* Z have been assigned names XL - ZH. Highest RAM address for Internal
;* SRAM is also defined
;*
;*************************************************************************

#ifndef _M4809DEF_INC_
#define _M4809DEF_INC_


#pragma partinc 0

; ***** SPECIFY DEVICE ***************************************************
.device	ATmega4809

#pragma AVRPART ADMIN PART_NAME ATmega4809

.equ	SIGNATURE_000	= 0x1E
.equ	SIGNATURE_001	= 0x96
.equ	SIGNATURE_002	= 0x51

#pragma AVRPART CORE CORE_VERSION V4


; ***** ABSOLUTE I/O REGISTER LOCATIONS **********************************


;*************************************************************************
;** AC0 - Analog Comparator
;*************************************************************************

.equ AC0_CTRLA = 0x0680                  ; Control A
.equ AC0_MUXCTRLA = 0x0682               ; Mux Control A
.equ AC0_DACREF = 0x0684                 ; Referance scale control
.equ AC0_INTCTRL = 0x0686                ; Interrupt Control
.equ AC0_STATUS = 0x0687                 ; Status

;*************************************************************************
;** ADC0 - Analog to Digital Converter
;*************************************************************************

.equ ADC0_CTRLA = 0x0600                 ; Control A
.equ ADC0_CTRLB = 0x0601                 ; Control B
.equ ADC0_CTRLC = 0x0602                 ; Control C
.equ ADC0_CTRLD = 0x0603                 ; Control D
.equ ADC0_CTRLE = 0x0604                 ; Control E
.equ ADC0_SAMPCTRL = 0x0605              ; Sample Control
.equ ADC0_MUXPOS = 0x0606                ; Positive mux input
.equ ADC0_COMMAND = 0x0608               ; Command
.equ ADC0_EVCTRL = 0x0609                ; Event Control
.equ ADC0_INTCTRL = 0x060A               ; Interrupt Control
.equ ADC0_INTFLAGS = 0x060B              ; Interrupt Flags
.equ ADC0_DBGCTRL = 0x060C               ; Debug Control
.equ ADC0_TEMP = 0x060D                  ; Temporary Data
.equ ADC0_RES = 0x0610                   ; ADC Accumulator Result
.equ ADC0_RESL = 0x0610                  ; ADC Accumulator Result low byte
.equ ADC0_RESH = 0x0611                  ; ADC Accumulator Result hi byte
.equ ADC0_WINLT = 0x0612                 ; Window comparator low threshold
.equ ADC0_WINLTL = 0x0612                ; Window comparator low threshold low byte
.equ ADC0_WINLTH = 0x0613                ; Window comparator low threshold hi byte
.equ ADC0_WINHT = 0x0614                 ; Window comparator high threshold
.equ ADC0_WINHTL = 0x0614                ; Window comparator high threshold low byte
.equ ADC0_WINHTH = 0x0615                ; Window comparator high threshold hi byte
.equ ADC0_CALIB = 0x0616                 ; Calibration

;*************************************************************************
;** BOD - Bod interface
;*************************************************************************

.equ BOD_CTRLA = 0x0080                  ; Control A
.equ BOD_CTRLB = 0x0081                  ; Control B
.equ BOD_VLMCTRLA = 0x0088               ; Voltage level monitor Control
.equ BOD_INTCTRL = 0x0089                ; Voltage level monitor interrupt Control
.equ BOD_INTFLAGS = 0x008A               ; Voltage level monitor interrupt Flags
.equ BOD_STATUS = 0x008B                 ; Voltage level monitor status

;*************************************************************************
;** CCL - Configurable Custom Logic
;*************************************************************************

.equ CCL_CTRLA = 0x01C0                  ; Control Register A
.equ CCL_SEQCTRL0 = 0x01C1               ; Sequential Control 0
.equ CCL_SEQCTRL1 = 0x01C2               ; Sequential Control 1
.equ CCL_INTCTRL0 = 0x01C5               ; Interrupt Control 0
.equ CCL_INTFLAGS = 0x01C7               ; Interrupt Flags
.equ CCL_LUT0CTRLA = 0x01C8              ; LUT Control 0 A
.equ CCL_LUT0CTRLB = 0x01C9              ; LUT Control 0 B
.equ CCL_LUT0CTRLC = 0x01CA              ; LUT Control 0 C
.equ CCL_TRUTH0 = 0x01CB                 ; Truth 0
.equ CCL_LUT1CTRLA = 0x01CC              ; LUT Control 1 A
.equ CCL_LUT1CTRLB = 0x01CD              ; LUT Control 1 B
.equ CCL_LUT1CTRLC = 0x01CE              ; LUT Control 1 C
.equ CCL_TRUTH1 = 0x01CF                 ; Truth 1
.equ CCL_LUT2CTRLA = 0x01D0              ; LUT Control 2 A
.equ CCL_LUT2CTRLB = 0x01D1              ; LUT Control 2 B
.equ CCL_LUT2CTRLC = 0x01D2              ; LUT Control 2 C
.equ CCL_TRUTH2 = 0x01D3                 ; Truth 2
.equ CCL_LUT3CTRLA = 0x01D4              ; LUT Control 3 A
.equ CCL_LUT3CTRLB = 0x01D5              ; LUT Control 3 B
.equ CCL_LUT3CTRLC = 0x01D6              ; LUT Control 3 C
.equ CCL_TRUTH3 = 0x01D7                 ; Truth 3

;*************************************************************************
;** CLKCTRL - Clock controller
;*************************************************************************

.equ CLKCTRL_MCLKCTRLA = 0x0060          ; MCLK Control A
.equ CLKCTRL_MCLKCTRLB = 0x0061          ; MCLK Control B
.equ CLKCTRL_MCLKLOCK = 0x0062           ; MCLK Lock
.equ CLKCTRL_MCLKSTATUS = 0x0063         ; MCLK Status
.equ CLKCTRL_OSC20MCTRLA = 0x0070        ; OSC20M Control A
.equ CLKCTRL_OSC20MCALIBA = 0x0071       ; OSC20M Calibration A
.equ CLKCTRL_OSC20MCALIBB = 0x0072       ; OSC20M Calibration B
.equ CLKCTRL_OSC32KCTRLA = 0x0078        ; OSC32K Control A
.equ CLKCTRL_XOSC32KCTRLA = 0x007C       ; XOSC32K Control A

;*************************************************************************
;** CPU - CPU
;*************************************************************************

.equ CPU_CCP = 0x0034                    ; Configuration Change Protection
.equ CPU_SPL = 0x003D                    ; Stack Pointer Low
.equ CPU_SPH = 0x003E                    ; Stack Pointer High
.equ CPU_SREG = 0x003F                   ; Status Register

;*************************************************************************
;** CPUINT - Interrupt Controller
;*************************************************************************

.equ CPUINT_CTRLA = 0x0110               ; Control A
.equ CPUINT_STATUS = 0x0111              ; Status
.equ CPUINT_LVL0PRI = 0x0112             ; Interrupt Level 0 Priority
.equ CPUINT_LVL1VEC = 0x0113             ; Interrupt Level 1 Priority Vector

;*************************************************************************
;** CRCSCAN - CRCSCAN
;*************************************************************************

.equ CRCSCAN_CTRLA = 0x0120              ; Control A
.equ CRCSCAN_CTRLB = 0x0121              ; Control B
.equ CRCSCAN_STATUS = 0x0122             ; Status

;*************************************************************************
;** EVSYS - Event System
;*************************************************************************

.equ EVSYS_STROBE = 0x0180               ; Channel Strobe
.equ EVSYS_CHANNEL0 = 0x0190             ; Multiplexer Channel 0
.equ EVSYS_CHANNEL1 = 0x0191             ; Multiplexer Channel 1
.equ EVSYS_CHANNEL2 = 0x0192             ; Multiplexer Channel 2
.equ EVSYS_CHANNEL3 = 0x0193             ; Multiplexer Channel 3
.equ EVSYS_CHANNEL4 = 0x0194             ; Multiplexer Channel 4
.equ EVSYS_CHANNEL5 = 0x0195             ; Multiplexer Channel 5
.equ EVSYS_CHANNEL6 = 0x0196             ; Multiplexer Channel 6
.equ EVSYS_CHANNEL7 = 0x0197             ; Multiplexer Channel 7
.equ EVSYS_USERCCLLUT0A = 0x01A0         ; User CCL LUT0 Event A
.equ EVSYS_USERCCLLUT0B = 0x01A1         ; User CCL LUT0 Event B
.equ EVSYS_USERCCLLUT1A = 0x01A2         ; User CCL LUT1 Event A
.equ EVSYS_USERCCLLUT1B = 0x01A3         ; User CCL LUT1 Event B
.equ EVSYS_USERCCLLUT2A = 0x01A4         ; User CCL LUT2 Event A
.equ EVSYS_USERCCLLUT2B = 0x01A5         ; User CCL LUT2 Event B
.equ EVSYS_USERCCLLUT3A = 0x01A6         ; User CCL LUT3 Event A
.equ EVSYS_USERCCLLUT3B = 0x01A7         ; User CCL LUT3 Event B
.equ EVSYS_USERADC0 = 0x01A8             ; User ADC0
.equ EVSYS_USEREVOUTA = 0x01A9           ; User EVOUT Port A
.equ EVSYS_USEREVOUTB = 0x01AA           ; User EVOUT Port B
.equ EVSYS_USEREVOUTC = 0x01AB           ; User EVOUT Port C
.equ EVSYS_USEREVOUTD = 0x01AC           ; User EVOUT Port D
.equ EVSYS_USEREVOUTE = 0x01AD           ; User EVOUT Port E
.equ EVSYS_USEREVOUTF = 0x01AE           ; User EVOUT Port F
.equ EVSYS_USERUSART0 = 0x01AF           ; User USART0
.equ EVSYS_USERUSART1 = 0x01B0           ; User USART1
.equ EVSYS_USERUSART2 = 0x01B1           ; User USART2
.equ EVSYS_USERUSART3 = 0x01B2           ; User USART3
.equ EVSYS_USERTCA0 = 0x01B3             ; User TCA0
.equ EVSYS_USERTCB0 = 0x01B4             ; User TCB0
.equ EVSYS_USERTCB1 = 0x01B5             ; User TCB1
.equ EVSYS_USERTCB2 = 0x01B6             ; User TCB2
.equ EVSYS_USERTCB3 = 0x01B7             ; User TCB3

;*************************************************************************
;** FUSE - Fuses
;*************************************************************************

.equ FUSE_WDTCFG = 0x1280                ; Watchdog Configuration
.equ FUSE_BODCFG = 0x1281                ; BOD Configuration
.equ FUSE_OSCCFG = 0x1282                ; Oscillator Configuration
.equ FUSE_SYSCFG0 = 0x1285               ; System Configuration 0
.equ FUSE_SYSCFG1 = 0x1286               ; System Configuration 1
.equ FUSE_APPEND = 0x1287                ; Application Code Section End
.equ FUSE_BOOTEND = 0x1288               ; Boot Section End

;*************************************************************************
;** GPIO - General Purpose IO
;*************************************************************************

.equ GPIO_GPIOR0 = 0x001C                ; General Purpose IO Register 0
.equ GPIO_GPIOR1 = 0x001D                ; General Purpose IO Register 1
.equ GPIO_GPIOR2 = 0x001E                ; General Purpose IO Register 2
.equ GPIO_GPIOR3 = 0x001F                ; General Purpose IO Register 3

;*************************************************************************
;** LOCKBIT - Lockbit
;*************************************************************************

.equ LOCKBIT_LOCKBIT = 0x128A            ; Lock Bits

;*************************************************************************
;** NVMCTRL - Non-volatile Memory Controller
;*************************************************************************

.equ NVMCTRL_CTRLA = 0x1000              ; Control A
.equ NVMCTRL_CTRLB = 0x1001              ; Control B
.equ NVMCTRL_STATUS = 0x1002             ; Status
.equ NVMCTRL_INTCTRL = 0x1003            ; Interrupt Control
.equ NVMCTRL_INTFLAGS = 0x1004           ; Interrupt Flags
.equ NVMCTRL_DATA = 0x1006               ; Data
.equ NVMCTRL_DATAL = 0x1006              ; Data low byte
.equ NVMCTRL_DATAH = 0x1007              ; Data hi byte
.equ NVMCTRL_ADDR = 0x1008               ; Address
.equ NVMCTRL_ADDRL = 0x1008              ; Address low byte
.equ NVMCTRL_ADDRH = 0x1009              ; Address hi byte

;*************************************************************************
;** PORTA - I/O Ports
;*************************************************************************

.equ PORTA_DIR = 0x0400                  ; Data Direction
.equ PORTA_DIRSET = 0x0401               ; Data Direction Set
.equ PORTA_DIRCLR = 0x0402               ; Data Direction Clear
.equ PORTA_DIRTGL = 0x0403               ; Data Direction Toggle
.equ PORTA_OUT = 0x0404                  ; Output Value
.equ PORTA_OUTSET = 0x0405               ; Output Value Set
.equ PORTA_OUTCLR = 0x0406               ; Output Value Clear
.equ PORTA_OUTTGL = 0x0407               ; Output Value Toggle
.equ PORTA_IN = 0x0408                   ; Input Value
.equ PORTA_INTFLAGS = 0x0409             ; Interrupt Flags
.equ PORTA_PORTCTRL = 0x040A             ; Port Control
.equ PORTA_PIN0CTRL = 0x0410             ; Pin 0 Control
.equ PORTA_PIN1CTRL = 0x0411             ; Pin 1 Control
.equ PORTA_PIN2CTRL = 0x0412             ; Pin 2 Control
.equ PORTA_PIN3CTRL = 0x0413             ; Pin 3 Control
.equ PORTA_PIN4CTRL = 0x0414             ; Pin 4 Control
.equ PORTA_PIN5CTRL = 0x0415             ; Pin 5 Control
.equ PORTA_PIN6CTRL = 0x0416             ; Pin 6 Control
.equ PORTA_PIN7CTRL = 0x0417             ; Pin 7 Control

;*************************************************************************
;** PORTB - I/O Ports
;*************************************************************************

.equ PORTB_DIR = 0x0420                  ; Data Direction
.equ PORTB_DIRSET = 0x0421               ; Data Direction Set
.equ PORTB_DIRCLR = 0x0422               ; Data Direction Clear
.equ PORTB_DIRTGL = 0x0423               ; Data Direction Toggle
.equ PORTB_OUT = 0x0424                  ; Output Value
.equ PORTB_OUTSET = 0x0425               ; Output Value Set
.equ PORTB_OUTCLR = 0x0426               ; Output Value Clear
.equ PORTB_OUTTGL = 0x0427               ; Output Value Toggle
.equ PORTB_IN = 0x0428                   ; Input Value
.equ PORTB_INTFLAGS = 0x0429             ; Interrupt Flags
.equ PORTB_PORTCTRL = 0x042A             ; Port Control
.equ PORTB_PIN0CTRL = 0x0430             ; Pin 0 Control
.equ PORTB_PIN1CTRL = 0x0431             ; Pin 1 Control
.equ PORTB_PIN2CTRL = 0x0432             ; Pin 2 Control
.equ PORTB_PIN3CTRL = 0x0433             ; Pin 3 Control
.equ PORTB_PIN4CTRL = 0x0434             ; Pin 4 Control
.equ PORTB_PIN5CTRL = 0x0435             ; Pin 5 Control
.equ PORTB_PIN6CTRL = 0x0436             ; Pin 6 Control
.equ PORTB_PIN7CTRL = 0x0437             ; Pin 7 Control

;*************************************************************************
;** PORTC - I/O Ports
;*************************************************************************

.equ PORTC_DIR = 0x0440                  ; Data Direction
.equ PORTC_DIRSET = 0x0441               ; Data Direction Set
.equ PORTC_DIRCLR = 0x0442               ; Data Direction Clear
.equ PORTC_DIRTGL = 0x0443               ; Data Direction Toggle
.equ PORTC_OUT = 0x0444                  ; Output Value
.equ PORTC_OUTSET = 0x0445               ; Output Value Set
.equ PORTC_OUTCLR = 0x0446               ; Output Value Clear
.equ PORTC_OUTTGL = 0x0447               ; Output Value Toggle
.equ PORTC_IN = 0x0448                   ; Input Value
.equ PORTC_INTFLAGS = 0x0449             ; Interrupt Flags
.equ PORTC_PORTCTRL = 0x044A             ; Port Control
.equ PORTC_PIN0CTRL = 0x0450             ; Pin 0 Control
.equ PORTC_PIN1CTRL = 0x0451             ; Pin 1 Control
.equ PORTC_PIN2CTRL = 0x0452             ; Pin 2 Control
.equ PORTC_PIN3CTRL = 0x0453             ; Pin 3 Control
.equ PORTC_PIN4CTRL = 0x0454             ; Pin 4 Control
.equ PORTC_PIN5CTRL = 0x0455             ; Pin 5 Control
.equ PORTC_PIN6CTRL = 0x0456             ; Pin 6 Control
.equ PORTC_PIN7CTRL = 0x0457             ; Pin 7 Control

;*************************************************************************
;** PORTD - I/O Ports
;*************************************************************************

.equ PORTD_DIR = 0x0460                  ; Data Direction
.equ PORTD_DIRSET = 0x0461               ; Data Direction Set
.equ PORTD_DIRCLR = 0x0462               ; Data Direction Clear
.equ PORTD_DIRTGL = 0x0463               ; Data Direction Toggle
.equ PORTD_OUT = 0x0464                  ; Output Value
.equ PORTD_OUTSET = 0x0465               ; Output Value Set
.equ PORTD_OUTCLR = 0x0466               ; Output Value Clear
.equ PORTD_OUTTGL = 0x0467               ; Output Value Toggle
.equ PORTD_IN = 0x0468                   ; Input Value
.equ PORTD_INTFLAGS = 0x0469             ; Interrupt Flags
.equ PORTD_PORTCTRL = 0x046A             ; Port Control
.equ PORTD_PIN0CTRL = 0x0470             ; Pin 0 Control
.equ PORTD_PIN1CTRL = 0x0471             ; Pin 1 Control
.equ PORTD_PIN2CTRL = 0x0472             ; Pin 2 Control
.equ PORTD_PIN3CTRL = 0x0473             ; Pin 3 Control
.equ PORTD_PIN4CTRL = 0x0474             ; Pin 4 Control
.equ PORTD_PIN5CTRL = 0x0475             ; Pin 5 Control
.equ PORTD_PIN6CTRL = 0x0476             ; Pin 6 Control
.equ PORTD_PIN7CTRL = 0x0477             ; Pin 7 Control

;*************************************************************************
;** PORTE - I/O Ports
;*************************************************************************

.equ PORTE_DIR = 0x0480                  ; Data Direction
.equ PORTE_DIRSET = 0x0481               ; Data Direction Set
.equ PORTE_DIRCLR = 0x0482               ; Data Direction Clear
.equ PORTE_DIRTGL = 0x0483               ; Data Direction Toggle
.equ PORTE_OUT = 0x0484                  ; Output Value
.equ PORTE_OUTSET = 0x0485               ; Output Value Set
.equ PORTE_OUTCLR = 0x0486               ; Output Value Clear
.equ PORTE_OUTTGL = 0x0487               ; Output Value Toggle
.equ PORTE_IN = 0x0488                   ; Input Value
.equ PORTE_INTFLAGS = 0x0489             ; Interrupt Flags
.equ PORTE_PORTCTRL = 0x048A             ; Port Control
.equ PORTE_PIN0CTRL = 0x0490             ; Pin 0 Control
.equ PORTE_PIN1CTRL = 0x0491             ; Pin 1 Control
.equ PORTE_PIN2CTRL = 0x0492             ; Pin 2 Control
.equ PORTE_PIN3CTRL = 0x0493             ; Pin 3 Control
.equ PORTE_PIN4CTRL = 0x0494             ; Pin 4 Control
.equ PORTE_PIN5CTRL = 0x0495             ; Pin 5 Control
.equ PORTE_PIN6CTRL = 0x0496             ; Pin 6 Control
.equ PORTE_PIN7CTRL = 0x0497             ; Pin 7 Control

;*************************************************************************
;** PORTF - I/O Ports
;*************************************************************************

.equ PORTF_DIR = 0x04A0                  ; Data Direction
.equ PORTF_DIRSET = 0x04A1               ; Data Direction Set
.equ PORTF_DIRCLR = 0x04A2               ; Data Direction Clear
.equ PORTF_DIRTGL = 0x04A3               ; Data Direction Toggle
.equ PORTF_OUT = 0x04A4                  ; Output Value
.equ PORTF_OUTSET = 0x04A5               ; Output Value Set
.equ PORTF_OUTCLR = 0x04A6               ; Output Value Clear
.equ PORTF_OUTTGL = 0x04A7               ; Output Value Toggle
.equ PORTF_IN = 0x04A8                   ; Input Value
.equ PORTF_INTFLAGS = 0x04A9             ; Interrupt Flags
.equ PORTF_PORTCTRL = 0x04AA             ; Port Control
.equ PORTF_PIN0CTRL = 0x04B0             ; Pin 0 Control
.equ PORTF_PIN1CTRL = 0x04B1             ; Pin 1 Control
.equ PORTF_PIN2CTRL = 0x04B2             ; Pin 2 Control
.equ PORTF_PIN3CTRL = 0x04B3             ; Pin 3 Control
.equ PORTF_PIN4CTRL = 0x04B4             ; Pin 4 Control
.equ PORTF_PIN5CTRL = 0x04B5             ; Pin 5 Control
.equ PORTF_PIN6CTRL = 0x04B6             ; Pin 6 Control
.equ PORTF_PIN7CTRL = 0x04B7             ; Pin 7 Control

;*************************************************************************
;** PORTMUX - Port Multiplexer
;*************************************************************************

.equ PORTMUX_EVSYSROUTEA = 0x05E0        ; Port Multiplexer EVSYS
.equ PORTMUX_CCLROUTEA = 0x05E1          ; Port Multiplexer CCL
.equ PORTMUX_USARTROUTEA = 0x05E2        ; Port Multiplexer USART register A
.equ PORTMUX_TWISPIROUTEA = 0x05E3       ; Port Multiplexer TWI and SPI
.equ PORTMUX_TCAROUTEA = 0x05E4          ; Port Multiplexer TCA
.equ PORTMUX_TCBROUTEA = 0x05E5          ; Port Multiplexer TCB

;*************************************************************************
;** RSTCTRL - Reset controller
;*************************************************************************

.equ RSTCTRL_RSTFR = 0x0040              ; Reset Flags
.equ RSTCTRL_SWRR = 0x0041               ; Software Reset

;*************************************************************************
;** RTC - Real-Time Counter
;*************************************************************************

.equ RTC_CTRLA = 0x0140                  ; Control A
.equ RTC_STATUS = 0x0141                 ; Status
.equ RTC_INTCTRL = 0x0142                ; Interrupt Control
.equ RTC_INTFLAGS = 0x0143               ; Interrupt Flags
.equ RTC_TEMP = 0x0144                   ; Temporary
.equ RTC_DBGCTRL = 0x0145                ; Debug control
.equ RTC_CALIB = 0x0146                  ; Calibration
.equ RTC_CLKSEL = 0x0147                 ; Clock Select
.equ RTC_CNT = 0x0148                    ; Counter
.equ RTC_CNTL = 0x0148                   ; Counter low byte
.equ RTC_CNTH = 0x0149                   ; Counter hi byte
.equ RTC_PER = 0x014A                    ; Period
.equ RTC_PERL = 0x014A                   ; Period low byte
.equ RTC_PERH = 0x014B                   ; Period hi byte
.equ RTC_CMP = 0x014C                    ; Compare
.equ RTC_CMPL = 0x014C                   ; Compare low byte
.equ RTC_CMPH = 0x014D                   ; Compare hi byte
.equ RTC_PITCTRLA = 0x0150               ; PIT Control A
.equ RTC_PITSTATUS = 0x0151              ; PIT Status
.equ RTC_PITINTCTRL = 0x0152             ; PIT Interrupt Control
.equ RTC_PITINTFLAGS = 0x0153            ; PIT Interrupt Flags
.equ RTC_PITDBGCTRL = 0x0155             ; PIT Debug control

;*************************************************************************
;** SIGROW - Signature row
;*************************************************************************

.equ SIGROW_DEVICEID0 = 0x1100           ; Device ID Byte 0
.equ SIGROW_DEVICEID1 = 0x1101           ; Device ID Byte 1
.equ SIGROW_DEVICEID2 = 0x1102           ; Device ID Byte 2
.equ SIGROW_SERNUM0 = 0x1103             ; Serial Number Byte 0
.equ SIGROW_SERNUM1 = 0x1104             ; Serial Number Byte 1
.equ SIGROW_SERNUM2 = 0x1105             ; Serial Number Byte 2
.equ SIGROW_SERNUM3 = 0x1106             ; Serial Number Byte 3
.equ SIGROW_SERNUM4 = 0x1107             ; Serial Number Byte 4
.equ SIGROW_SERNUM5 = 0x1108             ; Serial Number Byte 5
.equ SIGROW_SERNUM6 = 0x1109             ; Serial Number Byte 6
.equ SIGROW_SERNUM7 = 0x110A             ; Serial Number Byte 7
.equ SIGROW_SERNUM8 = 0x110B             ; Serial Number Byte 8
.equ SIGROW_SERNUM9 = 0x110C             ; Serial Number Byte 9
.equ SIGROW_OSCCAL32K = 0x1114           ; Oscillator Calibration for 32kHz ULP
.equ SIGROW_OSCCAL16M0 = 0x1118          ; Oscillator Calibration 16 MHz Byte 0
.equ SIGROW_OSCCAL16M1 = 0x1119          ; Oscillator Calibration 16 MHz Byte 1
.equ SIGROW_OSCCAL20M0 = 0x111A          ; Oscillator Calibration 20 MHz Byte 0
.equ SIGROW_OSCCAL20M1 = 0x111B          ; Oscillator Calibration 20 MHz Byte 1
.equ SIGROW_TEMPSENSE0 = 0x1120          ; Temperature Sensor Calibration Byte 0
.equ SIGROW_TEMPSENSE1 = 0x1121          ; Temperature Sensor Calibration Byte 1
.equ SIGROW_OSC16ERR3V = 0x1122          ; OSC16 error at 3V
.equ SIGROW_OSC16ERR5V = 0x1123          ; OSC16 error at 5V
.equ SIGROW_OSC20ERR3V = 0x1124          ; OSC20 error at 3V
.equ SIGROW_OSC20ERR5V = 0x1125          ; OSC20 error at 5V
.equ SIGROW_CHECKSUM1 = 0x112F           ; CRC Checksum Byte 1

;*************************************************************************
;** SLPCTRL - Sleep Controller
;*************************************************************************

.equ SLPCTRL_CTRLA = 0x0050              ; Control

;*************************************************************************
;** SPI0 - Serial Peripheral Interface
;*************************************************************************

.equ SPI0_CTRLA = 0x08C0                 ; Control A
.equ SPI0_CTRLB = 0x08C1                 ; Control B
.equ SPI0_INTCTRL = 0x08C2               ; Interrupt Control
.equ SPI0_INTFLAGS = 0x08C3              ; Interrupt Flags
.equ SPI0_DATA = 0x08C4                  ; Data

;*************************************************************************
;** SYSCFG - System Configuration Registers
;*************************************************************************

.equ SYSCFG_REVID = 0x0F01               ; Revision ID
.equ SYSCFG_EXTBRK = 0x0F02              ; External Break
.equ SYSCFG_OCDM = 0x0F18                ; OCD Message Register
.equ SYSCFG_OCDMS = 0x0F19               ; OCD Message Status

;*************************************************************************
;** TCA0 - 16-bit Timer/Counter Type A
;*************************************************************************

.equ TCA0_SINGLE_CTRLA = 0x0A00          ; SINGLE Control A
.equ TCA0_SINGLE_CTRLB = 0x0A01          ; SINGLE Control B
.equ TCA0_SINGLE_CTRLC = 0x0A02          ; SINGLE Control C
.equ TCA0_SINGLE_CTRLD = 0x0A03          ; SINGLE Control D
.equ TCA0_SINGLE_CTRLECLR = 0x0A04       ; SINGLE Control E Clear
.equ TCA0_SINGLE_CTRLESET = 0x0A05       ; SINGLE Control E Set
.equ TCA0_SINGLE_CTRLFCLR = 0x0A06       ; SINGLE Control F Clear
.equ TCA0_SINGLE_CTRLFSET = 0x0A07       ; SINGLE Control F Set
.equ TCA0_SINGLE_EVCTRL = 0x0A09         ; SINGLE Event Control
.equ TCA0_SINGLE_INTCTRL = 0x0A0A        ; SINGLE Interrupt Control
.equ TCA0_SINGLE_INTFLAGS = 0x0A0B       ; SINGLE Interrupt Flags
.equ TCA0_SINGLE_DBGCTRL = 0x0A0E        ; SINGLE Degbug Control
.equ TCA0_SINGLE_TEMP = 0x0A0F           ; SINGLE Temporary data for 16-bit Access
.equ TCA0_SINGLE_CNT = 0x0A20            ; SINGLE Count
.equ TCA0_SINGLE_PER = 0x0A26            ; SINGLE Period
.equ TCA0_SINGLE_CMP0 = 0x0A28           ; SINGLE Compare 0
.equ TCA0_SINGLE_CMP1 = 0x0A2A           ; SINGLE Compare 1
.equ TCA0_SINGLE_CMP2 = 0x0A2C           ; SINGLE Compare 2
.equ TCA0_SINGLE_PERBUF = 0x0A36         ; SINGLE Period Buffer
.equ TCA0_SINGLE_CMP0BUF = 0x0A38        ; SINGLE Compare 0 Buffer
.equ TCA0_SINGLE_CMP1BUF = 0x0A3A        ; SINGLE Compare 1 Buffer
.equ TCA0_SINGLE_CMP2BUF = 0x0A3C        ; SINGLE Compare 2 Buffer
.equ TCA0_SPLIT_CTRLA = 0x0A00           ; SPLIT Control A
.equ TCA0_SPLIT_CTRLB = 0x0A01           ; SPLIT Control B
.equ TCA0_SPLIT_CTRLC = 0x0A02           ; SPLIT Control C
.equ TCA0_SPLIT_CTRLD = 0x0A03           ; SPLIT Control D
.equ TCA0_SPLIT_CTRLECLR = 0x0A04        ; SPLIT Control E Clear
.equ TCA0_SPLIT_CTRLESET = 0x0A05        ; SPLIT Control E Set
.equ TCA0_SPLIT_INTCTRL = 0x0A0A         ; SPLIT Interrupt Control
.equ TCA0_SPLIT_INTFLAGS = 0x0A0B        ; SPLIT Interrupt Flags
.equ TCA0_SPLIT_DBGCTRL = 0x0A0E         ; SPLIT Degbug Control
.equ TCA0_SPLIT_LCNT = 0x0A20            ; SPLIT Low Count
.equ TCA0_SPLIT_HCNT = 0x0A21            ; SPLIT High Count
.equ TCA0_SPLIT_LPER = 0x0A26            ; SPLIT Low Period
.equ TCA0_SPLIT_HPER = 0x0A27            ; SPLIT High Period
.equ TCA0_SPLIT_LCMP0 = 0x0A28           ; SPLIT Low Compare
.equ TCA0_SPLIT_HCMP0 = 0x0A29           ; SPLIT High Compare
.equ TCA0_SPLIT_LCMP1 = 0x0A2A           ; SPLIT Low Compare
.equ TCA0_SPLIT_HCMP1 = 0x0A2B           ; SPLIT High Compare
.equ TCA0_SPLIT_LCMP2 = 0x0A2C           ; SPLIT Low Compare
.equ TCA0_SPLIT_HCMP2 = 0x0A2D           ; SPLIT High Compare

;*************************************************************************
;** TCB0 - 16-bit Timer Type B
;*************************************************************************

.equ TCB0_CTRLA = 0x0A80                 ; Control A
.equ TCB0_CTRLB = 0x0A81                 ; Control Register B
.equ TCB0_EVCTRL = 0x0A84                ; Event Control
.equ TCB0_INTCTRL = 0x0A85               ; Interrupt Control
.equ TCB0_INTFLAGS = 0x0A86              ; Interrupt Flags
.equ TCB0_STATUS = 0x0A87                ; Status
.equ TCB0_DBGCTRL = 0x0A88               ; Debug Control
.equ TCB0_TEMP = 0x0A89                  ; Temporary Value
.equ TCB0_CNT = 0x0A8A                   ; Count
.equ TCB0_CNTL = 0x0A8A                  ; Count low byte
.equ TCB0_CNTH = 0x0A8B                  ; Count hi byte
.equ TCB0_CCMP = 0x0A8C                  ; Compare or Capture
.equ TCB0_CCMPL = 0x0A8C                 ; Compare or Capture low byte
.equ TCB0_CCMPH = 0x0A8D                 ; Compare or Capture hi byte

;*************************************************************************
;** TCB1 - 16-bit Timer Type B
;*************************************************************************

.equ TCB1_CTRLA = 0x0A90                 ; Control A
.equ TCB1_CTRLB = 0x0A91                 ; Control Register B
.equ TCB1_EVCTRL = 0x0A94                ; Event Control
.equ TCB1_INTCTRL = 0x0A95               ; Interrupt Control
.equ TCB1_INTFLAGS = 0x0A96              ; Interrupt Flags
.equ TCB1_STATUS = 0x0A97                ; Status
.equ TCB1_DBGCTRL = 0x0A98               ; Debug Control
.equ TCB1_TEMP = 0x0A99                  ; Temporary Value
.equ TCB1_CNT = 0x0A9A                   ; Count
.equ TCB1_CNTL = 0x0A9A                  ; Count low byte
.equ TCB1_CNTH = 0x0A9B                  ; Count hi byte
.equ TCB1_CCMP = 0x0A9C                  ; Compare or Capture
.equ TCB1_CCMPL = 0x0A9C                 ; Compare or Capture low byte
.equ TCB1_CCMPH = 0x0A9D                 ; Compare or Capture hi byte

;*************************************************************************
;** TCB2 - 16-bit Timer Type B
;*************************************************************************

.equ TCB2_CTRLA = 0x0AA0                 ; Control A
.equ TCB2_CTRLB = 0x0AA1                 ; Control Register B
.equ TCB2_EVCTRL = 0x0AA4                ; Event Control
.equ TCB2_INTCTRL = 0x0AA5               ; Interrupt Control
.equ TCB2_INTFLAGS = 0x0AA6              ; Interrupt Flags
.equ TCB2_STATUS = 0x0AA7                ; Status
.equ TCB2_DBGCTRL = 0x0AA8               ; Debug Control
.equ TCB2_TEMP = 0x0AA9                  ; Temporary Value
.equ TCB2_CNT = 0x0AAA                   ; Count
.equ TCB2_CNTL = 0x0AAA                  ; Count low byte
.equ TCB2_CNTH = 0x0AAB                  ; Count hi byte
.equ TCB2_CCMP = 0x0AAC                  ; Compare or Capture
.equ TCB2_CCMPL = 0x0AAC                 ; Compare or Capture low byte
.equ TCB2_CCMPH = 0x0AAD                 ; Compare or Capture hi byte

;*************************************************************************
;** TCB3 - 16-bit Timer Type B
;*************************************************************************

.equ TCB3_CTRLA = 0x0AB0                 ; Control A
.equ TCB3_CTRLB = 0x0AB1                 ; Control Register B
.equ TCB3_EVCTRL = 0x0AB4                ; Event Control
.equ TCB3_INTCTRL = 0x0AB5               ; Interrupt Control
.equ TCB3_INTFLAGS = 0x0AB6              ; Interrupt Flags
.equ TCB3_STATUS = 0x0AB7                ; Status
.equ TCB3_DBGCTRL = 0x0AB8               ; Debug Control
.equ TCB3_TEMP = 0x0AB9                  ; Temporary Value
.equ TCB3_CNT = 0x0ABA                   ; Count
.equ TCB3_CNTL = 0x0ABA                  ; Count low byte
.equ TCB3_CNTH = 0x0ABB                  ; Count hi byte
.equ TCB3_CCMP = 0x0ABC                  ; Compare or Capture
.equ TCB3_CCMPL = 0x0ABC                 ; Compare or Capture low byte
.equ TCB3_CCMPH = 0x0ABD                 ; Compare or Capture hi byte

;*************************************************************************
;** TWI0 - Two-Wire Interface
;*************************************************************************

.equ TWI0_CTRLA = 0x08A0                 ; Control A
.equ TWI0_DUALCTRL = 0x08A1              ; Dual Control
.equ TWI0_DBGCTRL = 0x08A2               ; Debug Control Register
.equ TWI0_MCTRLA = 0x08A3                ; Master Control A
.equ TWI0_MCTRLB = 0x08A4                ; Master Control B
.equ TWI0_MSTATUS = 0x08A5               ; Master Status
.equ TWI0_MBAUD = 0x08A6                 ; Master Baurd Rate Control
.equ TWI0_MADDR = 0x08A7                 ; Master Address
.equ TWI0_MDATA = 0x08A8                 ; Master Data
.equ TWI0_SCTRLA = 0x08A9                ; Slave Control A
.equ TWI0_SCTRLB = 0x08AA                ; Slave Control B
.equ TWI0_SSTATUS = 0x08AB               ; Slave Status
.equ TWI0_SADDR = 0x08AC                 ; Slave Address
.equ TWI0_SDATA = 0x08AD                 ; Slave Data
.equ TWI0_SADDRMASK = 0x08AE             ; Slave Address Mask

;*************************************************************************
;** USART0 - Universal Synchronous and Asynchronous Receiver and Transmitter
;*************************************************************************

.equ USART0_RXDATAL = 0x0800             ; Receive Data Low Byte
.equ USART0_RXDATAH = 0x0801             ; Receive Data High Byte
.equ USART0_TXDATAL = 0x0802             ; Transmit Data Low Byte
.equ USART0_TXDATAH = 0x0803             ; Transmit Data High Byte
.equ USART0_STATUS = 0x0804              ; Status
.equ USART0_CTRLA = 0x0805               ; Control A
.equ USART0_CTRLB = 0x0806               ; Control B
.equ USART0_CTRLC = 0x0807               ; Control C
.equ USART0_BAUD = 0x0808                ; Baud Rate
.equ USART0_BAUDL = 0x0808               ; Baud Rate low byte
.equ USART0_BAUDH = 0x0809               ; Baud Rate hi byte
.equ USART0_CTRLD = 0x080A               ; Control D
.equ USART0_DBGCTRL = 0x080B             ; Debug Control
.equ USART0_EVCTRL = 0x080C              ; Event Control
.equ USART0_TXPLCTRL = 0x080D            ; IRCOM Transmitter Pulse Length Control
.equ USART0_RXPLCTRL = 0x080E            ; IRCOM Receiver Pulse Length Control

;*************************************************************************
;** USART1 - Universal Synchronous and Asynchronous Receiver and Transmitter
;*************************************************************************

.equ USART1_RXDATAL = 0x0820             ; Receive Data Low Byte
.equ USART1_RXDATAH = 0x0821             ; Receive Data High Byte
.equ USART1_TXDATAL = 0x0822             ; Transmit Data Low Byte
.equ USART1_TXDATAH = 0x0823             ; Transmit Data High Byte
.equ USART1_STATUS = 0x0824              ; Status
.equ USART1_CTRLA = 0x0825               ; Control A
.equ USART1_CTRLB = 0x0826               ; Control B
.equ USART1_CTRLC = 0x0827               ; Control C
.equ USART1_BAUD = 0x0828                ; Baud Rate
.equ USART1_BAUDL = 0x0828               ; Baud Rate low byte
.equ USART1_BAUDH = 0x0829               ; Baud Rate hi byte
.equ USART1_CTRLD = 0x082A               ; Control D
.equ USART1_DBGCTRL = 0x082B             ; Debug Control
.equ USART1_EVCTRL = 0x082C              ; Event Control
.equ USART1_TXPLCTRL = 0x082D            ; IRCOM Transmitter Pulse Length Control
.equ USART1_RXPLCTRL = 0x082E            ; IRCOM Receiver Pulse Length Control

;*************************************************************************
;** USART2 - Universal Synchronous and Asynchronous Receiver and Transmitter
;*************************************************************************

.equ USART2_RXDATAL = 0x0840             ; Receive Data Low Byte
.equ USART2_RXDATAH = 0x0841             ; Receive Data High Byte
.equ USART2_TXDATAL = 0x0842             ; Transmit Data Low Byte
.equ USART2_TXDATAH = 0x0843             ; Transmit Data High Byte
.equ USART2_STATUS = 0x0844              ; Status
.equ USART2_CTRLA = 0x0845               ; Control A
.equ USART2_CTRLB = 0x0846               ; Control B
.equ USART2_CTRLC = 0x0847               ; Control C
.equ USART2_BAUD = 0x0848                ; Baud Rate
.equ USART2_BAUDL = 0x0848               ; Baud Rate low byte
.equ USART2_BAUDH = 0x0849               ; Baud Rate hi byte
.equ USART2_CTRLD = 0x084A               ; Control D
.equ USART2_DBGCTRL = 0x084B             ; Debug Control
.equ USART2_EVCTRL = 0x084C              ; Event Control
.equ USART2_TXPLCTRL = 0x084D            ; IRCOM Transmitter Pulse Length Control
.equ USART2_RXPLCTRL = 0x084E            ; IRCOM Receiver Pulse Length Control

;*************************************************************************
;** USART3 - Universal Synchronous and Asynchronous Receiver and Transmitter
;*************************************************************************

.equ USART3_RXDATAL = 0x0860             ; Receive Data Low Byte
.equ USART3_RXDATAH = 0x0861             ; Receive Data High Byte
.equ USART3_TXDATAL = 0x0862             ; Transmit Data Low Byte
.equ USART3_TXDATAH = 0x0863             ; Transmit Data High Byte
.equ USART3_STATUS = 0x0864              ; Status
.equ USART3_CTRLA = 0x0865               ; Control A
.equ USART3_CTRLB = 0x0866               ; Control B
.equ USART3_CTRLC = 0x0867               ; Control C
.equ USART3_BAUD = 0x0868                ; Baud Rate
.equ USART3_BAUDL = 0x0868               ; Baud Rate low byte
.equ USART3_BAUDH = 0x0869               ; Baud Rate hi byte
.equ USART3_CTRLD = 0x086A               ; Control D
.equ USART3_DBGCTRL = 0x086B             ; Debug Control
.equ USART3_EVCTRL = 0x086C              ; Event Control
.equ USART3_TXPLCTRL = 0x086D            ; IRCOM Transmitter Pulse Length Control
.equ USART3_RXPLCTRL = 0x086E            ; IRCOM Receiver Pulse Length Control

;*************************************************************************
;** USERROW - User Row
;*************************************************************************

.equ USERROW_USERROW0 = 0x1300           ; User Row Byte 0
.equ USERROW_USERROW1 = 0x1301           ; User Row Byte 1
.equ USERROW_USERROW2 = 0x1302           ; User Row Byte 2
.equ USERROW_USERROW3 = 0x1303           ; User Row Byte 3
.equ USERROW_USERROW4 = 0x1304           ; User Row Byte 4
.equ USERROW_USERROW5 = 0x1305           ; User Row Byte 5
.equ USERROW_USERROW6 = 0x1306           ; User Row Byte 6
.equ USERROW_USERROW7 = 0x1307           ; User Row Byte 7
.equ USERROW_USERROW8 = 0x1308           ; User Row Byte 8
.equ USERROW_USERROW9 = 0x1309           ; User Row Byte 9
.equ USERROW_USERROW10 = 0x130A          ; User Row Byte 10
.equ USERROW_USERROW11 = 0x130B          ; User Row Byte 11
.equ USERROW_USERROW12 = 0x130C          ; User Row Byte 12
.equ USERROW_USERROW13 = 0x130D          ; User Row Byte 13
.equ USERROW_USERROW14 = 0x130E          ; User Row Byte 14
.equ USERROW_USERROW15 = 0x130F          ; User Row Byte 15
.equ USERROW_USERROW16 = 0x1310          ; User Row Byte 16
.equ USERROW_USERROW17 = 0x1311          ; User Row Byte 17
.equ USERROW_USERROW18 = 0x1312          ; User Row Byte 18
.equ USERROW_USERROW19 = 0x1313          ; User Row Byte 19
.equ USERROW_USERROW20 = 0x1314          ; User Row Byte 20
.equ USERROW_USERROW21 = 0x1315          ; User Row Byte 21
.equ USERROW_USERROW22 = 0x1316          ; User Row Byte 22
.equ USERROW_USERROW23 = 0x1317          ; User Row Byte 23
.equ USERROW_USERROW24 = 0x1318          ; User Row Byte 24
.equ USERROW_USERROW25 = 0x1319          ; User Row Byte 25
.equ USERROW_USERROW26 = 0x131A          ; User Row Byte 26
.equ USERROW_USERROW27 = 0x131B          ; User Row Byte 27
.equ USERROW_USERROW28 = 0x131C          ; User Row Byte 28
.equ USERROW_USERROW29 = 0x131D          ; User Row Byte 29
.equ USERROW_USERROW30 = 0x131E          ; User Row Byte 30
.equ USERROW_USERROW31 = 0x131F          ; User Row Byte 31
.equ USERROW_USERROW32 = 0x1320          ; User Row Byte 32
.equ USERROW_USERROW33 = 0x1321          ; User Row Byte 33
.equ USERROW_USERROW34 = 0x1322          ; User Row Byte 34
.equ USERROW_USERROW35 = 0x1323          ; User Row Byte 35
.equ USERROW_USERROW36 = 0x1324          ; User Row Byte 36
.equ USERROW_USERROW37 = 0x1325          ; User Row Byte 37
.equ USERROW_USERROW38 = 0x1326          ; User Row Byte 38
.equ USERROW_USERROW39 = 0x1327          ; User Row Byte 39
.equ USERROW_USERROW40 = 0x1328          ; User Row Byte 40
.equ USERROW_USERROW41 = 0x1329          ; User Row Byte 41
.equ USERROW_USERROW42 = 0x132A          ; User Row Byte 42
.equ USERROW_USERROW43 = 0x132B          ; User Row Byte 43
.equ USERROW_USERROW44 = 0x132C          ; User Row Byte 44
.equ USERROW_USERROW45 = 0x132D          ; User Row Byte 45
.equ USERROW_USERROW46 = 0x132E          ; User Row Byte 46
.equ USERROW_USERROW47 = 0x132F          ; User Row Byte 47
.equ USERROW_USERROW48 = 0x1330          ; User Row Byte 48
.equ USERROW_USERROW49 = 0x1331          ; User Row Byte 49
.equ USERROW_USERROW50 = 0x1332          ; User Row Byte 50
.equ USERROW_USERROW51 = 0x1333          ; User Row Byte 51
.equ USERROW_USERROW52 = 0x1334          ; User Row Byte 52
.equ USERROW_USERROW53 = 0x1335          ; User Row Byte 53
.equ USERROW_USERROW54 = 0x1336          ; User Row Byte 54
.equ USERROW_USERROW55 = 0x1337          ; User Row Byte 55
.equ USERROW_USERROW56 = 0x1338          ; User Row Byte 56
.equ USERROW_USERROW57 = 0x1339          ; User Row Byte 57
.equ USERROW_USERROW58 = 0x133A          ; User Row Byte 58
.equ USERROW_USERROW59 = 0x133B          ; User Row Byte 59
.equ USERROW_USERROW60 = 0x133C          ; User Row Byte 60
.equ USERROW_USERROW61 = 0x133D          ; User Row Byte 61
.equ USERROW_USERROW62 = 0x133E          ; User Row Byte 62
.equ USERROW_USERROW63 = 0x133F          ; User Row Byte 63

;*************************************************************************
;** VPORTA - Virtual Ports
;*************************************************************************

.equ VPORTA_DIR = 0x0000                 ; Data Direction
.equ VPORTA_OUT = 0x0001                 ; Output Value
.equ VPORTA_IN = 0x0002                  ; Input Value
.equ VPORTA_INTFLAGS = 0x0003            ; Interrupt Flags

;*************************************************************************
;** VPORTB - Virtual Ports
;*************************************************************************

.equ VPORTB_DIR = 0x0004                 ; Data Direction
.equ VPORTB_OUT = 0x0005                 ; Output Value
.equ VPORTB_IN = 0x0006                  ; Input Value
.equ VPORTB_INTFLAGS = 0x0007            ; Interrupt Flags

;*************************************************************************
;** VPORTC - Virtual Ports
;*************************************************************************

.equ VPORTC_DIR = 0x0008                 ; Data Direction
.equ VPORTC_OUT = 0x0009                 ; Output Value
.equ VPORTC_IN = 0x000A                  ; Input Value
.equ VPORTC_INTFLAGS = 0x000B            ; Interrupt Flags

;*************************************************************************
;** VPORTD - Virtual Ports
;*************************************************************************

.equ VPORTD_DIR = 0x000C                 ; Data Direction
.equ VPORTD_OUT = 0x000D                 ; Output Value
.equ VPORTD_IN = 0x000E                  ; Input Value
.equ VPORTD_INTFLAGS = 0x000F            ; Interrupt Flags

;*************************************************************************
;** VPORTE - Virtual Ports
;*************************************************************************

.equ VPORTE_DIR = 0x0010                 ; Data Direction
.equ VPORTE_OUT = 0x0011                 ; Output Value
.equ VPORTE_IN = 0x0012                  ; Input Value
.equ VPORTE_INTFLAGS = 0x0013            ; Interrupt Flags

;*************************************************************************
;** VPORTF - Virtual Ports
;*************************************************************************

.equ VPORTF_DIR = 0x0014                 ; Data Direction
.equ VPORTF_OUT = 0x0015                 ; Output Value
.equ VPORTF_IN = 0x0016                  ; Input Value
.equ VPORTF_INTFLAGS = 0x0017            ; Interrupt Flags

;*************************************************************************
;** VREF - Voltage reference
;*************************************************************************

.equ VREF_CTRLA = 0x00A0                 ; Control A
.equ VREF_CTRLB = 0x00A1                 ; Control B

;*************************************************************************
;** WDT - Watch-Dog Timer
;*************************************************************************

.equ WDT_CTRLA = 0x0100                  ; Control A
.equ WDT_STATUS = 0x0101                 ; Status


; ***** ALL MODULE BASE ADRESSES *****************************************

.equ AC0_base = 0x0680                   ; Analog Comparator
.equ ADC0_base = 0x0600                  ; Analog to Digital Converter
.equ BOD_base = 0x0080                   ; Bod interface
.equ CCL_base = 0x01C0                   ; Configurable Custom Logic
.equ CLKCTRL_base = 0x0060               ; Clock controller
.equ CPU_base = 0x0030                   ; CPU
.equ CPUINT_base = 0x0110                ; Interrupt Controller
.equ CRCSCAN_base = 0x0120               ; CRCSCAN
.equ EVSYS_base = 0x0180                 ; Event System
.equ FUSE_base = 0x1280                  ; Fuses
.equ GPIO_base = 0x001C                  ; General Purpose IO
.equ LOCKBIT_base = 0x128A               ; Lockbit
.equ NVMCTRL_base = 0x1000               ; Non-volatile Memory Controller
.equ PORTA_base = 0x0400                 ; I/O Ports
.equ PORTB_base = 0x0420                 ; I/O Ports
.equ PORTC_base = 0x0440                 ; I/O Ports
.equ PORTD_base = 0x0460                 ; I/O Ports
.equ PORTE_base = 0x0480                 ; I/O Ports
.equ PORTF_base = 0x04A0                 ; I/O Ports
.equ PORTMUX_base = 0x05E0               ; Port Multiplexer
.equ RSTCTRL_base = 0x0040               ; Reset controller
.equ RTC_base = 0x0140                   ; Real-Time Counter
.equ SIGROW_base = 0x1100                ; Signature row
.equ SLPCTRL_base = 0x0050               ; Sleep Controller
.equ SPI0_base = 0x08C0                  ; Serial Peripheral Interface
.equ SYSCFG_base = 0x0F00                ; System Configuration Registers
.equ TCA0_base = 0x0A00                  ; 16-bit Timer/Counter Type A
.equ TCB0_base = 0x0A80                  ; 16-bit Timer Type B
.equ TCB1_base = 0x0A90                  ; 16-bit Timer Type B
.equ TCB2_base = 0x0AA0                  ; 16-bit Timer Type B
.equ TCB3_base = 0x0AB0                  ; 16-bit Timer Type B
.equ TWI0_base = 0x08A0                  ; Two-Wire Interface
.equ USART0_base = 0x0800                ; Universal Synchronous and Asynchronous Receiver and Transmitter
.equ USART1_base = 0x0820                ; Universal Synchronous and Asynchronous Receiver and Transmitter
.equ USART2_base = 0x0840                ; Universal Synchronous and Asynchronous Receiver and Transmitter
.equ USART3_base = 0x0860                ; Universal Synchronous and Asynchronous Receiver and Transmitter
.equ USERROW_base = 0x1300               ; User Row
.equ VPORTA_base = 0x0000                ; Virtual Ports
.equ VPORTB_base = 0x0004                ; Virtual Ports
.equ VPORTC_base = 0x0008                ; Virtual Ports
.equ VPORTD_base = 0x000C                ; Virtual Ports
.equ VPORTE_base = 0x0010                ; Virtual Ports
.equ VPORTF_base = 0x0014                ; Virtual Ports
.equ VREF_base = 0x00A0                  ; Voltage reference
.equ WDT_base = 0x0100                   ; Watch-Dog Timer


; ***** IO REGISTER OFFSETS **********************************************


;*************************************************************************
;** AC - Analog Comparator
;*************************************************************************
.equ AC_CTRLA_offset = 0x00              ; Control A
.equ AC_MUXCTRLA_offset = 0x02           ; Mux Control A
.equ AC_DACREF_offset = 0x04             ; Referance scale control
.equ AC_INTCTRL_offset = 0x06            ; Interrupt Control
.equ AC_STATUS_offset = 0x07             ; Status

;*************************************************************************
;** ADC - Analog to Digital Converter
;*************************************************************************
.equ ADC_CTRLA_offset = 0x00             ; Control A
.equ ADC_CTRLB_offset = 0x01             ; Control B
.equ ADC_CTRLC_offset = 0x02             ; Control C
.equ ADC_CTRLD_offset = 0x03             ; Control D
.equ ADC_CTRLE_offset = 0x04             ; Control E
.equ ADC_SAMPCTRL_offset = 0x05          ; Sample Control
.equ ADC_MUXPOS_offset = 0x06            ; Positive mux input
.equ ADC_COMMAND_offset = 0x08           ; Command
.equ ADC_EVCTRL_offset = 0x09            ; Event Control
.equ ADC_INTCTRL_offset = 0x0A           ; Interrupt Control
.equ ADC_INTFLAGS_offset = 0x0B          ; Interrupt Flags
.equ ADC_DBGCTRL_offset = 0x0C           ; Debug Control
.equ ADC_TEMP_offset = 0x0D              ; Temporary Data
.equ ADC_RES_offset = 0x10               ; ADC Accumulator Result
.equ ADC_WINLT_offset = 0x12             ; Window comparator low threshold
.equ ADC_WINHT_offset = 0x14             ; Window comparator high threshold
.equ ADC_CALIB_offset = 0x16             ; Calibration

;*************************************************************************
;** BOD - Bod interface
;*************************************************************************
.equ BOD_CTRLA_offset = 0x00             ; Control A
.equ BOD_CTRLB_offset = 0x01             ; Control B
.equ BOD_VLMCTRLA_offset = 0x08          ; Voltage level monitor Control
.equ BOD_INTCTRL_offset = 0x09           ; Voltage level monitor interrupt Control
.equ BOD_INTFLAGS_offset = 0x0A          ; Voltage level monitor interrupt Flags
.equ BOD_STATUS_offset = 0x0B            ; Voltage level monitor status

;*************************************************************************
;** CCL - Configurable Custom Logic
;*************************************************************************
.equ CCL_CTRLA_offset = 0x00             ; Control Register A
.equ CCL_SEQCTRL0_offset = 0x01          ; Sequential Control 0
.equ CCL_SEQCTRL1_offset = 0x02          ; Sequential Control 1
.equ CCL_INTCTRL0_offset = 0x05          ; Interrupt Control 0
.equ CCL_INTFLAGS_offset = 0x07          ; Interrupt Flags
.equ CCL_LUT0CTRLA_offset = 0x08         ; LUT Control 0 A
.equ CCL_LUT0CTRLB_offset = 0x09         ; LUT Control 0 B
.equ CCL_LUT0CTRLC_offset = 0x0A         ; LUT Control 0 C
.equ CCL_TRUTH0_offset = 0x0B            ; Truth 0
.equ CCL_LUT1CTRLA_offset = 0x0C         ; LUT Control 1 A
.equ CCL_LUT1CTRLB_offset = 0x0D         ; LUT Control 1 B
.equ CCL_LUT1CTRLC_offset = 0x0E         ; LUT Control 1 C
.equ CCL_TRUTH1_offset = 0x0F            ; Truth 1
.equ CCL_LUT2CTRLA_offset = 0x10         ; LUT Control 2 A
.equ CCL_LUT2CTRLB_offset = 0x11         ; LUT Control 2 B
.equ CCL_LUT2CTRLC_offset = 0x12         ; LUT Control 2 C
.equ CCL_TRUTH2_offset = 0x13            ; Truth 2
.equ CCL_LUT3CTRLA_offset = 0x14         ; LUT Control 3 A
.equ CCL_LUT3CTRLB_offset = 0x15         ; LUT Control 3 B
.equ CCL_LUT3CTRLC_offset = 0x16         ; LUT Control 3 C
.equ CCL_TRUTH3_offset = 0x17            ; Truth 3

;*************************************************************************
;** CLKCTRL - Clock controller
;*************************************************************************
.equ CLKCTRL_MCLKCTRLA_offset = 0x00     ; MCLK Control A
.equ CLKCTRL_MCLKCTRLB_offset = 0x01     ; MCLK Control B
.equ CLKCTRL_MCLKLOCK_offset = 0x02      ; MCLK Lock
.equ CLKCTRL_MCLKSTATUS_offset = 0x03    ; MCLK Status
.equ CLKCTRL_OSC20MCTRLA_offset = 0x10   ; OSC20M Control A
.equ CLKCTRL_OSC20MCALIBA_offset = 0x11  ; OSC20M Calibration A
.equ CLKCTRL_OSC20MCALIBB_offset = 0x12  ; OSC20M Calibration B
.equ CLKCTRL_OSC32KCTRLA_offset = 0x18   ; OSC32K Control A
.equ CLKCTRL_XOSC32KCTRLA_offset = 0x1C  ; XOSC32K Control A

;*************************************************************************
;** CPU - CPU
;*************************************************************************
.equ CPU_CCP_offset = 0x04               ; Configuration Change Protection
.equ CPU_SPL_offset = 0x0D               ; Stack Pointer Low
.equ CPU_SPH_offset = 0x0E               ; Stack Pointer High
.equ CPU_SREG_offset = 0x0F              ; Status Register

;*************************************************************************
;** CPUINT - Interrupt Controller
;*************************************************************************
.equ CPUINT_CTRLA_offset = 0x00          ; Control A
.equ CPUINT_STATUS_offset = 0x01         ; Status
.equ CPUINT_LVL0PRI_offset = 0x02        ; Interrupt Level 0 Priority
.equ CPUINT_LVL1VEC_offset = 0x03        ; Interrupt Level 1 Priority Vector

;*************************************************************************
;** CRCSCAN - CRCSCAN
;*************************************************************************
.equ CRCSCAN_CTRLA_offset = 0x00         ; Control A
.equ CRCSCAN_CTRLB_offset = 0x01         ; Control B
.equ CRCSCAN_STATUS_offset = 0x02        ; Status

;*************************************************************************
;** EVSYS - Event System
;*************************************************************************
.equ EVSYS_STROBE_offset = 0x00          ; Channel Strobe
.equ EVSYS_CHANNEL0_offset = 0x10        ; Multiplexer Channel 0
.equ EVSYS_CHANNEL1_offset = 0x11        ; Multiplexer Channel 1
.equ EVSYS_CHANNEL2_offset = 0x12        ; Multiplexer Channel 2
.equ EVSYS_CHANNEL3_offset = 0x13        ; Multiplexer Channel 3
.equ EVSYS_CHANNEL4_offset = 0x14        ; Multiplexer Channel 4
.equ EVSYS_CHANNEL5_offset = 0x15        ; Multiplexer Channel 5
.equ EVSYS_CHANNEL6_offset = 0x16        ; Multiplexer Channel 6
.equ EVSYS_CHANNEL7_offset = 0x17        ; Multiplexer Channel 7
.equ EVSYS_USERCCLLUT0A_offset = 0x20    ; User CCL LUT0 Event A
.equ EVSYS_USERCCLLUT0B_offset = 0x21    ; User CCL LUT0 Event B
.equ EVSYS_USERCCLLUT1A_offset = 0x22    ; User CCL LUT1 Event A
.equ EVSYS_USERCCLLUT1B_offset = 0x23    ; User CCL LUT1 Event B
.equ EVSYS_USERCCLLUT2A_offset = 0x24    ; User CCL LUT2 Event A
.equ EVSYS_USERCCLLUT2B_offset = 0x25    ; User CCL LUT2 Event B
.equ EVSYS_USERCCLLUT3A_offset = 0x26    ; User CCL LUT3 Event A
.equ EVSYS_USERCCLLUT3B_offset = 0x27    ; User CCL LUT3 Event B
.equ EVSYS_USERADC0_offset = 0x28        ; User ADC0
.equ EVSYS_USEREVOUTA_offset = 0x29      ; User EVOUT Port A
.equ EVSYS_USEREVOUTB_offset = 0x2A      ; User EVOUT Port B
.equ EVSYS_USEREVOUTC_offset = 0x2B      ; User EVOUT Port C
.equ EVSYS_USEREVOUTD_offset = 0x2C      ; User EVOUT Port D
.equ EVSYS_USEREVOUTE_offset = 0x2D      ; User EVOUT Port E
.equ EVSYS_USEREVOUTF_offset = 0x2E      ; User EVOUT Port F
.equ EVSYS_USERUSART0_offset = 0x2F      ; User USART0
.equ EVSYS_USERUSART1_offset = 0x30      ; User USART1
.equ EVSYS_USERUSART2_offset = 0x31      ; User USART2
.equ EVSYS_USERUSART3_offset = 0x32      ; User USART3
.equ EVSYS_USERTCA0_offset = 0x33        ; User TCA0
.equ EVSYS_USERTCB0_offset = 0x34        ; User TCB0
.equ EVSYS_USERTCB1_offset = 0x35        ; User TCB1
.equ EVSYS_USERTCB2_offset = 0x36        ; User TCB2
.equ EVSYS_USERTCB3_offset = 0x37        ; User TCB3

;*************************************************************************
;** FUSE - Fuses
;*************************************************************************
.equ FUSE_WDTCFG_offset = 0x00           ; Watchdog Configuration
.equ FUSE_BODCFG_offset = 0x01           ; BOD Configuration
.equ FUSE_OSCCFG_offset = 0x02           ; Oscillator Configuration
.equ FUSE_SYSCFG0_offset = 0x05          ; System Configuration 0
.equ FUSE_SYSCFG1_offset = 0x06          ; System Configuration 1
.equ FUSE_APPEND_offset = 0x07           ; Application Code Section End
.equ FUSE_BOOTEND_offset = 0x08          ; Boot Section End

;*************************************************************************
;** GPIO - General Purpose IO
;*************************************************************************
.equ GPIO_GPIOR0_offset = 0x00           ; General Purpose IO Register 0
.equ GPIO_GPIOR1_offset = 0x01           ; General Purpose IO Register 1
.equ GPIO_GPIOR2_offset = 0x02           ; General Purpose IO Register 2
.equ GPIO_GPIOR3_offset = 0x03           ; General Purpose IO Register 3

;*************************************************************************
;** LOCKBIT - Lockbit
;*************************************************************************
.equ LOCKBIT_LOCKBIT_offset = 0x00       ; Lock Bits

;*************************************************************************
;** NVMCTRL - Non-volatile Memory Controller
;*************************************************************************
.equ NVMCTRL_CTRLA_offset = 0x00         ; Control A
.equ NVMCTRL_CTRLB_offset = 0x01         ; Control B
.equ NVMCTRL_STATUS_offset = 0x02        ; Status
.equ NVMCTRL_INTCTRL_offset = 0x03       ; Interrupt Control
.equ NVMCTRL_INTFLAGS_offset = 0x04      ; Interrupt Flags
.equ NVMCTRL_DATA_offset = 0x06          ; Data
.equ NVMCTRL_ADDR_offset = 0x08          ; Address

;*************************************************************************
;** PORT - I/O Ports
;*************************************************************************
.equ PORT_DIR_offset = 0x00              ; Data Direction
.equ PORT_DIRSET_offset = 0x01           ; Data Direction Set
.equ PORT_DIRCLR_offset = 0x02           ; Data Direction Clear
.equ PORT_DIRTGL_offset = 0x03           ; Data Direction Toggle
.equ PORT_OUT_offset = 0x04              ; Output Value
.equ PORT_OUTSET_offset = 0x05           ; Output Value Set
.equ PORT_OUTCLR_offset = 0x06           ; Output Value Clear
.equ PORT_OUTTGL_offset = 0x07           ; Output Value Toggle
.equ PORT_IN_offset = 0x08               ; Input Value
.equ PORT_INTFLAGS_offset = 0x09         ; Interrupt Flags
.equ PORT_PORTCTRL_offset = 0x0A         ; Port Control
.equ PORT_PIN0CTRL_offset = 0x10         ; Pin 0 Control
.equ PORT_PIN1CTRL_offset = 0x11         ; Pin 1 Control
.equ PORT_PIN2CTRL_offset = 0x12         ; Pin 2 Control
.equ PORT_PIN3CTRL_offset = 0x13         ; Pin 3 Control
.equ PORT_PIN4CTRL_offset = 0x14         ; Pin 4 Control
.equ PORT_PIN5CTRL_offset = 0x15         ; Pin 5 Control
.equ PORT_PIN6CTRL_offset = 0x16         ; Pin 6 Control
.equ PORT_PIN7CTRL_offset = 0x17         ; Pin 7 Control

;*************************************************************************
;** PORTMUX - Port Multiplexer
;*************************************************************************
.equ PORTMUX_EVSYSROUTEA_offset = 0x00   ; Port Multiplexer EVSYS
.equ PORTMUX_CCLROUTEA_offset = 0x01     ; Port Multiplexer CCL
.equ PORTMUX_USARTROUTEA_offset = 0x02   ; Port Multiplexer USART register A
.equ PORTMUX_TWISPIROUTEA_offset = 0x03  ; Port Multiplexer TWI and SPI
.equ PORTMUX_TCAROUTEA_offset = 0x04     ; Port Multiplexer TCA
.equ PORTMUX_TCBROUTEA_offset = 0x05     ; Port Multiplexer TCB

;*************************************************************************
;** RSTCTRL - Reset controller
;*************************************************************************
.equ RSTCTRL_RSTFR_offset = 0x00         ; Reset Flags
.equ RSTCTRL_SWRR_offset = 0x01          ; Software Reset

;*************************************************************************
;** RTC - Real-Time Counter
;*************************************************************************
.equ RTC_CTRLA_offset = 0x00             ; Control A
.equ RTC_STATUS_offset = 0x01            ; Status
.equ RTC_INTCTRL_offset = 0x02           ; Interrupt Control
.equ RTC_INTFLAGS_offset = 0x03          ; Interrupt Flags
.equ RTC_TEMP_offset = 0x04              ; Temporary
.equ RTC_DBGCTRL_offset = 0x05           ; Debug control
.equ RTC_CALIB_offset = 0x06             ; Calibration
.equ RTC_CLKSEL_offset = 0x07            ; Clock Select
.equ RTC_CNT_offset = 0x08               ; Counter
.equ RTC_PER_offset = 0x0A               ; Period
.equ RTC_CMP_offset = 0x0C               ; Compare
.equ RTC_PITCTRLA_offset = 0x10          ; PIT Control A
.equ RTC_PITSTATUS_offset = 0x11         ; PIT Status
.equ RTC_PITINTCTRL_offset = 0x12        ; PIT Interrupt Control
.equ RTC_PITINTFLAGS_offset = 0x13       ; PIT Interrupt Flags
.equ RTC_PITDBGCTRL_offset = 0x15        ; PIT Debug control

;*************************************************************************
;** SIGROW - Signature row
;*************************************************************************
.equ SIGROW_DEVICEID0_offset = 0x00      ; Device ID Byte 0
.equ SIGROW_DEVICEID1_offset = 0x01      ; Device ID Byte 1
.equ SIGROW_DEVICEID2_offset = 0x02      ; Device ID Byte 2
.equ SIGROW_SERNUM0_offset = 0x03        ; Serial Number Byte 0
.equ SIGROW_SERNUM1_offset = 0x04        ; Serial Number Byte 1
.equ SIGROW_SERNUM2_offset = 0x05        ; Serial Number Byte 2
.equ SIGROW_SERNUM3_offset = 0x06        ; Serial Number Byte 3
.equ SIGROW_SERNUM4_offset = 0x07        ; Serial Number Byte 4
.equ SIGROW_SERNUM5_offset = 0x08        ; Serial Number Byte 5
.equ SIGROW_SERNUM6_offset = 0x09        ; Serial Number Byte 6
.equ SIGROW_SERNUM7_offset = 0x0A        ; Serial Number Byte 7
.equ SIGROW_SERNUM8_offset = 0x0B        ; Serial Number Byte 8
.equ SIGROW_SERNUM9_offset = 0x0C        ; Serial Number Byte 9
.equ SIGROW_OSCCAL32K_offset = 0x14      ; Oscillator Calibration for 32kHz ULP
.equ SIGROW_OSCCAL16M0_offset = 0x18     ; Oscillator Calibration 16 MHz Byte 0
.equ SIGROW_OSCCAL16M1_offset = 0x19     ; Oscillator Calibration 16 MHz Byte 1
.equ SIGROW_OSCCAL20M0_offset = 0x1A     ; Oscillator Calibration 20 MHz Byte 0
.equ SIGROW_OSCCAL20M1_offset = 0x1B     ; Oscillator Calibration 20 MHz Byte 1
.equ SIGROW_TEMPSENSE0_offset = 0x20     ; Temperature Sensor Calibration Byte 0
.equ SIGROW_TEMPSENSE1_offset = 0x21     ; Temperature Sensor Calibration Byte 1
.equ SIGROW_OSC16ERR3V_offset = 0x22     ; OSC16 error at 3V
.equ SIGROW_OSC16ERR5V_offset = 0x23     ; OSC16 error at 5V
.equ SIGROW_OSC20ERR3V_offset = 0x24     ; OSC20 error at 3V
.equ SIGROW_OSC20ERR5V_offset = 0x25     ; OSC20 error at 5V
.equ SIGROW_CHECKSUM1_offset = 0x2F      ; CRC Checksum Byte 1

;*************************************************************************
;** SLPCTRL - Sleep Controller
;*************************************************************************
.equ SLPCTRL_CTRLA_offset = 0x00         ; Control

;*************************************************************************
;** SPI - Serial Peripheral Interface
;*************************************************************************
.equ SPI_CTRLA_offset = 0x00             ; Control A
.equ SPI_CTRLB_offset = 0x01             ; Control B
.equ SPI_INTCTRL_offset = 0x02           ; Interrupt Control
.equ SPI_INTFLAGS_offset = 0x03          ; Interrupt Flags
.equ SPI_DATA_offset = 0x04              ; Data

;*************************************************************************
;** SYSCFG - System Configuration Registers
;*************************************************************************
.equ SYSCFG_REVID_offset = 0x01          ; Revision ID
.equ SYSCFG_EXTBRK_offset = 0x02         ; External Break
.equ SYSCFG_OCDM_offset = 0x18           ; OCD Message Register
.equ SYSCFG_OCDMS_offset = 0x19          ; OCD Message Status

;*************************************************************************
;** TCA - 16-bit Timer/Counter Type A
;*************************************************************************
.equ TCA_SINGLE_CTRLA_offset = 0x00      ; Control A
.equ TCA_SINGLE_CTRLB_offset = 0x01      ; Control B
.equ TCA_SINGLE_CTRLC_offset = 0x02      ; Control C
.equ TCA_SINGLE_CTRLD_offset = 0x03      ; Control D
.equ TCA_SINGLE_CTRLECLR_offset = 0x04   ; Control E Clear
.equ TCA_SINGLE_CTRLESET_offset = 0x05   ; Control E Set
.equ TCA_SINGLE_CTRLFCLR_offset = 0x06   ; Control F Clear
.equ TCA_SINGLE_CTRLFSET_offset = 0x07   ; Control F Set
.equ TCA_SINGLE_EVCTRL_offset = 0x09     ; Event Control
.equ TCA_SINGLE_INTCTRL_offset = 0x0A    ; Interrupt Control
.equ TCA_SINGLE_INTFLAGS_offset = 0x0B   ; Interrupt Flags
.equ TCA_SINGLE_DBGCTRL_offset = 0x0E    ; Degbug Control
.equ TCA_SINGLE_TEMP_offset = 0x0F       ; Temporary data for 16-bit Access
.equ TCA_SINGLE_CNT_offset = 0x20        ; Count
.equ TCA_SINGLE_PER_offset = 0x26        ; Period
.equ TCA_SINGLE_CMP0_offset = 0x28       ; Compare 0
.equ TCA_SINGLE_CMP1_offset = 0x2A       ; Compare 1
.equ TCA_SINGLE_CMP2_offset = 0x2C       ; Compare 2
.equ TCA_SINGLE_PERBUF_offset = 0x36     ; Period Buffer
.equ TCA_SINGLE_CMP0BUF_offset = 0x38    ; Compare 0 Buffer
.equ TCA_SINGLE_CMP1BUF_offset = 0x3A    ; Compare 1 Buffer
.equ TCA_SINGLE_CMP2BUF_offset = 0x3C    ; Compare 2 Buffer
.equ TCA_SPLIT_CTRLA_offset = 0x00       ; Control A
.equ TCA_SPLIT_CTRLB_offset = 0x01       ; Control B
.equ TCA_SPLIT_CTRLC_offset = 0x02       ; Control C
.equ TCA_SPLIT_CTRLD_offset = 0x03       ; Control D
.equ TCA_SPLIT_CTRLECLR_offset = 0x04    ; Control E Clear
.equ TCA_SPLIT_CTRLESET_offset = 0x05    ; Control E Set
.equ TCA_SPLIT_INTCTRL_offset = 0x0A     ; Interrupt Control
.equ TCA_SPLIT_INTFLAGS_offset = 0x0B    ; Interrupt Flags
.equ TCA_SPLIT_DBGCTRL_offset = 0x0E     ; Degbug Control
.equ TCA_SPLIT_LCNT_offset = 0x20        ; Low Count
.equ TCA_SPLIT_HCNT_offset = 0x21        ; High Count
.equ TCA_SPLIT_LPER_offset = 0x26        ; Low Period
.equ TCA_SPLIT_HPER_offset = 0x27        ; High Period
.equ TCA_SPLIT_LCMP0_offset = 0x28       ; Low Compare
.equ TCA_SPLIT_HCMP0_offset = 0x29       ; High Compare
.equ TCA_SPLIT_LCMP1_offset = 0x2A       ; Low Compare
.equ TCA_SPLIT_HCMP1_offset = 0x2B       ; High Compare
.equ TCA_SPLIT_LCMP2_offset = 0x2C       ; Low Compare
.equ TCA_SPLIT_HCMP2_offset = 0x2D       ; High Compare
.equ TCA_SINGLE_offset = 0x00            ; 
.equ TCA_SPLIT_offset = 0x00             ; 

;*************************************************************************
;** TCB - 16-bit Timer Type B
;*************************************************************************
.equ TCB_CTRLA_offset = 0x00             ; Control A
.equ TCB_CTRLB_offset = 0x01             ; Control Register B
.equ TCB_EVCTRL_offset = 0x04            ; Event Control
.equ TCB_INTCTRL_offset = 0x05           ; Interrupt Control
.equ TCB_INTFLAGS_offset = 0x06          ; Interrupt Flags
.equ TCB_STATUS_offset = 0x07            ; Status
.equ TCB_DBGCTRL_offset = 0x08           ; Debug Control
.equ TCB_TEMP_offset = 0x09              ; Temporary Value
.equ TCB_CNT_offset = 0x0A               ; Count
.equ TCB_CCMP_offset = 0x0C              ; Compare or Capture

;*************************************************************************
;** TWI - Two-Wire Interface
;*************************************************************************
.equ TWI_CTRLA_offset = 0x00             ; Control A
.equ TWI_DUALCTRL_offset = 0x01          ; Dual Control
.equ TWI_DBGCTRL_offset = 0x02           ; Debug Control Register
.equ TWI_MCTRLA_offset = 0x03            ; Master Control A
.equ TWI_MCTRLB_offset = 0x04            ; Master Control B
.equ TWI_MSTATUS_offset = 0x05           ; Master Status
.equ TWI_MBAUD_offset = 0x06             ; Master Baurd Rate Control
.equ TWI_MADDR_offset = 0x07             ; Master Address
.equ TWI_MDATA_offset = 0x08             ; Master Data
.equ TWI_SCTRLA_offset = 0x09            ; Slave Control A
.equ TWI_SCTRLB_offset = 0x0A            ; Slave Control B
.equ TWI_SSTATUS_offset = 0x0B           ; Slave Status
.equ TWI_SADDR_offset = 0x0C             ; Slave Address
.equ TWI_SDATA_offset = 0x0D             ; Slave Data
.equ TWI_SADDRMASK_offset = 0x0E         ; Slave Address Mask

;*************************************************************************
;** USART - Universal Synchronous and Asynchronous Receiver and Transmitter
;*************************************************************************
.equ USART_RXDATAL_offset = 0x00         ; Receive Data Low Byte
.equ USART_RXDATAH_offset = 0x01         ; Receive Data High Byte
.equ USART_TXDATAL_offset = 0x02         ; Transmit Data Low Byte
.equ USART_TXDATAH_offset = 0x03         ; Transmit Data High Byte
.equ USART_STATUS_offset = 0x04          ; Status
.equ USART_CTRLA_offset = 0x05           ; Control A
.equ USART_CTRLB_offset = 0x06           ; Control B
.equ USART_CTRLC_offset = 0x07           ; Control C
.equ USART_BAUD_offset = 0x08            ; Baud Rate
.equ USART_CTRLD_offset = 0x0A           ; Control D
.equ USART_DBGCTRL_offset = 0x0B         ; Debug Control
.equ USART_EVCTRL_offset = 0x0C          ; Event Control
.equ USART_TXPLCTRL_offset = 0x0D        ; IRCOM Transmitter Pulse Length Control
.equ USART_RXPLCTRL_offset = 0x0E        ; IRCOM Receiver Pulse Length Control

;*************************************************************************
;** USERROW - User Row
;*************************************************************************
.equ USERROW_USERROW0_offset = 0x00      ; User Row Byte 0
.equ USERROW_USERROW1_offset = 0x01      ; User Row Byte 1
.equ USERROW_USERROW2_offset = 0x02      ; User Row Byte 2
.equ USERROW_USERROW3_offset = 0x03      ; User Row Byte 3
.equ USERROW_USERROW4_offset = 0x04      ; User Row Byte 4
.equ USERROW_USERROW5_offset = 0x05      ; User Row Byte 5
.equ USERROW_USERROW6_offset = 0x06      ; User Row Byte 6
.equ USERROW_USERROW7_offset = 0x07      ; User Row Byte 7
.equ USERROW_USERROW8_offset = 0x08      ; User Row Byte 8
.equ USERROW_USERROW9_offset = 0x09      ; User Row Byte 9
.equ USERROW_USERROW10_offset = 0x0A     ; User Row Byte 10
.equ USERROW_USERROW11_offset = 0x0B     ; User Row Byte 11
.equ USERROW_USERROW12_offset = 0x0C     ; User Row Byte 12
.equ USERROW_USERROW13_offset = 0x0D     ; User Row Byte 13
.equ USERROW_USERROW14_offset = 0x0E     ; User Row Byte 14
.equ USERROW_USERROW15_offset = 0x0F     ; User Row Byte 15
.equ USERROW_USERROW16_offset = 0x10     ; User Row Byte 16
.equ USERROW_USERROW17_offset = 0x11     ; User Row Byte 17
.equ USERROW_USERROW18_offset = 0x12     ; User Row Byte 18
.equ USERROW_USERROW19_offset = 0x13     ; User Row Byte 19
.equ USERROW_USERROW20_offset = 0x14     ; User Row Byte 20
.equ USERROW_USERROW21_offset = 0x15     ; User Row Byte 21
.equ USERROW_USERROW22_offset = 0x16     ; User Row Byte 22
.equ USERROW_USERROW23_offset = 0x17     ; User Row Byte 23
.equ USERROW_USERROW24_offset = 0x18     ; User Row Byte 24
.equ USERROW_USERROW25_offset = 0x19     ; User Row Byte 25
.equ USERROW_USERROW26_offset = 0x1A     ; User Row Byte 26
.equ USERROW_USERROW27_offset = 0x1B     ; User Row Byte 27
.equ USERROW_USERROW28_offset = 0x1C     ; User Row Byte 28
.equ USERROW_USERROW29_offset = 0x1D     ; User Row Byte 29
.equ USERROW_USERROW30_offset = 0x1E     ; User Row Byte 30
.equ USERROW_USERROW31_offset = 0x1F     ; User Row Byte 31
.equ USERROW_USERROW32_offset = 0x20     ; User Row Byte 32
.equ USERROW_USERROW33_offset = 0x21     ; User Row Byte 33
.equ USERROW_USERROW34_offset = 0x22     ; User Row Byte 34
.equ USERROW_USERROW35_offset = 0x23     ; User Row Byte 35
.equ USERROW_USERROW36_offset = 0x24     ; User Row Byte 36
.equ USERROW_USERROW37_offset = 0x25     ; User Row Byte 37
.equ USERROW_USERROW38_offset = 0x26     ; User Row Byte 38
.equ USERROW_USERROW39_offset = 0x27     ; User Row Byte 39
.equ USERROW_USERROW40_offset = 0x28     ; User Row Byte 40
.equ USERROW_USERROW41_offset = 0x29     ; User Row Byte 41
.equ USERROW_USERROW42_offset = 0x2A     ; User Row Byte 42
.equ USERROW_USERROW43_offset = 0x2B     ; User Row Byte 43
.equ USERROW_USERROW44_offset = 0x2C     ; User Row Byte 44
.equ USERROW_USERROW45_offset = 0x2D     ; User Row Byte 45
.equ USERROW_USERROW46_offset = 0x2E     ; User Row Byte 46
.equ USERROW_USERROW47_offset = 0x2F     ; User Row Byte 47
.equ USERROW_USERROW48_offset = 0x30     ; User Row Byte 48
.equ USERROW_USERROW49_offset = 0x31     ; User Row Byte 49
.equ USERROW_USERROW50_offset = 0x32     ; User Row Byte 50
.equ USERROW_USERROW51_offset = 0x33     ; User Row Byte 51
.equ USERROW_USERROW52_offset = 0x34     ; User Row Byte 52
.equ USERROW_USERROW53_offset = 0x35     ; User Row Byte 53
.equ USERROW_USERROW54_offset = 0x36     ; User Row Byte 54
.equ USERROW_USERROW55_offset = 0x37     ; User Row Byte 55
.equ USERROW_USERROW56_offset = 0x38     ; User Row Byte 56
.equ USERROW_USERROW57_offset = 0x39     ; User Row Byte 57
.equ USERROW_USERROW58_offset = 0x3A     ; User Row Byte 58
.equ USERROW_USERROW59_offset = 0x3B     ; User Row Byte 59
.equ USERROW_USERROW60_offset = 0x3C     ; User Row Byte 60
.equ USERROW_USERROW61_offset = 0x3D     ; User Row Byte 61
.equ USERROW_USERROW62_offset = 0x3E     ; User Row Byte 62
.equ USERROW_USERROW63_offset = 0x3F     ; User Row Byte 63

;*************************************************************************
;** VPORT - Virtual Ports
;*************************************************************************
.equ VPORT_DIR_offset = 0x00             ; Data Direction
.equ VPORT_OUT_offset = 0x01             ; Output Value
.equ VPORT_IN_offset = 0x02              ; Input Value
.equ VPORT_INTFLAGS_offset = 0x03        ; Interrupt Flags

;*************************************************************************
;** VREF - Voltage reference
;*************************************************************************
.equ VREF_CTRLA_offset = 0x00            ; Control A
.equ VREF_CTRLB_offset = 0x01            ; Control B

;*************************************************************************
;** WDT - Watch-Dog Timer
;*************************************************************************
.equ WDT_CTRLA_offset = 0x00             ; Control A
.equ WDT_STATUS_offset = 0x01            ; Status


; ***** LOCKBIT REGISTER LOCATIONS ***************************************




; ***** FUSE REGISTER LOCATIONS ******************************************




; ***** BIT AND VALUE DEFINITIONS ****************************************


;*************************************************************************
;** AC - Analog Comparator
;*************************************************************************

; AC_CTRLA masks
.equ AC_ENABLE_bm = 0x01                 ; Enable bit mask
.equ AC_ENABLE_bp = 0                    ; Enable bit position
.equ AC_HYSMODE_gm = 0x06                ; Hysteresis Mode group mask
.equ AC_HYSMODE_gp = 1                   ; Hysteresis Mode group position
.equ AC_HYSMODE0_bm = (1<<1)             ; Hysteresis Mode bit 0 mask
.equ AC_HYSMODE0_bp = 1                  ; Hysteresis Mode bit 0 position
.equ AC_HYSMODE1_bm = (1<<2)             ; Hysteresis Mode bit 1 mask
.equ AC_HYSMODE1_bp = 2                  ; Hysteresis Mode bit 1 position
.equ AC_INTMODE_gm = 0x30                ; Interrupt Mode group mask
.equ AC_INTMODE_gp = 4                   ; Interrupt Mode group position
.equ AC_INTMODE0_bm = (1<<4)             ; Interrupt Mode bit 0 mask
.equ AC_INTMODE0_bp = 4                  ; Interrupt Mode bit 0 position
.equ AC_INTMODE1_bm = (1<<5)             ; Interrupt Mode bit 1 mask
.equ AC_INTMODE1_bp = 5                  ; Interrupt Mode bit 1 position
.equ AC_LPMODE_bm = 0x08                 ; Low Power Mode bit mask
.equ AC_LPMODE_bp = 3                    ; Low Power Mode bit position
.equ AC_OUTEN_bm = 0x40                  ; Output Buffer Enable bit mask
.equ AC_OUTEN_bp = 6                     ; Output Buffer Enable bit position
.equ AC_RUNSTDBY_bm = 0x80               ; Run in Standby Mode bit mask
.equ AC_RUNSTDBY_bp = 7                  ; Run in Standby Mode bit position

; AC_DACREF masks
.equ AC_DATA_gm = 0xFF                   ; DAC voltage reference group mask
.equ AC_DATA_gp = 0                      ; DAC voltage reference group position
.equ AC_DATA0_bm = (1<<0)                ; DAC voltage reference bit 0 mask
.equ AC_DATA0_bp = 0                     ; DAC voltage reference bit 0 position
.equ AC_DATA1_bm = (1<<1)                ; DAC voltage reference bit 1 mask
.equ AC_DATA1_bp = 1                     ; DAC voltage reference bit 1 position
.equ AC_DATA2_bm = (1<<2)                ; DAC voltage reference bit 2 mask
.equ AC_DATA2_bp = 2                     ; DAC voltage reference bit 2 position
.equ AC_DATA3_bm = (1<<3)                ; DAC voltage reference bit 3 mask
.equ AC_DATA3_bp = 3                     ; DAC voltage reference bit 3 position
.equ AC_DATA4_bm = (1<<4)                ; DAC voltage reference bit 4 mask
.equ AC_DATA4_bp = 4                     ; DAC voltage reference bit 4 position
.equ AC_DATA5_bm = (1<<5)                ; DAC voltage reference bit 5 mask
.equ AC_DATA5_bp = 5                     ; DAC voltage reference bit 5 position
.equ AC_DATA6_bm = (1<<6)                ; DAC voltage reference bit 6 mask
.equ AC_DATA6_bp = 6                     ; DAC voltage reference bit 6 position
.equ AC_DATA7_bm = (1<<7)                ; DAC voltage reference bit 7 mask
.equ AC_DATA7_bp = 7                     ; DAC voltage reference bit 7 position

; AC_INTCTRL masks
.equ AC_CMP_bm = 0x01                    ; Analog Comparator 0 Interrupt Enable bit mask
.equ AC_CMP_bp = 0                       ; Analog Comparator 0 Interrupt Enable bit position

; AC_MUXCTRLA masks
.equ AC_INVERT_bm = 0x80                 ; Invert AC Output bit mask
.equ AC_INVERT_bp = 7                    ; Invert AC Output bit position
.equ AC_MUXNEG_gm = 0x03                 ; Negative Input MUX Selection group mask
.equ AC_MUXNEG_gp = 0                    ; Negative Input MUX Selection group position
.equ AC_MUXNEG0_bm = (1<<0)              ; Negative Input MUX Selection bit 0 mask
.equ AC_MUXNEG0_bp = 0                   ; Negative Input MUX Selection bit 0 position
.equ AC_MUXNEG1_bm = (1<<1)              ; Negative Input MUX Selection bit 1 mask
.equ AC_MUXNEG1_bp = 1                   ; Negative Input MUX Selection bit 1 position
.equ AC_MUXPOS_gm = 0x18                 ; Positive Input MUX Selection group mask
.equ AC_MUXPOS_gp = 3                    ; Positive Input MUX Selection group position
.equ AC_MUXPOS0_bm = (1<<3)              ; Positive Input MUX Selection bit 0 mask
.equ AC_MUXPOS0_bp = 3                   ; Positive Input MUX Selection bit 0 position
.equ AC_MUXPOS1_bm = (1<<4)              ; Positive Input MUX Selection bit 1 mask
.equ AC_MUXPOS1_bp = 4                   ; Positive Input MUX Selection bit 1 position

; AC_STATUS masks
; Masks for AC_CMP already defined
.equ AC_STATE_bm = 0x10                  ; Analog Comparator State bit mask
.equ AC_STATE_bp = 4                     ; Analog Comparator State bit position

; Hysteresis Mode select
.equ AC_HYSMODE_OFF_gc = (0x00<<1)       ; No hysteresis
.equ AC_HYSMODE_10mV_gc = (0x01<<1)      ; 10mV hysteresis
.equ AC_HYSMODE_25mV_gc = (0x02<<1)      ; 25mV hysteresis
.equ AC_HYSMODE_50mV_gc = (0x03<<1)      ; 50mV hysteresis

; Interrupt Mode select
.equ AC_INTMODE_BOTHEDGE_gc = (0x00<<4)  ; Any Edge
.equ AC_INTMODE_NEGEDGE_gc = (0x02<<4)   ; Negative Edge
.equ AC_INTMODE_POSEDGE_gc = (0x03<<4)   ; Positive Edge

; Low Power Mode select
.equ AC_LPMODE_DIS_gc = (0x00<<3)        ; Low power mode disabled
.equ AC_LPMODE_EN_gc = (0x01<<3)         ; Low power mode enabled

; Negative Input MUX Selection select
.equ AC_MUXNEG_PIN0_gc = (0x00<<0)       ; Negative Pin 0
.equ AC_MUXNEG_PIN1_gc = (0x01<<0)       ; Negative Pin 1
.equ AC_MUXNEG_PIN2_gc = (0x02<<0)       ; Negative Pin 2
.equ AC_MUXNEG_DACREF_gc = (0x03<<0)     ; DAC Voltage Reference

; Positive Input MUX Selection select
.equ AC_MUXPOS_PIN0_gc = (0x00<<3)       ; Positive Pin 0
.equ AC_MUXPOS_PIN1_gc = (0x01<<3)       ; Positive Pin 1
.equ AC_MUXPOS_PIN2_gc = (0x02<<3)       ; Positive Pin 2
.equ AC_MUXPOS_PIN3_gc = (0x03<<3)       ; Positive Pin 3


;*************************************************************************
;** ADC - Analog to Digital Converter
;*************************************************************************

; ADC_CALIB masks
.equ ADC_DUTYCYC_bm = 0x01               ; Duty Cycle bit mask
.equ ADC_DUTYCYC_bp = 0                  ; Duty Cycle bit position

; ADC_COMMAND masks
.equ ADC_STCONV_bm = 0x01                ; Start Conversion Operation bit mask
.equ ADC_STCONV_bp = 0                   ; Start Conversion Operation bit position

; ADC_CTRLA masks
.equ ADC_ENABLE_bm = 0x01                ; ADC Enable bit mask
.equ ADC_ENABLE_bp = 0                   ; ADC Enable bit position
.equ ADC_FREERUN_bm = 0x02               ; ADC Freerun mode bit mask
.equ ADC_FREERUN_bp = 1                  ; ADC Freerun mode bit position
.equ ADC_RESSEL_bm = 0x04                ; ADC Resolution bit mask
.equ ADC_RESSEL_bp = 2                   ; ADC Resolution bit position
.equ ADC_RUNSTBY_bm = 0x80               ; Run standby mode bit mask
.equ ADC_RUNSTBY_bp = 7                  ; Run standby mode bit position

; ADC_CTRLB masks
.equ ADC_SAMPNUM_gm = 0x07               ; Accumulation Samples group mask
.equ ADC_SAMPNUM_gp = 0                  ; Accumulation Samples group position
.equ ADC_SAMPNUM0_bm = (1<<0)            ; Accumulation Samples bit 0 mask
.equ ADC_SAMPNUM0_bp = 0                 ; Accumulation Samples bit 0 position
.equ ADC_SAMPNUM1_bm = (1<<1)            ; Accumulation Samples bit 1 mask
.equ ADC_SAMPNUM1_bp = 1                 ; Accumulation Samples bit 1 position
.equ ADC_SAMPNUM2_bm = (1<<2)            ; Accumulation Samples bit 2 mask
.equ ADC_SAMPNUM2_bp = 2                 ; Accumulation Samples bit 2 position

; ADC_CTRLC masks
.equ ADC_PRESC_gm = 0x07                 ; Clock Pre-scaler group mask
.equ ADC_PRESC_gp = 0                    ; Clock Pre-scaler group position
.equ ADC_PRESC0_bm = (1<<0)              ; Clock Pre-scaler bit 0 mask
.equ ADC_PRESC0_bp = 0                   ; Clock Pre-scaler bit 0 position
.equ ADC_PRESC1_bm = (1<<1)              ; Clock Pre-scaler bit 1 mask
.equ ADC_PRESC1_bp = 1                   ; Clock Pre-scaler bit 1 position
.equ ADC_PRESC2_bm = (1<<2)              ; Clock Pre-scaler bit 2 mask
.equ ADC_PRESC2_bp = 2                   ; Clock Pre-scaler bit 2 position
.equ ADC_REFSEL_gm = 0x30                ; Reference Selection group mask
.equ ADC_REFSEL_gp = 4                   ; Reference Selection group position
.equ ADC_REFSEL0_bm = (1<<4)             ; Reference Selection bit 0 mask
.equ ADC_REFSEL0_bp = 4                  ; Reference Selection bit 0 position
.equ ADC_REFSEL1_bm = (1<<5)             ; Reference Selection bit 1 mask
.equ ADC_REFSEL1_bp = 5                  ; Reference Selection bit 1 position
.equ ADC_SAMPCAP_bm = 0x40               ; Sample Capacitance Selection bit mask
.equ ADC_SAMPCAP_bp = 6                  ; Sample Capacitance Selection bit position

; ADC_CTRLD masks
.equ ADC_ASDV_bm = 0x10                  ; Automatic Sampling Delay Variation bit mask
.equ ADC_ASDV_bp = 4                     ; Automatic Sampling Delay Variation bit position
.equ ADC_INITDLY_gm = 0xE0               ; Initial Delay Selection group mask
.equ ADC_INITDLY_gp = 5                  ; Initial Delay Selection group position
.equ ADC_INITDLY0_bm = (1<<5)            ; Initial Delay Selection bit 0 mask
.equ ADC_INITDLY0_bp = 5                 ; Initial Delay Selection bit 0 position
.equ ADC_INITDLY1_bm = (1<<6)            ; Initial Delay Selection bit 1 mask
.equ ADC_INITDLY1_bp = 6                 ; Initial Delay Selection bit 1 position
.equ ADC_INITDLY2_bm = (1<<7)            ; Initial Delay Selection bit 2 mask
.equ ADC_INITDLY2_bp = 7                 ; Initial Delay Selection bit 2 position
.equ ADC_SAMPDLY_gm = 0x0F               ; Sampling Delay Selection group mask
.equ ADC_SAMPDLY_gp = 0                  ; Sampling Delay Selection group position
.equ ADC_SAMPDLY0_bm = (1<<0)            ; Sampling Delay Selection bit 0 mask
.equ ADC_SAMPDLY0_bp = 0                 ; Sampling Delay Selection bit 0 position
.equ ADC_SAMPDLY1_bm = (1<<1)            ; Sampling Delay Selection bit 1 mask
.equ ADC_SAMPDLY1_bp = 1                 ; Sampling Delay Selection bit 1 position
.equ ADC_SAMPDLY2_bm = (1<<2)            ; Sampling Delay Selection bit 2 mask
.equ ADC_SAMPDLY2_bp = 2                 ; Sampling Delay Selection bit 2 position
.equ ADC_SAMPDLY3_bm = (1<<3)            ; Sampling Delay Selection bit 3 mask
.equ ADC_SAMPDLY3_bp = 3                 ; Sampling Delay Selection bit 3 position

; ADC_CTRLE masks
.equ ADC_WINCM_gm = 0x07                 ; Window Comparator Mode group mask
.equ ADC_WINCM_gp = 0                    ; Window Comparator Mode group position
.equ ADC_WINCM0_bm = (1<<0)              ; Window Comparator Mode bit 0 mask
.equ ADC_WINCM0_bp = 0                   ; Window Comparator Mode bit 0 position
.equ ADC_WINCM1_bm = (1<<1)              ; Window Comparator Mode bit 1 mask
.equ ADC_WINCM1_bp = 1                   ; Window Comparator Mode bit 1 position
.equ ADC_WINCM2_bm = (1<<2)              ; Window Comparator Mode bit 2 mask
.equ ADC_WINCM2_bp = 2                   ; Window Comparator Mode bit 2 position

; ADC_DBGCTRL masks
.equ ADC_DBGRUN_bm = 0x01                ; Debug run bit mask
.equ ADC_DBGRUN_bp = 0                   ; Debug run bit position

; ADC_EVCTRL masks
.equ ADC_STARTEI_bm = 0x01               ; Start Event Input Enable bit mask
.equ ADC_STARTEI_bp = 0                  ; Start Event Input Enable bit position

; ADC_INTCTRL masks
.equ ADC_RESRDY_bm = 0x01                ; Result Ready Interrupt Enable bit mask
.equ ADC_RESRDY_bp = 0                   ; Result Ready Interrupt Enable bit position
.equ ADC_WCMP_bm = 0x02                  ; Window Comparator Interrupt Enable bit mask
.equ ADC_WCMP_bp = 1                     ; Window Comparator Interrupt Enable bit position

; ADC_INTFLAGS masks
; Masks for ADC_RESRDY already defined
; Masks for ADC_WCMP already defined

; ADC_MUXPOS masks
.equ ADC_MUXPOS_gm = 0x1F                ; Analog Channel Selection Bits group mask
.equ ADC_MUXPOS_gp = 0                   ; Analog Channel Selection Bits group position
.equ ADC_MUXPOS0_bm = (1<<0)             ; Analog Channel Selection Bits bit 0 mask
.equ ADC_MUXPOS0_bp = 0                  ; Analog Channel Selection Bits bit 0 position
.equ ADC_MUXPOS1_bm = (1<<1)             ; Analog Channel Selection Bits bit 1 mask
.equ ADC_MUXPOS1_bp = 1                  ; Analog Channel Selection Bits bit 1 position
.equ ADC_MUXPOS2_bm = (1<<2)             ; Analog Channel Selection Bits bit 2 mask
.equ ADC_MUXPOS2_bp = 2                  ; Analog Channel Selection Bits bit 2 position
.equ ADC_MUXPOS3_bm = (1<<3)             ; Analog Channel Selection Bits bit 3 mask
.equ ADC_MUXPOS3_bp = 3                  ; Analog Channel Selection Bits bit 3 position
.equ ADC_MUXPOS4_bm = (1<<4)             ; Analog Channel Selection Bits bit 4 mask
.equ ADC_MUXPOS4_bp = 4                  ; Analog Channel Selection Bits bit 4 position

; ADC_SAMPCTRL masks
.equ ADC_SAMPLEN_gm = 0x1F               ; Sample lenght group mask
.equ ADC_SAMPLEN_gp = 0                  ; Sample lenght group position
.equ ADC_SAMPLEN0_bm = (1<<0)            ; Sample lenght bit 0 mask
.equ ADC_SAMPLEN0_bp = 0                 ; Sample lenght bit 0 position
.equ ADC_SAMPLEN1_bm = (1<<1)            ; Sample lenght bit 1 mask
.equ ADC_SAMPLEN1_bp = 1                 ; Sample lenght bit 1 position
.equ ADC_SAMPLEN2_bm = (1<<2)            ; Sample lenght bit 2 mask
.equ ADC_SAMPLEN2_bp = 2                 ; Sample lenght bit 2 position
.equ ADC_SAMPLEN3_bm = (1<<3)            ; Sample lenght bit 3 mask
.equ ADC_SAMPLEN3_bp = 3                 ; Sample lenght bit 3 position
.equ ADC_SAMPLEN4_bm = (1<<4)            ; Sample lenght bit 4 mask
.equ ADC_SAMPLEN4_bp = 4                 ; Sample lenght bit 4 position

; ADC_TEMP masks
.equ ADC_TEMP_gm = 0xFF                  ; Temporary group mask
.equ ADC_TEMP_gp = 0                     ; Temporary group position
.equ ADC_TEMP0_bm = (1<<0)               ; Temporary bit 0 mask
.equ ADC_TEMP0_bp = 0                    ; Temporary bit 0 position
.equ ADC_TEMP1_bm = (1<<1)               ; Temporary bit 1 mask
.equ ADC_TEMP1_bp = 1                    ; Temporary bit 1 position
.equ ADC_TEMP2_bm = (1<<2)               ; Temporary bit 2 mask
.equ ADC_TEMP2_bp = 2                    ; Temporary bit 2 position
.equ ADC_TEMP3_bm = (1<<3)               ; Temporary bit 3 mask
.equ ADC_TEMP3_bp = 3                    ; Temporary bit 3 position
.equ ADC_TEMP4_bm = (1<<4)               ; Temporary bit 4 mask
.equ ADC_TEMP4_bp = 4                    ; Temporary bit 4 position
.equ ADC_TEMP5_bm = (1<<5)               ; Temporary bit 5 mask
.equ ADC_TEMP5_bp = 5                    ; Temporary bit 5 position
.equ ADC_TEMP6_bm = (1<<6)               ; Temporary bit 6 mask
.equ ADC_TEMP6_bp = 6                    ; Temporary bit 6 position
.equ ADC_TEMP7_bm = (1<<7)               ; Temporary bit 7 mask
.equ ADC_TEMP7_bp = 7                    ; Temporary bit 7 position

; Duty Cycle select
.equ ADC_DUTYCYC_DUTY50_gc = (0x00<<0)   ; 50% Duty cycle
.equ ADC_DUTYCYC_DUTY25_gc = (0x01<<0)   ; 25% Duty cycle

; ADC Resolution select
.equ ADC_RESSEL_10BIT_gc = (0x00<<2)     ; 10-bit mode
.equ ADC_RESSEL_8BIT_gc = (0x01<<2)      ; 8-bit mode

; Accumulation Samples select
.equ ADC_SAMPNUM_ACC1_gc = (0x00<<0)     ; 1 ADC sample
.equ ADC_SAMPNUM_ACC2_gc = (0x01<<0)     ; Accumulate 2 samples
.equ ADC_SAMPNUM_ACC4_gc = (0x02<<0)     ; Accumulate 4 samples
.equ ADC_SAMPNUM_ACC8_gc = (0x03<<0)     ; Accumulate 8 samples
.equ ADC_SAMPNUM_ACC16_gc = (0x04<<0)    ; Accumulate 16 samples
.equ ADC_SAMPNUM_ACC32_gc = (0x05<<0)    ; Accumulate 32 samples
.equ ADC_SAMPNUM_ACC64_gc = (0x06<<0)    ; Accumulate 64 samples

; Clock Pre-scaler select
.equ ADC_PRESC_DIV2_gc = (0x00<<0)       ; CLK_PER divided by 2
.equ ADC_PRESC_DIV4_gc = (0x01<<0)       ; CLK_PER divided by 4
.equ ADC_PRESC_DIV8_gc = (0x02<<0)       ; CLK_PER divided by 8
.equ ADC_PRESC_DIV16_gc = (0x03<<0)      ; CLK_PER divided by 16
.equ ADC_PRESC_DIV32_gc = (0x04<<0)      ; CLK_PER divided by 32
.equ ADC_PRESC_DIV64_gc = (0x05<<0)      ; CLK_PER divided by 64
.equ ADC_PRESC_DIV128_gc = (0x06<<0)     ; CLK_PER divided by 128
.equ ADC_PRESC_DIV256_gc = (0x07<<0)     ; CLK_PER divided by 256

; Reference Selection select
.equ ADC_REFSEL_INTREF_gc = (0x00<<4)    ; Internal reference
.equ ADC_REFSEL_VDDREF_gc = (0x01<<4)    ; VDD
.equ ADC_REFSEL_VREFA_gc = (0x02<<4)     ; External reference

; Automatic Sampling Delay Variation select
.equ ADC_ASDV_ASVOFF_gc = (0x00<<4)      ; The Automatic Sampling Delay Variation is disabled
.equ ADC_ASDV_ASVON_gc = (0x01<<4)       ; The Automatic Sampling Delay Variation is enabled

; Initial Delay Selection select
.equ ADC_INITDLY_DLY0_gc = (0x00<<5)     ; Delay 0 CLK_ADC cycles
.equ ADC_INITDLY_DLY16_gc = (0x01<<5)    ; Delay 16 CLK_ADC cycles
.equ ADC_INITDLY_DLY32_gc = (0x02<<5)    ; Delay 32 CLK_ADC cycles
.equ ADC_INITDLY_DLY64_gc = (0x03<<5)    ; Delay 64 CLK_ADC cycles
.equ ADC_INITDLY_DLY128_gc = (0x04<<5)   ; Delay 128 CLK_ADC cycles
.equ ADC_INITDLY_DLY256_gc = (0x05<<5)   ; Delay 256 CLK_ADC cycles

; Window Comparator Mode select
.equ ADC_WINCM_NONE_gc = (0x00<<0)       ; No Window Comparison
.equ ADC_WINCM_BELOW_gc = (0x01<<0)      ; Below Window
.equ ADC_WINCM_ABOVE_gc = (0x02<<0)      ; Above Window
.equ ADC_WINCM_INSIDE_gc = (0x03<<0)     ; Inside Window
.equ ADC_WINCM_OUTSIDE_gc = (0x04<<0)    ; Outside Window

; Analog Channel Selection Bits select
.equ ADC_MUXPOS_AIN0_gc = (0x00<<0)      ; ADC input pin 0
.equ ADC_MUXPOS_AIN1_gc = (0x01<<0)      ; ADC input pin 1
.equ ADC_MUXPOS_AIN2_gc = (0x02<<0)      ; ADC input pin 2
.equ ADC_MUXPOS_AIN3_gc = (0x03<<0)      ; ADC input pin 3
.equ ADC_MUXPOS_AIN4_gc = (0x04<<0)      ; ADC input pin 4
.equ ADC_MUXPOS_AIN5_gc = (0x05<<0)      ; ADC input pin 5
.equ ADC_MUXPOS_AIN6_gc = (0x06<<0)      ; ADC input pin 6
.equ ADC_MUXPOS_AIN7_gc = (0x07<<0)      ; ADC input pin 7
.equ ADC_MUXPOS_AIN8_gc = (0x08<<0)      ; ADC input pin 8
.equ ADC_MUXPOS_AIN9_gc = (0x09<<0)      ; ADC input pin 9
.equ ADC_MUXPOS_AIN10_gc = (0x0A<<0)     ; ADC input pin 10
.equ ADC_MUXPOS_AIN11_gc = (0x0B<<0)     ; ADC input pin 11
.equ ADC_MUXPOS_AIN12_gc = (0x0C<<0)     ; ADC input pin 12
.equ ADC_MUXPOS_AIN13_gc = (0x0D<<0)     ; ADC input pin 13
.equ ADC_MUXPOS_AIN14_gc = (0x0E<<0)     ; ADC input pin 14
.equ ADC_MUXPOS_AIN15_gc = (0x0F<<0)     ; ADC input pin 15
.equ ADC_MUXPOS_DACREF_gc = (0x1C<<0)    ; AC DAC Reference
.equ ADC_MUXPOS_TEMPSENSE_gc = (0x1E<<0) ; Temperature sensor
.equ ADC_MUXPOS_GND_gc = (0x1F<<0)       ; 0V (GND)


;*************************************************************************
;** BOD - Bod interface
;*************************************************************************

; BOD_CTRLA masks
.equ BOD_ACTIVE_gm = 0x0C                ; Operation in active mode group mask
.equ BOD_ACTIVE_gp = 2                   ; Operation in active mode group position
.equ BOD_ACTIVE0_bm = (1<<2)             ; Operation in active mode bit 0 mask
.equ BOD_ACTIVE0_bp = 2                  ; Operation in active mode bit 0 position
.equ BOD_ACTIVE1_bm = (1<<3)             ; Operation in active mode bit 1 mask
.equ BOD_ACTIVE1_bp = 3                  ; Operation in active mode bit 1 position
.equ BOD_SAMPFREQ_bm = 0x10              ; Sample frequency bit mask
.equ BOD_SAMPFREQ_bp = 4                 ; Sample frequency bit position
.equ BOD_SLEEP_gm = 0x03                 ; Operation in sleep mode group mask
.equ BOD_SLEEP_gp = 0                    ; Operation in sleep mode group position
.equ BOD_SLEEP0_bm = (1<<0)              ; Operation in sleep mode bit 0 mask
.equ BOD_SLEEP0_bp = 0                   ; Operation in sleep mode bit 0 position
.equ BOD_SLEEP1_bm = (1<<1)              ; Operation in sleep mode bit 1 mask
.equ BOD_SLEEP1_bp = 1                   ; Operation in sleep mode bit 1 position

; BOD_CTRLB masks
.equ BOD_LVL_gm = 0x07                   ; Bod level group mask
.equ BOD_LVL_gp = 0                      ; Bod level group position
.equ BOD_LVL0_bm = (1<<0)                ; Bod level bit 0 mask
.equ BOD_LVL0_bp = 0                     ; Bod level bit 0 position
.equ BOD_LVL1_bm = (1<<1)                ; Bod level bit 1 mask
.equ BOD_LVL1_bp = 1                     ; Bod level bit 1 position
.equ BOD_LVL2_bm = (1<<2)                ; Bod level bit 2 mask
.equ BOD_LVL2_bp = 2                     ; Bod level bit 2 position

; BOD_INTCTRL masks
.equ BOD_VLMCFG_gm = 0x06                ; Configuration group mask
.equ BOD_VLMCFG_gp = 1                   ; Configuration group position
.equ BOD_VLMCFG0_bm = (1<<1)             ; Configuration bit 0 mask
.equ BOD_VLMCFG0_bp = 1                  ; Configuration bit 0 position
.equ BOD_VLMCFG1_bm = (1<<2)             ; Configuration bit 1 mask
.equ BOD_VLMCFG1_bp = 2                  ; Configuration bit 1 position
.equ BOD_VLMIE_bm = 0x01                 ; voltage level monitor interrrupt enable bit mask
.equ BOD_VLMIE_bp = 0                    ; voltage level monitor interrrupt enable bit position

; BOD_INTFLAGS masks
.equ BOD_VLMIF_bm = 0x01                 ; Voltage level monitor interrupt flag bit mask
.equ BOD_VLMIF_bp = 0                    ; Voltage level monitor interrupt flag bit position

; BOD_STATUS masks
.equ BOD_VLMS_bm = 0x01                  ; Voltage level monitor status bit mask
.equ BOD_VLMS_bp = 0                     ; Voltage level monitor status bit position

; BOD_VLMCTRLA masks
.equ BOD_VLMLVL_gm = 0x03                ; voltage level monitor level group mask
.equ BOD_VLMLVL_gp = 0                   ; voltage level monitor level group position
.equ BOD_VLMLVL0_bm = (1<<0)             ; voltage level monitor level bit 0 mask
.equ BOD_VLMLVL0_bp = 0                  ; voltage level monitor level bit 0 position
.equ BOD_VLMLVL1_bm = (1<<1)             ; voltage level monitor level bit 1 mask
.equ BOD_VLMLVL1_bp = 1                  ; voltage level monitor level bit 1 position

; Operation in active mode select
.equ BOD_ACTIVE_DIS_gc = (0x00<<2)       ; Disabled
.equ BOD_ACTIVE_ENABLED_gc = (0x01<<2)   ; Enabled
.equ BOD_ACTIVE_SAMPLED_gc = (0x02<<2)   ; Sampled
.equ BOD_ACTIVE_ENWAKE_gc = (0x03<<2)    ; Enabled with wake-up halted until BOD is ready

; Sample frequency select
.equ BOD_SAMPFREQ_1KHZ_gc = (0x00<<4)    ; 1kHz sampling frequency
.equ BOD_SAMPFREQ_125HZ_gc = (0x01<<4)   ; 125Hz sampling frequency

; Operation in sleep mode select
.equ BOD_SLEEP_DIS_gc = (0x00<<0)        ; Disabled
.equ BOD_SLEEP_ENABLED_gc = (0x01<<0)    ; Enabled
.equ BOD_SLEEP_SAMPLED_gc = (0x02<<0)    ; Sampled

; Bod level select
.equ BOD_LVL_BODLEVEL0_gc = (0x00<<0)    ; 1.8 V
.equ BOD_LVL_BODLEVEL2_gc = (0x02<<0)    ; 2.6 V
.equ BOD_LVL_BODLEVEL7_gc = (0x07<<0)    ; 4.2 V

; Configuration select
.equ BOD_VLMCFG_BELOW_gc = (0x00<<1)     ; Interrupt when supply goes below VLM level
.equ BOD_VLMCFG_ABOVE_gc = (0x01<<1)     ; Interrupt when supply goes above VLM level
.equ BOD_VLMCFG_CROSS_gc = (0x02<<1)     ; Interrupt when supply crosses VLM level

; voltage level monitor level select
.equ BOD_VLMLVL_5ABOVE_gc = (0x00<<0)    ; VLM threshold 5% above BOD level
.equ BOD_VLMLVL_15ABOVE_gc = (0x01<<0)   ; VLM threshold 15% above BOD level
.equ BOD_VLMLVL_25ABOVE_gc = (0x02<<0)   ; VLM threshold 25% above BOD level


;*************************************************************************
;** CCL - Configurable Custom Logic
;*************************************************************************

; CCL_CTRLA masks
.equ CCL_ENABLE_bm = 0x01                ; Enable bit mask
.equ CCL_ENABLE_bp = 0                   ; Enable bit position
.equ CCL_RUNSTDBY_bm = 0x40              ; Run in Standby bit mask
.equ CCL_RUNSTDBY_bp = 6                 ; Run in Standby bit position

; CCL_INTCTRL0 masks
.equ CCL_INTMODE0_gm = 0x03              ; Interrupt Mode for LUT0 group mask
.equ CCL_INTMODE0_gp = 0                 ; Interrupt Mode for LUT0 group position
.equ CCL_INTMODE00_bm = (1<<0)           ; Interrupt Mode for LUT0 bit 0 mask
.equ CCL_INTMODE00_bp = 0                ; Interrupt Mode for LUT0 bit 0 position
.equ CCL_INTMODE01_bm = (1<<1)           ; Interrupt Mode for LUT0 bit 1 mask
.equ CCL_INTMODE01_bp = 1                ; Interrupt Mode for LUT0 bit 1 position
.equ CCL_INTMODE1_gm = 0x0C              ; Interrupt Mode for LUT1 group mask
.equ CCL_INTMODE1_gp = 2                 ; Interrupt Mode for LUT1 group position
.equ CCL_INTMODE10_bm = (1<<2)           ; Interrupt Mode for LUT1 bit 0 mask
.equ CCL_INTMODE10_bp = 2                ; Interrupt Mode for LUT1 bit 0 position
.equ CCL_INTMODE11_bm = (1<<3)           ; Interrupt Mode for LUT1 bit 1 mask
.equ CCL_INTMODE11_bp = 3                ; Interrupt Mode for LUT1 bit 1 position
.equ CCL_INTMODE2_gm = 0x30              ; Interrupt Mode for LUT2 group mask
.equ CCL_INTMODE2_gp = 4                 ; Interrupt Mode for LUT2 group position
.equ CCL_INTMODE20_bm = (1<<4)           ; Interrupt Mode for LUT2 bit 0 mask
.equ CCL_INTMODE20_bp = 4                ; Interrupt Mode for LUT2 bit 0 position
.equ CCL_INTMODE21_bm = (1<<5)           ; Interrupt Mode for LUT2 bit 1 mask
.equ CCL_INTMODE21_bp = 5                ; Interrupt Mode for LUT2 bit 1 position
.equ CCL_INTMODE3_gm = 0xC0              ; Interrupt Mode for LUT3 group mask
.equ CCL_INTMODE3_gp = 6                 ; Interrupt Mode for LUT3 group position
.equ CCL_INTMODE30_bm = (1<<6)           ; Interrupt Mode for LUT3 bit 0 mask
.equ CCL_INTMODE30_bp = 6                ; Interrupt Mode for LUT3 bit 0 position
.equ CCL_INTMODE31_bm = (1<<7)           ; Interrupt Mode for LUT3 bit 1 mask
.equ CCL_INTMODE31_bp = 7                ; Interrupt Mode for LUT3 bit 1 position

; CCL_INTFLAGS masks
.equ CCL_INT_gm = 0x0F                   ; Interrupt Flags group mask
.equ CCL_INT_gp = 0                      ; Interrupt Flags group position
.equ CCL_INT0_bm = (1<<0)                ; Interrupt Flags bit 0 mask
.equ CCL_INT0_bp = 0                     ; Interrupt Flags bit 0 position
.equ CCL_INT1_bm = (1<<1)                ; Interrupt Flags bit 1 mask
.equ CCL_INT1_bp = 1                     ; Interrupt Flags bit 1 position
.equ CCL_INT2_bm = (1<<2)                ; Interrupt Flags bit 2 mask
.equ CCL_INT2_bp = 2                     ; Interrupt Flags bit 2 position
.equ CCL_INT3_bm = (1<<3)                ; Interrupt Flags bit 3 mask
.equ CCL_INT3_bp = 3                     ; Interrupt Flags bit 3 position

; CCL_LUT0CTRLA masks
.equ CCL_CLKSRC_gm = 0x0E                ; Clock Source Selection group mask
.equ CCL_CLKSRC_gp = 1                   ; Clock Source Selection group position
.equ CCL_CLKSRC0_bm = (1<<1)             ; Clock Source Selection bit 0 mask
.equ CCL_CLKSRC0_bp = 1                  ; Clock Source Selection bit 0 position
.equ CCL_CLKSRC1_bm = (1<<2)             ; Clock Source Selection bit 1 mask
.equ CCL_CLKSRC1_bp = 2                  ; Clock Source Selection bit 1 position
.equ CCL_CLKSRC2_bm = (1<<3)             ; Clock Source Selection bit 2 mask
.equ CCL_CLKSRC2_bp = 3                  ; Clock Source Selection bit 2 position
.equ CCL_EDGEDET_bm = 0x80               ; Edge Detection Enable bit mask
.equ CCL_EDGEDET_bp = 7                  ; Edge Detection Enable bit position
; Masks for CCL_ENABLE already defined
.equ CCL_FILTSEL_gm = 0x30               ; Filter Selection group mask
.equ CCL_FILTSEL_gp = 4                  ; Filter Selection group position
.equ CCL_FILTSEL0_bm = (1<<4)            ; Filter Selection bit 0 mask
.equ CCL_FILTSEL0_bp = 4                 ; Filter Selection bit 0 position
.equ CCL_FILTSEL1_bm = (1<<5)            ; Filter Selection bit 1 mask
.equ CCL_FILTSEL1_bp = 5                 ; Filter Selection bit 1 position
.equ CCL_OUTEN_bm = 0x40                 ; Output Enable bit mask
.equ CCL_OUTEN_bp = 6                    ; Output Enable bit position

; CCL_LUT0CTRLB masks
.equ CCL_INSEL0_gm = 0x0F                ; LUT Input 0 Source Selection group mask
.equ CCL_INSEL0_gp = 0                   ; LUT Input 0 Source Selection group position
.equ CCL_INSEL00_bm = (1<<0)             ; LUT Input 0 Source Selection bit 0 mask
.equ CCL_INSEL00_bp = 0                  ; LUT Input 0 Source Selection bit 0 position
.equ CCL_INSEL01_bm = (1<<1)             ; LUT Input 0 Source Selection bit 1 mask
.equ CCL_INSEL01_bp = 1                  ; LUT Input 0 Source Selection bit 1 position
.equ CCL_INSEL02_bm = (1<<2)             ; LUT Input 0 Source Selection bit 2 mask
.equ CCL_INSEL02_bp = 2                  ; LUT Input 0 Source Selection bit 2 position
.equ CCL_INSEL03_bm = (1<<3)             ; LUT Input 0 Source Selection bit 3 mask
.equ CCL_INSEL03_bp = 3                  ; LUT Input 0 Source Selection bit 3 position
.equ CCL_INSEL1_gm = 0xF0                ; LUT Input 1 Source Selection group mask
.equ CCL_INSEL1_gp = 4                   ; LUT Input 1 Source Selection group position
.equ CCL_INSEL10_bm = (1<<4)             ; LUT Input 1 Source Selection bit 0 mask
.equ CCL_INSEL10_bp = 4                  ; LUT Input 1 Source Selection bit 0 position
.equ CCL_INSEL11_bm = (1<<5)             ; LUT Input 1 Source Selection bit 1 mask
.equ CCL_INSEL11_bp = 5                  ; LUT Input 1 Source Selection bit 1 position
.equ CCL_INSEL12_bm = (1<<6)             ; LUT Input 1 Source Selection bit 2 mask
.equ CCL_INSEL12_bp = 6                  ; LUT Input 1 Source Selection bit 2 position
.equ CCL_INSEL13_bm = (1<<7)             ; LUT Input 1 Source Selection bit 3 mask
.equ CCL_INSEL13_bp = 7                  ; LUT Input 1 Source Selection bit 3 position

; CCL_LUT0CTRLC masks
.equ CCL_INSEL2_gm = 0x0F                ; LUT Input 2 Source Selection group mask
.equ CCL_INSEL2_gp = 0                   ; LUT Input 2 Source Selection group position
.equ CCL_INSEL20_bm = (1<<0)             ; LUT Input 2 Source Selection bit 0 mask
.equ CCL_INSEL20_bp = 0                  ; LUT Input 2 Source Selection bit 0 position
.equ CCL_INSEL21_bm = (1<<1)             ; LUT Input 2 Source Selection bit 1 mask
.equ CCL_INSEL21_bp = 1                  ; LUT Input 2 Source Selection bit 1 position
.equ CCL_INSEL22_bm = (1<<2)             ; LUT Input 2 Source Selection bit 2 mask
.equ CCL_INSEL22_bp = 2                  ; LUT Input 2 Source Selection bit 2 position
.equ CCL_INSEL23_bm = (1<<3)             ; LUT Input 2 Source Selection bit 3 mask
.equ CCL_INSEL23_bp = 3                  ; LUT Input 2 Source Selection bit 3 position

; CCL_LUT1CTRLA masks
; Masks for CCL_CLKSRC already defined
; Masks for CCL_EDGEDET already defined
; Masks for CCL_ENABLE already defined
; Masks for CCL_FILTSEL already defined
; Masks for CCL_OUTEN already defined

; CCL_LUT1CTRLB masks
; Masks for CCL_INSEL0 already defined
; Masks for CCL_INSEL1 already defined

; CCL_LUT1CTRLC masks
; Masks for CCL_INSEL2 already defined

; CCL_LUT2CTRLA masks
; Masks for CCL_CLKSRC already defined
; Masks for CCL_EDGEDET already defined
; Masks for CCL_ENABLE already defined
; Masks for CCL_FILTSEL already defined
; Masks for CCL_OUTEN already defined

; CCL_LUT2CTRLB masks
; Masks for CCL_INSEL0 already defined
; Masks for CCL_INSEL1 already defined

; CCL_LUT2CTRLC masks
; Masks for CCL_INSEL2 already defined

; CCL_LUT3CTRLA masks
; Masks for CCL_CLKSRC already defined
; Masks for CCL_EDGEDET already defined
; Masks for CCL_ENABLE already defined
; Masks for CCL_FILTSEL already defined
; Masks for CCL_OUTEN already defined

; CCL_LUT3CTRLB masks
; Masks for CCL_INSEL0 already defined
; Masks for CCL_INSEL1 already defined

; CCL_LUT3CTRLC masks
; Masks for CCL_INSEL2 already defined

; CCL_SEQCTRL0 masks
.equ CCL_SEQSEL0_gm = 0x07               ; Sequential Selection group mask
.equ CCL_SEQSEL0_gp = 0                  ; Sequential Selection group position
.equ CCL_SEQSEL00_bm = (1<<0)            ; Sequential Selection bit 0 mask
.equ CCL_SEQSEL00_bp = 0                 ; Sequential Selection bit 0 position
.equ CCL_SEQSEL01_bm = (1<<1)            ; Sequential Selection bit 1 mask
.equ CCL_SEQSEL01_bp = 1                 ; Sequential Selection bit 1 position
.equ CCL_SEQSEL02_bm = (1<<2)            ; Sequential Selection bit 2 mask
.equ CCL_SEQSEL02_bp = 2                 ; Sequential Selection bit 2 position

; CCL_SEQCTRL1 masks
.equ CCL_SEQSEL1_gm = 0x07               ; Sequential Selection group mask
.equ CCL_SEQSEL1_gp = 0                  ; Sequential Selection group position
.equ CCL_SEQSEL10_bm = (1<<0)            ; Sequential Selection bit 0 mask
.equ CCL_SEQSEL10_bp = 0                 ; Sequential Selection bit 0 position
.equ CCL_SEQSEL11_bm = (1<<1)            ; Sequential Selection bit 1 mask
.equ CCL_SEQSEL11_bp = 1                 ; Sequential Selection bit 1 position
.equ CCL_SEQSEL12_bm = (1<<2)            ; Sequential Selection bit 2 mask
.equ CCL_SEQSEL12_bp = 2                 ; Sequential Selection bit 2 position

; CCL_TRUTH0 masks
.equ CCL_TRUTH_gm = 0xFF                 ; Truth Table group mask
.equ CCL_TRUTH_gp = 0                    ; Truth Table group position
.equ CCL_TRUTH0_bm = (1<<0)              ; Truth Table bit 0 mask
.equ CCL_TRUTH0_bp = 0                   ; Truth Table bit 0 position
.equ CCL_TRUTH1_bm = (1<<1)              ; Truth Table bit 1 mask
.equ CCL_TRUTH1_bp = 1                   ; Truth Table bit 1 position
.equ CCL_TRUTH2_bm = (1<<2)              ; Truth Table bit 2 mask
.equ CCL_TRUTH2_bp = 2                   ; Truth Table bit 2 position
.equ CCL_TRUTH3_bm = (1<<3)              ; Truth Table bit 3 mask
.equ CCL_TRUTH3_bp = 3                   ; Truth Table bit 3 position
.equ CCL_TRUTH4_bm = (1<<4)              ; Truth Table bit 4 mask
.equ CCL_TRUTH4_bp = 4                   ; Truth Table bit 4 position
.equ CCL_TRUTH5_bm = (1<<5)              ; Truth Table bit 5 mask
.equ CCL_TRUTH5_bp = 5                   ; Truth Table bit 5 position
.equ CCL_TRUTH6_bm = (1<<6)              ; Truth Table bit 6 mask
.equ CCL_TRUTH6_bp = 6                   ; Truth Table bit 6 position
.equ CCL_TRUTH7_bm = (1<<7)              ; Truth Table bit 7 mask
.equ CCL_TRUTH7_bp = 7                   ; Truth Table bit 7 position

; CCL_TRUTH1 masks
; Masks for CCL_TRUTH already defined

; CCL_TRUTH2 masks
; Masks for CCL_TRUTH already defined

; CCL_TRUTH3 masks
; Masks for CCL_TRUTH already defined

; Interrupt Mode for LUT0 select
.equ CCL_INTMODE0_INTDISABLE_gc = (0x00<<0) ; Interrupt disabled
.equ CCL_INTMODE0_RISING_gc = (0x01<<0)  ; Sense rising edge
.equ CCL_INTMODE0_FALLING_gc = (0x02<<0) ; Sense falling edge
.equ CCL_INTMODE0_BOTH_gc = (0x03<<0)    ; Sense both edges

; Interrupt Mode for LUT1 select
.equ CCL_INTMODE1_INTDISABLE_gc = (0x00<<2) ; Interrupt disabled
.equ CCL_INTMODE1_RISING_gc = (0x01<<2)  ; Sense rising edge
.equ CCL_INTMODE1_FALLING_gc = (0x02<<2) ; Sense falling edge
.equ CCL_INTMODE1_BOTH_gc = (0x03<<2)    ; Sense both edges

; Interrupt Mode for LUT2 select
.equ CCL_INTMODE2_INTDISABLE_gc = (0x00<<4) ; Interrupt disabled
.equ CCL_INTMODE2_RISING_gc = (0x01<<4)  ; Sense rising edge
.equ CCL_INTMODE2_FALLING_gc = (0x02<<4) ; Sense falling edge
.equ CCL_INTMODE2_BOTH_gc = (0x03<<4)    ; Sense both edges

; Interrupt Mode for LUT3 select
.equ CCL_INTMODE3_INTDISABLE_gc = (0x00<<6) ; Interrupt disabled
.equ CCL_INTMODE3_RISING_gc = (0x01<<6)  ; Sense rising edge
.equ CCL_INTMODE3_FALLING_gc = (0x02<<6) ; Sense falling edge
.equ CCL_INTMODE3_BOTH_gc = (0x03<<6)    ; Sense both edges

; Clock Source Selection select
.equ CCL_CLKSRC_CLKPER_gc = (0x00<<1)    ; CLK_PER is clocking the LUT
.equ CCL_CLKSRC_IN2_gc = (0x01<<1)       ; IN[2] is clocking the LUT
.equ CCL_CLKSRC_OSC20M_gc = (0x04<<1)    ; 20MHz oscillator before prescaler is clocking the LUT
.equ CCL_CLKSRC_OSCULP32K_gc = (0x05<<1) ; 32kHz oscillator is clocking the LUT
.equ CCL_CLKSRC_OSCULP1K_gc = (0x06<<1)  ; 32kHz oscillator after DIV32 is clocking the LUT

; Edge Detection Enable select
.equ CCL_EDGEDET_DIS_gc = (0x00<<7)      ; Edge detector is disabled
.equ CCL_EDGEDET_EN_gc = (0x01<<7)       ; Edge detector is enabled

; Filter Selection select
.equ CCL_FILTSEL_DISABLE_gc = (0x00<<4)  ; Filter disabled
.equ CCL_FILTSEL_SYNCH_gc = (0x01<<4)    ; Synchronizer enabled
.equ CCL_FILTSEL_FILTER_gc = (0x02<<4)   ; Filter enabled

; LUT Input 0 Source Selection select
.equ CCL_INSEL0_MASK_gc = (0x00<<0)      ; Masked input
.equ CCL_INSEL0_FEEDBACK_gc = (0x01<<0)  ; Feedback input source
.equ CCL_INSEL0_LINK_gc = (0x02<<0)      ; Linked LUT input source
.equ CCL_INSEL0_EVENTA_gc = (0x03<<0)    ; Event input source A
.equ CCL_INSEL0_EVENTB_gc = (0x04<<0)    ; Event input source B
.equ CCL_INSEL0_IO_gc = (0x05<<0)        ; IO pin LUTn-IN0 input source
.equ CCL_INSEL0_AC0_gc = (0x06<<0)       ; AC0 OUT input source
.equ CCL_INSEL0_USART0_gc = (0x08<<0)    ; USART0 TXD input source
.equ CCL_INSEL0_SPI0_gc = (0x09<<0)      ; SPI0 MOSI input source
.equ CCL_INSEL0_TCA0_gc = (0x0A<<0)      ; TCA0 WO0 input source
.equ CCL_INSEL0_TCB0_gc = (0x0C<<0)      ; TCB0 WO input source

; LUT Input 1 Source Selection select
.equ CCL_INSEL1_MASK_gc = (0x00<<4)      ; Masked input
.equ CCL_INSEL1_FEEDBACK_gc = (0x01<<4)  ; Feedback input source
.equ CCL_INSEL1_LINK_gc = (0x02<<4)      ; Linked LUT input source
.equ CCL_INSEL1_EVENTA_gc = (0x03<<4)    ; Event input source A
.equ CCL_INSEL1_EVENTB_gc = (0x04<<4)    ; Event input source B
.equ CCL_INSEL1_IO_gc = (0x05<<4)        ; IO pin LUTn-N1 input source
.equ CCL_INSEL1_AC0_gc = (0x06<<4)       ; AC0 OUT input source
.equ CCL_INSEL1_USART1_gc = (0x08<<4)    ; USART1 TXD input source
.equ CCL_INSEL1_SPI0_gc = (0x09<<4)      ; SPI0 MOSI input source
.equ CCL_INSEL1_TCA0_gc = (0x0A<<4)      ; TCA0 WO1 input source
.equ CCL_INSEL1_TCB1_gc = (0x0C<<4)      ; TCB1 WO input source

; LUT Input 2 Source Selection select
.equ CCL_INSEL2_MASK_gc = (0x00<<0)      ; Masked input
.equ CCL_INSEL2_FEEDBACK_gc = (0x01<<0)  ; Feedback input source
.equ CCL_INSEL2_LINK_gc = (0x02<<0)      ; Linked LUT input source
.equ CCL_INSEL2_EVENTA_gc = (0x03<<0)    ; Event input source A
.equ CCL_INSEL2_EVENTB_gc = (0x04<<0)    ; Event input source B
.equ CCL_INSEL2_IO_gc = (0x05<<0)        ; IO pin LUTn-IN2 input source
.equ CCL_INSEL2_AC0_gc = (0x06<<0)       ; AC0 OUT input source
.equ CCL_INSEL2_USART2_gc = (0x08<<0)    ; USART2 TXD input source
.equ CCL_INSEL2_SPI0_gc = (0x09<<0)      ; SPI0 SCK input source
.equ CCL_INSEL2_TCA0_gc = (0x0A<<0)      ; TCA0 WO2 input source
.equ CCL_INSEL2_TCB2_gc = (0x0C<<0)      ; TCB2 WO input source

; Sequential Selection select
.equ CCL_SEQSEL0_DISABLE_gc = (0x00<<0)  ; Sequential logic disabled
.equ CCL_SEQSEL0_DFF_gc = (0x01<<0)      ; D FlipFlop
.equ CCL_SEQSEL0_JK_gc = (0x02<<0)       ; JK FlipFlop
.equ CCL_SEQSEL0_LATCH_gc = (0x03<<0)    ; D Latch
.equ CCL_SEQSEL0_RS_gc = (0x04<<0)       ; RS Latch

; Sequential Selection select
.equ CCL_SEQSEL1_DISABLE_gc = (0x00<<0)  ; Sequential logic disabled
.equ CCL_SEQSEL1_DFF_gc = (0x01<<0)      ; D FlipFlop
.equ CCL_SEQSEL1_JK_gc = (0x02<<0)       ; JK FlipFlop
.equ CCL_SEQSEL1_LATCH_gc = (0x03<<0)    ; D Latch
.equ CCL_SEQSEL1_RS_gc = (0x04<<0)       ; RS Latch


;*************************************************************************
;** CLKCTRL - Clock controller
;*************************************************************************

; CLKCTRL_MCLKCTRLA masks
.equ CLKCTRL_CLKOUT_bm = 0x80            ; System clock out bit mask
.equ CLKCTRL_CLKOUT_bp = 7               ; System clock out bit position
.equ CLKCTRL_CLKSEL_gm = 0x03            ; clock select group mask
.equ CLKCTRL_CLKSEL_gp = 0               ; clock select group position
.equ CLKCTRL_CLKSEL0_bm = (1<<0)         ; clock select bit 0 mask
.equ CLKCTRL_CLKSEL0_bp = 0              ; clock select bit 0 position
.equ CLKCTRL_CLKSEL1_bm = (1<<1)         ; clock select bit 1 mask
.equ CLKCTRL_CLKSEL1_bp = 1              ; clock select bit 1 position

; CLKCTRL_MCLKCTRLB masks
.equ CLKCTRL_PDIV_gm = 0x1E              ; Prescaler division group mask
.equ CLKCTRL_PDIV_gp = 1                 ; Prescaler division group position
.equ CLKCTRL_PDIV0_bm = (1<<1)           ; Prescaler division bit 0 mask
.equ CLKCTRL_PDIV0_bp = 1                ; Prescaler division bit 0 position
.equ CLKCTRL_PDIV1_bm = (1<<2)           ; Prescaler division bit 1 mask
.equ CLKCTRL_PDIV1_bp = 2                ; Prescaler division bit 1 position
.equ CLKCTRL_PDIV2_bm = (1<<3)           ; Prescaler division bit 2 mask
.equ CLKCTRL_PDIV2_bp = 3                ; Prescaler division bit 2 position
.equ CLKCTRL_PDIV3_bm = (1<<4)           ; Prescaler division bit 3 mask
.equ CLKCTRL_PDIV3_bp = 4                ; Prescaler division bit 3 position
.equ CLKCTRL_PEN_bm = 0x01               ; Prescaler enable bit mask
.equ CLKCTRL_PEN_bp = 0                  ; Prescaler enable bit position

; CLKCTRL_MCLKLOCK masks
.equ CLKCTRL_LOCKEN_bm = 0x01            ; lock ebable bit mask
.equ CLKCTRL_LOCKEN_bp = 0               ; lock ebable bit position

; CLKCTRL_MCLKSTATUS masks
.equ CLKCTRL_EXTS_bm = 0x80              ; External Clock status bit mask
.equ CLKCTRL_EXTS_bp = 7                 ; External Clock status bit position
.equ CLKCTRL_OSC20MS_bm = 0x10           ; 20MHz oscillator status bit mask
.equ CLKCTRL_OSC20MS_bp = 4              ; 20MHz oscillator status bit position
.equ CLKCTRL_OSC32KS_bm = 0x20           ; 32KHz oscillator status bit mask
.equ CLKCTRL_OSC32KS_bp = 5              ; 32KHz oscillator status bit position
.equ CLKCTRL_SOSC_bm = 0x01              ; System Oscillator changing bit mask
.equ CLKCTRL_SOSC_bp = 0                 ; System Oscillator changing bit position
.equ CLKCTRL_XOSC32KS_bm = 0x40          ; 32.768 kHz Crystal Oscillator status bit mask
.equ CLKCTRL_XOSC32KS_bp = 6             ; 32.768 kHz Crystal Oscillator status bit position

; CLKCTRL_OSC20MCALIBA masks
.equ CLKCTRL_CAL20M_gm = 0x7F            ; Calibration group mask
.equ CLKCTRL_CAL20M_gp = 0               ; Calibration group position
.equ CLKCTRL_CAL20M0_bm = (1<<0)         ; Calibration bit 0 mask
.equ CLKCTRL_CAL20M0_bp = 0              ; Calibration bit 0 position
.equ CLKCTRL_CAL20M1_bm = (1<<1)         ; Calibration bit 1 mask
.equ CLKCTRL_CAL20M1_bp = 1              ; Calibration bit 1 position
.equ CLKCTRL_CAL20M2_bm = (1<<2)         ; Calibration bit 2 mask
.equ CLKCTRL_CAL20M2_bp = 2              ; Calibration bit 2 position
.equ CLKCTRL_CAL20M3_bm = (1<<3)         ; Calibration bit 3 mask
.equ CLKCTRL_CAL20M3_bp = 3              ; Calibration bit 3 position
.equ CLKCTRL_CAL20M4_bm = (1<<4)         ; Calibration bit 4 mask
.equ CLKCTRL_CAL20M4_bp = 4              ; Calibration bit 4 position
.equ CLKCTRL_CAL20M5_bm = (1<<5)         ; Calibration bit 5 mask
.equ CLKCTRL_CAL20M5_bp = 5              ; Calibration bit 5 position
.equ CLKCTRL_CAL20M6_bm = (1<<6)         ; Calibration bit 6 mask
.equ CLKCTRL_CAL20M6_bp = 6              ; Calibration bit 6 position

; CLKCTRL_OSC20MCALIBB masks
.equ CLKCTRL_LOCK_bm = 0x80              ; Lock bit mask
.equ CLKCTRL_LOCK_bp = 7                 ; Lock bit position
.equ CLKCTRL_TEMPCAL20M_gm = 0x0F        ; Oscillator temperature coefficient group mask
.equ CLKCTRL_TEMPCAL20M_gp = 0           ; Oscillator temperature coefficient group position
.equ CLKCTRL_TEMPCAL20M0_bm = (1<<0)     ; Oscillator temperature coefficient bit 0 mask
.equ CLKCTRL_TEMPCAL20M0_bp = 0          ; Oscillator temperature coefficient bit 0 position
.equ CLKCTRL_TEMPCAL20M1_bm = (1<<1)     ; Oscillator temperature coefficient bit 1 mask
.equ CLKCTRL_TEMPCAL20M1_bp = 1          ; Oscillator temperature coefficient bit 1 position
.equ CLKCTRL_TEMPCAL20M2_bm = (1<<2)     ; Oscillator temperature coefficient bit 2 mask
.equ CLKCTRL_TEMPCAL20M2_bp = 2          ; Oscillator temperature coefficient bit 2 position
.equ CLKCTRL_TEMPCAL20M3_bm = (1<<3)     ; Oscillator temperature coefficient bit 3 mask
.equ CLKCTRL_TEMPCAL20M3_bp = 3          ; Oscillator temperature coefficient bit 3 position

; CLKCTRL_OSC20MCTRLA masks
.equ CLKCTRL_RUNSTDBY_bm = 0x02          ; Run standby bit mask
.equ CLKCTRL_RUNSTDBY_bp = 1             ; Run standby bit position

; CLKCTRL_OSC32KCTRLA masks
; Masks for CLKCTRL_RUNSTDBY already defined

; CLKCTRL_XOSC32KCTRLA masks
.equ CLKCTRL_CSUT_gm = 0x30              ; Crystal startup time group mask
.equ CLKCTRL_CSUT_gp = 4                 ; Crystal startup time group position
.equ CLKCTRL_CSUT0_bm = (1<<4)           ; Crystal startup time bit 0 mask
.equ CLKCTRL_CSUT0_bp = 4                ; Crystal startup time bit 0 position
.equ CLKCTRL_CSUT1_bm = (1<<5)           ; Crystal startup time bit 1 mask
.equ CLKCTRL_CSUT1_bp = 5                ; Crystal startup time bit 1 position
.equ CLKCTRL_ENABLE_bm = 0x01            ; Enable bit mask
.equ CLKCTRL_ENABLE_bp = 0               ; Enable bit position
; Masks for CLKCTRL_RUNSTDBY already defined
.equ CLKCTRL_SEL_bm = 0x04               ; Select bit mask
.equ CLKCTRL_SEL_bp = 2                  ; Select bit position

; clock select select
.equ CLKCTRL_CLKSEL_OSC20M_gc = (0x00<<0) ; 20MHz oscillator
.equ CLKCTRL_CLKSEL_OSCULP32K_gc = (0x01<<0) ; 32KHz oscillator
.equ CLKCTRL_CLKSEL_XOSC32K_gc = (0x02<<0) ; 32.768kHz crystal oscillator
.equ CLKCTRL_CLKSEL_EXTCLK_gc = (0x03<<0) ; External clock

; Prescaler division select
.equ CLKCTRL_PDIV_2X_gc = (0x00<<1)      ; 2X
.equ CLKCTRL_PDIV_4X_gc = (0x01<<1)      ; 4X
.equ CLKCTRL_PDIV_8X_gc = (0x02<<1)      ; 8X
.equ CLKCTRL_PDIV_16X_gc = (0x03<<1)     ; 16X
.equ CLKCTRL_PDIV_32X_gc = (0x04<<1)     ; 32X
.equ CLKCTRL_PDIV_64X_gc = (0x05<<1)     ; 64X
.equ CLKCTRL_PDIV_6X_gc = (0x08<<1)      ; 6X
.equ CLKCTRL_PDIV_10X_gc = (0x09<<1)     ; 10X
.equ CLKCTRL_PDIV_12X_gc = (0x0A<<1)     ; 12X
.equ CLKCTRL_PDIV_24X_gc = (0x0B<<1)     ; 24X
.equ CLKCTRL_PDIV_48X_gc = (0x0C<<1)     ; 48X

; Crystal startup time select
.equ CLKCTRL_CSUT_1K_gc = (0x00<<4)      ; 1k cycles
.equ CLKCTRL_CSUT_16K_gc = (0x01<<4)     ; 16k cycles
.equ CLKCTRL_CSUT_32K_gc = (0x02<<4)     ; 32k cycles
.equ CLKCTRL_CSUT_64K_gc = (0x03<<4)     ; 64k cycles


;*************************************************************************
;** CPU - CPU
;*************************************************************************

; CPU_CCP masks
.equ CPU_CCP_gm = 0xFF                   ; CCP signature group mask
.equ CPU_CCP_gp = 0                      ; CCP signature group position
.equ CPU_CCP0_bm = (1<<0)                ; CCP signature bit 0 mask
.equ CPU_CCP0_bp = 0                     ; CCP signature bit 0 position
.equ CPU_CCP1_bm = (1<<1)                ; CCP signature bit 1 mask
.equ CPU_CCP1_bp = 1                     ; CCP signature bit 1 position
.equ CPU_CCP2_bm = (1<<2)                ; CCP signature bit 2 mask
.equ CPU_CCP2_bp = 2                     ; CCP signature bit 2 position
.equ CPU_CCP3_bm = (1<<3)                ; CCP signature bit 3 mask
.equ CPU_CCP3_bp = 3                     ; CCP signature bit 3 position
.equ CPU_CCP4_bm = (1<<4)                ; CCP signature bit 4 mask
.equ CPU_CCP4_bp = 4                     ; CCP signature bit 4 position
.equ CPU_CCP5_bm = (1<<5)                ; CCP signature bit 5 mask
.equ CPU_CCP5_bp = 5                     ; CCP signature bit 5 position
.equ CPU_CCP6_bm = (1<<6)                ; CCP signature bit 6 mask
.equ CPU_CCP6_bp = 6                     ; CCP signature bit 6 position
.equ CPU_CCP7_bm = (1<<7)                ; CCP signature bit 7 mask
.equ CPU_CCP7_bp = 7                     ; CCP signature bit 7 position

; CPU_SREG masks
.equ CPU_C_bm = 0x01                     ; Carry Flag bit mask
.equ CPU_C_bp = 0                        ; Carry Flag bit position
.equ CPU_H_bm = 0x20                     ; Half Carry Flag bit mask
.equ CPU_H_bp = 5                        ; Half Carry Flag bit position
.equ CPU_I_bm = 0x80                     ; Global Interrupt Enable Flag bit mask
.equ CPU_I_bp = 7                        ; Global Interrupt Enable Flag bit position
.equ CPU_N_bm = 0x04                     ; Negative Flag bit mask
.equ CPU_N_bp = 2                        ; Negative Flag bit position
.equ CPU_S_bm = 0x10                     ; N Exclusive Or V Flag bit mask
.equ CPU_S_bp = 4                        ; N Exclusive Or V Flag bit position
.equ CPU_T_bm = 0x40                     ; Transfer Bit bit mask
.equ CPU_T_bp = 6                        ; Transfer Bit bit position
.equ CPU_V_bm = 0x08                     ; Two's Complement Overflow Flag bit mask
.equ CPU_V_bp = 3                        ; Two's Complement Overflow Flag bit position
.equ CPU_Z_bm = 0x02                     ; Zero Flag bit mask
.equ CPU_Z_bp = 1                        ; Zero Flag bit position

; CCP signature select
.equ CPU_CCP_SPM_gc = (0x9D<<0)          ; SPM Instruction Protection
.equ CPU_CCP_IOREG_gc = (0xD8<<0)        ; IO Register Protection


;*************************************************************************
;** CPUINT - Interrupt Controller
;*************************************************************************

; CPUINT_CTRLA masks
.equ CPUINT_CVT_bm = 0x20                ; Compact Vector Table bit mask
.equ CPUINT_CVT_bp = 5                   ; Compact Vector Table bit position
.equ CPUINT_IVSEL_bm = 0x40              ; Interrupt Vector Select bit mask
.equ CPUINT_IVSEL_bp = 6                 ; Interrupt Vector Select bit position
.equ CPUINT_LVL0RR_bm = 0x01             ; Round-robin Scheduling Enable bit mask
.equ CPUINT_LVL0RR_bp = 0                ; Round-robin Scheduling Enable bit position

; CPUINT_LVL0PRI masks
.equ CPUINT_LVL0PRI_gm = 0xFF            ; Interrupt Level Priority group mask
.equ CPUINT_LVL0PRI_gp = 0               ; Interrupt Level Priority group position
.equ CPUINT_LVL0PRI0_bm = (1<<0)         ; Interrupt Level Priority bit 0 mask
.equ CPUINT_LVL0PRI0_bp = 0              ; Interrupt Level Priority bit 0 position
.equ CPUINT_LVL0PRI1_bm = (1<<1)         ; Interrupt Level Priority bit 1 mask
.equ CPUINT_LVL0PRI1_bp = 1              ; Interrupt Level Priority bit 1 position
.equ CPUINT_LVL0PRI2_bm = (1<<2)         ; Interrupt Level Priority bit 2 mask
.equ CPUINT_LVL0PRI2_bp = 2              ; Interrupt Level Priority bit 2 position
.equ CPUINT_LVL0PRI3_bm = (1<<3)         ; Interrupt Level Priority bit 3 mask
.equ CPUINT_LVL0PRI3_bp = 3              ; Interrupt Level Priority bit 3 position
.equ CPUINT_LVL0PRI4_bm = (1<<4)         ; Interrupt Level Priority bit 4 mask
.equ CPUINT_LVL0PRI4_bp = 4              ; Interrupt Level Priority bit 4 position
.equ CPUINT_LVL0PRI5_bm = (1<<5)         ; Interrupt Level Priority bit 5 mask
.equ CPUINT_LVL0PRI5_bp = 5              ; Interrupt Level Priority bit 5 position
.equ CPUINT_LVL0PRI6_bm = (1<<6)         ; Interrupt Level Priority bit 6 mask
.equ CPUINT_LVL0PRI6_bp = 6              ; Interrupt Level Priority bit 6 position
.equ CPUINT_LVL0PRI7_bm = (1<<7)         ; Interrupt Level Priority bit 7 mask
.equ CPUINT_LVL0PRI7_bp = 7              ; Interrupt Level Priority bit 7 position

; CPUINT_LVL1VEC masks
.equ CPUINT_LVL1VEC_gm = 0xFF            ; Interrupt Vector with High Priority group mask
.equ CPUINT_LVL1VEC_gp = 0               ; Interrupt Vector with High Priority group position
.equ CPUINT_LVL1VEC0_bm = (1<<0)         ; Interrupt Vector with High Priority bit 0 mask
.equ CPUINT_LVL1VEC0_bp = 0              ; Interrupt Vector with High Priority bit 0 position
.equ CPUINT_LVL1VEC1_bm = (1<<1)         ; Interrupt Vector with High Priority bit 1 mask
.equ CPUINT_LVL1VEC1_bp = 1              ; Interrupt Vector with High Priority bit 1 position
.equ CPUINT_LVL1VEC2_bm = (1<<2)         ; Interrupt Vector with High Priority bit 2 mask
.equ CPUINT_LVL1VEC2_bp = 2              ; Interrupt Vector with High Priority bit 2 position
.equ CPUINT_LVL1VEC3_bm = (1<<3)         ; Interrupt Vector with High Priority bit 3 mask
.equ CPUINT_LVL1VEC3_bp = 3              ; Interrupt Vector with High Priority bit 3 position
.equ CPUINT_LVL1VEC4_bm = (1<<4)         ; Interrupt Vector with High Priority bit 4 mask
.equ CPUINT_LVL1VEC4_bp = 4              ; Interrupt Vector with High Priority bit 4 position
.equ CPUINT_LVL1VEC5_bm = (1<<5)         ; Interrupt Vector with High Priority bit 5 mask
.equ CPUINT_LVL1VEC5_bp = 5              ; Interrupt Vector with High Priority bit 5 position
.equ CPUINT_LVL1VEC6_bm = (1<<6)         ; Interrupt Vector with High Priority bit 6 mask
.equ CPUINT_LVL1VEC6_bp = 6              ; Interrupt Vector with High Priority bit 6 position
.equ CPUINT_LVL1VEC7_bm = (1<<7)         ; Interrupt Vector with High Priority bit 7 mask
.equ CPUINT_LVL1VEC7_bp = 7              ; Interrupt Vector with High Priority bit 7 position

; CPUINT_STATUS masks
.equ CPUINT_LVL0EX_bm = 0x01             ; Level 0 Interrupt Executing bit mask
.equ CPUINT_LVL0EX_bp = 0                ; Level 0 Interrupt Executing bit position
.equ CPUINT_LVL1EX_bm = 0x02             ; Level 1 Interrupt Executing bit mask
.equ CPUINT_LVL1EX_bp = 1                ; Level 1 Interrupt Executing bit position
.equ CPUINT_NMIEX_bm = 0x80              ; Non-maskable Interrupt Executing bit mask
.equ CPUINT_NMIEX_bp = 7                 ; Non-maskable Interrupt Executing bit position


;*************************************************************************
;** CRCSCAN - CRCSCAN
;*************************************************************************

; CRCSCAN_CTRLA masks
.equ CRCSCAN_ENABLE_bm = 0x01            ; Enable CRC scan bit mask
.equ CRCSCAN_ENABLE_bp = 0               ; Enable CRC scan bit position
.equ CRCSCAN_NMIEN_bm = 0x02             ; Enable NMI Trigger bit mask
.equ CRCSCAN_NMIEN_bp = 1                ; Enable NMI Trigger bit position
.equ CRCSCAN_RESET_bm = 0x80             ; Reset CRC scan bit mask
.equ CRCSCAN_RESET_bp = 7                ; Reset CRC scan bit position

; CRCSCAN_CTRLB masks
.equ CRCSCAN_SRC_gm = 0x03               ; CRC Source group mask
.equ CRCSCAN_SRC_gp = 0                  ; CRC Source group position
.equ CRCSCAN_SRC0_bm = (1<<0)            ; CRC Source bit 0 mask
.equ CRCSCAN_SRC0_bp = 0                 ; CRC Source bit 0 position
.equ CRCSCAN_SRC1_bm = (1<<1)            ; CRC Source bit 1 mask
.equ CRCSCAN_SRC1_bp = 1                 ; CRC Source bit 1 position

; CRCSCAN_STATUS masks
.equ CRCSCAN_BUSY_bm = 0x01              ; CRC Busy bit mask
.equ CRCSCAN_BUSY_bp = 0                 ; CRC Busy bit position
.equ CRCSCAN_OK_bm = 0x02                ; CRC Ok bit mask
.equ CRCSCAN_OK_bp = 1                   ; CRC Ok bit position

; CRC Source select
.equ CRCSCAN_SRC_FLASH_gc = (0x00<<0)    ; CRC on entire flash
.equ CRCSCAN_SRC_APPLICATION_gc = (0x01<<0) ; CRC on boot and appl section of flash
.equ CRCSCAN_SRC_BOOT_gc = (0x02<<0)     ; CRC on boot section of flash


;*************************************************************************
;** EVSYS - Event System
;*************************************************************************

; EVSYS_CHANNEL0 masks
.equ EVSYS_GENERATOR_gm = 0xFF           ; Generator selector group mask
.equ EVSYS_GENERATOR_gp = 0              ; Generator selector group position
.equ EVSYS_GENERATOR0_bm = (1<<0)        ; Generator selector bit 0 mask
.equ EVSYS_GENERATOR0_bp = 0             ; Generator selector bit 0 position
.equ EVSYS_GENERATOR1_bm = (1<<1)        ; Generator selector bit 1 mask
.equ EVSYS_GENERATOR1_bp = 1             ; Generator selector bit 1 position
.equ EVSYS_GENERATOR2_bm = (1<<2)        ; Generator selector bit 2 mask
.equ EVSYS_GENERATOR2_bp = 2             ; Generator selector bit 2 position
.equ EVSYS_GENERATOR3_bm = (1<<3)        ; Generator selector bit 3 mask
.equ EVSYS_GENERATOR3_bp = 3             ; Generator selector bit 3 position
.equ EVSYS_GENERATOR4_bm = (1<<4)        ; Generator selector bit 4 mask
.equ EVSYS_GENERATOR4_bp = 4             ; Generator selector bit 4 position
.equ EVSYS_GENERATOR5_bm = (1<<5)        ; Generator selector bit 5 mask
.equ EVSYS_GENERATOR5_bp = 5             ; Generator selector bit 5 position
.equ EVSYS_GENERATOR6_bm = (1<<6)        ; Generator selector bit 6 mask
.equ EVSYS_GENERATOR6_bp = 6             ; Generator selector bit 6 position
.equ EVSYS_GENERATOR7_bm = (1<<7)        ; Generator selector bit 7 mask
.equ EVSYS_GENERATOR7_bp = 7             ; Generator selector bit 7 position

; EVSYS_CHANNEL1 masks
; Masks for EVSYS_GENERATOR already defined

; EVSYS_CHANNEL2 masks
; Masks for EVSYS_GENERATOR already defined

; EVSYS_CHANNEL3 masks
; Masks for EVSYS_GENERATOR already defined

; EVSYS_CHANNEL4 masks
; Masks for EVSYS_GENERATOR already defined

; EVSYS_CHANNEL5 masks
; Masks for EVSYS_GENERATOR already defined

; EVSYS_CHANNEL6 masks
; Masks for EVSYS_GENERATOR already defined

; EVSYS_CHANNEL7 masks
; Masks for EVSYS_GENERATOR already defined

; EVSYS_STROBE masks
.equ EVSYS_STROBE0_gm = 0xFF             ; Software event on channels group mask
.equ EVSYS_STROBE0_gp = 0                ; Software event on channels group position
.equ EVSYS_STROBE00_bm = (1<<0)          ; Software event on channels bit 0 mask
.equ EVSYS_STROBE00_bp = 0               ; Software event on channels bit 0 position
.equ EVSYS_STROBE01_bm = (1<<1)          ; Software event on channels bit 1 mask
.equ EVSYS_STROBE01_bp = 1               ; Software event on channels bit 1 position
.equ EVSYS_STROBE02_bm = (1<<2)          ; Software event on channels bit 2 mask
.equ EVSYS_STROBE02_bp = 2               ; Software event on channels bit 2 position
.equ EVSYS_STROBE03_bm = (1<<3)          ; Software event on channels bit 3 mask
.equ EVSYS_STROBE03_bp = 3               ; Software event on channels bit 3 position
.equ EVSYS_STROBE04_bm = (1<<4)          ; Software event on channels bit 4 mask
.equ EVSYS_STROBE04_bp = 4               ; Software event on channels bit 4 position
.equ EVSYS_STROBE05_bm = (1<<5)          ; Software event on channels bit 5 mask
.equ EVSYS_STROBE05_bp = 5               ; Software event on channels bit 5 position
.equ EVSYS_STROBE06_bm = (1<<6)          ; Software event on channels bit 6 mask
.equ EVSYS_STROBE06_bp = 6               ; Software event on channels bit 6 position
.equ EVSYS_STROBE07_bm = (1<<7)          ; Software event on channels bit 7 mask
.equ EVSYS_STROBE07_bp = 7               ; Software event on channels bit 7 position

; EVSYS_USERADC0 masks
.equ EVSYS_CHANNEL_gm = 0xFF             ; Channel selector group mask
.equ EVSYS_CHANNEL_gp = 0                ; Channel selector group position
.equ EVSYS_CHANNEL0_bm = (1<<0)          ; Channel selector bit 0 mask
.equ EVSYS_CHANNEL0_bp = 0               ; Channel selector bit 0 position
.equ EVSYS_CHANNEL1_bm = (1<<1)          ; Channel selector bit 1 mask
.equ EVSYS_CHANNEL1_bp = 1               ; Channel selector bit 1 position
.equ EVSYS_CHANNEL2_bm = (1<<2)          ; Channel selector bit 2 mask
.equ EVSYS_CHANNEL2_bp = 2               ; Channel selector bit 2 position
.equ EVSYS_CHANNEL3_bm = (1<<3)          ; Channel selector bit 3 mask
.equ EVSYS_CHANNEL3_bp = 3               ; Channel selector bit 3 position
.equ EVSYS_CHANNEL4_bm = (1<<4)          ; Channel selector bit 4 mask
.equ EVSYS_CHANNEL4_bp = 4               ; Channel selector bit 4 position
.equ EVSYS_CHANNEL5_bm = (1<<5)          ; Channel selector bit 5 mask
.equ EVSYS_CHANNEL5_bp = 5               ; Channel selector bit 5 position
.equ EVSYS_CHANNEL6_bm = (1<<6)          ; Channel selector bit 6 mask
.equ EVSYS_CHANNEL6_bp = 6               ; Channel selector bit 6 position
.equ EVSYS_CHANNEL7_bm = (1<<7)          ; Channel selector bit 7 mask
.equ EVSYS_CHANNEL7_bp = 7               ; Channel selector bit 7 position

; EVSYS_USERCCLLUT0A masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERCCLLUT0B masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERCCLLUT1A masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERCCLLUT1B masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERCCLLUT2A masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERCCLLUT2B masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERCCLLUT3A masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERCCLLUT3B masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USEREVOUTA masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USEREVOUTB masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USEREVOUTC masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USEREVOUTD masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USEREVOUTE masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USEREVOUTF masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERTCA0 masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERTCB0 masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERTCB1 masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERTCB2 masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERTCB3 masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERUSART0 masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERUSART1 masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERUSART2 masks
; Masks for EVSYS_CHANNEL already defined

; EVSYS_USERUSART3 masks
; Masks for EVSYS_CHANNEL already defined

; Generator selector select
.equ EVSYS_GENERATOR_OFF_gc = (0x00<<0)  ; Off
.equ EVSYS_GENERATOR_UPDI_gc = (0x01<<0) ; Unified Program and Debug Interface
.equ EVSYS_GENERATOR_RTC_OVF_gc = (0x06<<0) ; Real Time Counter overflow
.equ EVSYS_GENERATOR_RTC_CMP_gc = (0x07<<0) ; Real Time Counter compare
.equ EVSYS_GENERATOR_RTC_PIT0_gc = (0x08<<0) ; Periodic Interrupt Timer output 0
.equ EVSYS_GENERATOR_RTC_PIT1_gc = (0x09<<0) ; Periodic Interrupt Timer output 1
.equ EVSYS_GENERATOR_RTC_PIT2_gc = (0x0A<<0) ; Periodic Interrupt Timer output 2
.equ EVSYS_GENERATOR_RTC_PIT3_gc = (0x0B<<0) ; Periodic Interrupt Timer output 3
.equ EVSYS_GENERATOR_CCL_LUT0_gc = (0x10<<0) ; Configurable Custom Logic LUT0
.equ EVSYS_GENERATOR_CCL_LUT1_gc = (0x11<<0) ; Configurable Custom Logic LUT1
.equ EVSYS_GENERATOR_CCL_LUT2_gc = (0x12<<0) ; Configurable Custom Logic LUT2
.equ EVSYS_GENERATOR_CCL_LUT3_gc = (0x13<<0) ; Configurable Custom Logic LUT3
.equ EVSYS_GENERATOR_AC0_OUT_gc = (0x20<<0) ; Analog Comparator 0 out
.equ EVSYS_GENERATOR_ADC0_RESRDY_gc = (0x24<<0) ; ADC 0 Result Ready Event
.equ EVSYS_GENERATOR_PORT0_PIN0_gc = (0x40<<0) ; Port 0 Pin 0
.equ EVSYS_GENERATOR_PORT0_PIN1_gc = (0x41<<0) ; Port 0 Pin 1
.equ EVSYS_GENERATOR_PORT0_PIN2_gc = (0x42<<0) ; Port 0 Pin 2
.equ EVSYS_GENERATOR_PORT0_PIN3_gc = (0x43<<0) ; Port 0 Pin 3
.equ EVSYS_GENERATOR_PORT0_PIN4_gc = (0x44<<0) ; Port 0 Pin 4
.equ EVSYS_GENERATOR_PORT0_PIN5_gc = (0x45<<0) ; Port 0 Pin 5
.equ EVSYS_GENERATOR_PORT0_PIN6_gc = (0x46<<0) ; Port 0 Pin 6
.equ EVSYS_GENERATOR_PORT0_PIN7_gc = (0x47<<0) ; Port 0 Pin 7
.equ EVSYS_GENERATOR_PORT1_PIN0_gc = (0x48<<0) ; Port 1 Pin 0
.equ EVSYS_GENERATOR_PORT1_PIN1_gc = (0x49<<0) ; Port 1 Pin 1
.equ EVSYS_GENERATOR_PORT1_PIN2_gc = (0x4A<<0) ; Port 1 Pin 2
.equ EVSYS_GENERATOR_PORT1_PIN3_gc = (0x4B<<0) ; Port 1 Pin 3
.equ EVSYS_GENERATOR_PORT1_PIN4_gc = (0x4C<<0) ; Port 1 Pin 4
.equ EVSYS_GENERATOR_PORT1_PIN5_gc = (0x4D<<0) ; Port 1 Pin 5
.equ EVSYS_GENERATOR_PORT1_PIN6_gc = (0x4E<<0) ; Port 1 Pin 6
.equ EVSYS_GENERATOR_PORT1_PIN7_gc = (0x4F<<0) ; Port 1 Pin 7
.equ EVSYS_GENERATOR_USART0_XCK_gc = (0x60<<0) ; USART 0 Xclock
.equ EVSYS_GENERATOR_USART1_XCK_gc = (0x61<<0) ; USART 1 Xclock
.equ EVSYS_GENERATOR_USART2_XCK_gc = (0x62<<0) ; USART 2 Xclock
.equ EVSYS_GENERATOR_USART3_XCK_gc = (0x63<<0) ; USART 3 Xclock
.equ EVSYS_GENERATOR_SPI0_SCK_gc = (0x68<<0) ; SPI 0 Sclock
.equ EVSYS_GENERATOR_TCA0_OVF_LUNF_gc = (0x80<<0) ; Timer/Counter A0 overflow / low byte underflow
.equ EVSYS_GENERATOR_TCA0_HUNF_gc = (0x81<<0) ; Timer/Counter A0 high byte underflow (split mode)
.equ EVSYS_GENERATOR_TCA0_CMP0_gc = (0x84<<0) ; Timer/Counter A0 compare 0
.equ EVSYS_GENERATOR_TCA0_CMP1_gc = (0x85<<0) ; Timer/Counter A0 compare 1
.equ EVSYS_GENERATOR_TCA0_CMP2_gc = (0x86<<0) ; Timer/Counter A0 compare 2
.equ EVSYS_GENERATOR_TCB0_CAPT_gc = (0xA0<<0) ; Timer/Counter B0 capture
.equ EVSYS_GENERATOR_TCB1_CAPT_gc = (0xA2<<0) ; Timer/Counter B1 capture
.equ EVSYS_GENERATOR_TCB2_CAPT_gc = (0xA4<<0) ; Timer/Counter B2 capture
.equ EVSYS_GENERATOR_TCB3_CAPT_gc = (0xA6<<0) ; Timer/Counter B3 capture

; Software event on channels select
.equ EVSYS_STROBE0_EV_STROBE_CH0_gc = (0x01<<0) ; 
.equ EVSYS_STROBE0_EV_STROBE_CH1_gc = (0x02<<0) ; 
.equ EVSYS_STROBE0_EV_STROBE_CH2_gc = (0x04<<0) ; 
.equ EVSYS_STROBE0_EV_STROBE_CH3_gc = (0x08<<0) ; 
.equ EVSYS_STROBE0_EV_STROBE_CH4_gc = (0x10<<0) ; 
.equ EVSYS_STROBE0_EV_STROBE_CH5_gc = (0x20<<0) ; 
.equ EVSYS_STROBE0_EV_STROBE_CH6_gc = (0x40<<0) ; 
.equ EVSYS_STROBE0_EV_STROBE_CH7_gc = (0x80<<0) ; 

; Channel selector select
.equ EVSYS_CHANNEL_OFF_gc = (0x00<<0)    ; Off
.equ EVSYS_CHANNEL_CHANNEL0_gc = (0x01<<0) ; Connect user to event channel 0
.equ EVSYS_CHANNEL_CHANNEL1_gc = (0x02<<0) ; Connect user to event channel 1
.equ EVSYS_CHANNEL_CHANNEL2_gc = (0x03<<0) ; Connect user to event channel 2
.equ EVSYS_CHANNEL_CHANNEL3_gc = (0x04<<0) ; Connect user to event channel 3
.equ EVSYS_CHANNEL_CHANNEL4_gc = (0x05<<0) ; Connect user to event channel 4
.equ EVSYS_CHANNEL_CHANNEL5_gc = (0x06<<0) ; Connect user to event channel 5
.equ EVSYS_CHANNEL_CHANNEL6_gc = (0x07<<0) ; Connect user to event channel 6
.equ EVSYS_CHANNEL_CHANNEL7_gc = (0x08<<0) ; Connect user to event channel 7


;*************************************************************************
;** FUSE - Fuses
;*************************************************************************

; FUSE_BODCFG masks
.equ FUSE_ACTIVE_gm = 0x0C               ; BOD Operation in Active Mode group mask
.equ FUSE_ACTIVE_gp = 2                  ; BOD Operation in Active Mode group position
.equ FUSE_ACTIVE0_bm = (1<<2)            ; BOD Operation in Active Mode bit 0 mask
.equ FUSE_ACTIVE0_bp = 2                 ; BOD Operation in Active Mode bit 0 position
.equ FUSE_ACTIVE1_bm = (1<<3)            ; BOD Operation in Active Mode bit 1 mask
.equ FUSE_ACTIVE1_bp = 3                 ; BOD Operation in Active Mode bit 1 position
.equ FUSE_LVL_gm = 0xE0                  ; BOD Level group mask
.equ FUSE_LVL_gp = 5                     ; BOD Level group position
.equ FUSE_LVL0_bm = (1<<5)               ; BOD Level bit 0 mask
.equ FUSE_LVL0_bp = 5                    ; BOD Level bit 0 position
.equ FUSE_LVL1_bm = (1<<6)               ; BOD Level bit 1 mask
.equ FUSE_LVL1_bp = 6                    ; BOD Level bit 1 position
.equ FUSE_LVL2_bm = (1<<7)               ; BOD Level bit 2 mask
.equ FUSE_LVL2_bp = 7                    ; BOD Level bit 2 position
.equ FUSE_SAMPFREQ_bm = 0x10             ; BOD Sample Frequency bit mask
.equ FUSE_SAMPFREQ_bp = 4                ; BOD Sample Frequency bit position
.equ FUSE_SLEEP_gm = 0x03                ; BOD Operation in Sleep Mode group mask
.equ FUSE_SLEEP_gp = 0                   ; BOD Operation in Sleep Mode group position
.equ FUSE_SLEEP0_bm = (1<<0)             ; BOD Operation in Sleep Mode bit 0 mask
.equ FUSE_SLEEP0_bp = 0                  ; BOD Operation in Sleep Mode bit 0 position
.equ FUSE_SLEEP1_bm = (1<<1)             ; BOD Operation in Sleep Mode bit 1 mask
.equ FUSE_SLEEP1_bp = 1                  ; BOD Operation in Sleep Mode bit 1 position

; FUSE_OSCCFG masks
.equ FUSE_FREQSEL_gm = 0x03              ; Frequency Select group mask
.equ FUSE_FREQSEL_gp = 0                 ; Frequency Select group position
.equ FUSE_FREQSEL0_bm = (1<<0)           ; Frequency Select bit 0 mask
.equ FUSE_FREQSEL0_bp = 0                ; Frequency Select bit 0 position
.equ FUSE_FREQSEL1_bm = (1<<1)           ; Frequency Select bit 1 mask
.equ FUSE_FREQSEL1_bp = 1                ; Frequency Select bit 1 position
.equ FUSE_OSCLOCK_bm = 0x80              ; Oscillator Lock bit mask
.equ FUSE_OSCLOCK_bp = 7                 ; Oscillator Lock bit position

; FUSE_SYSCFG0 masks
.equ FUSE_CRCSRC_gm = 0xC0               ; CRC Source group mask
.equ FUSE_CRCSRC_gp = 6                  ; CRC Source group position
.equ FUSE_CRCSRC0_bm = (1<<6)            ; CRC Source bit 0 mask
.equ FUSE_CRCSRC0_bp = 6                 ; CRC Source bit 0 position
.equ FUSE_CRCSRC1_bm = (1<<7)            ; CRC Source bit 1 mask
.equ FUSE_CRCSRC1_bp = 7                 ; CRC Source bit 1 position
.equ FUSE_EESAVE_bm = 0x01               ; EEPROM Save bit mask
.equ FUSE_EESAVE_bp = 0                  ; EEPROM Save bit position
.equ FUSE_RSTPINCFG_bm = 0x08            ; Reset Pin Configuration bit mask
.equ FUSE_RSTPINCFG_bp = 3               ; Reset Pin Configuration bit position

; FUSE_SYSCFG1 masks
.equ FUSE_SUT_gm = 0x07                  ; Startup Time group mask
.equ FUSE_SUT_gp = 0                     ; Startup Time group position
.equ FUSE_SUT0_bm = (1<<0)               ; Startup Time bit 0 mask
.equ FUSE_SUT0_bp = 0                    ; Startup Time bit 0 position
.equ FUSE_SUT1_bm = (1<<1)               ; Startup Time bit 1 mask
.equ FUSE_SUT1_bp = 1                    ; Startup Time bit 1 position
.equ FUSE_SUT2_bm = (1<<2)               ; Startup Time bit 2 mask
.equ FUSE_SUT2_bp = 2                    ; Startup Time bit 2 position

; FUSE_WDTCFG masks
.equ FUSE_PERIOD_gm = 0x0F               ; Watchdog Timeout Period group mask
.equ FUSE_PERIOD_gp = 0                  ; Watchdog Timeout Period group position
.equ FUSE_PERIOD0_bm = (1<<0)            ; Watchdog Timeout Period bit 0 mask
.equ FUSE_PERIOD0_bp = 0                 ; Watchdog Timeout Period bit 0 position
.equ FUSE_PERIOD1_bm = (1<<1)            ; Watchdog Timeout Period bit 1 mask
.equ FUSE_PERIOD1_bp = 1                 ; Watchdog Timeout Period bit 1 position
.equ FUSE_PERIOD2_bm = (1<<2)            ; Watchdog Timeout Period bit 2 mask
.equ FUSE_PERIOD2_bp = 2                 ; Watchdog Timeout Period bit 2 position
.equ FUSE_PERIOD3_bm = (1<<3)            ; Watchdog Timeout Period bit 3 mask
.equ FUSE_PERIOD3_bp = 3                 ; Watchdog Timeout Period bit 3 position
.equ FUSE_WINDOW_gm = 0xF0               ; Watchdog Window Timeout Period group mask
.equ FUSE_WINDOW_gp = 4                  ; Watchdog Window Timeout Period group position
.equ FUSE_WINDOW0_bm = (1<<4)            ; Watchdog Window Timeout Period bit 0 mask
.equ FUSE_WINDOW0_bp = 4                 ; Watchdog Window Timeout Period bit 0 position
.equ FUSE_WINDOW1_bm = (1<<5)            ; Watchdog Window Timeout Period bit 1 mask
.equ FUSE_WINDOW1_bp = 5                 ; Watchdog Window Timeout Period bit 1 position
.equ FUSE_WINDOW2_bm = (1<<6)            ; Watchdog Window Timeout Period bit 2 mask
.equ FUSE_WINDOW2_bp = 6                 ; Watchdog Window Timeout Period bit 2 position
.equ FUSE_WINDOW3_bm = (1<<7)            ; Watchdog Window Timeout Period bit 3 mask
.equ FUSE_WINDOW3_bp = 7                 ; Watchdog Window Timeout Period bit 3 position

; BOD Operation in Active Mode select
.equ FUSE_ACTIVE_DIS_gc = (0x00<<2)      ; Disabled
.equ FUSE_ACTIVE_ENABLED_gc = (0x01<<2)  ; Enabled
.equ FUSE_ACTIVE_SAMPLED_gc = (0x02<<2)  ; Sampled
.equ FUSE_ACTIVE_ENWAKE_gc = (0x03<<2)   ; Enabled with wake-up halted until BOD is ready

; BOD Level select
.equ FUSE_LVL_BODLEVEL0_gc = (0x00<<5)   ; 1.8 V
.equ FUSE_LVL_BODLEVEL2_gc = (0x02<<5)   ; 2.6 V
.equ FUSE_LVL_BODLEVEL7_gc = (0x07<<5)   ; 4.2 V

; BOD Sample Frequency select
.equ FUSE_SAMPFREQ_1KHZ_gc = (0x00<<4)   ; 1kHz sampling frequency
.equ FUSE_SAMPFREQ_125HZ_gc = (0x01<<4)  ; 125Hz sampling frequency

; BOD Operation in Sleep Mode select
.equ FUSE_SLEEP_DIS_gc = (0x00<<0)       ; Disabled
.equ FUSE_SLEEP_ENABLED_gc = (0x01<<0)   ; Enabled
.equ FUSE_SLEEP_SAMPLED_gc = (0x02<<0)   ; Sampled

; Frequency Select select
.equ FUSE_FREQSEL_16MHZ_gc = (0x01<<0)   ; 16 MHz
.equ FUSE_FREQSEL_20MHZ_gc = (0x02<<0)   ; 20 MHz

; CRC Source select
.equ FUSE_CRCSRC_FLASH_gc = (0x00<<6)    ; The CRC is performed on the entire Flash (boot, application code and application data section).
.equ FUSE_CRCSRC_BOOT_gc = (0x01<<6)     ; The CRC is performed on the boot section of Flash
.equ FUSE_CRCSRC_BOOTAPP_gc = (0x02<<6)  ; The CRC is performed on the boot and application code section of Flash
.equ FUSE_CRCSRC_NOCRC_gc = (0x03<<6)    ; Disable CRC.

; Reset Pin Configuration select
.equ FUSE_RSTPINCFG_GPIO_gc = (0x00<<3)  ; GPIO mode
.equ FUSE_RSTPINCFG_RST_gc = (0x01<<3)   ; Reset mode

; Startup Time select
.equ FUSE_SUT_0MS_gc = (0x00<<0)         ; 0 ms
.equ FUSE_SUT_1MS_gc = (0x01<<0)         ; 1 ms
.equ FUSE_SUT_2MS_gc = (0x02<<0)         ; 2 ms
.equ FUSE_SUT_4MS_gc = (0x03<<0)         ; 4 ms
.equ FUSE_SUT_8MS_gc = (0x04<<0)         ; 8 ms
.equ FUSE_SUT_16MS_gc = (0x05<<0)        ; 16 ms
.equ FUSE_SUT_32MS_gc = (0x06<<0)        ; 32 ms
.equ FUSE_SUT_64MS_gc = (0x07<<0)        ; 64 ms

; Watchdog Timeout Period select
.equ FUSE_PERIOD_OFF_gc = (0x00<<0)      ; Off
.equ FUSE_PERIOD_8CLK_gc = (0x01<<0)     ; 8 cycles (8ms)
.equ FUSE_PERIOD_16CLK_gc = (0x02<<0)    ; 16 cycles (16ms)
.equ FUSE_PERIOD_32CLK_gc = (0x03<<0)    ; 32 cycles (32ms)
.equ FUSE_PERIOD_64CLK_gc = (0x04<<0)    ; 64 cycles (64ms)
.equ FUSE_PERIOD_128CLK_gc = (0x05<<0)   ; 128 cycles (0.128s)
.equ FUSE_PERIOD_256CLK_gc = (0x06<<0)   ; 256 cycles (0.256s)
.equ FUSE_PERIOD_512CLK_gc = (0x07<<0)   ; 512 cycles (0.512s)
.equ FUSE_PERIOD_1KCLK_gc = (0x08<<0)    ; 1K cycles (1.0s)
.equ FUSE_PERIOD_2KCLK_gc = (0x09<<0)    ; 2K cycles (2.0s)
.equ FUSE_PERIOD_4KCLK_gc = (0x0A<<0)    ; 4K cycles (4.1s)
.equ FUSE_PERIOD_8KCLK_gc = (0x0B<<0)    ; 8K cycles (8.2s)

; Watchdog Window Timeout Period select
.equ FUSE_WINDOW_OFF_gc = (0x00<<4)      ; Off
.equ FUSE_WINDOW_8CLK_gc = (0x01<<4)     ; 8 cycles (8ms)
.equ FUSE_WINDOW_16CLK_gc = (0x02<<4)    ; 16 cycles (16ms)
.equ FUSE_WINDOW_32CLK_gc = (0x03<<4)    ; 32 cycles (32ms)
.equ FUSE_WINDOW_64CLK_gc = (0x04<<4)    ; 64 cycles (64ms)
.equ FUSE_WINDOW_128CLK_gc = (0x05<<4)   ; 128 cycles (0.128s)
.equ FUSE_WINDOW_256CLK_gc = (0x06<<4)   ; 256 cycles (0.256s)
.equ FUSE_WINDOW_512CLK_gc = (0x07<<4)   ; 512 cycles (0.512s)
.equ FUSE_WINDOW_1KCLK_gc = (0x08<<4)    ; 1K cycles (1.0s)
.equ FUSE_WINDOW_2KCLK_gc = (0x09<<4)    ; 2K cycles (2.0s)
.equ FUSE_WINDOW_4KCLK_gc = (0x0A<<4)    ; 4K cycles (4.1s)
.equ FUSE_WINDOW_8KCLK_gc = (0x0B<<4)    ; 8K cycles (8.2s)


;*************************************************************************
;** GPIO - General Purpose IO
;*************************************************************************


;*************************************************************************
;** LOCKBIT - Lockbit
;*************************************************************************

; LOCKBIT_LOCKBIT masks
.equ LOCKBIT_LB_gm = 0xFF                ; Lock Bits group mask
.equ LOCKBIT_LB_gp = 0                   ; Lock Bits group position
.equ LOCKBIT_LB0_bm = (1<<0)             ; Lock Bits bit 0 mask
.equ LOCKBIT_LB0_bp = 0                  ; Lock Bits bit 0 position
.equ LOCKBIT_LB1_bm = (1<<1)             ; Lock Bits bit 1 mask
.equ LOCKBIT_LB1_bp = 1                  ; Lock Bits bit 1 position
.equ LOCKBIT_LB2_bm = (1<<2)             ; Lock Bits bit 2 mask
.equ LOCKBIT_LB2_bp = 2                  ; Lock Bits bit 2 position
.equ LOCKBIT_LB3_bm = (1<<3)             ; Lock Bits bit 3 mask
.equ LOCKBIT_LB3_bp = 3                  ; Lock Bits bit 3 position
.equ LOCKBIT_LB4_bm = (1<<4)             ; Lock Bits bit 4 mask
.equ LOCKBIT_LB4_bp = 4                  ; Lock Bits bit 4 position
.equ LOCKBIT_LB5_bm = (1<<5)             ; Lock Bits bit 5 mask
.equ LOCKBIT_LB5_bp = 5                  ; Lock Bits bit 5 position
.equ LOCKBIT_LB6_bm = (1<<6)             ; Lock Bits bit 6 mask
.equ LOCKBIT_LB6_bp = 6                  ; Lock Bits bit 6 position
.equ LOCKBIT_LB7_bm = (1<<7)             ; Lock Bits bit 7 mask
.equ LOCKBIT_LB7_bp = 7                  ; Lock Bits bit 7 position

; Lock Bits select
.equ LOCKBIT_LB_RWLOCK_gc = (0x3A<<0)    ; Read and write lock
.equ LOCKBIT_LB_NOLOCK_gc = (0xC5<<0)    ; No locks


;*************************************************************************
;** NVMCTRL - Non-volatile Memory Controller
;*************************************************************************

; NVMCTRL_CTRLA masks
.equ NVMCTRL_CMD_gm = 0x07               ; Command group mask
.equ NVMCTRL_CMD_gp = 0                  ; Command group position
.equ NVMCTRL_CMD0_bm = (1<<0)            ; Command bit 0 mask
.equ NVMCTRL_CMD0_bp = 0                 ; Command bit 0 position
.equ NVMCTRL_CMD1_bm = (1<<1)            ; Command bit 1 mask
.equ NVMCTRL_CMD1_bp = 1                 ; Command bit 1 position
.equ NVMCTRL_CMD2_bm = (1<<2)            ; Command bit 2 mask
.equ NVMCTRL_CMD2_bp = 2                 ; Command bit 2 position

; NVMCTRL_CTRLB masks
.equ NVMCTRL_APCWP_bm = 0x01             ; Application code write protect bit mask
.equ NVMCTRL_APCWP_bp = 0                ; Application code write protect bit position
.equ NVMCTRL_BOOTLOCK_bm = 0x02          ; Boot Lock bit mask
.equ NVMCTRL_BOOTLOCK_bp = 1             ; Boot Lock bit position

; NVMCTRL_INTCTRL masks
.equ NVMCTRL_EEREADY_bm = 0x01           ; EEPROM Ready bit mask
.equ NVMCTRL_EEREADY_bp = 0              ; EEPROM Ready bit position

; NVMCTRL_INTFLAGS masks
; Masks for NVMCTRL_EEREADY already defined

; NVMCTRL_STATUS masks
.equ NVMCTRL_EEBUSY_bm = 0x02            ; EEPROM busy bit mask
.equ NVMCTRL_EEBUSY_bp = 1               ; EEPROM busy bit position
.equ NVMCTRL_FBUSY_bm = 0x01             ; Flash busy bit mask
.equ NVMCTRL_FBUSY_bp = 0                ; Flash busy bit position
.equ NVMCTRL_WRERROR_bm = 0x04           ; Write error bit mask
.equ NVMCTRL_WRERROR_bp = 2              ; Write error bit position

; Command select
.equ NVMCTRL_CMD_NONE_gc = (0x00<<0)     ; No Command
.equ NVMCTRL_CMD_PAGEWRITE_gc = (0x01<<0) ; Write page
.equ NVMCTRL_CMD_PAGEERASE_gc = (0x02<<0) ; Erase page
.equ NVMCTRL_CMD_PAGEERASEWRITE_gc = (0x03<<0) ; Erase and write page
.equ NVMCTRL_CMD_PAGEBUFCLR_gc = (0x04<<0) ; Page buffer clear
.equ NVMCTRL_CMD_CHIPERASE_gc = (0x05<<0) ; Chip erase
.equ NVMCTRL_CMD_EEERASE_gc = (0x06<<0)  ; EEPROM erase
.equ NVMCTRL_CMD_FUSEWRITE_gc = (0x07<<0) ; Write fuse (PDI only)


;*************************************************************************
;** PORT - I/O Ports
;*************************************************************************

; PORT_INTFLAGS masks
.equ PORT_INT_gm = 0xFF                  ; Pin Interrupt group mask
.equ PORT_INT_gp = 0                     ; Pin Interrupt group position
.equ PORT_INT0_bm = (1<<0)               ; Pin Interrupt bit 0 mask
.equ PORT_INT0_bp = 0                    ; Pin Interrupt bit 0 position
.equ PORT_INT1_bm = (1<<1)               ; Pin Interrupt bit 1 mask
.equ PORT_INT1_bp = 1                    ; Pin Interrupt bit 1 position
.equ PORT_INT2_bm = (1<<2)               ; Pin Interrupt bit 2 mask
.equ PORT_INT2_bp = 2                    ; Pin Interrupt bit 2 position
.equ PORT_INT3_bm = (1<<3)               ; Pin Interrupt bit 3 mask
.equ PORT_INT3_bp = 3                    ; Pin Interrupt bit 3 position
.equ PORT_INT4_bm = (1<<4)               ; Pin Interrupt bit 4 mask
.equ PORT_INT4_bp = 4                    ; Pin Interrupt bit 4 position
.equ PORT_INT5_bm = (1<<5)               ; Pin Interrupt bit 5 mask
.equ PORT_INT5_bp = 5                    ; Pin Interrupt bit 5 position
.equ PORT_INT6_bm = (1<<6)               ; Pin Interrupt bit 6 mask
.equ PORT_INT6_bp = 6                    ; Pin Interrupt bit 6 position
.equ PORT_INT7_bm = (1<<7)               ; Pin Interrupt bit 7 mask
.equ PORT_INT7_bp = 7                    ; Pin Interrupt bit 7 position

; PORT_PIN0CTRL masks
.equ PORT_INVEN_bm = 0x80                ; Inverted I/O Enable bit mask
.equ PORT_INVEN_bp = 7                   ; Inverted I/O Enable bit position
.equ PORT_ISC_gm = 0x07                  ; Input/Sense Configuration group mask
.equ PORT_ISC_gp = 0                     ; Input/Sense Configuration group position
.equ PORT_ISC0_bm = (1<<0)               ; Input/Sense Configuration bit 0 mask
.equ PORT_ISC0_bp = 0                    ; Input/Sense Configuration bit 0 position
.equ PORT_ISC1_bm = (1<<1)               ; Input/Sense Configuration bit 1 mask
.equ PORT_ISC1_bp = 1                    ; Input/Sense Configuration bit 1 position
.equ PORT_ISC2_bm = (1<<2)               ; Input/Sense Configuration bit 2 mask
.equ PORT_ISC2_bp = 2                    ; Input/Sense Configuration bit 2 position
.equ PORT_PULLUPEN_bm = 0x08             ; Pullup enable bit mask
.equ PORT_PULLUPEN_bp = 3                ; Pullup enable bit position

; PORT_PIN1CTRL masks
; Masks for PORT_INVEN already defined
; Masks for PORT_ISC already defined
; Masks for PORT_PULLUPEN already defined

; PORT_PIN2CTRL masks
; Masks for PORT_INVEN already defined
; Masks for PORT_ISC already defined
; Masks for PORT_PULLUPEN already defined

; PORT_PIN3CTRL masks
; Masks for PORT_INVEN already defined
; Masks for PORT_ISC already defined
; Masks for PORT_PULLUPEN already defined

; PORT_PIN4CTRL masks
; Masks for PORT_INVEN already defined
; Masks for PORT_ISC already defined
; Masks for PORT_PULLUPEN already defined

; PORT_PIN5CTRL masks
; Masks for PORT_INVEN already defined
; Masks for PORT_ISC already defined
; Masks for PORT_PULLUPEN already defined

; PORT_PIN6CTRL masks
; Masks for PORT_INVEN already defined
; Masks for PORT_ISC already defined
; Masks for PORT_PULLUPEN already defined

; PORT_PIN7CTRL masks
; Masks for PORT_INVEN already defined
; Masks for PORT_ISC already defined
; Masks for PORT_PULLUPEN already defined

; PORT_PORTCTRL masks
.equ PORT_SRL_bm = 0x01                  ; Slew Rate Limit Enable bit mask
.equ PORT_SRL_bp = 0                     ; Slew Rate Limit Enable bit position

; Input/Sense Configuration select
.equ PORT_ISC_INTDISABLE_gc = (0x00<<0)  ; Interrupt disabled but input buffer enabled
.equ PORT_ISC_BOTHEDGES_gc = (0x01<<0)   ; Sense Both Edges
.equ PORT_ISC_RISING_gc = (0x02<<0)      ; Sense Rising Edge
.equ PORT_ISC_FALLING_gc = (0x03<<0)     ; Sense Falling Edge
.equ PORT_ISC_INPUT_DISABLE_gc = (0x04<<0) ; Digital Input Buffer disabled
.equ PORT_ISC_LEVEL_gc = (0x05<<0)       ; Sense low Level


;*************************************************************************
;** PORTMUX - Port Multiplexer
;*************************************************************************

; PORTMUX_CCLROUTEA masks
.equ PORTMUX_LUT0_bm = 0x01              ; CCL LUT0 bit mask
.equ PORTMUX_LUT0_bp = 0                 ; CCL LUT0 bit position
.equ PORTMUX_LUT1_bm = 0x02              ; CCL LUT1 bit mask
.equ PORTMUX_LUT1_bp = 1                 ; CCL LUT1 bit position
.equ PORTMUX_LUT2_bm = 0x04              ; CCL LUT2 bit mask
.equ PORTMUX_LUT2_bp = 2                 ; CCL LUT2 bit position
.equ PORTMUX_LUT3_bm = 0x08              ; CCL LUT3 bit mask
.equ PORTMUX_LUT3_bp = 3                 ; CCL LUT3 bit position

; PORTMUX_EVSYSROUTEA masks
.equ PORTMUX_EVOUTA_bm = 0x01            ; Event Output A bit mask
.equ PORTMUX_EVOUTA_bp = 0               ; Event Output A bit position
.equ PORTMUX_EVOUTB_bm = 0x02            ; Event Output B bit mask
.equ PORTMUX_EVOUTB_bp = 1               ; Event Output B bit position
.equ PORTMUX_EVOUTC_bm = 0x04            ; Event Output C bit mask
.equ PORTMUX_EVOUTC_bp = 2               ; Event Output C bit position
.equ PORTMUX_EVOUTD_bm = 0x08            ; Event Output D bit mask
.equ PORTMUX_EVOUTD_bp = 3               ; Event Output D bit position
.equ PORTMUX_EVOUTE_bm = 0x10            ; Event Output E bit mask
.equ PORTMUX_EVOUTE_bp = 4               ; Event Output E bit position
.equ PORTMUX_EVOUTF_bm = 0x20            ; Event Output F bit mask
.equ PORTMUX_EVOUTF_bp = 5               ; Event Output F bit position

; PORTMUX_TCAROUTEA masks
.equ PORTMUX_TCA0_gm = 0x07              ; Port Multiplexer TCA0 group mask
.equ PORTMUX_TCA0_gp = 0                 ; Port Multiplexer TCA0 group position
.equ PORTMUX_TCA00_bm = (1<<0)           ; Port Multiplexer TCA0 bit 0 mask
.equ PORTMUX_TCA00_bp = 0                ; Port Multiplexer TCA0 bit 0 position
.equ PORTMUX_TCA01_bm = (1<<1)           ; Port Multiplexer TCA0 bit 1 mask
.equ PORTMUX_TCA01_bp = 1                ; Port Multiplexer TCA0 bit 1 position
.equ PORTMUX_TCA02_bm = (1<<2)           ; Port Multiplexer TCA0 bit 2 mask
.equ PORTMUX_TCA02_bp = 2                ; Port Multiplexer TCA0 bit 2 position

; PORTMUX_TCBROUTEA masks
.equ PORTMUX_TCB0_bm = 0x01              ; Port Multiplexer TCB0 bit mask
.equ PORTMUX_TCB0_bp = 0                 ; Port Multiplexer TCB0 bit position
.equ PORTMUX_TCB1_bm = 0x02              ; Port Multiplexer TCB1 bit mask
.equ PORTMUX_TCB1_bp = 1                 ; Port Multiplexer TCB1 bit position
.equ PORTMUX_TCB2_bm = 0x04              ; Port Multiplexer TCB2 bit mask
.equ PORTMUX_TCB2_bp = 2                 ; Port Multiplexer TCB2 bit position
.equ PORTMUX_TCB3_bm = 0x08              ; Port Multiplexer TCB3 bit mask
.equ PORTMUX_TCB3_bp = 3                 ; Port Multiplexer TCB3 bit position

; PORTMUX_TWISPIROUTEA masks
.equ PORTMUX_SPI0_gm = 0x03              ; Port Multiplexer SPI0 group mask
.equ PORTMUX_SPI0_gp = 0                 ; Port Multiplexer SPI0 group position
.equ PORTMUX_SPI00_bm = (1<<0)           ; Port Multiplexer SPI0 bit 0 mask
.equ PORTMUX_SPI00_bp = 0                ; Port Multiplexer SPI0 bit 0 position
.equ PORTMUX_SPI01_bm = (1<<1)           ; Port Multiplexer SPI0 bit 1 mask
.equ PORTMUX_SPI01_bp = 1                ; Port Multiplexer SPI0 bit 1 position
.equ PORTMUX_TWI0_gm = 0x30              ; Port Multiplexer TWI0 group mask
.equ PORTMUX_TWI0_gp = 4                 ; Port Multiplexer TWI0 group position
.equ PORTMUX_TWI00_bm = (1<<4)           ; Port Multiplexer TWI0 bit 0 mask
.equ PORTMUX_TWI00_bp = 4                ; Port Multiplexer TWI0 bit 0 position
.equ PORTMUX_TWI01_bm = (1<<5)           ; Port Multiplexer TWI0 bit 1 mask
.equ PORTMUX_TWI01_bp = 5                ; Port Multiplexer TWI0 bit 1 position

; PORTMUX_USARTROUTEA masks
.equ PORTMUX_USART0_gm = 0x03            ; Port Multiplexer USART0 group mask
.equ PORTMUX_USART0_gp = 0               ; Port Multiplexer USART0 group position
.equ PORTMUX_USART00_bm = (1<<0)         ; Port Multiplexer USART0 bit 0 mask
.equ PORTMUX_USART00_bp = 0              ; Port Multiplexer USART0 bit 0 position
.equ PORTMUX_USART01_bm = (1<<1)         ; Port Multiplexer USART0 bit 1 mask
.equ PORTMUX_USART01_bp = 1              ; Port Multiplexer USART0 bit 1 position
.equ PORTMUX_USART1_gm = 0x0C            ; Port Multiplexer USART1 group mask
.equ PORTMUX_USART1_gp = 2               ; Port Multiplexer USART1 group position
.equ PORTMUX_USART10_bm = (1<<2)         ; Port Multiplexer USART1 bit 0 mask
.equ PORTMUX_USART10_bp = 2              ; Port Multiplexer USART1 bit 0 position
.equ PORTMUX_USART11_bm = (1<<3)         ; Port Multiplexer USART1 bit 1 mask
.equ PORTMUX_USART11_bp = 3              ; Port Multiplexer USART1 bit 1 position
.equ PORTMUX_USART2_gm = 0x30            ; Port Multiplexer USART2 group mask
.equ PORTMUX_USART2_gp = 4               ; Port Multiplexer USART2 group position
.equ PORTMUX_USART20_bm = (1<<4)         ; Port Multiplexer USART2 bit 0 mask
.equ PORTMUX_USART20_bp = 4              ; Port Multiplexer USART2 bit 0 position
.equ PORTMUX_USART21_bm = (1<<5)         ; Port Multiplexer USART2 bit 1 mask
.equ PORTMUX_USART21_bp = 5              ; Port Multiplexer USART2 bit 1 position
.equ PORTMUX_USART3_gm = 0xC0            ; Port Multiplexer USART3 group mask
.equ PORTMUX_USART3_gp = 6               ; Port Multiplexer USART3 group position
.equ PORTMUX_USART30_bm = (1<<6)         ; Port Multiplexer USART3 bit 0 mask
.equ PORTMUX_USART30_bp = 6              ; Port Multiplexer USART3 bit 0 position
.equ PORTMUX_USART31_bm = (1<<7)         ; Port Multiplexer USART3 bit 1 mask
.equ PORTMUX_USART31_bp = 7              ; Port Multiplexer USART3 bit 1 position

; Event Output A select
.equ PORTMUX_EVOUTA_DEFAULT_gc = (0x00<<0) ; EVOUT on PA2
.equ PORTMUX_EVOUTA_ALT1_gc = (0x01<<0)  ; EVOUT on PA7

; Event Output B select
.equ PORTMUX_EVOUTB_DEFAULT_gc = (0x00<<1) ; EVOUT on PB2

; Event Output C select
.equ PORTMUX_EVOUTC_DEFAULT_gc = (0x00<<2) ; EVOUT on PC2
.equ PORTMUX_EVOUTC_ALT1_gc = (0x01<<2)  ; EVOUT on PC7

; Event Output D select
.equ PORTMUX_EVOUTD_DEFAULT_gc = (0x00<<3) ; EVOUT on PD2
.equ PORTMUX_EVOUTD_ALT1_gc = (0x01<<3)  ; EVOUT on PD7

; Event Output E select
.equ PORTMUX_EVOUTE_DEFAULT_gc = (0x00<<4) ; EVOUT on PE2

; Event Output F select
.equ PORTMUX_EVOUTF_DEFAULT_gc = (0x00<<5) ; EVOUT on PF2

; Port Multiplexer TCA0 select
.equ PORTMUX_TCA0_PORTA_gc = (0x00<<0)   ; TCA0 pins on PA[5:0]
.equ PORTMUX_TCA0_PORTB_gc = (0x01<<0)   ; TCA0 pins on PB[5:0]
.equ PORTMUX_TCA0_PORTC_gc = (0x02<<0)   ; TCA0 pins on PC[5:0]
.equ PORTMUX_TCA0_PORTD_gc = (0x03<<0)   ; TCA0 pins on PD[5:0]
.equ PORTMUX_TCA0_PORTE_gc = (0x04<<0)   ; TCA0 pins on PE[5:0]
.equ PORTMUX_TCA0_PORTF_gc = (0x05<<0)   ; TCA0 pins on PF[5:0]

; Port Multiplexer TCB0 select
.equ PORTMUX_TCB0_DEFAULT_gc = (0x00<<0) ; WO on PA2
.equ PORTMUX_TCB0_ALT1_gc = (0x01<<0)    ; WO on PF4

; Port Multiplexer TCB1 select
.equ PORTMUX_TCB1_DEFAULT_gc = (0x00<<1) ; WO on PA3
.equ PORTMUX_TCB1_ALT1_gc = (0x01<<1)    ; WO on PF5

; Port Multiplexer TCB2 select
.equ PORTMUX_TCB2_DEFAULT_gc = (0x00<<2) ; WO on PC0
.equ PORTMUX_TCB2_ALT1_gc = (0x01<<2)    ; WO on PB4

; Port Multiplexer TCB3 select
.equ PORTMUX_TCB3_DEFAULT_gc = (0x00<<3) ; WO on PB5
.equ PORTMUX_TCB3_ALT1_gc = (0x01<<3)    ; WO on PC1

; Port Multiplexer SPI0 select
.equ PORTMUX_SPI0_DEFAULT_gc = (0x00<<0) ; SPI0 on PA[7:4]
.equ PORTMUX_SPI0_ALT1_gc = (0x01<<0)    ; SPI0 on PC[3:0]
.equ PORTMUX_SPI0_ALT2_gc = (0x02<<0)    ; SPI0 on PE[3:0]
.equ PORTMUX_SPI0_NONE_gc = (0x03<<0)    ; Not connected to any pins

; Port Multiplexer TWI0 select
.equ PORTMUX_TWI0_DEFAULT_gc = (0x00<<4) ; SCL/SDA on PA[3:2], Slave mode on PC[3:2] in dual TWI mode
.equ PORTMUX_TWI0_ALT1_gc = (0x01<<4)    ; SCL/SDA on PA[3:2], Slave mode on PF[3:2] in dual TWI mode
.equ PORTMUX_TWI0_ALT2_gc = (0x02<<4)    ; SCL/SDA on PC[3:2], Slave mode on PF[3:2] in dual TWI mode
.equ PORTMUX_TWI0_NONE_gc = (0x03<<4)    ; Not connected to any pins

; Port Multiplexer USART0 select
.equ PORTMUX_USART0_DEFAULT_gc = (0x00<<0) ; USART0 on PA[3:0]
.equ PORTMUX_USART0_ALT1_gc = (0x01<<0)  ; USART0 on PA[7:4]
.equ PORTMUX_USART0_NONE_gc = (0x03<<0)  ; Not connected to any pins

; Port Multiplexer USART1 select
.equ PORTMUX_USART1_DEFAULT_gc = (0x00<<2) ; USART1 on PC[3:0]
.equ PORTMUX_USART1_ALT1_gc = (0x01<<2)  ; USART1 on PC[7:4]
.equ PORTMUX_USART1_NONE_gc = (0x03<<2)  ; Not connected to any pins

; Port Multiplexer USART2 select
.equ PORTMUX_USART2_DEFAULT_gc = (0x00<<4) ; USART2 on PF[3:0]
.equ PORTMUX_USART2_ALT1_gc = (0x01<<4)  ; USART2 on PF[6:4]
.equ PORTMUX_USART2_NONE_gc = (0x03<<4)  ; Not connected to any pins

; Port Multiplexer USART3 select
.equ PORTMUX_USART3_DEFAULT_gc = (0x00<<6) ; USART3 on PB[3:0]
.equ PORTMUX_USART3_ALT1_gc = (0x01<<6)  ; USART3 on PB[5:4]
.equ PORTMUX_USART3_NONE_gc = (0x03<<6)  ; Not connected to any pins


;*************************************************************************
;** RSTCTRL - Reset controller
;*************************************************************************

; RSTCTRL_RSTFR masks
.equ RSTCTRL_BORF_bm = 0x02              ; Brown out detector Reset flag bit mask
.equ RSTCTRL_BORF_bp = 1                 ; Brown out detector Reset flag bit position
.equ RSTCTRL_EXTRF_bm = 0x04             ; External Reset flag bit mask
.equ RSTCTRL_EXTRF_bp = 2                ; External Reset flag bit position
.equ RSTCTRL_PORF_bm = 0x01              ; Power on Reset flag bit mask
.equ RSTCTRL_PORF_bp = 0                 ; Power on Reset flag bit position
.equ RSTCTRL_SWRF_bm = 0x10              ; Software Reset flag bit mask
.equ RSTCTRL_SWRF_bp = 4                 ; Software Reset flag bit position
.equ RSTCTRL_UPDIRF_bm = 0x20            ; UPDI Reset flag bit mask
.equ RSTCTRL_UPDIRF_bp = 5               ; UPDI Reset flag bit position
.equ RSTCTRL_WDRF_bm = 0x08              ; Watch dog Reset flag bit mask
.equ RSTCTRL_WDRF_bp = 3                 ; Watch dog Reset flag bit position

; RSTCTRL_SWRR masks
.equ RSTCTRL_SWRE_bm = 0x01              ; Software reset enable bit mask
.equ RSTCTRL_SWRE_bp = 0                 ; Software reset enable bit position


;*************************************************************************
;** RTC - Real-Time Counter
;*************************************************************************

; RTC_CALIB masks
.equ RTC_ERROR_gm = 0x7F                 ; Error Correction Value group mask
.equ RTC_ERROR_gp = 0                    ; Error Correction Value group position
.equ RTC_ERROR0_bm = (1<<0)              ; Error Correction Value bit 0 mask
.equ RTC_ERROR0_bp = 0                   ; Error Correction Value bit 0 position
.equ RTC_ERROR1_bm = (1<<1)              ; Error Correction Value bit 1 mask
.equ RTC_ERROR1_bp = 1                   ; Error Correction Value bit 1 position
.equ RTC_ERROR2_bm = (1<<2)              ; Error Correction Value bit 2 mask
.equ RTC_ERROR2_bp = 2                   ; Error Correction Value bit 2 position
.equ RTC_ERROR3_bm = (1<<3)              ; Error Correction Value bit 3 mask
.equ RTC_ERROR3_bp = 3                   ; Error Correction Value bit 3 position
.equ RTC_ERROR4_bm = (1<<4)              ; Error Correction Value bit 4 mask
.equ RTC_ERROR4_bp = 4                   ; Error Correction Value bit 4 position
.equ RTC_ERROR5_bm = (1<<5)              ; Error Correction Value bit 5 mask
.equ RTC_ERROR5_bp = 5                   ; Error Correction Value bit 5 position
.equ RTC_ERROR6_bm = (1<<6)              ; Error Correction Value bit 6 mask
.equ RTC_ERROR6_bp = 6                   ; Error Correction Value bit 6 position
.equ RTC_SIGN_bm = 0x80                  ; Error Correction Sign Bit bit mask
.equ RTC_SIGN_bp = 7                     ; Error Correction Sign Bit bit position

; RTC_CLKSEL masks
.equ RTC_CLKSEL_gm = 0x03                ; Clock Select group mask
.equ RTC_CLKSEL_gp = 0                   ; Clock Select group position
.equ RTC_CLKSEL0_bm = (1<<0)             ; Clock Select bit 0 mask
.equ RTC_CLKSEL0_bp = 0                  ; Clock Select bit 0 position
.equ RTC_CLKSEL1_bm = (1<<1)             ; Clock Select bit 1 mask
.equ RTC_CLKSEL1_bp = 1                  ; Clock Select bit 1 position

; RTC_CTRLA masks
.equ RTC_CORREN_bm = 0x04                ; Correction enable bit mask
.equ RTC_CORREN_bp = 2                   ; Correction enable bit position
.equ RTC_PRESCALER_gm = 0x78             ; Prescaling Factor group mask
.equ RTC_PRESCALER_gp = 3                ; Prescaling Factor group position
.equ RTC_PRESCALER0_bm = (1<<3)          ; Prescaling Factor bit 0 mask
.equ RTC_PRESCALER0_bp = 3               ; Prescaling Factor bit 0 position
.equ RTC_PRESCALER1_bm = (1<<4)          ; Prescaling Factor bit 1 mask
.equ RTC_PRESCALER1_bp = 4               ; Prescaling Factor bit 1 position
.equ RTC_PRESCALER2_bm = (1<<5)          ; Prescaling Factor bit 2 mask
.equ RTC_PRESCALER2_bp = 5               ; Prescaling Factor bit 2 position
.equ RTC_PRESCALER3_bm = (1<<6)          ; Prescaling Factor bit 3 mask
.equ RTC_PRESCALER3_bp = 6               ; Prescaling Factor bit 3 position
.equ RTC_RTCEN_bm = 0x01                 ; Enable bit mask
.equ RTC_RTCEN_bp = 0                    ; Enable bit position
.equ RTC_RUNSTDBY_bm = 0x80              ; Run In Standby bit mask
.equ RTC_RUNSTDBY_bp = 7                 ; Run In Standby bit position

; RTC_DBGCTRL masks
.equ RTC_DBGRUN_bm = 0x01                ; Run in debug bit mask
.equ RTC_DBGRUN_bp = 0                   ; Run in debug bit position

; RTC_INTCTRL masks
.equ RTC_CMP_bm = 0x02                   ; Compare Match Interrupt enable bit mask
.equ RTC_CMP_bp = 1                      ; Compare Match Interrupt enable bit position
.equ RTC_OVF_bm = 0x01                   ; Overflow Interrupt enable bit mask
.equ RTC_OVF_bp = 0                      ; Overflow Interrupt enable bit position

; RTC_INTFLAGS masks
; Masks for RTC_CMP already defined
; Masks for RTC_OVF already defined

; RTC_PITCTRLA masks
.equ RTC_PERIOD_gm = 0x78                ; Period group mask
.equ RTC_PERIOD_gp = 3                   ; Period group position
.equ RTC_PERIOD0_bm = (1<<3)             ; Period bit 0 mask
.equ RTC_PERIOD0_bp = 3                  ; Period bit 0 position
.equ RTC_PERIOD1_bm = (1<<4)             ; Period bit 1 mask
.equ RTC_PERIOD1_bp = 4                  ; Period bit 1 position
.equ RTC_PERIOD2_bm = (1<<5)             ; Period bit 2 mask
.equ RTC_PERIOD2_bp = 5                  ; Period bit 2 position
.equ RTC_PERIOD3_bm = (1<<6)             ; Period bit 3 mask
.equ RTC_PERIOD3_bp = 6                  ; Period bit 3 position
.equ RTC_PITEN_bm = 0x01                 ; Enable bit mask
.equ RTC_PITEN_bp = 0                    ; Enable bit position

; RTC_PITDBGCTRL masks
; Masks for RTC_DBGRUN already defined

; RTC_PITINTCTRL masks
.equ RTC_PI_bm = 0x01                    ; Periodic Interrupt bit mask
.equ RTC_PI_bp = 0                       ; Periodic Interrupt bit position

; RTC_PITINTFLAGS masks
; Masks for RTC_PI already defined

; RTC_PITSTATUS masks
.equ RTC_CTRLBUSY_bm = 0x01              ; CTRLA Synchronization Busy Flag bit mask
.equ RTC_CTRLBUSY_bp = 0                 ; CTRLA Synchronization Busy Flag bit position

; RTC_STATUS masks
.equ RTC_CMPBUSY_bm = 0x08               ; Comparator Synchronization Busy Flag bit mask
.equ RTC_CMPBUSY_bp = 3                  ; Comparator Synchronization Busy Flag bit position
.equ RTC_CNTBUSY_bm = 0x02               ; Count Synchronization Busy Flag bit mask
.equ RTC_CNTBUSY_bp = 1                  ; Count Synchronization Busy Flag bit position
.equ RTC_CTRLABUSY_bm = 0x01             ; CTRLA Synchronization Busy Flag bit mask
.equ RTC_CTRLABUSY_bp = 0                ; CTRLA Synchronization Busy Flag bit position
.equ RTC_PERBUSY_bm = 0x04               ; Period Synchronization Busy Flag bit mask
.equ RTC_PERBUSY_bp = 2                  ; Period Synchronization Busy Flag bit position

; Clock Select select
.equ RTC_CLKSEL_INT32K_gc = (0x00<<0)    ; Internal 32kHz OSC
.equ RTC_CLKSEL_INT1K_gc = (0x01<<0)     ; Internal 1kHz OSC
.equ RTC_CLKSEL_TOSC32K_gc = (0x02<<0)   ; 32KHz Crystal OSC
.equ RTC_CLKSEL_EXTCLK_gc = (0x03<<0)    ; External Clock

; Prescaling Factor select
.equ RTC_PRESCALER_DIV1_gc = (0x00<<3)   ; RTC Clock / 1
.equ RTC_PRESCALER_DIV2_gc = (0x01<<3)   ; RTC Clock / 2
.equ RTC_PRESCALER_DIV4_gc = (0x02<<3)   ; RTC Clock / 4
.equ RTC_PRESCALER_DIV8_gc = (0x03<<3)   ; RTC Clock / 8
.equ RTC_PRESCALER_DIV16_gc = (0x04<<3)  ; RTC Clock / 16
.equ RTC_PRESCALER_DIV32_gc = (0x05<<3)  ; RTC Clock / 32
.equ RTC_PRESCALER_DIV64_gc = (0x06<<3)  ; RTC Clock / 64
.equ RTC_PRESCALER_DIV128_gc = (0x07<<3) ; RTC Clock / 128
.equ RTC_PRESCALER_DIV256_gc = (0x08<<3) ; RTC Clock / 256
.equ RTC_PRESCALER_DIV512_gc = (0x09<<3) ; RTC Clock / 512
.equ RTC_PRESCALER_DIV1024_gc = (0x0A<<3) ; RTC Clock / 1024
.equ RTC_PRESCALER_DIV2048_gc = (0x0B<<3) ; RTC Clock / 2048
.equ RTC_PRESCALER_DIV4096_gc = (0x0C<<3) ; RTC Clock / 4096
.equ RTC_PRESCALER_DIV8192_gc = (0x0D<<3) ; RTC Clock / 8192
.equ RTC_PRESCALER_DIV16384_gc = (0x0E<<3) ; RTC Clock / 16384
.equ RTC_PRESCALER_DIV32768_gc = (0x0F<<3) ; RTC Clock / 32768

; Period select
.equ RTC_PERIOD_OFF_gc = (0x00<<3)       ; Off
.equ RTC_PERIOD_CYC4_gc = (0x01<<3)      ; RTC Clock Cycles 4
.equ RTC_PERIOD_CYC8_gc = (0x02<<3)      ; RTC Clock Cycles 8
.equ RTC_PERIOD_CYC16_gc = (0x03<<3)     ; RTC Clock Cycles 16
.equ RTC_PERIOD_CYC32_gc = (0x04<<3)     ; RTC Clock Cycles 32
.equ RTC_PERIOD_CYC64_gc = (0x05<<3)     ; RTC Clock Cycles 64
.equ RTC_PERIOD_CYC128_gc = (0x06<<3)    ; RTC Clock Cycles 128
.equ RTC_PERIOD_CYC256_gc = (0x07<<3)    ; RTC Clock Cycles 256
.equ RTC_PERIOD_CYC512_gc = (0x08<<3)    ; RTC Clock Cycles 512
.equ RTC_PERIOD_CYC1024_gc = (0x09<<3)   ; RTC Clock Cycles 1024
.equ RTC_PERIOD_CYC2048_gc = (0x0A<<3)   ; RTC Clock Cycles 2048
.equ RTC_PERIOD_CYC4096_gc = (0x0B<<3)   ; RTC Clock Cycles 4096
.equ RTC_PERIOD_CYC8192_gc = (0x0C<<3)   ; RTC Clock Cycles 8192
.equ RTC_PERIOD_CYC16384_gc = (0x0D<<3)  ; RTC Clock Cycles 16384
.equ RTC_PERIOD_CYC32768_gc = (0x0E<<3)  ; RTC Clock Cycles 32768


;*************************************************************************
;** SIGROW - Signature row
;*************************************************************************


;*************************************************************************
;** SLPCTRL - Sleep Controller
;*************************************************************************

; SLPCTRL_CTRLA masks
.equ SLPCTRL_SEN_bm = 0x01               ; Sleep enable bit mask
.equ SLPCTRL_SEN_bp = 0                  ; Sleep enable bit position
.equ SLPCTRL_SMODE_gm = 0x06             ; Sleep mode group mask
.equ SLPCTRL_SMODE_gp = 1                ; Sleep mode group position
.equ SLPCTRL_SMODE0_bm = (1<<1)          ; Sleep mode bit 0 mask
.equ SLPCTRL_SMODE0_bp = 1               ; Sleep mode bit 0 position
.equ SLPCTRL_SMODE1_bm = (1<<2)          ; Sleep mode bit 1 mask
.equ SLPCTRL_SMODE1_bp = 2               ; Sleep mode bit 1 position

; Sleep mode select
.equ SLPCTRL_SMODE_IDLE_gc = (0x00<<1)   ; Idle mode
.equ SLPCTRL_SMODE_STDBY_gc = (0x01<<1)  ; Standby Mode
.equ SLPCTRL_SMODE_PDOWN_gc = (0x02<<1)  ; Power-down Mode


;*************************************************************************
;** SPI - Serial Peripheral Interface
;*************************************************************************

; SPI_CTRLA masks
.equ SPI_CLK2X_bm = 0x10                 ; Enable Double Speed bit mask
.equ SPI_CLK2X_bp = 4                    ; Enable Double Speed bit position
.equ SPI_DORD_bm = 0x40                  ; Data Order Setting bit mask
.equ SPI_DORD_bp = 6                     ; Data Order Setting bit position
.equ SPI_ENABLE_bm = 0x01                ; Enable Module bit mask
.equ SPI_ENABLE_bp = 0                   ; Enable Module bit position
.equ SPI_MASTER_bm = 0x20                ; Master Operation Enable bit mask
.equ SPI_MASTER_bp = 5                   ; Master Operation Enable bit position
.equ SPI_PRESC_gm = 0x06                 ; Prescaler group mask
.equ SPI_PRESC_gp = 1                    ; Prescaler group position
.equ SPI_PRESC0_bm = (1<<1)              ; Prescaler bit 0 mask
.equ SPI_PRESC0_bp = 1                   ; Prescaler bit 0 position
.equ SPI_PRESC1_bm = (1<<2)              ; Prescaler bit 1 mask
.equ SPI_PRESC1_bp = 2                   ; Prescaler bit 1 position

; SPI_CTRLB masks
.equ SPI_BUFEN_bm = 0x80                 ; Buffer Mode Enable bit mask
.equ SPI_BUFEN_bp = 7                    ; Buffer Mode Enable bit position
.equ SPI_BUFWR_bm = 0x40                 ; Buffer Write Mode bit mask
.equ SPI_BUFWR_bp = 6                    ; Buffer Write Mode bit position
.equ SPI_MODE_gm = 0x03                  ; SPI Mode group mask
.equ SPI_MODE_gp = 0                     ; SPI Mode group position
.equ SPI_MODE0_bm = (1<<0)               ; SPI Mode bit 0 mask
.equ SPI_MODE0_bp = 0                    ; SPI Mode bit 0 position
.equ SPI_MODE1_bm = (1<<1)               ; SPI Mode bit 1 mask
.equ SPI_MODE1_bp = 1                    ; SPI Mode bit 1 position
.equ SPI_SSD_bm = 0x04                   ; Slave Select Disable bit mask
.equ SPI_SSD_bp = 2                      ; Slave Select Disable bit position

; SPI_INTCTRL masks
.equ SPI_DREIE_bm = 0x20                 ; Data Register Empty Interrupt Enable bit mask
.equ SPI_DREIE_bp = 5                    ; Data Register Empty Interrupt Enable bit position
.equ SPI_IE_bm = 0x01                    ; Interrupt Enable bit mask
.equ SPI_IE_bp = 0                       ; Interrupt Enable bit position
.equ SPI_RXCIE_bm = 0x80                 ; Receive Complete Interrupt Enable bit mask
.equ SPI_RXCIE_bp = 7                    ; Receive Complete Interrupt Enable bit position
.equ SPI_SSIE_bm = 0x10                  ; Slave Select Trigger Interrupt Enable bit mask
.equ SPI_SSIE_bp = 4                     ; Slave Select Trigger Interrupt Enable bit position
.equ SPI_TXCIE_bm = 0x40                 ; Transfer Complete Interrupt Enable bit mask
.equ SPI_TXCIE_bp = 6                    ; Transfer Complete Interrupt Enable bit position

; SPI_INTFLAGS masks
.equ SPI_BUFOVF_bm = 0x01                ; Buffer Overflow bit mask
.equ SPI_BUFOVF_bp = 0                   ; Buffer Overflow bit position
.equ SPI_DREIF_bm = 0x20                 ; Data Register Empty Interrupt Flag bit mask
.equ SPI_DREIF_bp = 5                    ; Data Register Empty Interrupt Flag bit position
.equ SPI_RXCIF_bm = 0x80                 ; Receive Complete Interrupt Flag bit mask
.equ SPI_RXCIF_bp = 7                    ; Receive Complete Interrupt Flag bit position
.equ SPI_SSIF_bm = 0x10                  ; Slave Select Trigger Interrupt Flag bit mask
.equ SPI_SSIF_bp = 4                     ; Slave Select Trigger Interrupt Flag bit position
.equ SPI_TXCIF_bm = 0x40                 ; Transfer Complete Interrupt Flag bit mask
.equ SPI_TXCIF_bp = 6                    ; Transfer Complete Interrupt Flag bit position
.equ SPI_IF_bm = 0x80                    ; Interrupt Flag bit mask
.equ SPI_IF_bp = 7                       ; Interrupt Flag bit position
.equ SPI_WRCOL_bm = 0x40                 ; Write Collision bit mask
.equ SPI_WRCOL_bp = 6                    ; Write Collision bit position

; Prescaler select
.equ SPI_PRESC_DIV4_gc = (0x00<<1)       ; System Clock / 4
.equ SPI_PRESC_DIV16_gc = (0x01<<1)      ; System Clock / 16
.equ SPI_PRESC_DIV64_gc = (0x02<<1)      ; System Clock / 64
.equ SPI_PRESC_DIV128_gc = (0x03<<1)     ; System Clock / 128

; SPI Mode select
.equ SPI_MODE_0_gc = (0x00<<0)           ; SPI Mode 0
.equ SPI_MODE_1_gc = (0x01<<0)           ; SPI Mode 1
.equ SPI_MODE_2_gc = (0x02<<0)           ; SPI Mode 2
.equ SPI_MODE_3_gc = (0x03<<0)           ; SPI Mode 3


;*************************************************************************
;** SYSCFG - System Configuration Registers
;*************************************************************************

; SYSCFG_EXTBRK masks
.equ SYSCFG_ENEXTBRK_bm = 0x01           ; External break enable bit mask
.equ SYSCFG_ENEXTBRK_bp = 0              ; External break enable bit position

; SYSCFG_OCDMS masks
.equ SYSCFG_OCDMR_bm = 0x01              ; OCD Message Read bit mask
.equ SYSCFG_OCDMR_bp = 0                 ; OCD Message Read bit position


;*************************************************************************
;** TCA - 16-bit Timer/Counter Type A
;*************************************************************************

; TCA_SINGLE_CTRLA masks
.equ TCA_SINGLE_CLKSEL_gm = 0x0E         ; Clock Selection group mask
.equ TCA_SINGLE_CLKSEL_gp = 1            ; Clock Selection group position
.equ TCA_SINGLE_CLKSEL0_bm = (1<<1)      ; Clock Selection bit 0 mask
.equ TCA_SINGLE_CLKSEL0_bp = 1           ; Clock Selection bit 0 position
.equ TCA_SINGLE_CLKSEL1_bm = (1<<2)      ; Clock Selection bit 1 mask
.equ TCA_SINGLE_CLKSEL1_bp = 2           ; Clock Selection bit 1 position
.equ TCA_SINGLE_CLKSEL2_bm = (1<<3)      ; Clock Selection bit 2 mask
.equ TCA_SINGLE_CLKSEL2_bp = 3           ; Clock Selection bit 2 position
.equ TCA_SINGLE_ENABLE_bm = 0x01         ; Module Enable bit mask
.equ TCA_SINGLE_ENABLE_bp = 0            ; Module Enable bit position

; TCA_SINGLE_CTRLB masks
.equ TCA_SINGLE_ALUPD_bm = 0x08          ; Auto Lock Update bit mask
.equ TCA_SINGLE_ALUPD_bp = 3             ; Auto Lock Update bit position
.equ TCA_SINGLE_CMP0EN_bm = 0x10         ; Compare 0 Enable bit mask
.equ TCA_SINGLE_CMP0EN_bp = 4            ; Compare 0 Enable bit position
.equ TCA_SINGLE_CMP1EN_bm = 0x20         ; Compare 1 Enable bit mask
.equ TCA_SINGLE_CMP1EN_bp = 5            ; Compare 1 Enable bit position
.equ TCA_SINGLE_CMP2EN_bm = 0x40         ; Compare 2 Enable bit mask
.equ TCA_SINGLE_CMP2EN_bp = 6            ; Compare 2 Enable bit position
.equ TCA_SINGLE_WGMODE_gm = 0x07         ; Waveform generation mode group mask
.equ TCA_SINGLE_WGMODE_gp = 0            ; Waveform generation mode group position
.equ TCA_SINGLE_WGMODE0_bm = (1<<0)      ; Waveform generation mode bit 0 mask
.equ TCA_SINGLE_WGMODE0_bp = 0           ; Waveform generation mode bit 0 position
.equ TCA_SINGLE_WGMODE1_bm = (1<<1)      ; Waveform generation mode bit 1 mask
.equ TCA_SINGLE_WGMODE1_bp = 1           ; Waveform generation mode bit 1 position
.equ TCA_SINGLE_WGMODE2_bm = (1<<2)      ; Waveform generation mode bit 2 mask
.equ TCA_SINGLE_WGMODE2_bp = 2           ; Waveform generation mode bit 2 position

; TCA_SINGLE_CTRLC masks
.equ TCA_SINGLE_CMP0OV_bm = 0x01         ; Compare 0 Waveform Output Value bit mask
.equ TCA_SINGLE_CMP0OV_bp = 0            ; Compare 0 Waveform Output Value bit position
.equ TCA_SINGLE_CMP1OV_bm = 0x02         ; Compare 1 Waveform Output Value bit mask
.equ TCA_SINGLE_CMP1OV_bp = 1            ; Compare 1 Waveform Output Value bit position
.equ TCA_SINGLE_CMP2OV_bm = 0x04         ; Compare 2 Waveform Output Value bit mask
.equ TCA_SINGLE_CMP2OV_bp = 2            ; Compare 2 Waveform Output Value bit position

; TCA_SINGLE_CTRLD masks
.equ TCA_SINGLE_SPLITM_bm = 0x01         ; Split Mode Enable bit mask
.equ TCA_SINGLE_SPLITM_bp = 0            ; Split Mode Enable bit position

; TCA_SINGLE_CTRLECLR masks
.equ TCA_SINGLE_CMD_gm = 0x0C            ; Command group mask
.equ TCA_SINGLE_CMD_gp = 2               ; Command group position
.equ TCA_SINGLE_CMD0_bm = (1<<2)         ; Command bit 0 mask
.equ TCA_SINGLE_CMD0_bp = 2              ; Command bit 0 position
.equ TCA_SINGLE_CMD1_bm = (1<<3)         ; Command bit 1 mask
.equ TCA_SINGLE_CMD1_bp = 3              ; Command bit 1 position
.equ TCA_SINGLE_DIR_bm = 0x01            ; Direction bit mask
.equ TCA_SINGLE_DIR_bp = 0               ; Direction bit position
.equ TCA_SINGLE_LUPD_bm = 0x02           ; Lock Update bit mask
.equ TCA_SINGLE_LUPD_bp = 1              ; Lock Update bit position

; TCA_SINGLE_CTRLESET masks
; Masks for TCA_SINGLE_CMD already defined
; Masks for TCA_SINGLE_DIR already defined
; Masks for TCA_SINGLE_LUPD already defined

; TCA_SINGLE_CTRLFCLR masks
.equ TCA_SINGLE_CMP0BV_bm = 0x02         ; Compare 0 Buffer Valid bit mask
.equ TCA_SINGLE_CMP0BV_bp = 1            ; Compare 0 Buffer Valid bit position
.equ TCA_SINGLE_CMP1BV_bm = 0x04         ; Compare 1 Buffer Valid bit mask
.equ TCA_SINGLE_CMP1BV_bp = 2            ; Compare 1 Buffer Valid bit position
.equ TCA_SINGLE_CMP2BV_bm = 0x08         ; Compare 2 Buffer Valid bit mask
.equ TCA_SINGLE_CMP2BV_bp = 3            ; Compare 2 Buffer Valid bit position
.equ TCA_SINGLE_PERBV_bm = 0x01          ; Period Buffer Valid bit mask
.equ TCA_SINGLE_PERBV_bp = 0             ; Period Buffer Valid bit position

; TCA_SINGLE_CTRLFSET masks
; Masks for TCA_SINGLE_CMP0BV already defined
; Masks for TCA_SINGLE_CMP1BV already defined
; Masks for TCA_SINGLE_CMP2BV already defined
; Masks for TCA_SINGLE_PERBV already defined

; TCA_SINGLE_DBGCTRL masks
.equ TCA_SINGLE_DBGRUN_bm = 0x01         ; Debug Run bit mask
.equ TCA_SINGLE_DBGRUN_bp = 0            ; Debug Run bit position

; TCA_SINGLE_EVCTRL masks
.equ TCA_SINGLE_CNTEI_bm = 0x01          ; Count on Event Input bit mask
.equ TCA_SINGLE_CNTEI_bp = 0             ; Count on Event Input bit position
.equ TCA_SINGLE_EVACT_gm = 0x06          ; Event Action group mask
.equ TCA_SINGLE_EVACT_gp = 1             ; Event Action group position
.equ TCA_SINGLE_EVACT0_bm = (1<<1)       ; Event Action bit 0 mask
.equ TCA_SINGLE_EVACT0_bp = 1            ; Event Action bit 0 position
.equ TCA_SINGLE_EVACT1_bm = (1<<2)       ; Event Action bit 1 mask
.equ TCA_SINGLE_EVACT1_bp = 2            ; Event Action bit 1 position

; TCA_SINGLE_INTCTRL masks
.equ TCA_SINGLE_CMP0_bm = 0x10           ; Compare 0 Interrupt bit mask
.equ TCA_SINGLE_CMP0_bp = 4              ; Compare 0 Interrupt bit position
.equ TCA_SINGLE_CMP1_bm = 0x20           ; Compare 1 Interrupt bit mask
.equ TCA_SINGLE_CMP1_bp = 5              ; Compare 1 Interrupt bit position
.equ TCA_SINGLE_CMP2_bm = 0x40           ; Compare 2 Interrupt bit mask
.equ TCA_SINGLE_CMP2_bp = 6              ; Compare 2 Interrupt bit position
.equ TCA_SINGLE_OVF_bm = 0x01            ; Overflow Interrupt bit mask
.equ TCA_SINGLE_OVF_bp = 0               ; Overflow Interrupt bit position

; TCA_SINGLE_INTFLAGS masks
; Masks for TCA_SINGLE_CMP0 already defined
; Masks for TCA_SINGLE_CMP1 already defined
; Masks for TCA_SINGLE_CMP2 already defined
; Masks for TCA_SINGLE_OVF already defined

; TCA_SPLIT_CTRLA masks
.equ TCA_SPLIT_CLKSEL_gm = 0x0E          ; Clock Selection group mask
.equ TCA_SPLIT_CLKSEL_gp = 1             ; Clock Selection group position
.equ TCA_SPLIT_CLKSEL0_bm = (1<<1)       ; Clock Selection bit 0 mask
.equ TCA_SPLIT_CLKSEL0_bp = 1            ; Clock Selection bit 0 position
.equ TCA_SPLIT_CLKSEL1_bm = (1<<2)       ; Clock Selection bit 1 mask
.equ TCA_SPLIT_CLKSEL1_bp = 2            ; Clock Selection bit 1 position
.equ TCA_SPLIT_CLKSEL2_bm = (1<<3)       ; Clock Selection bit 2 mask
.equ TCA_SPLIT_CLKSEL2_bp = 3            ; Clock Selection bit 2 position
.equ TCA_SPLIT_ENABLE_bm = 0x01          ; Module Enable bit mask
.equ TCA_SPLIT_ENABLE_bp = 0             ; Module Enable bit position

; TCA_SPLIT_CTRLB masks
.equ TCA_SPLIT_HCMP0EN_bm = 0x10         ; High Compare 0 Enable bit mask
.equ TCA_SPLIT_HCMP0EN_bp = 4            ; High Compare 0 Enable bit position
.equ TCA_SPLIT_HCMP1EN_bm = 0x20         ; High Compare 1 Enable bit mask
.equ TCA_SPLIT_HCMP1EN_bp = 5            ; High Compare 1 Enable bit position
.equ TCA_SPLIT_HCMP2EN_bm = 0x40         ; High Compare 2 Enable bit mask
.equ TCA_SPLIT_HCMP2EN_bp = 6            ; High Compare 2 Enable bit position
.equ TCA_SPLIT_LCMP0EN_bm = 0x01         ; Low Compare 0 Enable bit mask
.equ TCA_SPLIT_LCMP0EN_bp = 0            ; Low Compare 0 Enable bit position
.equ TCA_SPLIT_LCMP1EN_bm = 0x02         ; Low Compare 1 Enable bit mask
.equ TCA_SPLIT_LCMP1EN_bp = 1            ; Low Compare 1 Enable bit position
.equ TCA_SPLIT_LCMP2EN_bm = 0x04         ; Low Compare 2 Enable bit mask
.equ TCA_SPLIT_LCMP2EN_bp = 2            ; Low Compare 2 Enable bit position

; TCA_SPLIT_CTRLC masks
.equ TCA_SPLIT_HCMP0OV_bm = 0x10         ; High Compare 0 Output Value bit mask
.equ TCA_SPLIT_HCMP0OV_bp = 4            ; High Compare 0 Output Value bit position
.equ TCA_SPLIT_HCMP1OV_bm = 0x20         ; High Compare 1 Output Value bit mask
.equ TCA_SPLIT_HCMP1OV_bp = 5            ; High Compare 1 Output Value bit position
.equ TCA_SPLIT_HCMP2OV_bm = 0x40         ; High Compare 2 Output Value bit mask
.equ TCA_SPLIT_HCMP2OV_bp = 6            ; High Compare 2 Output Value bit position
.equ TCA_SPLIT_LCMP0OV_bm = 0x01         ; Low Compare 0 Output Value bit mask
.equ TCA_SPLIT_LCMP0OV_bp = 0            ; Low Compare 0 Output Value bit position
.equ TCA_SPLIT_LCMP1OV_bm = 0x02         ; Low Compare 1 Output Value bit mask
.equ TCA_SPLIT_LCMP1OV_bp = 1            ; Low Compare 1 Output Value bit position
.equ TCA_SPLIT_LCMP2OV_bm = 0x04         ; Low Compare 2 Output Value bit mask
.equ TCA_SPLIT_LCMP2OV_bp = 2            ; Low Compare 2 Output Value bit position

; TCA_SPLIT_CTRLD masks
.equ TCA_SPLIT_SPLITM_bm = 0x01          ; Split Mode Enable bit mask
.equ TCA_SPLIT_SPLITM_bp = 0             ; Split Mode Enable bit position

; TCA_SPLIT_CTRLECLR masks
.equ TCA_SPLIT_CMD_gm = 0x0C             ; Command group mask
.equ TCA_SPLIT_CMD_gp = 2                ; Command group position
.equ TCA_SPLIT_CMD0_bm = (1<<2)          ; Command bit 0 mask
.equ TCA_SPLIT_CMD0_bp = 2               ; Command bit 0 position
.equ TCA_SPLIT_CMD1_bm = (1<<3)          ; Command bit 1 mask
.equ TCA_SPLIT_CMD1_bp = 3               ; Command bit 1 position

; TCA_SPLIT_CTRLESET masks
; Masks for TCA_SPLIT_CMD already defined

; TCA_SPLIT_DBGCTRL masks
.equ TCA_SPLIT_DBGRUN_bm = 0x01          ; Debug Run bit mask
.equ TCA_SPLIT_DBGRUN_bp = 0             ; Debug Run bit position

; TCA_SPLIT_INTCTRL masks
.equ TCA_SPLIT_HUNF_bm = 0x02            ; High Underflow Interrupt Enable bit mask
.equ TCA_SPLIT_HUNF_bp = 1               ; High Underflow Interrupt Enable bit position
.equ TCA_SPLIT_LCMP0_bm = 0x10           ; Low Compare 0 Interrupt Enable bit mask
.equ TCA_SPLIT_LCMP0_bp = 4              ; Low Compare 0 Interrupt Enable bit position
.equ TCA_SPLIT_LCMP1_bm = 0x20           ; Low Compare 1 Interrupt Enable bit mask
.equ TCA_SPLIT_LCMP1_bp = 5              ; Low Compare 1 Interrupt Enable bit position
.equ TCA_SPLIT_LCMP2_bm = 0x40           ; Low Compare 2 Interrupt Enable bit mask
.equ TCA_SPLIT_LCMP2_bp = 6              ; Low Compare 2 Interrupt Enable bit position
.equ TCA_SPLIT_LUNF_bm = 0x01            ; Low Underflow Interrupt Enable bit mask
.equ TCA_SPLIT_LUNF_bp = 0               ; Low Underflow Interrupt Enable bit position

; TCA_SPLIT_INTFLAGS masks
; Masks for TCA_SPLIT_HUNF already defined
; Masks for TCA_SPLIT_LCMP0 already defined
; Masks for TCA_SPLIT_LCMP1 already defined
; Masks for TCA_SPLIT_LCMP2 already defined
; Masks for TCA_SPLIT_LUNF already defined

; Clock Selection select
.equ TCA_SINGLE_CLKSEL_DIV1_gc = (0x00<<1) ; System Clock
.equ TCA_SINGLE_CLKSEL_DIV2_gc = (0x01<<1) ; System Clock / 2
.equ TCA_SINGLE_CLKSEL_DIV4_gc = (0x02<<1) ; System Clock / 4
.equ TCA_SINGLE_CLKSEL_DIV8_gc = (0x03<<1) ; System Clock / 8
.equ TCA_SINGLE_CLKSEL_DIV16_gc = (0x04<<1) ; System Clock / 16
.equ TCA_SINGLE_CLKSEL_DIV64_gc = (0x05<<1) ; System Clock / 64
.equ TCA_SINGLE_CLKSEL_DIV256_gc = (0x06<<1) ; System Clock / 256
.equ TCA_SINGLE_CLKSEL_DIV1024_gc = (0x07<<1) ; System Clock / 1024

; Waveform generation mode select
.equ TCA_SINGLE_WGMODE_NORMAL_gc = (0x00<<0) ; Normal Mode
.equ TCA_SINGLE_WGMODE_FRQ_gc = (0x01<<0) ; Frequency Generation Mode
.equ TCA_SINGLE_WGMODE_SINGLESLOPE_gc = (0x03<<0) ; Single Slope PWM
.equ TCA_SINGLE_WGMODE_DSTOP_gc = (0x05<<0) ; Dual Slope PWM, overflow on TOP
.equ TCA_SINGLE_WGMODE_DSBOTH_gc = (0x06<<0) ; Dual Slope PWM, overflow on TOP and BOTTOM
.equ TCA_SINGLE_WGMODE_DSBOTTOM_gc = (0x07<<0) ; Dual Slope PWM, overflow on BOTTOM

; Command select
.equ TCA_SINGLE_CMD_NONE_gc = (0x00<<2)  ; No Command
.equ TCA_SINGLE_CMD_UPDATE_gc = (0x01<<2) ; Force Update
.equ TCA_SINGLE_CMD_RESTART_gc = (0x02<<2) ; Force Restart
.equ TCA_SINGLE_CMD_RESET_gc = (0x03<<2) ; Force Hard Reset

; Direction select
.equ TCA_SINGLE_DIR_UP_gc = (0x00<<0)    ; Count up
.equ TCA_SINGLE_DIR_DOWN_gc = (0x01<<0)  ; Count down

; Event Action select
.equ TCA_SINGLE_EVACT_POSEDGE_gc = (0x00<<1) ; Count on positive edge event
.equ TCA_SINGLE_EVACT_ANYEDGE_gc = (0x01<<1) ; Count on any edge event
.equ TCA_SINGLE_EVACT_HIGHLVL_gc = (0x02<<1) ; Count on prescaled clock while event line is 1.
.equ TCA_SINGLE_EVACT_UPDOWN_gc = (0x03<<1) ; Count on prescaled clock. Event controls count direction. Up-count when event line is 0, down-count when event line is 1.

; Clock Selection select
.equ TCA_SPLIT_CLKSEL_DIV1_gc = (0x00<<1) ; System Clock
.equ TCA_SPLIT_CLKSEL_DIV2_gc = (0x01<<1) ; System Clock / 2
.equ TCA_SPLIT_CLKSEL_DIV4_gc = (0x02<<1) ; System Clock / 4
.equ TCA_SPLIT_CLKSEL_DIV8_gc = (0x03<<1) ; System Clock / 8
.equ TCA_SPLIT_CLKSEL_DIV16_gc = (0x04<<1) ; System Clock / 16
.equ TCA_SPLIT_CLKSEL_DIV64_gc = (0x05<<1) ; System Clock / 64
.equ TCA_SPLIT_CLKSEL_DIV256_gc = (0x06<<1) ; System Clock / 256
.equ TCA_SPLIT_CLKSEL_DIV1024_gc = (0x07<<1) ; System Clock / 1024

; Command select
.equ TCA_SPLIT_CMD_NONE_gc = (0x00<<2)   ; No Command
.equ TCA_SPLIT_CMD_UPDATE_gc = (0x01<<2) ; Force Update
.equ TCA_SPLIT_CMD_RESTART_gc = (0x02<<2) ; Force Restart
.equ TCA_SPLIT_CMD_RESET_gc = (0x03<<2)  ; Force Hard Reset


;*************************************************************************
;** TCB - 16-bit Timer Type B
;*************************************************************************

; TCB_CTRLA masks
.equ TCB_CLKSEL_gm = 0x06                ; Clock Select group mask
.equ TCB_CLKSEL_gp = 1                   ; Clock Select group position
.equ TCB_CLKSEL0_bm = (1<<1)             ; Clock Select bit 0 mask
.equ TCB_CLKSEL0_bp = 1                  ; Clock Select bit 0 position
.equ TCB_CLKSEL1_bm = (1<<2)             ; Clock Select bit 1 mask
.equ TCB_CLKSEL1_bp = 2                  ; Clock Select bit 1 position
.equ TCB_ENABLE_bm = 0x01                ; Enable bit mask
.equ TCB_ENABLE_bp = 0                   ; Enable bit position
.equ TCB_RUNSTDBY_bm = 0x40              ; Run Standby bit mask
.equ TCB_RUNSTDBY_bp = 6                 ; Run Standby bit position
.equ TCB_SYNCUPD_bm = 0x10               ; Synchronize Update bit mask
.equ TCB_SYNCUPD_bp = 4                  ; Synchronize Update bit position

; TCB_CTRLB masks
.equ TCB_ASYNC_bm = 0x40                 ; Asynchronous Enable bit mask
.equ TCB_ASYNC_bp = 6                    ; Asynchronous Enable bit position
.equ TCB_CCMPEN_bm = 0x10                ; Pin Output Enable bit mask
.equ TCB_CCMPEN_bp = 4                   ; Pin Output Enable bit position
.equ TCB_CCMPINIT_bm = 0x20              ; Pin Initial State bit mask
.equ TCB_CCMPINIT_bp = 5                 ; Pin Initial State bit position
.equ TCB_CNTMODE_gm = 0x07               ; Timer Mode group mask
.equ TCB_CNTMODE_gp = 0                  ; Timer Mode group position
.equ TCB_CNTMODE0_bm = (1<<0)            ; Timer Mode bit 0 mask
.equ TCB_CNTMODE0_bp = 0                 ; Timer Mode bit 0 position
.equ TCB_CNTMODE1_bm = (1<<1)            ; Timer Mode bit 1 mask
.equ TCB_CNTMODE1_bp = 1                 ; Timer Mode bit 1 position
.equ TCB_CNTMODE2_bm = (1<<2)            ; Timer Mode bit 2 mask
.equ TCB_CNTMODE2_bp = 2                 ; Timer Mode bit 2 position

; TCB_DBGCTRL masks
.equ TCB_DBGRUN_bm = 0x01                ; Debug Run bit mask
.equ TCB_DBGRUN_bp = 0                   ; Debug Run bit position

; TCB_EVCTRL masks
.equ TCB_CAPTEI_bm = 0x01                ; Event Input Enable bit mask
.equ TCB_CAPTEI_bp = 0                   ; Event Input Enable bit position
.equ TCB_EDGE_bm = 0x10                  ; Event Edge bit mask
.equ TCB_EDGE_bp = 4                     ; Event Edge bit position
.equ TCB_FILTER_bm = 0x40                ; Input Capture Noise Cancellation Filter bit mask
.equ TCB_FILTER_bp = 6                   ; Input Capture Noise Cancellation Filter bit position

; TCB_INTCTRL masks
.equ TCB_CAPT_bm = 0x01                  ; Capture or Timeout bit mask
.equ TCB_CAPT_bp = 0                     ; Capture or Timeout bit position

; TCB_INTFLAGS masks
; Masks for TCB_CAPT already defined

; TCB_STATUS masks
.equ TCB_RUN_bm = 0x01                   ; Run bit mask
.equ TCB_RUN_bp = 0                      ; Run bit position

; Clock Select select
.equ TCB_CLKSEL_CLKDIV1_gc = (0x00<<1)   ; CLK_PER (No Prescaling)
.equ TCB_CLKSEL_CLKDIV2_gc = (0x01<<1)   ; CLK_PER/2 (From Prescaler)
.equ TCB_CLKSEL_CLKTCA_gc = (0x02<<1)    ; Use Clock from TCA

; Timer Mode select
.equ TCB_CNTMODE_INT_gc = (0x00<<0)      ; Periodic Interrupt
.equ TCB_CNTMODE_TIMEOUT_gc = (0x01<<0)  ; Periodic Timeout
.equ TCB_CNTMODE_CAPT_gc = (0x02<<0)     ; Input Capture Event
.equ TCB_CNTMODE_FRQ_gc = (0x03<<0)      ; Input Capture Frequency measurement
.equ TCB_CNTMODE_PW_gc = (0x04<<0)       ; Input Capture Pulse-Width measurement
.equ TCB_CNTMODE_FRQPW_gc = (0x05<<0)    ; Input Capture Frequency and Pulse-Width measurement
.equ TCB_CNTMODE_SINGLE_gc = (0x06<<0)   ; Single Shot
.equ TCB_CNTMODE_PWM8_gc = (0x07<<0)     ; 8-bit PWM


;*************************************************************************
;** TWI - Two-Wire Interface
;*************************************************************************

; TWI_CTRLA masks
.equ TWI_FMPEN_bm = 0x02                 ; FM Plus Enable bit mask
.equ TWI_FMPEN_bp = 1                    ; FM Plus Enable bit position
.equ TWI_SDAHOLD_gm = 0x0C               ; SDA Hold Time group mask
.equ TWI_SDAHOLD_gp = 2                  ; SDA Hold Time group position
.equ TWI_SDAHOLD0_bm = (1<<2)            ; SDA Hold Time bit 0 mask
.equ TWI_SDAHOLD0_bp = 2                 ; SDA Hold Time bit 0 position
.equ TWI_SDAHOLD1_bm = (1<<3)            ; SDA Hold Time bit 1 mask
.equ TWI_SDAHOLD1_bp = 3                 ; SDA Hold Time bit 1 position
.equ TWI_SDASETUP_bm = 0x10              ; SDA Setup Time bit mask
.equ TWI_SDASETUP_bp = 4                 ; SDA Setup Time bit position

; TWI_DBGCTRL masks
.equ TWI_DBGRUN_bm = 0x01                ; Debug Run bit mask
.equ TWI_DBGRUN_bp = 0                   ; Debug Run bit position

; TWI_DUALCTRL masks
.equ TWI_ENABLE_bm = 0x01                ; Dual Control Enable bit mask
.equ TWI_ENABLE_bp = 0                   ; Dual Control Enable bit position
; Masks for TWI_FMPEN already defined
; Masks for TWI_SDAHOLD already defined

; TWI_MCTRLA masks
; Masks for TWI_ENABLE already defined
.equ TWI_QCEN_bm = 0x10                  ; Quick Command Enable bit mask
.equ TWI_QCEN_bp = 4                     ; Quick Command Enable bit position
.equ TWI_RIEN_bm = 0x80                  ; Read Interrupt Enable bit mask
.equ TWI_RIEN_bp = 7                     ; Read Interrupt Enable bit position
.equ TWI_SMEN_bm = 0x02                  ; Smart Mode Enable bit mask
.equ TWI_SMEN_bp = 1                     ; Smart Mode Enable bit position
.equ TWI_TIMEOUT_gm = 0x0C               ; Inactive Bus Timeout group mask
.equ TWI_TIMEOUT_gp = 2                  ; Inactive Bus Timeout group position
.equ TWI_TIMEOUT0_bm = (1<<2)            ; Inactive Bus Timeout bit 0 mask
.equ TWI_TIMEOUT0_bp = 2                 ; Inactive Bus Timeout bit 0 position
.equ TWI_TIMEOUT1_bm = (1<<3)            ; Inactive Bus Timeout bit 1 mask
.equ TWI_TIMEOUT1_bp = 3                 ; Inactive Bus Timeout bit 1 position
.equ TWI_WIEN_bm = 0x40                  ; Write Interrupt Enable bit mask
.equ TWI_WIEN_bp = 6                     ; Write Interrupt Enable bit position

; TWI_MCTRLB masks
.equ TWI_ACKACT_bm = 0x04                ; Acknowledge Action bit mask
.equ TWI_ACKACT_bp = 2                   ; Acknowledge Action bit position
.equ TWI_FLUSH_bm = 0x08                 ; Flush bit mask
.equ TWI_FLUSH_bp = 3                    ; Flush bit position
.equ TWI_MCMD_gm = 0x03                  ; Command group mask
.equ TWI_MCMD_gp = 0                     ; Command group position
.equ TWI_MCMD0_bm = (1<<0)               ; Command bit 0 mask
.equ TWI_MCMD0_bp = 0                    ; Command bit 0 position
.equ TWI_MCMD1_bm = (1<<1)               ; Command bit 1 mask
.equ TWI_MCMD1_bp = 1                    ; Command bit 1 position

; TWI_MSTATUS masks
.equ TWI_ARBLOST_bm = 0x08               ; Arbitration Lost bit mask
.equ TWI_ARBLOST_bp = 3                  ; Arbitration Lost bit position
.equ TWI_BUSERR_bm = 0x04                ; Bus Error bit mask
.equ TWI_BUSERR_bp = 2                   ; Bus Error bit position
.equ TWI_BUSSTATE_gm = 0x03              ; Bus State group mask
.equ TWI_BUSSTATE_gp = 0                 ; Bus State group position
.equ TWI_BUSSTATE0_bm = (1<<0)           ; Bus State bit 0 mask
.equ TWI_BUSSTATE0_bp = 0                ; Bus State bit 0 position
.equ TWI_BUSSTATE1_bm = (1<<1)           ; Bus State bit 1 mask
.equ TWI_BUSSTATE1_bp = 1                ; Bus State bit 1 position
.equ TWI_CLKHOLD_bm = 0x20               ; Clock Hold bit mask
.equ TWI_CLKHOLD_bp = 5                  ; Clock Hold bit position
.equ TWI_RIF_bm = 0x80                   ; Read Interrupt Flag bit mask
.equ TWI_RIF_bp = 7                      ; Read Interrupt Flag bit position
.equ TWI_RXACK_bm = 0x10                 ; Received Acknowledge bit mask
.equ TWI_RXACK_bp = 4                    ; Received Acknowledge bit position
.equ TWI_WIF_bm = 0x40                   ; Write Interrupt Flag bit mask
.equ TWI_WIF_bp = 6                      ; Write Interrupt Flag bit position

; TWI_SADDRMASK masks
.equ TWI_ADDREN_bm = 0x01                ; Address Enable bit mask
.equ TWI_ADDREN_bp = 0                   ; Address Enable bit position
.equ TWI_ADDRMASK_gm = 0xFE              ; Address Mask group mask
.equ TWI_ADDRMASK_gp = 1                 ; Address Mask group position
.equ TWI_ADDRMASK0_bm = (1<<1)           ; Address Mask bit 0 mask
.equ TWI_ADDRMASK0_bp = 1                ; Address Mask bit 0 position
.equ TWI_ADDRMASK1_bm = (1<<2)           ; Address Mask bit 1 mask
.equ TWI_ADDRMASK1_bp = 2                ; Address Mask bit 1 position
.equ TWI_ADDRMASK2_bm = (1<<3)           ; Address Mask bit 2 mask
.equ TWI_ADDRMASK2_bp = 3                ; Address Mask bit 2 position
.equ TWI_ADDRMASK3_bm = (1<<4)           ; Address Mask bit 3 mask
.equ TWI_ADDRMASK3_bp = 4                ; Address Mask bit 3 position
.equ TWI_ADDRMASK4_bm = (1<<5)           ; Address Mask bit 4 mask
.equ TWI_ADDRMASK4_bp = 5                ; Address Mask bit 4 position
.equ TWI_ADDRMASK5_bm = (1<<6)           ; Address Mask bit 5 mask
.equ TWI_ADDRMASK5_bp = 6                ; Address Mask bit 5 position
.equ TWI_ADDRMASK6_bm = (1<<7)           ; Address Mask bit 6 mask
.equ TWI_ADDRMASK6_bp = 7                ; Address Mask bit 6 position

; TWI_SCTRLA masks
.equ TWI_APIEN_bm = 0x40                 ; Address/Stop Interrupt Enable bit mask
.equ TWI_APIEN_bp = 6                    ; Address/Stop Interrupt Enable bit position
.equ TWI_DIEN_bm = 0x80                  ; Data Interrupt Enable bit mask
.equ TWI_DIEN_bp = 7                     ; Data Interrupt Enable bit position
; Masks for TWI_ENABLE already defined
.equ TWI_PIEN_bm = 0x20                  ; Stop Interrupt Enable bit mask
.equ TWI_PIEN_bp = 5                     ; Stop Interrupt Enable bit position
.equ TWI_PMEN_bm = 0x04                  ; Promiscuous Mode Enable bit mask
.equ TWI_PMEN_bp = 2                     ; Promiscuous Mode Enable bit position
; Masks for TWI_SMEN already defined

; TWI_SCTRLB masks
; Masks for TWI_ACKACT already defined
.equ TWI_SCMD_gm = 0x03                  ; Command group mask
.equ TWI_SCMD_gp = 0                     ; Command group position
.equ TWI_SCMD0_bm = (1<<0)               ; Command bit 0 mask
.equ TWI_SCMD0_bp = 0                    ; Command bit 0 position
.equ TWI_SCMD1_bm = (1<<1)               ; Command bit 1 mask
.equ TWI_SCMD1_bp = 1                    ; Command bit 1 position

; TWI_SSTATUS masks
.equ TWI_AP_bm = 0x01                    ; Slave Address or Stop bit mask
.equ TWI_AP_bp = 0                       ; Slave Address or Stop bit position
.equ TWI_APIF_bm = 0x40                  ; Address/Stop Interrupt Flag bit mask
.equ TWI_APIF_bp = 6                     ; Address/Stop Interrupt Flag bit position
; Masks for TWI_BUSERR already defined
; Masks for TWI_CLKHOLD already defined
.equ TWI_COLL_bm = 0x08                  ; Collision bit mask
.equ TWI_COLL_bp = 3                     ; Collision bit position
.equ TWI_DIF_bm = 0x80                   ; Data Interrupt Flag bit mask
.equ TWI_DIF_bp = 7                      ; Data Interrupt Flag bit position
.equ TWI_DIR_bm = 0x02                   ; Read/Write Direction bit mask
.equ TWI_DIR_bp = 1                      ; Read/Write Direction bit position
; Masks for TWI_RXACK already defined

; SDA Hold Time select
.equ TWI_DEFAULT_SDAHOLD_OFF_gc = (0x00<<2) ; SDA hold time off
.equ TWI_DEFAULT_SDAHOLD_50NS_gc = (0x01<<2) ; Typical 50ns hold time
.equ TWI_DEFAULT_SDAHOLD_300NS_gc = (0x02<<2) ; Typical 300ns hold time
.equ TWI_DEFAULT_SDAHOLD_500NS_gc = (0x03<<2) ; Typical 500ns hold time

; SDA Setup Time select
.equ TWI_DEFAULT_SDASETUP_4CYC_gc = (0x00<<4) ; SDA setup time is 4 clock cycles
.equ TWI_DEFAULT_SDASETUP_8CYC_gc = (0x01<<4) ; SDA setup time is 8 clock cycles

; Inactive Bus Timeout select
.equ TWI_TIMEOUT_DISABLED_gc = (0x00<<2) ; Bus Timeout Disabled
.equ TWI_TIMEOUT_50US_gc = (0x01<<2)     ; 50 Microseconds
.equ TWI_TIMEOUT_100US_gc = (0x02<<2)    ; 100 Microseconds
.equ TWI_TIMEOUT_200US_gc = (0x03<<2)    ; 200 Microseconds

; Acknowledge Action select
.equ TWI_ACKACT_ACK_gc = (0x00<<2)       ; Send ACK
.equ TWI_ACKACT_NACK_gc = (0x01<<2)      ; Send NACK

; Command select
.equ TWI_MCMD_NOACT_gc = (0x00<<0)       ; No Action
.equ TWI_MCMD_REPSTART_gc = (0x01<<0)    ; Issue Repeated Start Condition
.equ TWI_MCMD_RECVTRANS_gc = (0x02<<0)   ; Receive or Transmit Data, depending on DIR
.equ TWI_MCMD_STOP_gc = (0x03<<0)        ; Issue Stop Condition

; Bus State select
.equ TWI_BUSSTATE_UNKNOWN_gc = (0x00<<0) ; Unknown Bus State
.equ TWI_BUSSTATE_IDLE_gc = (0x01<<0)    ; Bus is Idle
.equ TWI_BUSSTATE_OWNER_gc = (0x02<<0)   ; This Module Controls The Bus
.equ TWI_BUSSTATE_BUSY_gc = (0x03<<0)    ; The Bus is Busy

; Command select
.equ TWI_SCMD_NOACT_gc = (0x00<<0)       ; No Action
.equ TWI_SCMD_COMPTRANS_gc = (0x02<<0)   ; Used To Complete a Transaction
.equ TWI_SCMD_RESPONSE_gc = (0x03<<0)    ; Used in Response to Address/Data Interrupt

; Slave Address or Stop select
.equ TWI_AP_STOP_gc = (0x00<<0)          ; Stop condition generated APIF
.equ TWI_AP_ADR_gc = (0x01<<0)           ; Address detection generated APIF


;*************************************************************************
;** USART - Universal Synchronous and Asynchronous Receiver and Transmitter
;*************************************************************************

; USART_CTRLA masks
.equ USART_ABEIE_bm = 0x04               ; Auto-baud Error Interrupt Enable bit mask
.equ USART_ABEIE_bp = 2                  ; Auto-baud Error Interrupt Enable bit position
.equ USART_DREIE_bm = 0x20               ; Data Register Empty Interrupt Enable bit mask
.equ USART_DREIE_bp = 5                  ; Data Register Empty Interrupt Enable bit position
.equ USART_LBME_bm = 0x08                ; Loop-back Mode Enable bit mask
.equ USART_LBME_bp = 3                   ; Loop-back Mode Enable bit position
.equ USART_RS485_gm = 0x03               ; RS485 Mode internal transmitter group mask
.equ USART_RS485_gp = 0                  ; RS485 Mode internal transmitter group position
.equ USART_RS4850_bm = (1<<0)            ; RS485 Mode internal transmitter bit 0 mask
.equ USART_RS4850_bp = 0                 ; RS485 Mode internal transmitter bit 0 position
.equ USART_RS4851_bm = (1<<1)            ; RS485 Mode internal transmitter bit 1 mask
.equ USART_RS4851_bp = 1                 ; RS485 Mode internal transmitter bit 1 position
.equ USART_RXCIE_bm = 0x80               ; Receive Complete Interrupt Enable bit mask
.equ USART_RXCIE_bp = 7                  ; Receive Complete Interrupt Enable bit position
.equ USART_RXSIE_bm = 0x10               ; Receiver Start Frame Interrupt Enable bit mask
.equ USART_RXSIE_bp = 4                  ; Receiver Start Frame Interrupt Enable bit position
.equ USART_TXCIE_bm = 0x40               ; Transmit Complete Interrupt Enable bit mask
.equ USART_TXCIE_bp = 6                  ; Transmit Complete Interrupt Enable bit position

; USART_CTRLB masks
.equ USART_MPCM_bm = 0x01                ; Multi-processor Communication Mode bit mask
.equ USART_MPCM_bp = 0                   ; Multi-processor Communication Mode bit position
.equ USART_ODME_bm = 0x08                ; Open Drain Mode Enable bit mask
.equ USART_ODME_bp = 3                   ; Open Drain Mode Enable bit position
.equ USART_RXEN_bm = 0x80                ; Reciever enable bit mask
.equ USART_RXEN_bp = 7                   ; Reciever enable bit position
.equ USART_RXMODE_gm = 0x06              ; Receiver Mode group mask
.equ USART_RXMODE_gp = 1                 ; Receiver Mode group position
.equ USART_RXMODE0_bm = (1<<1)           ; Receiver Mode bit 0 mask
.equ USART_RXMODE0_bp = 1                ; Receiver Mode bit 0 position
.equ USART_RXMODE1_bm = (1<<2)           ; Receiver Mode bit 1 mask
.equ USART_RXMODE1_bp = 2                ; Receiver Mode bit 1 position
.equ USART_SFDEN_bm = 0x10               ; Start Frame Detection Enable bit mask
.equ USART_SFDEN_bp = 4                  ; Start Frame Detection Enable bit position
.equ USART_TXEN_bm = 0x40                ; Transmitter Enable bit mask
.equ USART_TXEN_bp = 6                   ; Transmitter Enable bit position

; USART_CTRLC masks
.equ USART_CMODE_gm = 0xC0               ; Communication Mode group mask
.equ USART_CMODE_gp = 6                  ; Communication Mode group position
.equ USART_CMODE0_bm = (1<<6)            ; Communication Mode bit 0 mask
.equ USART_CMODE0_bp = 6                 ; Communication Mode bit 0 position
.equ USART_CMODE1_bm = (1<<7)            ; Communication Mode bit 1 mask
.equ USART_CMODE1_bp = 7                 ; Communication Mode bit 1 position
.equ USART_UCPHA_bm = 0x02               ; SPI Master Mode, Clock Phase bit mask
.equ USART_UCPHA_bp = 1                  ; SPI Master Mode, Clock Phase bit position
.equ USART_UDORD_bm = 0x04               ; SPI Master Mode, Data Order bit mask
.equ USART_UDORD_bp = 2                  ; SPI Master Mode, Data Order bit position
.equ USART_CHSIZE_gm = 0x07              ; Character Size group mask
.equ USART_CHSIZE_gp = 0                 ; Character Size group position
.equ USART_CHSIZE0_bm = (1<<0)           ; Character Size bit 0 mask
.equ USART_CHSIZE0_bp = 0                ; Character Size bit 0 position
.equ USART_CHSIZE1_bm = (1<<1)           ; Character Size bit 1 mask
.equ USART_CHSIZE1_bp = 1                ; Character Size bit 1 position
.equ USART_CHSIZE2_bm = (1<<2)           ; Character Size bit 2 mask
.equ USART_CHSIZE2_bp = 2                ; Character Size bit 2 position
; Masks for USART_CMODE already defined
.equ USART_PMODE_gm = 0x30               ; Parity Mode group mask
.equ USART_PMODE_gp = 4                  ; Parity Mode group position
.equ USART_PMODE0_bm = (1<<4)            ; Parity Mode bit 0 mask
.equ USART_PMODE0_bp = 4                 ; Parity Mode bit 0 position
.equ USART_PMODE1_bm = (1<<5)            ; Parity Mode bit 1 mask
.equ USART_PMODE1_bp = 5                 ; Parity Mode bit 1 position
.equ USART_SBMODE_bm = 0x08              ; Stop Bit Mode bit mask
.equ USART_SBMODE_bp = 3                 ; Stop Bit Mode bit position

; USART_CTRLD masks
.equ USART_ABW_gm = 0xC0                 ; Auto Baud Window group mask
.equ USART_ABW_gp = 6                    ; Auto Baud Window group position
.equ USART_ABW0_bm = (1<<6)              ; Auto Baud Window bit 0 mask
.equ USART_ABW0_bp = 6                   ; Auto Baud Window bit 0 position
.equ USART_ABW1_bm = (1<<7)              ; Auto Baud Window bit 1 mask
.equ USART_ABW1_bp = 7                   ; Auto Baud Window bit 1 position

; USART_DBGCTRL masks
.equ USART_DBGRUN_bm = 0x01              ; Debug Run bit mask
.equ USART_DBGRUN_bp = 0                 ; Debug Run bit position

; USART_EVCTRL masks
.equ USART_IREI_bm = 0x01                ; IrDA Event Input Enable bit mask
.equ USART_IREI_bp = 0                   ; IrDA Event Input Enable bit position

; USART_RXDATAH masks
.equ USART_BUFOVF_bm = 0x40              ; Buffer Overflow bit mask
.equ USART_BUFOVF_bp = 6                 ; Buffer Overflow bit position
.equ USART_DATA8_bm = 0x01               ; Receiver Data Register bit mask
.equ USART_DATA8_bp = 0                  ; Receiver Data Register bit position
.equ USART_FERR_bm = 0x04                ; Frame Error bit mask
.equ USART_FERR_bp = 2                   ; Frame Error bit position
.equ USART_PERR_bm = 0x02                ; Parity Error bit mask
.equ USART_PERR_bp = 1                   ; Parity Error bit position
.equ USART_RXCIF_bm = 0x80               ; Receive Complete Interrupt Flag bit mask
.equ USART_RXCIF_bp = 7                  ; Receive Complete Interrupt Flag bit position

; USART_RXDATAL masks
.equ USART_DATA_gm = 0xFF                ; RX Data group mask
.equ USART_DATA_gp = 0                   ; RX Data group position
.equ USART_DATA0_bm = (1<<0)             ; RX Data bit 0 mask
.equ USART_DATA0_bp = 0                  ; RX Data bit 0 position
.equ USART_DATA1_bm = (1<<1)             ; RX Data bit 1 mask
.equ USART_DATA1_bp = 1                  ; RX Data bit 1 position
.equ USART_DATA2_bm = (1<<2)             ; RX Data bit 2 mask
.equ USART_DATA2_bp = 2                  ; RX Data bit 2 position
.equ USART_DATA3_bm = (1<<3)             ; RX Data bit 3 mask
.equ USART_DATA3_bp = 3                  ; RX Data bit 3 position
.equ USART_DATA4_bm = (1<<4)             ; RX Data bit 4 mask
.equ USART_DATA4_bp = 4                  ; RX Data bit 4 position
.equ USART_DATA5_bm = (1<<5)             ; RX Data bit 5 mask
.equ USART_DATA5_bp = 5                  ; RX Data bit 5 position
.equ USART_DATA6_bm = (1<<6)             ; RX Data bit 6 mask
.equ USART_DATA6_bp = 6                  ; RX Data bit 6 position
.equ USART_DATA7_bm = (1<<7)             ; RX Data bit 7 mask
.equ USART_DATA7_bp = 7                  ; RX Data bit 7 position

; USART_RXPLCTRL masks
.equ USART_RXPL_gm = 0x7F                ; Receiver Pulse Lenght group mask
.equ USART_RXPL_gp = 0                   ; Receiver Pulse Lenght group position
.equ USART_RXPL0_bm = (1<<0)             ; Receiver Pulse Lenght bit 0 mask
.equ USART_RXPL0_bp = 0                  ; Receiver Pulse Lenght bit 0 position
.equ USART_RXPL1_bm = (1<<1)             ; Receiver Pulse Lenght bit 1 mask
.equ USART_RXPL1_bp = 1                  ; Receiver Pulse Lenght bit 1 position
.equ USART_RXPL2_bm = (1<<2)             ; Receiver Pulse Lenght bit 2 mask
.equ USART_RXPL2_bp = 2                  ; Receiver Pulse Lenght bit 2 position
.equ USART_RXPL3_bm = (1<<3)             ; Receiver Pulse Lenght bit 3 mask
.equ USART_RXPL3_bp = 3                  ; Receiver Pulse Lenght bit 3 position
.equ USART_RXPL4_bm = (1<<4)             ; Receiver Pulse Lenght bit 4 mask
.equ USART_RXPL4_bp = 4                  ; Receiver Pulse Lenght bit 4 position
.equ USART_RXPL5_bm = (1<<5)             ; Receiver Pulse Lenght bit 5 mask
.equ USART_RXPL5_bp = 5                  ; Receiver Pulse Lenght bit 5 position
.equ USART_RXPL6_bm = (1<<6)             ; Receiver Pulse Lenght bit 6 mask
.equ USART_RXPL6_bp = 6                  ; Receiver Pulse Lenght bit 6 position

; USART_STATUS masks
.equ USART_BDF_bm = 0x02                 ; Break Detected Flag bit mask
.equ USART_BDF_bp = 1                    ; Break Detected Flag bit position
.equ USART_DREIF_bm = 0x20               ; Data Register Empty Flag bit mask
.equ USART_DREIF_bp = 5                  ; Data Register Empty Flag bit position
.equ USART_ISFIF_bm = 0x08               ; Inconsistent Sync Field Interrupt Flag bit mask
.equ USART_ISFIF_bp = 3                  ; Inconsistent Sync Field Interrupt Flag bit position
; Masks for USART_RXCIF already defined
.equ USART_RXSIF_bm = 0x10               ; Receive Start Interrupt bit mask
.equ USART_RXSIF_bp = 4                  ; Receive Start Interrupt bit position
.equ USART_TXCIF_bm = 0x40               ; Transmit Interrupt Flag bit mask
.equ USART_TXCIF_bp = 6                  ; Transmit Interrupt Flag bit position
.equ USART_WFB_bm = 0x01                 ; Wait For Break bit mask
.equ USART_WFB_bp = 0                    ; Wait For Break bit position

; USART_TXDATAH masks
; Masks for USART_DATA8 already defined

; USART_TXDATAL masks
; Masks for USART_DATA already defined

; USART_TXPLCTRL masks
.equ USART_TXPL_gm = 0xFF                ; Transmit pulse length group mask
.equ USART_TXPL_gp = 0                   ; Transmit pulse length group position
.equ USART_TXPL0_bm = (1<<0)             ; Transmit pulse length bit 0 mask
.equ USART_TXPL0_bp = 0                  ; Transmit pulse length bit 0 position
.equ USART_TXPL1_bm = (1<<1)             ; Transmit pulse length bit 1 mask
.equ USART_TXPL1_bp = 1                  ; Transmit pulse length bit 1 position
.equ USART_TXPL2_bm = (1<<2)             ; Transmit pulse length bit 2 mask
.equ USART_TXPL2_bp = 2                  ; Transmit pulse length bit 2 position
.equ USART_TXPL3_bm = (1<<3)             ; Transmit pulse length bit 3 mask
.equ USART_TXPL3_bp = 3                  ; Transmit pulse length bit 3 position
.equ USART_TXPL4_bm = (1<<4)             ; Transmit pulse length bit 4 mask
.equ USART_TXPL4_bp = 4                  ; Transmit pulse length bit 4 position
.equ USART_TXPL5_bm = (1<<5)             ; Transmit pulse length bit 5 mask
.equ USART_TXPL5_bp = 5                  ; Transmit pulse length bit 5 position
.equ USART_TXPL6_bm = (1<<6)             ; Transmit pulse length bit 6 mask
.equ USART_TXPL6_bp = 6                  ; Transmit pulse length bit 6 position
.equ USART_TXPL7_bm = (1<<7)             ; Transmit pulse length bit 7 mask
.equ USART_TXPL7_bp = 7                  ; Transmit pulse length bit 7 position

; RS485 Mode internal transmitter select
.equ USART_RS485_OFF_gc = (0x00<<0)      ; RS485 Mode disabled
.equ USART_RS485_EXT_gc = (0x01<<0)      ; RS485 Mode External drive
.equ USART_RS485_INT_gc = (0x02<<0)      ; RS485 Mode Internal drive

; Receiver Mode select
.equ USART_RXMODE_NORMAL_gc = (0x00<<1)  ; Normal mode
.equ USART_RXMODE_CLK2X_gc = (0x01<<1)   ; CLK2x mode
.equ USART_RXMODE_GENAUTO_gc = (0x02<<1) ; Generic autobaud mode
.equ USART_RXMODE_LINAUTO_gc = (0x03<<1) ; LIN constrained autobaud mode

; Communication Mode select
.equ USART_MSPI_CMODE_ASYNCHRONOUS_gc = (0x00<<6) ; Asynchronous Mode
.equ USART_MSPI_CMODE_SYNCHRONOUS_gc = (0x01<<6) ; Synchronous Mode
.equ USART_MSPI_CMODE_IRCOM_gc = (0x02<<6) ; Infrared Communication
.equ USART_MSPI_CMODE_MSPI_gc = (0x03<<6) ; Master SPI Mode

; Character Size select
.equ USART_NORMAL_CHSIZE_5BIT_gc = (0x00<<0) ; Character size: 5 bit
.equ USART_NORMAL_CHSIZE_6BIT_gc = (0x01<<0) ; Character size: 6 bit
.equ USART_NORMAL_CHSIZE_7BIT_gc = (0x02<<0) ; Character size: 7 bit
.equ USART_NORMAL_CHSIZE_8BIT_gc = (0x03<<0) ; Character size: 8 bit
.equ USART_NORMAL_CHSIZE_9BITL_gc = (0x06<<0) ; Character size: 9 bit read low byte first
.equ USART_NORMAL_CHSIZE_9BITH_gc = (0x07<<0) ; Character size: 9 bit read high byte first

; Communication Mode select
.equ USART_NORMAL_CMODE_ASYNCHRONOUS_gc = (0x00<<6) ; Asynchronous Mode
.equ USART_NORMAL_CMODE_SYNCHRONOUS_gc = (0x01<<6) ; Synchronous Mode
.equ USART_NORMAL_CMODE_IRCOM_gc = (0x02<<6) ; Infrared Communication
.equ USART_NORMAL_CMODE_MSPI_gc = (0x03<<6) ; Master SPI Mode

; Parity Mode select
.equ USART_NORMAL_PMODE_DISABLED_gc = (0x00<<4) ; No Parity
.equ USART_NORMAL_PMODE_EVEN_gc = (0x02<<4) ; Even Parity
.equ USART_NORMAL_PMODE_ODD_gc = (0x03<<4) ; Odd Parity

; Stop Bit Mode select
.equ USART_NORMAL_SBMODE_1BIT_gc = (0x00<<3) ; 1 stop bit
.equ USART_NORMAL_SBMODE_2BIT_gc = (0x01<<3) ; 2 stop bits

; Auto Baud Window select
.equ USART_ABW_WDW0_gc = (0x00<<6)       ; 18% tolerance
.equ USART_ABW_WDW1_gc = (0x01<<6)       ; 15% tolerance
.equ USART_ABW_WDW2_gc = (0x02<<6)       ; 21% tolerance
.equ USART_ABW_WDW3_gc = (0x03<<6)       ; 25% tolerance


;*************************************************************************
;** USERROW - User Row
;*************************************************************************


;*************************************************************************
;** VPORT - Virtual Ports
;*************************************************************************

; VPORT_INTFLAGS masks
.equ VPORT_INT_gm = 0xFF                 ; Pin Interrupt group mask
.equ VPORT_INT_gp = 0                    ; Pin Interrupt group position
.equ VPORT_INT0_bm = (1<<0)              ; Pin Interrupt bit 0 mask
.equ VPORT_INT0_bp = 0                   ; Pin Interrupt bit 0 position
.equ VPORT_INT1_bm = (1<<1)              ; Pin Interrupt bit 1 mask
.equ VPORT_INT1_bp = 1                   ; Pin Interrupt bit 1 position
.equ VPORT_INT2_bm = (1<<2)              ; Pin Interrupt bit 2 mask
.equ VPORT_INT2_bp = 2                   ; Pin Interrupt bit 2 position
.equ VPORT_INT3_bm = (1<<3)              ; Pin Interrupt bit 3 mask
.equ VPORT_INT3_bp = 3                   ; Pin Interrupt bit 3 position
.equ VPORT_INT4_bm = (1<<4)              ; Pin Interrupt bit 4 mask
.equ VPORT_INT4_bp = 4                   ; Pin Interrupt bit 4 position
.equ VPORT_INT5_bm = (1<<5)              ; Pin Interrupt bit 5 mask
.equ VPORT_INT5_bp = 5                   ; Pin Interrupt bit 5 position
.equ VPORT_INT6_bm = (1<<6)              ; Pin Interrupt bit 6 mask
.equ VPORT_INT6_bp = 6                   ; Pin Interrupt bit 6 position
.equ VPORT_INT7_bm = (1<<7)              ; Pin Interrupt bit 7 mask
.equ VPORT_INT7_bp = 7                   ; Pin Interrupt bit 7 position


;*************************************************************************
;** VREF - Voltage reference
;*************************************************************************

; VREF_CTRLA masks
.equ VREF_AC0REFSEL_gm = 0x07            ; AC0 reference select group mask
.equ VREF_AC0REFSEL_gp = 0               ; AC0 reference select group position
.equ VREF_AC0REFSEL0_bm = (1<<0)         ; AC0 reference select bit 0 mask
.equ VREF_AC0REFSEL0_bp = 0              ; AC0 reference select bit 0 position
.equ VREF_AC0REFSEL1_bm = (1<<1)         ; AC0 reference select bit 1 mask
.equ VREF_AC0REFSEL1_bp = 1              ; AC0 reference select bit 1 position
.equ VREF_AC0REFSEL2_bm = (1<<2)         ; AC0 reference select bit 2 mask
.equ VREF_AC0REFSEL2_bp = 2              ; AC0 reference select bit 2 position
.equ VREF_ADC0REFSEL_gm = 0x70           ; ADC0 reference select group mask
.equ VREF_ADC0REFSEL_gp = 4              ; ADC0 reference select group position
.equ VREF_ADC0REFSEL0_bm = (1<<4)        ; ADC0 reference select bit 0 mask
.equ VREF_ADC0REFSEL0_bp = 4             ; ADC0 reference select bit 0 position
.equ VREF_ADC0REFSEL1_bm = (1<<5)        ; ADC0 reference select bit 1 mask
.equ VREF_ADC0REFSEL1_bp = 5             ; ADC0 reference select bit 1 position
.equ VREF_ADC0REFSEL2_bm = (1<<6)        ; ADC0 reference select bit 2 mask
.equ VREF_ADC0REFSEL2_bp = 6             ; ADC0 reference select bit 2 position

; VREF_CTRLB masks
.equ VREF_AC0REFEN_bm = 0x01             ; AC0 DACREF reference enable bit mask
.equ VREF_AC0REFEN_bp = 0                ; AC0 DACREF reference enable bit position
.equ VREF_ADC0REFEN_bm = 0x02            ; ADC0 reference enable bit mask
.equ VREF_ADC0REFEN_bp = 1               ; ADC0 reference enable bit position

; AC0 reference select select
.equ VREF_AC0REFSEL_0V55_gc = (0x00<<0)  ; Voltage reference at 0.55V
.equ VREF_AC0REFSEL_1V1_gc = (0x01<<0)   ; Voltage reference at 1.1V
.equ VREF_AC0REFSEL_2V5_gc = (0x02<<0)   ; Voltage reference at 2.5V
.equ VREF_AC0REFSEL_4V34_gc = (0x03<<0)  ; Voltage reference at 4.34V
.equ VREF_AC0REFSEL_1V5_gc = (0x04<<0)   ; Voltage reference at 1.5V
.equ VREF_AC0REFSEL_AVDD_gc = (0x07<<0)  ; AVDD

; ADC0 reference select select
.equ VREF_ADC0REFSEL_0V55_gc = (0x00<<4) ; Voltage reference at 0.55V
.equ VREF_ADC0REFSEL_1V1_gc = (0x01<<4)  ; Voltage reference at 1.1V
.equ VREF_ADC0REFSEL_2V5_gc = (0x02<<4)  ; Voltage reference at 2.5V
.equ VREF_ADC0REFSEL_4V34_gc = (0x03<<4) ; Voltage reference at 4.34V
.equ VREF_ADC0REFSEL_1V5_gc = (0x04<<4)  ; Voltage reference at 1.5V


;*************************************************************************
;** WDT - Watch-Dog Timer
;*************************************************************************

; WDT_CTRLA masks
.equ WDT_PERIOD_gm = 0x0F                ; Period group mask
.equ WDT_PERIOD_gp = 0                   ; Period group position
.equ WDT_PERIOD0_bm = (1<<0)             ; Period bit 0 mask
.equ WDT_PERIOD0_bp = 0                  ; Period bit 0 position
.equ WDT_PERIOD1_bm = (1<<1)             ; Period bit 1 mask
.equ WDT_PERIOD1_bp = 1                  ; Period bit 1 position
.equ WDT_PERIOD2_bm = (1<<2)             ; Period bit 2 mask
.equ WDT_PERIOD2_bp = 2                  ; Period bit 2 position
.equ WDT_PERIOD3_bm = (1<<3)             ; Period bit 3 mask
.equ WDT_PERIOD3_bp = 3                  ; Period bit 3 position
.equ WDT_WINDOW_gm = 0xF0                ; Window group mask
.equ WDT_WINDOW_gp = 4                   ; Window group position
.equ WDT_WINDOW0_bm = (1<<4)             ; Window bit 0 mask
.equ WDT_WINDOW0_bp = 4                  ; Window bit 0 position
.equ WDT_WINDOW1_bm = (1<<5)             ; Window bit 1 mask
.equ WDT_WINDOW1_bp = 5                  ; Window bit 1 position
.equ WDT_WINDOW2_bm = (1<<6)             ; Window bit 2 mask
.equ WDT_WINDOW2_bp = 6                  ; Window bit 2 position
.equ WDT_WINDOW3_bm = (1<<7)             ; Window bit 3 mask
.equ WDT_WINDOW3_bp = 7                  ; Window bit 3 position

; WDT_STATUS masks
.equ WDT_LOCK_bm = 0x80                  ; Lock enable bit mask
.equ WDT_LOCK_bp = 7                     ; Lock enable bit position
.equ WDT_SYNCBUSY_bm = 0x01              ; Syncronization busy bit mask
.equ WDT_SYNCBUSY_bp = 0                 ; Syncronization busy bit position

; Period select
.equ WDT_PERIOD_OFF_gc = (0x00<<0)       ; Off
.equ WDT_PERIOD_8CLK_gc = (0x01<<0)      ; 8 cycles (8ms)
.equ WDT_PERIOD_16CLK_gc = (0x02<<0)     ; 16 cycles (16ms)
.equ WDT_PERIOD_32CLK_gc = (0x03<<0)     ; 32 cycles (32ms)
.equ WDT_PERIOD_64CLK_gc = (0x04<<0)     ; 64 cycles (64ms)
.equ WDT_PERIOD_128CLK_gc = (0x05<<0)    ; 128 cycles (0.128s)
.equ WDT_PERIOD_256CLK_gc = (0x06<<0)    ; 256 cycles (0.256s)
.equ WDT_PERIOD_512CLK_gc = (0x07<<0)    ; 512 cycles (0.512s)
.equ WDT_PERIOD_1KCLK_gc = (0x08<<0)     ; 1K cycles (1.0s)
.equ WDT_PERIOD_2KCLK_gc = (0x09<<0)     ; 2K cycles (2.0s)
.equ WDT_PERIOD_4KCLK_gc = (0x0A<<0)     ; 4K cycles (4.1s)
.equ WDT_PERIOD_8KCLK_gc = (0x0B<<0)     ; 8K cycles (8.2s)

; Window select
.equ WDT_WINDOW_OFF_gc = (0x00<<4)       ; Off
.equ WDT_WINDOW_8CLK_gc = (0x01<<4)      ; 8 cycles (8ms)
.equ WDT_WINDOW_16CLK_gc = (0x02<<4)     ; 16 cycles (16ms)
.equ WDT_WINDOW_32CLK_gc = (0x03<<4)     ; 32 cycles (32ms)
.equ WDT_WINDOW_64CLK_gc = (0x04<<4)     ; 64 cycles (64ms)
.equ WDT_WINDOW_128CLK_gc = (0x05<<4)    ; 128 cycles (0.128s)
.equ WDT_WINDOW_256CLK_gc = (0x06<<4)    ; 256 cycles (0.256s)
.equ WDT_WINDOW_512CLK_gc = (0x07<<4)    ; 512 cycles (0.512s)
.equ WDT_WINDOW_1KCLK_gc = (0x08<<4)     ; 1K cycles (1.0s)
.equ WDT_WINDOW_2KCLK_gc = (0x09<<4)     ; 2K cycles (2.0s)
.equ WDT_WINDOW_4KCLK_gc = (0x0A<<4)     ; 4K cycles (4.1s)
.equ WDT_WINDOW_8KCLK_gc = (0x0B<<4)     ; 8K cycles (8.2s)




; ***** CPU REGISTER DEFINITIONS *****************************************
.def	XH	= r27
.def	XL	= r26
.def	YH	= r29
.def	YL	= r28
.def	ZH	= r31
.def	ZL	= r30


; ***** DATA MEMORY DECLARATIONS *****************************************


#define DATAMEM_START 0x0000
#define DATAMEM_SIZE 0x10000
#define DATAMEM_END (0x0000 + 0x10000 - 1)

#define EEPROM_START 0x1400
#define EEPROM_SIZE 0x0100
#define EEPROM_END (0x1400 + 0x0100 - 1)
#define EEPROM_PAGE_SIZE 0x40

#define FUSES_START 0x1280
#define FUSES_SIZE 0x000A
#define FUSES_END (0x1280 + 0x000A - 1)
#define FUSES_PAGE_SIZE 0x40

#define INTERNAL_SRAM_START 0x2800
#define INTERNAL_SRAM_SIZE 0x1800
#define INTERNAL_SRAM_END (0x2800 + 0x1800 - 1)

#define IO_START 0x0000
#define IO_SIZE 0x1100
#define IO_END (0x0000 + 0x1100 - 1)

#define LOCKBITS_START 0x128A
#define LOCKBITS_SIZE 0x0001
#define LOCKBITS_END (0x128A + 0x0001 - 1)
#define LOCKBITS_PAGE_SIZE 0x40

#define MAPPED_PROGMEM_START 0x4000
#define MAPPED_PROGMEM_SIZE 0xC000
#define MAPPED_PROGMEM_END (0x4000 + 0xC000 - 1)
#define MAPPED_PROGMEM_PAGE_SIZE 0x80

#define PROD_SIGNATURES_START 0x1103
#define PROD_SIGNATURES_SIZE 0x007D
#define PROD_SIGNATURES_END (0x1103 + 0x007D - 1)
#define PROD_SIGNATURES_PAGE_SIZE 0x80

#define SIGNATURES_START 0x1100
#define SIGNATURES_SIZE 0x0003
#define SIGNATURES_END (0x1100 + 0x0003 - 1)
#define SIGNATURES_PAGE_SIZE 0x80

#define USER_SIGNATURES_START 0x1300
#define USER_SIGNATURES_SIZE 0x0040
#define USER_SIGNATURES_END (0x1300 + 0x0040 - 1)
#define USER_SIGNATURES_PAGE_SIZE 0x40

#define PROGMEM_START 0x0000
#define PROGMEM_SIZE 0xC000
#define PROGMEM_END (0x0000 + 0xC000 - 1)
#define PROGMEM_PAGE_SIZE 0x80


; Legacy definitions
.equ    FLASHSTART    = (PROGMEM_START / 2) ; Note: Word address
.equ    FLASHEND      = (PROGMEM_END / 2) ; Note: Word address
.equ    IOEND         = IO_END
.equ    SRAM_START    = INTERNAL_SRAM_START
.equ    SRAM_SIZE     = INTERNAL_SRAM_SIZE
.equ    RAMEND        = INTERNAL_SRAM_END
.equ    E2END         = EEPROM_END
.equ    EEPROMEND     = EEPROM_END


; Definitions used by the assembler
#pragma AVRPART MEMORY PROG_FLASH 0xC000
#pragma AVRPART MEMORY EEPROM 0x0100
#pragma AVRPART MEMORY INT_SRAM SIZE 0x1800
#pragma AVRPART MEMORY INT_SRAM START_ADDR 0x2800

; ***** INTERRUPT VECTORS, ABSOLUTE ADDRESSES ****************************

; CRCSCAN interrupt vectors
.equ CRCSCAN_NMI_vect = 0x0002           ; 

; BOD interrupt vectors
.equ BOD_VLM_vect = 0x0004               ; 

; RTC interrupt vectors
.equ RTC_CNT_vect = 0x0006               ; 
.equ RTC_PIT_vect = 0x0008               ; 

; CCL interrupt vectors
.equ CCL_CCL_vect = 0x000A               ; 

; PORTA interrupt vectors
.equ PORTA_PORT_vect = 0x000C            ; 

; TCA0 interrupt vectors
.equ TCA0_LUNF_vect = 0x000E             ; 
.equ TCA0_OVF_vect = 0x000E              ; 
.equ TCA0_HUNF_vect = 0x0010             ; 
.equ TCA0_CMP0_vect = 0x0012             ; 
.equ TCA0_LCMP0_vect = 0x0012            ; 
.equ TCA0_CMP1_vect = 0x0014             ; 
.equ TCA0_LCMP1_vect = 0x0014            ; 
.equ TCA0_CMP2_vect = 0x0016             ; 
.equ TCA0_LCMP2_vect = 0x0016            ; 

; TCB0 interrupt vectors
.equ TCB0_INT_vect = 0x0018              ; 

; TCB1 interrupt vectors
.equ TCB1_INT_vect = 0x001A              ; 

; TWI0 interrupt vectors
.equ TWI0_TWIS_vect = 0x001C             ; 
.equ TWI0_TWIM_vect = 0x001E             ; 

; SPI0 interrupt vectors
.equ SPI0_INT_vect = 0x0020              ; 

; USART0 interrupt vectors
.equ USART0_RXC_vect = 0x0022            ; 
.equ USART0_DRE_vect = 0x0024            ; 
.equ USART0_TXC_vect = 0x0026            ; 

; PORTD interrupt vectors
.equ PORTD_PORT_vect = 0x0028            ; 

; AC0 interrupt vectors
.equ AC0_AC_vect = 0x002A                ; 

; ADC0 interrupt vectors
.equ ADC0_RESRDY_vect = 0x002C           ; 
.equ ADC0_WCOMP_vect = 0x002E            ; 

; PORTC interrupt vectors
.equ PORTC_PORT_vect = 0x0030            ; 

; TCB2 interrupt vectors
.equ TCB2_INT_vect = 0x0032              ; 

; USART1 interrupt vectors
.equ USART1_RXC_vect = 0x0034            ; 
.equ USART1_DRE_vect = 0x0036            ; 
.equ USART1_TXC_vect = 0x0038            ; 

; PORTF interrupt vectors
.equ PORTF_PORT_vect = 0x003A            ; 

; NVMCTRL interrupt vectors
.equ NVMCTRL_EE_vect = 0x003C            ; 

; USART2 interrupt vectors
.equ USART2_RXC_vect = 0x003E            ; 
.equ USART2_DRE_vect = 0x0040            ; 
.equ USART2_TXC_vect = 0x0042            ; 

; PORTB interrupt vectors
.equ PORTB_PORT_vect = 0x0044            ; 

; PORTE interrupt vectors
.equ PORTE_PORT_vect = 0x0046            ; 

; TCB3 interrupt vectors
.equ TCB3_INT_vect = 0x0048              ; 

; USART3 interrupt vectors
.equ USART3_RXC_vect = 0x004A            ; 
.equ USART3_DRE_vect = 0x004C            ; 
.equ USART3_TXC_vect = 0x004E            ; 



; ***** INTERRUPT VECTORS, MODULE BASES **********************************

.equ CRCSCAN_vbase = 0x0002
.equ BOD_vbase = 0x0004
.equ RTC_vbase = 0x0006
.equ CCL_vbase = 0x000A
.equ PORTA_vbase = 0x000C
.equ TCA0_vbase = 0x000E
.equ TCB0_vbase = 0x0018
.equ TCB1_vbase = 0x001A
.equ TWI0_vbase = 0x001C
.equ SPI0_vbase = 0x0020
.equ USART0_vbase = 0x0022
.equ PORTD_vbase = 0x0028
.equ AC0_vbase = 0x002A
.equ ADC0_vbase = 0x002C
.equ PORTC_vbase = 0x0030
.equ TCB2_vbase = 0x0032
.equ USART1_vbase = 0x0034
.equ PORTF_vbase = 0x003A
.equ NVMCTRL_vbase = 0x003C
.equ USART2_vbase = 0x003E
.equ PORTB_vbase = 0x0044
.equ PORTE_vbase = 0x0046
.equ TCB3_vbase = 0x0048
.equ USART3_vbase = 0x004A


; ***** INTERRUPT VECTORS, VECTOR OFFSETS ********************************

; CRCSCAN interrupt vector offsets

.equ CRCSCAN_NMI_voffset = 0

; BOD interrupt vector offsets

.equ BOD_VLM_voffset = 0

; RTC interrupt vector offsets

.equ RTC_CNT_voffset = 0
.equ RTC_PIT_voffset = 2

; CCL interrupt vector offsets

.equ CCL_CCL_voffset = 0

; PORTA interrupt vector offsets

.equ PORTA_PORT_voffset = 0

; TCA0 interrupt vector offsets

.equ TCA0_LUNF_voffset = 0
.equ TCA0_OVF_voffset = 0
.equ TCA0_HUNF_voffset = 2
.equ TCA0_CMP0_voffset = 4
.equ TCA0_LCMP0_voffset = 4
.equ TCA0_CMP1_voffset = 6
.equ TCA0_LCMP1_voffset = 6
.equ TCA0_CMP2_voffset = 8
.equ TCA0_LCMP2_voffset = 8

; TCB0 interrupt vector offsets

.equ TCB0_INT_voffset = 0

; TCB1 interrupt vector offsets

.equ TCB1_INT_voffset = 0

; TWI0 interrupt vector offsets

.equ TWI0_TWIS_voffset = 0
.equ TWI0_TWIM_voffset = 2

; SPI0 interrupt vector offsets

.equ SPI0_INT_voffset = 0

; USART0 interrupt vector offsets

.equ USART0_RXC_voffset = 0
.equ USART0_DRE_voffset = 2
.equ USART0_TXC_voffset = 4

; PORTD interrupt vector offsets

.equ PORTD_PORT_voffset = 0

; AC0 interrupt vector offsets

.equ AC0_AC_voffset = 0

; ADC0 interrupt vector offsets

.equ ADC0_RESRDY_voffset = 0
.equ ADC0_WCOMP_voffset = 2

; PORTC interrupt vector offsets

.equ PORTC_PORT_voffset = 0

; TCB2 interrupt vector offsets

.equ TCB2_INT_voffset = 0

; USART1 interrupt vector offsets

.equ USART1_RXC_voffset = 0
.equ USART1_DRE_voffset = 2
.equ USART1_TXC_voffset = 4

; PORTF interrupt vector offsets

.equ PORTF_PORT_voffset = 0

; NVMCTRL interrupt vector offsets

.equ NVMCTRL_EE_voffset = 0

; USART2 interrupt vector offsets

.equ USART2_RXC_voffset = 0
.equ USART2_DRE_voffset = 2
.equ USART2_TXC_voffset = 4

; PORTB interrupt vector offsets

.equ PORTB_PORT_voffset = 0

; PORTE interrupt vector offsets

.equ PORTE_PORT_voffset = 0

; TCB3 interrupt vector offsets

.equ TCB3_INT_voffset = 0

; USART3 interrupt vector offsets

.equ USART3_RXC_voffset = 0
.equ USART3_DRE_voffset = 2
.equ USART3_TXC_voffset = 4



.equ INT_VECTORS_SIZE = 80 ; size in words


#endif /* _M4809DEF_INC_ */

; ***** END OF FILE ******************************************************



