.device ATmega328P
#pragma overlap error
	.cseg
	.org $100
	ret
	.dseg
	.org $100
	.byte 1
