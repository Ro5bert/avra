OS = linux
VERSION = 1.4.2

DISTFILES = src \
	includes \
	tests \
	README.md \
	CHANGELOG.md \
	USAGE.md \
	AUTHORS \
	COPYING \
	Makefile \

PREFIX ?= /usr/local
TARGET_INCLUDE_PATH ?= $(PREFIX)/include/avr

CDEFS = -DDEFAULT_INCLUDE_PATH='"$(TARGET_INCLUDE_PATH)"' \
	-DVERSION='"$(VERSION)"'
export CDEFS

.PHONY: all
all:
	$(MAKE) -C src -f makefiles/Makefile.$(OS)

.PHONY: clean
clean:
	$(MAKE) -C src -f makefiles/Makefile.$(OS) clean

avra-$(VERSION).tar.gz: $(DISTFILES) clean
	mkdir avra-$(VERSION)
	cp -r $(DISTFILES) avra-$(VERSION)/
	tar cvf avra-$(VERSION).tar avra-$(VERSION)/*
	gzip -9 -f avra-$(VERSION).tar
	rm -r avra-$(VERSION)

.PHONY: dist
dist: avra-$(VERSION).tar.gz

.PHONY: install
install: all
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 755 src/avra $(DESTDIR)$(PREFIX)/bin
	install -d $(DESTDIR)$(TARGET_INCLUDE_PATH)
	cp includes/* $(DESTDIR)$(TARGET_INCLUDE_PATH)

.PHONY: check
check: all
	cd tests/regression && ./runtests.sh
