SUBDIRS = lib
incdir = $(builddir)/include

bin_PROGRAMS = \
	cs0 \
	cs1 \
	cs2 \
	cs4 \
	cs6 \
	cs7 \
	cs8 \
	cs11 \
	cs12

cs0_SOURCES = src/cs0.c
cs1_SOURCES = src/cs1.c
cs2_SOURCES = src/cs2.c src/cs2_command.c
cs4_SOURCES = src/cs4.c
cs6_SOURCES = src/cs6.c
cs7_SOURCES = src/cs7.c
cs8_SOURCES = src/cs8.c
cs11_SOURCES = src/cs11.c
cs12_SOURCES = src/cs12.c

LDADD = \
	$(top_builddir)/lib/libhstcal.la \
	$(top_builddir)/hstio/libhstio.la \
	$(top_builddir)/tables/libhsttables.la \
	$(top_builddir)/cvos/libhstcvos.la \
	$(builddir)/lib/libhststis.la

AM_CFLAGS = \
	$(CFLAGS) \
	-I$(builddir)/include \
	-I$(srcdir)/include \
	-I$(top_srcdir)/include
AM_LDFLAGS = $(LDFLAGS) -lm
