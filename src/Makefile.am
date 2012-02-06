#@configure_input@
AM_CFLAGS=$(WARN_CFLAGS) $(WERROR_CFLAGS)
AM_CPPFLAGS=$(all_includes) -I$(top_builddir)/lib -I$(top_srcdir)/lib
AM_LDFLAGS=$(all_libraries)
#LDADD = $(top_builddir)/lib/liba2catalog.a $(LIBINTL)



bin_PROGRAMS=a2cass

a2cass_SOURCES=\
a2cass.c


check_SCRIPTS=unit_test.sh
TESTS=$(check_SCRIPTS)

unit_test.sh: .FORCE
echo "./a2cass --test" >>$@
chmod +x $@



CLEANFILES=unit_test.sh

.FORCE:
