#include "../../munit/munit.h"
#include "exercise.h"

static MunitResult test_change_filetype_cpp_to_python()
{
  codefile_t original;
  original.lines = 100;
  original.filetype = 1;

  codefile_t result = change_filetype(&original, 2);
  munit_assert_int(result.lines, ==, 100);
  munit_assert_int(result.filetype, ==, 2);

  return MUNIT_OK;
};

static MunitResult test_change_filetype_same_type()
{
  codefile_t original;
  original.lines = 50;
  original.filetype = 3;

  codefile_t result = change_filetype(&original, 3);
  munit_assert_int(result.lines, ==, 50);
  munit_assert_int(result.filetype, ==, 3);

  return MUNIT_OK;
};

static MunitResult test_change_filetype_java_to_rust()
{
  codefile_t original;
  original.lines = 200;
  original.filetype = 4;

  codefile_t result = change_filetype(&original, 5);
  munit_assert_int(result.lines, ==, 200);
  munit_assert_int(result.filetype, ==, 5);

  return MUNIT_OK;
};

static MunitResult test_change_filetype_zero_lines()
{
  codefile_t original;
  original.lines = 0;
  original.filetype = 1;

  codefile_t result = change_filetype(&original, 6);
  munit_assert_int(result.lines, ==, 0);
  munit_assert_int(result.filetype, ==, 6);

  return MUNIT_OK;
};

static MunitResult test_change_filetype_no_mutation()
{
  codefile_t original;
  original.lines = 150;
  original.filetype = 7;

  codefile_t backup = original;
  codefile_t result = change_filetype(&original, 8);
  munit_assert_int(result.filetype, ==, 8);
  munit_assert_int(original.lines, ==, backup.lines);
  munit_assert_int(original.filetype, ==, backup.filetype);

  return MUNIT_OK;
};

int main()
{
  static MunitTest tests[] = {
      {(char *)"/test_change_filetype_cpp_to_python", test_change_filetype_cpp_to_python, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/test_change_filetype_same_type", test_change_filetype_same_type, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/test_change_filetype_java_to_rust", test_change_filetype_java_to_rust, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/test_change_filetype_zero_lines", test_change_filetype_zero_lines, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/test_change_filetype_no_mutation", test_change_filetype_no_mutation, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  };

  static const MunitSuite suite = {(char *)"pointers", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE};

  return munit_suite_main(&suite, NULL, 0, NULL);
}
