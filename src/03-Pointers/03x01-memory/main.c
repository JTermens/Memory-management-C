#include "../../munit/munit.h"
#include "snek.h"

static MunitResult size_of_addr_16()
{
  unsigned long size = size_of_addr(16);
  munit_assert_ulong(size, ==, 8);

  return MUNIT_OK;
};

static MunitResult size_of_addr_32()
{
  unsigned long size = size_of_addr(32);
  munit_assert_ulong(size, ==, 8);

  return MUNIT_OK;
};

static MunitResult size_of_addr_64()
{
  unsigned long size = size_of_addr(64);
  munit_assert_ulong(size, ==, 8);

  return MUNIT_OK;
};

static MunitResult size_of_addr_128()
{
  unsigned long size = size_of_addr(128);
  munit_assert_ulong(size, ==, 8);

  return MUNIT_OK;
};

int main()
{
  static MunitTest tests[] = {
      {(char *)"/size_of_addr_16", size_of_addr_16, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/size_of_addr_32", size_of_addr_32, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/size_of_addr_64", size_of_addr_64, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/size_of_addr_128", size_of_addr_128, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  };

  static const MunitSuite suite = {(char *)"colors", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE};

  return munit_suite_main(&suite, NULL, 0, NULL);
}
