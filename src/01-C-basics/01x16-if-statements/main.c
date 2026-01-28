#include "../../munit/munit.h"
#include "exercise.h"

static MunitResult test_hot()
{
  char *result = get_temperature_status(50);
  munit_assert_string_equal(result, "too cold");

  return MUNIT_OK;
}

static MunitResult test_cold()
{
  char *result = get_temperature_status(100);
  munit_assert_string_equal(result, "too hot");

  return MUNIT_OK;
}

static MunitResult test_just_right()
{
  char *result = get_temperature_status(70);
  munit_assert_string_equal(result, "just right");

  return MUNIT_OK;
}

static MunitResult test_just_right2()
{
  char *result = get_temperature_status(75);
  munit_assert_string_equal(result, "just right");

  return MUNIT_OK;
}

int main()
{
  static MunitTest tests[] = {
      {(char *)"/test_hot", test_hot, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/test_cold", test_cold, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/test_just_right", test_just_right, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/test_just_right2", test_just_right2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL} // Munit null test
  };

  static const MunitSuite suite = {(char *)"get_temperature_status", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE};

  return munit_suite_main(&suite, NULL, 0, NULL);
}
