#include "../../../munit/munit.h"
#include "exercise.h"

static MunitResult test_get_average()
{
  float result = get_average(3, 4, 5);
  munit_assert_double_equal(result, 4.0, 7); // where 7 is the precision of float (1+6 decimals)

  return MUNIT_OK;
}

static MunitResult test_non_integer()
{
  float result = get_average(3, 3, 5);
  munit_assert_double_equal(result, 11.0 / 3.0, 7);

  return MUNIT_OK;
}

static MunitResult test_average_of_same()
{
  float result = get_average(10., 10., 10.);
  munit_assert_double_equal(result, 10., 7);

  return MUNIT_OK;
}

static MunitResult test_average_of_big_numbers()
{
  float result = get_average(1050, 2050, 2075);
  munit_assert_double_equal(result, 1725.0, 7);

  return MUNIT_OK;
}

int main()
{
  static MunitTest tests[] = {
      {(char *)"/get_average", test_get_average, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/get_average_float", test_non_integer, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/get_average_same", test_average_of_same, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/get_average_big", test_average_of_big_numbers, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}, // Munit null test
  };

  static const MunitSuite suite = {(char *)"get_average", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE};

  return munit_suite_main(&suite, NULL, 0, NULL);
}
