lib_LTLIBRARIES = libhstio.la
libhstio_la_SOURCES = \
	hstio.c \
	keyword.c \
	numeric.c
libhstio_la_CFLAGS = -I$(top_srcdir)/include $(OPENMP_CFLAGS)
libhstio_la_CPPFLAGS = $(OPENMP_CPPFLAGS)
libhstio_la_LDFLAGS = $(OPENMP_LDFLAGS)
