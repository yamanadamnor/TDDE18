#include "Time.hpp"
#include "catch.hpp"
#include <sstream>

// TODO: Complementary work needed: Your tests are insufficent, prefix/postfix
// should be tested in a correct way to show that they are implemented
// correctly. Specifally check that the instance you called the operator on is
// modified.
//
// TODO: Complementary work needed: Your tests are insufficent,
// adding/subtracting should be tested when input is a large number (such as
// three days 86 400*3) to show whether the Time resets correctly.

TEST_CASE("Functions") {
  Time time0{};
  Time time1{11, 59, 59};
  // Time time2{12, 0, 0};
  // Time time3{13, 0, 0};
  // Time time4{23, 59, 59};
  // Time time5{19, 59, 59};
  // Time time6{21, 59, 59};
  // Time time7{22, 0, 0};

  SECTION("bool is_am") {
    CHECK(is_am(time0));
    CHECK(is_am(time1));
  }

  SECTION("string to_string") {}
}

TEST_CASE("Operators") {
  Time time1{11, 59, 59};
  Time time2{11, 59, 59};

  SECTION("Prefix operator++") {
    std::cout << to_string(time1) << std::endl;
    std::cout << to_string(++time1) << std::endl;
    CHECK(time1++ == time2);
  }
}
