AC_INIT([program], [1.0], [batrynchuk1197@gmail.com])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])

AC_PROG_CXX
AC_LANG([C++])

AC_CHECK_PROG([DPKG_BUILDPACKAGE], [dpkg-buildpackage], [yes], [no])
AC_CHECK_PROG([DEBUILD], [debuild], [yes], [no])

AC_CHECK_HEADERS([cmath iostream])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT 