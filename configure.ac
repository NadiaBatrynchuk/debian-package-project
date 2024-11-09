AC_INIT([program], [1.0], [batrynchuk1197@gmail.com])
AM_INIT_AUTOMAKE([foreign subdir-objects -Wall -Werror])

AC_PROG_CXX
AC_LANG([C++])

AC_CHECK_PROG([DPKG_BUILDPACKAGE], [dpkg-buildpackage], [yes], [no])
AC_CHECK_PROG([DEBUILD], [debuild], [yes], [no])

AC_CHECK_HEADERS([cmath iostream])

AC_CHECK_LIB([gtest], [main], [], [
    AC_MSG_ERROR([Google Test not found. Please install libgtest-dev])
])
AC_CHECK_LIB([gtest_main], [main], [], [
    AC_MSG_ERROR([Google Test Main not found])
])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT 