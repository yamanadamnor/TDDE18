// Good use of SECTION() and some thoguhtful test cases.
// But a couple of things are missing.

// TODO: Complementary work needed: Test cases insufficient, what if a list is 
// empty for all functions? 

// Comment: Standard-wise, it is undefined what happens when accessing an object
// after a std::move.
//
// After
// SortedList r{std::move(l)};
// we can only make assertions about "r".

// TODO: Complementary work needed: Test cases insufficient, you should test
// all functions that you have implemented.

// TODO: Complementary work needed: Program crashes with SIGABRT and valgrind
// produces warnings when running certain tests.
//
// My suggestion is to add test cases, both the ones mentioned in this file
// but also ones that test other TODOs, one at a time until you find which
// one(s) cause your program to fail. After that, start fixing.
// Finally add any other tests you can think of and finally check your program
// with valgrind before submitting again.

// TODO: Complementary work needed: unnecessary include 

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