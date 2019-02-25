.device ATmega328P
#pragma overlap warning
	.org $101
	ret
	.org $100
	jmp $102
