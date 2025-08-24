.device atmega168

.equ F_CPU = 16000000

.macro delay1
	.set cycles = @0 * (F_CPU / 1000000)
	.dw cycles
	.if cycles != 16000
	.error "error in calculation"
	.endif
.endmacro

.macro delay2
	.set cycles = (@0 * F_CPU) / 1000000
	.dw cycles
	.if cycles != 16000
	.error "error in calculation"
	.endif
.endmacro

.macro delay3
	.set cycles = ( ( @0 * F_CPU ) / 1000000 )
	.dw cycles
	.if cycles != 16000
	.error "error in calculation"
	.endif
.endmacro

nop
delay1 1000
delay2 1000
delay3 1000
