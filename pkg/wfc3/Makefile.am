SUBDIRS = lib
incdir = $(builddir)/include

bin_PROGRAMS = \
	wf32d \
	wf3ccd \
	wf3cte \
	wf3ir \
	wf3rej \
	wf3sum \
	calwf3

wf32d_SOURCES = src/main2d.c
wf3ccd_SOURCES = src/mainccd.c
wf3cte_SOURCES = src/maincte.c
wf3ir_SOURCES = src/mainir.c
wf3rej_SOURCES = src/mainrej.c
wf3sum_SOURCES = src/mainsum.c
calwf3_SOURCES = src/mainwf3.c

LDADD = \
	$(top_builddir)/tables/libhsttables.la \
	$(top_builddir)/lib/libhstcal.la \
	$(top_builddir)/hstio/libhstio.la \
	$(top_builddir)/cvos/libhstcvos.la \
	$(top_builddir)/ctegen2/libhstctegen2.la \
	$(builddir)/lib/libhstwfc3.la

AM_CFLAGS = \
	-I$(top_srcdir)/include \
	-I$(srcdir)/include \
	$(OPENMP_CFLAGS)
AM_CPPFLAGS = $(OPENMP_CPPFLAGS)
AM_LDFLAGS = $(OPENMP_LDFLAGS)
