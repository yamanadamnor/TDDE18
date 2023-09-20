#include "Time.hpp"
#include "catch.hpp"

TEST_CASE("Constructor tests")
{
  SECTION("Default constructor")
  {

    Time time{};
    CHECK(time.hour == 0);
    CHECK(time.minute == 0);
    CHECK(time.second == 0);
  }

  SECTION("Test constructor")
  {
    Time time{12, 12, 12};
    CHECK(time.hour == 12);
    CHECK(time.minute == 12);
    CHECK(time.second == 12);

    Time time2{0, 0, 0};
    CHECK(time2.hour == 0);
    CHECK(time2.minute == 0);
    CHECK(time2.second == 0);
  }

  SECTION("Test constructor validation")
  {
    CHECK_THROWS(Time{25, 0, 0});
    CHECK_THROWS(Time{24, 60, 0});
    CHECK_THROWS(Time{24, 40, 60});
  }
}

TEST_CASE("Test methods")
{
  SECTION("Check string conversion")
  {
    Time time{12, 0, 0};
    CHECK(time.to_string() == "12:00:00");
  }

  SECTION("Test is_am")
  {
    Time time{13, 0, 0};
    Time time2{11, 59, 59};
    CHECK_FALSE(time.is_am());
    CHECK(time2.is_am());
  }
}

TEST_CASE("Test increment/decrement operators")
{
  SECTION("Test increment prefix")
  {
    Time time{15, 59, 59};
    Time time2 = ++time;

    CHECK(time2.hour == 16);
    CHECK(time2.minute == 0);
    CHECK(time2.second == 0);
  }

  SECTION("Test increment postfix")
  {
    Time time{15, 59, 59};
    Time time2 = time++;

    CHECK(time2.hour == 15);
    CHECK(time2.minute == 59);
    CHECK(time2.second == 59);
  }

  SECTION("Test increment operator")
  {
    Time time{15, 59, 59};
    Time time2 = time + 10;

    CHECK(time2.hour == 16);
    CHECK(time2.minute == 0);
    CHECK(time2.second == 9);
  }

  SECTION("Test decrement prefix")
  {
    Time time{15, 0, 0};
    Time time2 = --time;

    CHECK(time2.hour == 14);
    CHECK(time2.minute == 59);
    CHECK(time2.second == 59);
  }

  SECTION("Test decrement postfix")
  {
    Time time{15, 0, 0};
    Time time2 = time--;

    CHECK(time2.hour == 15);
    CHECK(time2.minute == 0);
    CHECK(time2.second == 0);
  }

  SECTION("Test decrement operator")
  {
    Time time{15, 0, 0};
    Time time2 = time - 10;

    CHECK(time2.hour == 14);
    CHECK(time2.minute == 59);
    CHECK(time2.second == 50);
  }
}
