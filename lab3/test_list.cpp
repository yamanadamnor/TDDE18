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

TEST_CASE("Insert to list") {
  SortedList l{};
  l.insert(6);
  l.insert(4);
  l.insert(5);
  l.insert(1);
  l.print();
}

TEST_CASE( "Create an empty list" ) {
  SortedList l{};

  REQUIRE( l.is_empty() == true );
  REQUIRE( l.size() == 0 );
}

// It is your job to create new test cases and fully test your SortedList class