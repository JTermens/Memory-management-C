#include "../../munit/munit.h"
#include "coord.h"

static MunitResult test_new_coordinate1()
{
  struct Coordinate c = new_coord(1, 2, 3);

  munit_assert_int(c.x, ==, 1);
  munit_assert_int(c.y, ==, 2);
  munit_assert_int(c.z, ==, 3);

  return MUNIT_OK;
}

static MunitResult test_new_coordinate2()
{
  struct Coordinate c = new_coord(4, 2, 0);

  munit_assert_int(c.x, ==, 4);
  munit_assert_int(c.y, ==, 2);
  munit_assert_int(c.z, ==, 0);

  return MUNIT_OK;
};

int main()
{
  static MunitTest tests[] = {
      {(char *)"/create_coordinate1", test_new_coordinate1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/create_coordinate2", test_new_coordinate2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  };

  static const MunitSuite suite = {(char *)"coordinates", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE};

  return munit_suite_main(&suite, NULL, 0, NULL);
}
