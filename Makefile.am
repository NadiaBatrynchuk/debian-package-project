bin_PROGRAMS = program
check_PROGRAMS = test_program

program_SOURCES = main.cpp FuncA.cpp FuncA.h

test_program_SOURCES = tests/test_FuncA.cpp FuncA.cpp FuncA.h
test_program_CXXFLAGS = $(AM_CXXFLAGS) -I$(srcdir)
test_program_LDADD = -lgtest -lgtest_main -lpthread

AM_CXXFLAGS = -Wall -Wextra -std=c++11

AM_CPPFLAGS = -I$(srcdir)

TESTS = test_program

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

.PHONY: deb clean-deb test