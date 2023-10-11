// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#include "catch.hpp"
#include "sorted_list.hpp"
#include <iostream>
#include <random>

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE("Insering to list")
{
  SortedList list{};
  SECTION("Calling order of insert should not matter")
  {
    list.insert(6);
    list.insert(4);
    list.insert(5);
    list.insert(1);
    CHECK(list.print() == "1 4 5 6");
  };

  SECTION("Inserting only one element")
  {
    list.insert(1);
    CHECK(list.print() == "1");
  };
}

TEST_CASE("Creating empty list")
{
  SortedList list{};
  REQUIRE(list.is_empty() == true);
  REQUIRE(list.size() == 0);
  REQUIRE(list.print() == "");
};
// It is your job to create new test cases and fully test your SortedList class