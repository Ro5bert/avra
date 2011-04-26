.device ATmega328P
#pragma overlap warning
	.overlap
	.org $024
	rcall	isr
	.org $026
	rcall	isr

isr:
	reti
usart_rx_isr:
	reti

	.org $024
	jmp		usart_rx_isr
