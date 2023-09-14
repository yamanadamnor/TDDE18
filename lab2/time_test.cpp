#include "Time.hpp"
#include "catch.hpp"

TEST_CASE("Test Time object")
{
  Time time{23, 59, 59};
  REQUIRE(time.to_string() == "23:59:59");
}