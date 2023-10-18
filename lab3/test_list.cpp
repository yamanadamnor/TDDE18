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

TEST_CASE("Move constructor")
{
  SortedList l{};
  l.insert(4);
  l.insert(6);
  l.insert(9);
  SortedList r{std::move(l)};
  CHECK(l.to_string() == "");
  CHECK(l.size() == 0);

  CHECK(r.to_string() == "4 6 9");
  CHECK(r.size() == 3);
}

TEST_CASE("Move assignment operator")
{
  SortedList l{};
  l.insert(4);
  l.insert(6);
  l.insert(9);
  SortedList r = std::move(l);

  CHECK(l.to_string() == "");
  CHECK(l.size() == 0);

  CHECK(r.to_string() == "4 6 9");
  CHECK(r.size() == 3);
}

TEST_CASE()
{
  SortedList l{};
  l.insert(4);
  l.insert(2);
  l.insert(1);
  SortedList l2{l};
  l.insert(9);

  REQUIRE(l2.to_string() == "1 2 4");
}

TEST_CASE("Copy assignment")
{
  SortedList l{};
  SECTION("Copy an empty list")
  {
    SortedList l2 = l;
    REQUIRE(l2.to_string() == "");
    REQUIRE(l2.size() == 0);
  }

  SECTION("Copy an already filled list")
  {
    l.insert(4);
    l.insert(2);
    l.insert(1);
    SortedList l2 = l;
    l.insert(9);
    REQUIRE(l2.to_string() == "1 2 4");
    REQUIRE(l2.size() == 3);
  }
}

TEST_CASE("Insering to list")
{
  SortedList list{};
  SECTION("Excution order of insert should not matter")
  {
    list.insert(6);
    list.insert(4);
    list.insert(5);
    list.insert(1);
    CHECK(list.to_string() == "1 4 5 6");
    CHECK(list.size() == 4);
  };

  SECTION("Inserting only one element")
  {
    list.insert(1);
    CHECK(list.to_string() == "1");
  };
}

TEST_CASE("Removing from list by index")
{
  SortedList l{};

  SECTION("Remove first element from the list")
  {
    l.insert(1);
    l.insert(4);
    l.insert(7);

    l.remove(0);
    REQUIRE(l.to_string() == "4 7");
    REQUIRE(l.size() == 2);
  }

  SECTION("Remove last element from the list")
  {
    l.insert(1);
    l.insert(4);
    l.insert(7);

    l.remove(2);
    REQUIRE(l.to_string() == "1 4");
    REQUIRE(l.size() == 2);
  }

  SECTION("Remove element from the middle")
  {
    l.insert(1);
    l.insert(4);
    l.insert(7);

    l.remove(1);
    REQUIRE(l.to_string() == "1 7");
    REQUIRE(l.size() == 2);
  }

  SECTION("Remove element with invalid index")
  {
    l.insert(1);
    l.insert(4);
    l.insert(7);

    l.remove(3);
    l.remove(5);
    l.remove(-100);
    REQUIRE(l.to_string() == "1 4 7");
    REQUIRE(l.size() == 3);
  }
}

TEST_CASE("Creating empty list")
{
  SortedList list{};
  REQUIRE(list.is_empty() == true);
  REQUIRE(list.size() == 0);
  REQUIRE(list.to_string() == "");
};

TEST_CASE("Get element by index")
{
  SortedList l{};
  l.insert(1);
  l.insert(4);
  l.insert(9);

  SECTION("Get value by valid index")
  {
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 4);
    CHECK(l.at(2) == 9);
  }

  SECTION("Out of range index")
  {
    CHECK(l.at(5) == -1);
    CHECK(l.at(-1) == -1);
  }
}

// It is your job to create new test cases and fully test your SortedList class