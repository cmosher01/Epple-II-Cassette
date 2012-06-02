#@configure_input@
AM_CFLAGS=$(WARN_CFLAGS) $(WERROR_CFLAGS)
AM_CPPFLAGS=$(all_includes) -I$(top_builddir)/lib -I$(top_srcdir)/lib
AM_LDFLAGS=$(all_libraries)



bin_PROGRAMS=a2cass

a2cass_SOURCES=a2cass.c a2cass_opt.c a2cass_opt.h
noinst_DATA=hello.md5
EXTRA_DIST=hello.md5


define_new_md5: all
	echo "hello" | ./a2cass | $(MD5SUM) --binary >$(srcdir)/hello.md5

check_SCRIPTS=unit_test.sh
TESTS=$(check_SCRIPTS)

unit_test.sh: .FORCE
	touch $@
	if test "X$(MD5SUM)" == X ; \
	then \
		echo "echo \"md5sum program not found, so cannot run this test\" >&2" >>$@ ; \
		echo "exit 1" >>$@ ; \
	else \
		echo "echo \"hello\" | ./a2cass | $(MD5SUM) --check --status --warn $(srcdir)/hello.md5" >>$@ ; \
	fi
	chmod +x $@



CLEANFILES=unit_test.sh

.FORCE:
