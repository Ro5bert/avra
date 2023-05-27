.device atmega328p

; Multiply test (result exceeds 32bit integer range)

.equ F_CPU = 16000000

.if 1000*F_CPU/1000000 != 16000
    .error "1000*F_CPU/1000000 != 16000"
.endif

; 64bit contant tests

.equ BIG_CONST = 0x1A2B3C4D5E6F7182

.if LOW(BIG_CONST) != 0x82
    .error "LOW(BIG_CONST) != 0x82"
.endif

.if HIGH(BIG_CONST) != 0x71
    .error "HIGH(BIG_CONST) != 0x71"
.endif

.if BYTE3(BIG_CONST) != 0x6F
    .error "BYTE3(BIG_CONST) != 0x6F"
.endif

.if BYTE4(BIG_CONST) != 0x5E
    .error "BYTE4(BIG_CONST) != 0x5E"
.endif

.if LOW(BIG_CONST>>32) != 0x4D
    .error "LOW(BIG_CONST>>32) != 0x4D"
.endif

.if HIGH(BIG_CONST>>32) != 0x3C
    .error "HIGH(BIG_CONST>>32) != 0x3C"
.endif

.if BYTE3(BIG_CONST>>32) != 0x2B
    .error "BYTE3(BIG_CONST>>32) != 0x2B"
.endif

.if BYTE4(BIG_CONST>>32) != 0x1A
    .error "BYTE4(BIG_CONST>>32) != 0x1A"
.endif

nop
