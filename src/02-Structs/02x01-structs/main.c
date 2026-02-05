#include "../../../munit/munit.h"
#include "coord.h"

static MunitResult test_new_coordinate1()
{
  struct Coordinate c;
  c.x = 1;
  c.y = 2;
  c.z = 3;

  munit_assert_int(c.x, ==, 1);
  munit_assert_int(c.y, ==, 2);
  munit_assert_int(c.z, ==, 3);

  return MUNIT_OK;
};

static MunitResult test_new_coordinate2()
{
  struct Coordinate c;
  c.x = 4;
  c.y = 2;
  c.z = 0;

  munit_assert_int(c.x, ==, 4);
  munit_assert_int(c.y, ==, 2);
  munit_assert_int(c.z, ==, 0);

  return MUNIT_OK;
};

static MunitResult test_new_coordinate3()
{
  struct Coordinate c;
  c.x = 10;
  c.y = 20;
  c.z = 30;

  munit_assert_int(c.x, ==, 10);
  munit_assert_int(c.y, ==, 20);
  munit_assert_int(c.z, ==, 30);

  return MUNIT_OK;
};

static MunitResult test_new_coordinate4()
{
  struct Coordinate c;
  c.x = 0;
  c.y = 6;
  c.z = 9;

  munit_assert_int(c.x, ==, 0);
  munit_assert_int(c.y, ==, 6);
  munit_assert_int(c.z, ==, 9);

  return MUNIT_OK;
};

int main()
{
  static MunitTest tests[] = {
      {(char *)"/create_coordinate1", test_new_coordinate1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/create_coordinate2", test_new_coordinate2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/create_coordinate3", test_new_coordinate3, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {(char *)"/create_coordinate4", test_new_coordinate4, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
      {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL} // Munit null test
  };

  static const MunitSuite suite = {(char *)"coordinates", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE};

  return munit_suite_main(&suite, NULL, 0, NULL);
}
