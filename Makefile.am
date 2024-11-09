bin_PROGRAMS = program
program_SOURCES = main.cpp FuncA.cpp FuncA.h

AM_CXXFLAGS = -Wall -Wextra -std=c++11

AM_CPPFLAGS = -I$(srcdir)

deb: dist
	mkdir -p debian-build
	cp $(PACKAGE)-$(VERSION).tar.gz debian-build/$(PACKAGE)_$(VERSION).orig.tar.gz
	cd debian-build && tar xf $(PACKAGE)_$(VERSION).orig.tar.gz
	cp -r debian debian-build/$(PACKAGE)-$(VERSION)/
	cd debian-build/$(PACKAGE)-$(VERSION) && \
		autoreconf --install && \
		./configure && \
		debuild -us -uc

clean-deb:
	rm -rf debian-build
	rm -f *.deb

.PHONY: deb clean-deb