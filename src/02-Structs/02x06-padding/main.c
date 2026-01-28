#include "../../munit/munit.h"
#include "exercise.h"

static MunitResult test_new_coordinate()
{
  munit_assert_int(sizeof(sneklang_var_t), ==, 24);
  /*  8 bytes of name (ptr)
    + 4 bytes of scope_level (int)
    + 4 bytes of value (int)
    + 1 bytes of is_constant (char)
    + 1 byte of type (char)
    + 6 bytes of padding to round to 3 8 byte addresses
    = 24 bytes
  */
  return MUNIT_OK;
};

int main()
{
  static MunitTest tests[] = {
      {(char *)"/test_optimal_size", test_new_coordinate, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  };

  static const MunitSuite suite = {(char *)"padding", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE};

  return munit_suite_main(&suite, NULL, 0, NULL);
}
