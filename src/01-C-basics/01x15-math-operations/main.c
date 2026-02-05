#include "../../../munit/munit.h"
#include "exercise.h"

static MunitResult test_snek_score_1()
{
  float result = snek_score(3, 4, 5, 0.1);
  munit_assert_double_equal(result, 1.9, 7); // where 7 is the precision of float (1+6 decimals)

  return MUNIT_OK;
}

static MunitResult test_snek_score_2()
{
  float result = snek_score(10, 10, 10, 0.1);
  munit_assert_double_equal(result, 11.0, 7);

  return MUNIT_OK;
}

static MunitResult test_snek_score_3()
{
  float result = snek_score(105, 205, 207, 0.1);
  munit_assert_double_equal(result, 2194, 7);

  return MUNIT_OK;
}

int main()
{
  static MunitTest tests[] = {
      {(char *)"/test_snek_score_1", test_snek_score_1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/test_snek_score_2", test_snek_score_2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/test_snek_score_3", test_snek_score_3, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL} // Munit null test
  };

  static const MunitSuite suite = {(char *)"snek_score", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE};

  return munit_suite_main(&suite, NULL, 0, NULL);
}
