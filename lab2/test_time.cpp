#include "Time.hpp"
#include "catch.hpp"
#include <sstream>

Time midnight{0, 0, 0};
Time single_digit{2, 2, 2};
Time afternoon{15, 15, 10};
Time almost_midnight{23, 59, 59};

TEST_CASE("Checking validity") {
  Time valid{16, 9, 3};
  Time invalid{59, 120, 666};

  REQUIRE(is_valid(valid));
  REQUIRE_FALSE(is_valid(invalid));
}
TEST_CASE("Testing functions") {
  SECTION("to_string function") {
    CHECK(to_string(midnight) == "00:00:00");
    CHECK(to_string(midnight, true) == "12:00:00 am");
    CHECK(to_string(single_digit) == "02:02:02");
    CHECK(to_string(afternoon) == "15:15:10");
    CHECK(to_string(afternoon, true) == "03:15:10 pm");
  }
  SECTION("is_am function") {
    CHECK(is_am(midnight));
    CHECK_FALSE(is_am(afternoon));
  }
}
TEST_CASE("Testing operators") {
  SECTION("operator==") {
    CHECK(midnight == midnight);
    CHECK_FALSE(midnight == afternoon);
  }

  SECTION("operator!=") {
    CHECK(midnight != almost_midnight);
    CHECK_FALSE(midnight != midnight);
  }

  SECTION("operator+") {
    Time midnight_plus_20{0, 0, 20};
    Time almost_midnight_plus_20{0, 0, 19};
    Time afternoon_plus_90{15, 16, 40};

    REQUIRE(is_valid(midnight + 20));
    CHECK(midnight + 20 == midnight_plus_20);

    REQUIRE(is_valid(almost_midnight + 20));
    CHECK(almost_midnight + 20 == almost_midnight_plus_20);

    REQUIRE(is_valid(afternoon + 90));
    CHECK(afternoon + 90 == afternoon_plus_90);

    REQUIRE(is_valid(midnight + 86400 * 3));
    CHECK(midnight + 86400 * 3 == midnight);

    REQUIRE(is_valid(afternoon + 86400 * 3));
    CHECK(afternoon + 86400 * 3 == afternoon);
  }

  SECTION("operator-") {
    Time midnight_minus_20{23, 59, 40};
    Time almost_midnight_minus_20{23, 59, 39};
    Time afternoon_minus_90{15, 13, 40};

    REQUIRE(is_valid(midnight - 20));
    CHECK(midnight - 20 == midnight_minus_20);

    REQUIRE(is_valid(almost_midnight - 20));
    CHECK(almost_midnight - 20 == almost_midnight_minus_20);

    REQUIRE(is_valid(afternoon - 90));
    CHECK(afternoon - 90 == afternoon_minus_90);

    REQUIRE(is_valid(midnight - 86400 * 3));
    CHECK(midnight - 86400 * 3 == midnight);

    REQUIRE(is_valid(afternoon - 86400 * 3));
    CHECK(afternoon - 86400 * 3 == afternoon);
  }

  SECTION("operator++") {
    Time time{midnight};
    Time time2{almost_midnight};
    Time time3{afternoon};

    SECTION("Postfix ++") {
      CHECK(to_string(time++) == "00:00:00");
      CHECK(to_string(time) == "00:00:01");

      CHECK(to_string(time2++) == "23:59:59");
      CHECK(to_string(time2) == "00:00:00");

      CHECK(to_string(time3++) == "15:15:10");
      CHECK(to_string(time3) == "15:15:11");
    }

    SECTION("Prefix ++") {
      CHECK(to_string(++time) == "00:00:01");
      CHECK(to_string(time) == "00:00:01");

      CHECK(to_string(++time2) == "00:00:00");
      CHECK(to_string(time2) == "00:00:00");

      CHECK(to_string(++time3) == "15:15:11");
      CHECK(to_string(time3) == "15:15:11");
    }
  }

  SECTION("operator--") {
    Time time{midnight};
    Time time2{almost_midnight};
    Time time3{afternoon};

    SECTION("Postfix --") {
      CHECK(to_string(time--) == "00:00:00");
      CHECK(to_string(time) == "23:59:59");

      CHECK(to_string(time2--) == "23:59:59");
      CHECK(to_string(time2) == "23:59:58");

      CHECK(to_string(time3--) == "15:15:10");
      CHECK(to_string(time3) == "15:15:09");
    }

    SECTION("Prefix --") {
      CHECK(to_string(--time) == "23:59:59");
      CHECK(to_string(time) == "23:59:59");

      CHECK(to_string(--time2) == "23:59:58");
      CHECK(to_string(time2) == "23:59:58");

      CHECK(to_string(--time3) == "15:15:09");
      CHECK(to_string(time3) == "15:15:09");
    }
  }

  SECTION("operator>") {
    CHECK_FALSE(midnight > afternoon);
    CHECK(almost_midnight > afternoon);
  }

  SECTION("operator>=") {
    CHECK(afternoon >= midnight);
    CHECK_FALSE(afternoon >= almost_midnight);
    CHECK(afternoon >= afternoon);
  }

  SECTION("operator<") {
    CHECK(midnight < afternoon);
    CHECK_FALSE(almost_midnight < afternoon);
  }

  SECTION("operator<=") {
    CHECK(midnight <= afternoon);
    CHECK_FALSE(almost_midnight <= afternoon);
    CHECK(afternoon <= afternoon);
  }

  SECTION("operator<<") {
    std::ostringstream os{};
    std::ostringstream os2{};

    os << afternoon;
    CHECK(os.str() == "15:15:10");
    os2 << midnight;
    CHECK(os2.str() == "00:00:00");
  }

  SECTION("operator>>") {
    std::istringstream is{"08:47:32"};
    std::istringstream is2{"64:47:32"};

    Time time_is{};
    is >> time_is;
    CHECK(to_string(time_is) == "08:47:32");

    Time time_is2{};
    is2 >> time_is2;
    CHECK(is2.fail());
  }
}
