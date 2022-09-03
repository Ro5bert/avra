.device atmega168
.macro DEST
	.dw @0
.endmacro
nop
KEYLOOP:
	DEST(KEYLOOP)
.if(1)
nop
.endif
