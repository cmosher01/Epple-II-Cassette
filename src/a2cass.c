#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <binary-io.h>

int CYC_HEAD = 65;
int CYC_SYNC_0 = 20;
int CYC_SYNC_1 = 25;
int CYC_0 = 25;
int CYC_1 = 50;

int c_header = 31;
int c_sync = 1;

static void out_head(void)
{
  int i;
  for (i = 0; i < c_header; ++i)
    {
      putchar(CYC_HEAD);
      putchar(CYC_HEAD);
    }
  fprintf(stderr,"wrote header: %d bytes.\n",c_header);
}

static void out_sync(void)
{
  int i;
  for (i = 0; i < c_sync; ++i)
    {
      putchar(CYC_SYNC_0);
      putchar(CYC_SYNC_1);
    }
  fprintf(stderr,"wrote sync: %d bytes.\n",c_sync);
}

static void out_bit(int b)
{
  if (b)
    {
      putchar(CYC_1);
      putchar(CYC_1);
    }
  else
    {
      putchar(CYC_0);
      putchar(CYC_0);
    }
}

static void out_byte(int b)
{
  int i;

  for (i = 0; i < 8; ++i)
    {
      out_bit(b & 0x80);
      b <<= 1;
    }
}

int main(int argc, char *argv[])
{
  int b;
  int c;

  (void)argc;
  (void)argv;

  SET_BINARY(0);
  SET_BINARY(1);

  out_head();
  out_sync();

  c = 0;
  while ((b = getchar()) != EOF)
    {
      out_byte(b);
      ++c;
    }

  fprintf(stderr,"wrote data: %d bytes.\n",c);

  return EXIT_SUCCESS;
}
