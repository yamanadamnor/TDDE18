#include "Time.hpp"
#include "catch.hpp"
#include <sstream>

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
    Time time2{22, 59, 59};

    CHECK(time.to_string() == "12:00:00");
    CHECK(time2.to_string(true) == "10:59:59 pm");
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

TEST_CASE("Test comparison operators")
{
  Time time{14, 0, 0};
  Time time2{14, 0, 0};
  Time time3{15, 0, 0};

  SECTION("greater/equal than")
  {
    CHECK(time3 > time);
    CHECK_FALSE(time > time3);

    CHECK(time3 >= time);
    CHECK_FALSE(time >= time3);
  }

  SECTION("less/equal than")
  {
    CHECK(time < time3);
    CHECK_FALSE(time3 < time);

    CHECK(time <= time3);
    CHECK_FALSE(time3 <= time);
  }

  SECTION("equal/not equal to")
  {
    CHECK(time == time2);
    CHECK_FALSE(time == time3);

    CHECK(time != time3);
    CHECK_FALSE(time != time2);
  }
}

TEST_CASE("streaming operators")
{
  std::istringstream iss{"21:00:10"};
  std::istringstream iss2{"26:00:00"};
  std::ostringstream oss{};
  Time time{};
  Time time2{};
  Time time3{21, 4, 4};

  SECTION("input stream")
  {
    // Correct input
    iss >> time;
    CHECK_FALSE(iss.fail());
    CHECK(time.to_string() == "21:00:10");

    // Invalid input
    iss2 >> time2;
    CHECK(iss2.fail());
    CHECK(time2.to_string() == "00:00:00");
  }

  SECTION("output stream")
  {
    oss << time3;
    CHECK(oss.str() == "21:04:04");
  }
}