#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
CFLAGS="$CFLAGS -Wall -Wextra"
LDFLAGS="$LDFLAGS -Wl,--as-needed"

AC_PREREQ([2.71])
AC_INIT([hstcal],
        [m4_esyscmd([.ci/bin/git-version-gen .tarball-version])],
        [https://github.com/spactelescope/hstcal/issues],
        [],
        [https://github.com/spactelescope/hstcal])
AC_SUBST(program_suffix, ".e")
AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_SRCDIR([lib/hstcalversion.c])
AC_CONFIG_HEADERS([config.h])
AC_USE_SYSTEM_EXTENSIONS

AM_INIT_AUTOMAKE([-Wall foreign subdir-objects])
AM_PROG_AR
LT_INIT

# Checks for programs.
AC_PROG_CC
AC_PROG_F77
AC_PROG_MAKE_SET
AC_OPENMP
PKG_PROG_PKG_CONFIG

AC_ARG_ENABLE(debug,
    AS_HELP_STRING([--enable-debug],[Enable symbols and disable optimization]),
    enable_debug=$enableval, enable_debug=no)

if test "$enable_debug" = "yes" ; then
    CFLAGS="$CFLAGS -g -O0 -DDEBUG"
fi

# Checks for libraries.
AC_ARG_WITH([cfitsio],
    AS_HELP_STRING([--with-cfitsio], [Path to prefix containing cfitsio]))

cfitsio_usage="unable to find cfitsio library.
  USE --with-cfitsio=/path/to/cfitsio
  OR set: PKG_CONFIG_PATH
  OR set: cfitsio_CFLAGS and cfitsio_LIBS"

AS_IF([test "x$with_cfitsio" != "x"],
    [test "$with_cfitsio" == "yes" && AC_SUBST(with_cfitsio, /usr/local)
        cfitsio_CFLAGS="-I${with_cfitsio}/include -I${with_cfitsio}/include/fitsio"
        cfitsio_LIBS="-L${with_cfitsio}/lib -Wl,-rpath,${with_cfitsio}/lib -lcfitsio"],
    [PKG_CHECK_MODULES([cfitsio], [cfitsio >= 3], [],
        [AC_MSG_ERROR($cfitsio_usage)])])
AC_MSG_NOTICE([cfitsio CFLAGS... $cfitsio_CFLAGS])
AC_MSG_NOTICE([cfitsio LIBS... $cfitsio_LIBS])

# Push global flags
AC_SUBST(CFLAGS_OLD, $CFLAGS)
AC_SUBST(LDFLAGS_OLD, $LDFLAGS)

# Push cfitsio flags
AC_SUBST(CFLAGS,$cfitsio_CFLAGS)
AC_SUBST(LDFLAGS,$cfitsio_LIBS)

# Verify cfitsio works
AC_CHECK_HEADERS([fitsio.h], [], [AC_MSG_ERROR(cfitsio headers not found! $cfitsio_usage)])
AC_CHECK_LIB(cfitsio, [ffopen], [], [AC_MSG_ERROR(cfitsio library not found! $cfitsio_usage)])
AC_CHECK_FUNC(ffopen, [], [AC_MSG_ERROR(cfitsio is not usable! $cfitsio_usage)])

# Pop global flags
AC_SUBST(CFLAGS, $CFLAGS_OLD)
AC_SUBST(LDFLAGS, $LDFLAGS_OLD)

# Checks for header files.
AC_CHECK_HEADERS([unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_MKTIME
AC_FUNC_REALLOC
AC_FUNC_STRTOD
AC_CHECK_FUNCS([floor memset pow sqrt strcasecmp strchr strdup strpbrk strrchr strstr strtol])

AC_CONFIG_FILES([
    Makefile
    lib/Makefile
    hstio/Makefile
    cvos/Makefile
    tables/Makefile
    ctegen2/Makefile
    pkg/Makefile
    pkg/acs/lib/Makefile
    pkg/acs/Makefile
    pkg/wfc3/lib/Makefile
    pkg/wfc3/Makefile
    pkg/stis/lib/Makefile
    pkg/stis/Makefile
])
AC_OUTPUT
