CC=gcc
ARCH=-arch i386 -arch x86_64 -arch ppc
SOURCE=args.c \
        avra.c \
        coff.c \
        device.c \
        directiv.c \
        expr.c \
        file.c \
        macro.c \
        map.c \
        mnemonic.c \
        parser.c \
        stdextra.c

all:
	$(CC) $(ARCH) -o avra $(SOURCE)

