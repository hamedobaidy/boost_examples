dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(boost_gmp_float_autotools, 1.0)


AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE()

AC_PROG_CXX

dnl PKG_CHECK_MODULES([MYAPP], [gmp])
AC_CHECK_LIB(gmp, __gmpz_init, )


AC_CONFIG_FILES(Makefile src/Makefile)
AC_OUTPUT

