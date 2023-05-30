.device atmega328p

#define EIGHT (1 << 3)
#define SQR(X) ((X)*(X))

ldi r16, EIGHT
ldi r16, SQR(4)

#define FOOBAR subi
#define IMMED(X) X##i
#define SUBI(X,Y) X ## Y

IMMED(ld) r16, 1
SUBI(FOO, BAR) r16, 1

#define REGN(N) r##N
ldi REGN(16), SQR(4)
