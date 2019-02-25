.device ATmega328P

; REGISTER USAGE
;
; R1: overflow counter. pin status tied to 7th bit
; R16: tmp stuff

	RJMP    MAIN

MAIN:
        LDI     R16, 0xff	; low RAMEND
        OUT     0x3d, R16	; SPL
        LDI     R16, 0x08	; high RAMEND
        OUT     0x3e, R16	; SPH

        SBI     0x04, 5		; DDRB5, output
        CBI     0x05, 5		; PORTB5, off

	; To have a blinking delay that's visible, we have to prescale a lot.
	; The maximum prescaler is 1024, which makes our TCNT0 increase
	; 15625 times per second, which means that it overflows 61 times per
	; second. That's manageable. If we keep a count of overflows in a
	; register and tie our LED to its highest bit, we get a 4 seconds span
	; for that counter. Good enough.
        IN      R16, 0x25	; TCCR0B
        ORI     R16, 0x05	; CS00 + CS02 = 1024 prescaler
        OUT     0x25, R16

        CLR     R1		; initialize overflow counter

LOOP:
	IN	R16, 0x15	; TIFR0
	SBRC	R16, 0		; is TOV flag clear?
	RCALL	TOGGLE
        RJMP    LOOP

TOGGLE:
	LDI	R16, 0x01
	OUT	0x15, R16
	INC	R1
        CBI     0x05, 5		; PORTB5, off
        SBRS    R1, 7		; if LED is on
        SBI     0x05, 5		; PORTB5, on
	RET
