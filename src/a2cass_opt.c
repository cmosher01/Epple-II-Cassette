#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "a2cass_opt.h"

#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

static const char shortopts[] = "hV";

static const struct option longopts[] =
  {
    {"help",no_argument,0,'h'},
    {"version",no_argument,0,'V'},
    {0,0,0,0}
  };

static void help(int argc, char *argv[])
{
  (void)argc;
  printf("Encodes into a cassette tape format file, suitable for\n");
  printf("input to the Epple ][ emulator's cassette functions.\n");
  printf("\n");
  printf("Usage: %s [OPTION...]\n",argv[0]);
  printf("Options:\n");
  printf("  -h, --help           shows this help\n");
  printf("  -V, --version        shows version information\n");
}

static struct opts_t *opts_factory(void)
  {
    struct opts_t *opts = (struct opts_t*)malloc(sizeof(struct opts_t));

    return opts;
  }

static void version(void)
{
  printf("%s\n",PACKAGE_STRING);
  printf("\n");
  printf("%s\n","Copyright (C) 2012, by Chris Mosher.");
  printf("%s\n","License GPLv3+: GNU GPL version 3 or later <http://www.gnu.org/licenses/gpl.html>.");
  printf("%s\n","This is free software: you are free to change and redistribute it.");
  printf("%s\n","There is NO WARRANTY, to the extent permitted by law.");
}

struct opts_t *parse_opts(int argc, char *argv[])
{
    int c;

    struct opts_t *opts = opts_factory();

    while ((c = getopt_long(argc,argv,shortopts,longopts,0)) >= 0)
      {
        switch (c)
          {
          case 'V':
            version();
            exit(0);
            break;
          case 0:
            break;
          case 'h':
          default:
            help(argc,argv);
            exit(0);
          }
      }

    return opts;
}
