#********************************************************************
# Makefile for SAS/C on Amiga
#********************************************************************

CC = sc
LD = sc
CFLAGS = NOVERSION OPTIMIZE STRINGMERGE
LDFLAGS = NOVERSION

SOURCES = avra.c device.c parser.c expr.c mnemonic.c directiv.c macro.c file.c map.c coff.c

OBJECTS = avra.o device.o parser.o expr.o mnemonic.o directiv.o macro.o file.o map.o coff.o

OBJ_ALL = $(OBJECTS) args.o stdextra.o

DISTFILES = *.c *.h README ChangeLog Makefile.* COPYING avra.1 avra.txt strip-headers TODO

ARCHFILES = $(DISTFILES)

BINFILES = avra README ChangeLog COPYING avra.1 avra.txt

VERSION = 1.1.0

#********************************************************************

all: avra

install: avra
	copy avra c:

clean:
	delete avra avra.info \#?.o \#?.lnk

avra: $(OBJ_ALL)
	$(LD) link $(OBJ_ALL) $(LDFLAGS)

args.o: args.c misc.h args.h
avra.o: avra.c misc.h args.h avra.h device.h
device.o: device.c misc.h avra.h device.h
directiv.o: directiv.c misc.h args.h avra.h device.h
expr.o: expr.c misc.h avra.h
file.o: file.c misc.h avra.h
macro.o: macro.c misc.h args.h avra.h
mnemonic.o: mnemonic.c misc.h avra.h device.h
parser.o: parser.c misc.h avra.h
stdextra.o: stdextra.c misc.h
coff.o: coff.c coff.h

#********************************************************************

disk: archive
	copy avra.tar.gz pc0:avra.tgz

archive: avra.lha

avra.lha: $(ARCHFILES)
	lha -xr u avra.lha $(ARCHFILES)

dist: avra-$(VERSION).lha

avra-$(VERSION).lha: $(DISTFILES)
	makedir avra-$(VERSION)
	copy $(DISTFILES) TO avra-$(VERSION)/
	lha -xr u avra-$(VERSION).lha avra-$(VERSION)/*
	delete ALL avra-$(VERSION)

bin: avra-$(VERSION)-Amiga.lha

avra-$(VERSION)-Amiga.lha: $(BINFILES)
	makedir avra-$(VERSION)
	copy $(BINFILES) avra-$(VERSION)/
	lha -xr u avra-$(VERSION)-Amiga.lha avra-$(VERSION)/*
	delete ALL avra-$(VERSION)

#********************************************************************
