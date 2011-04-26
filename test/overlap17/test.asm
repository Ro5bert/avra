.device ATmega328P
#pragma overlap warning
	.dseg
	.org $100
	.byte 1
	.cseg
	.org $100
	ret
	.dseg
	.org $100
	.byte 1
