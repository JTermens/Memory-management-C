#include "../../munit/munit.h"
#include "coord.h"

static MunitResult test_new_coordinate()
{
  struct Coordinate c = new_coord(1, 2, 3);

  munit_assert_int(c.x, ==, 1);
  munit_assert_int(c.y, ==, 2);
  munit_assert_int(c.z, ==, 3);

  return MUNIT_OK;
};

static MunitResult test_scale_coordinate1()
{
  struct Coordinate c = new_coord(1, 2, 3);
  struct Coordinate scaled = scale_coordinate(c, 2);

  munit_assert_int(scaled.x, ==, 2);
  munit_assert_int(scaled.y, ==, 4);
  munit_assert_int(scaled.z, ==, 6);

  return MUNIT_OK;
};

static MunitResult test_scale_coordinate2()
{
  struct Coordinate c = new_coord(4, 2, 0);
  struct Coordinate scaled = scale_coordinate(c, 2);

  munit_assert_int(scaled.x, ==, 8);
  munit_assert_int(scaled.y, ==, 4);
  munit_assert_int(scaled.z, ==, 0);
};

static MunitResult test_original_unchanged()
{
  struct Coordinate c = new_coord(1, 2, 3);
  struct Coordinate scaled = scale_coordinate(c, 2);

  munit_assert_int(c.x, ==, 1);
  munit_assert_int(c.y, ==, 2);
  munit_assert_int(c.z, ==, 3);

  return MUNIT_OK;
};

int main()
{
  static MunitTest tests[] = {
      {(char *)"/create_coordinate", test_new_coordinate, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/test_scale_coordinate1", test_scale_coordinate1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/test_scale_coordinate2", test_scale_coordinate2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/test_original_unchanged", test_original_unchanged, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  };

  static const MunitSuite suite = {(char *)"coordinates", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE};

  return munit_suite_main(&suite, NULL, 0, NULL);
}
