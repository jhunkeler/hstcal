lib_LTLIBRARIES = libhstctegen2.la
libhstctegen2_la_SOURCES = \
	ctegen2.c \
	ctehelpers.c
libhstctegen2_la_CFLAGS = \
	-I$(top_srcdir)/include \
	-I$(builddir) \
	-I$(top_srcdir)/tables \
	-I$(top_srcdir)/pkg/acs/include \
	$(OPENMP_CFLAGS)
libhstctegen2_la_CPPFLAGS = $(OPENMP_CPPFLAGS)
libhstctegen2_la_LDFLAGS = $(OPENMP_LDFLAGS)
