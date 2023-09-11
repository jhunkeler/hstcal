SUBDIRS = lib
incdir = $(builddir)/include

bin_PROGRAMS = \
	acs2d \
	acsccd \
	acscte \
	acsrej \
	acssum \
	calacs

acs2d_SOURCES = src/main2d.c

acsccd_SOURCES = src/mainccd.c

acscte_SOURCES = src/maincte.c

acsrej_SOURCES = src/mainrej.c

acssum_SOURCES = src/mainsum.c

calacs_SOURCES = src/mainacs.c

LDADD = \
	$(top_builddir)/tables/libhsttables.la \
	$(top_builddir)/lib/libhstcal.la \
	$(top_builddir)/hstio/libhstio.la \
	$(top_builddir)/cvos/libhstcvos.la \
	$(top_builddir)/ctegen2/libhstctegen2.la \
	$(builddir)/lib/libhstacs.la
AM_CFLAGS = \
	$(CFLAGS) \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/tables \
	-I$(srcdir)/include \
	-I$(incdir) \
	$(OPENMP_CFLAGS)
AM_CPPFLAGS = $(CPPFLAGS) $(OPENMP_CPPFLAGS)
AM_LDFLAGS = $(LDFLAGS) $(OPENMP_LDFLAGS) -lm
