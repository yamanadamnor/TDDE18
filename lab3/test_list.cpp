// Good use of SECTION() and some thoguhtful test cases.
// But a couple of things are missing.

// TODO: Complementary work needed: Test cases insufficient, what if a list is
// empty for all functions?

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

#include "SortedList.hpp"
#include "catch.hpp"

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE("Move constructor") {
  SortedList l{};
  SECTION("Move empty list") {
    REQUIRE(l.is_empty() == true);
    SortedList moved_list{std::move(l)};
    REQUIRE(moved_list.is_empty() == true);
  }

  SECTION("Move non empty list") {
    l.insert(4);
    l.insert(9);
    l.insert(6);
    SortedList r{std::move(l)};
    r.insert(9);
    REQUIRE(r.to_string() == "4 6 9 9");
    REQUIRE(r.size() == 4);
  }
}

TEST_CASE("Move assignment operator") {
  SortedList l{};
  l.insert(4);
  l.insert(6);
  l.insert(9);
  SECTION("Move assignment operator not self") {
    SortedList r = std::move(l);

    CHECK(l.to_string() == "");
    CHECK(l.size() == 0);

    CHECK(r.to_string() == "4 6 9");
    CHECK(r.size() == 3);
  }

  SECTION("Move assignment operator not self and with preexisting element") {
    SortedList r{};
    r.insert(4);
    r.insert(6);
    r.insert(9);
    r = std::move(l);

    CHECK(l.to_string() == "");
    CHECK(l.size() == 0);

    CHECK(r.to_string() == "4 6 9");
    CHECK(r.size() == 3);
  }

  SECTION("Move assignment operator self with existing elements") {
    l = std::move(l);
    l.insert(9);

    CHECK(l.to_string() == "4 6 9 9");
    CHECK(l.size() == 4);
  }
  
  SECTION("Move assignment operator self with no elements") {
    SortedList empty{};
    empty = std::move(empty);
    CHECK(empty.to_string() == "");
    CHECK(empty.is_empty() == true);
    CHECK(empty.size() == 0);
  }

  SECTION("Move assignment operator with empty list") {
    SortedList empty_list{};
    SortedList moved_empty = std::move(empty_list);

    CHECK(moved_empty.to_string() == "");
    CHECK(moved_empty.is_empty() == true);

    moved_empty.insert(4);
    moved_empty.insert(4);
    moved_empty.insert(4);

    CHECK(moved_empty.to_string() == "4 4 4");
    CHECK(moved_empty.is_empty() == false);
    CHECK(moved_empty.size() == 3);
  }
}

TEST_CASE("Copy constructor") {
  SortedList l{};
  SECTION("Non empty list") {
    l.insert(4);
    l.insert(2);
    l.insert(1);
    SortedList l2{l};
    l.insert(9);

    CHECK(l.to_string() == "1 2 4 9");
    CHECK(l.size() == 4);

    CHECK(l2.to_string() == "1 2 4");
    CHECK(l2.size() == 3);
  }

  SECTION("Empty list") {
    SortedList l2{l};

    CHECK(l.to_string() == "");
    CHECK(l.size() == 0);

    CHECK(l2.to_string() == "");
    CHECK(l2.size() == 0);
  }
}

TEST_CASE("Copy assignment") {
  SortedList l{};
  SECTION("Copy to list with existing elements") {
    SortedList existing_elements{};
    existing_elements.insert(4);
    existing_elements.insert(8);
    existing_elements.insert(0);

    REQUIRE(existing_elements.to_string() == "0 4 8");
    REQUIRE(existing_elements.size() == 3);

    existing_elements = l;

    REQUIRE(l.to_string() == "");
    REQUIRE(l.size() == 0);
  }

  SECTION("Copy an empty list") {
    SortedList l2 = l;
    REQUIRE(l2.to_string() == "");
    REQUIRE(l2.size() == 0);
  }

  SECTION("Copy an already filled list") {
    l.insert(4);
    l.insert(2);
    l.insert(1);
    SortedList l2 = l;
    l.insert(9);
    REQUIRE(l.to_string() == "1 2 4 9");
    REQUIRE(l.size() == 4);

    REQUIRE(l2.to_string() == "1 2 4");
    REQUIRE(l2.size() == 3);
  }

  SECTION("Copy to self") {
    l.insert(4);
    l.insert(2);
    l.insert(1);
    l = l;
    REQUIRE(l.to_string() == "1 2 4");
    REQUIRE(l.is_empty() == false);
    REQUIRE(l.size() == 3);
  }
}

TEST_CASE("Insering to list") {
  SortedList list{};
  SECTION("Excution order of insert should not matter") {
    list.insert(6);
    list.insert(4);
    list.insert(5);
    list.insert(1);
    CHECK(list.to_string() == "1 4 5 6");
    CHECK(list.size() == 4);
  };

  SECTION("Inserting only one element") {
    list.insert(1);
    CHECK(list.to_string() == "1");
  };
}

TEST_CASE("Removing from list by index") {
  SortedList l{};
  l.insert(1);
  l.insert(4);
  l.insert(7);

  SECTION("Remove first element from the list") {
    l.remove(0);
    REQUIRE(l.to_string() == "4 7");
    REQUIRE(l.size() == 2);
  }

  SECTION("Remove last element from the list") {
    int last_index{l.size() - 1};
    l.remove(last_index);
    REQUIRE(l.to_string() == "1 4");
    REQUIRE(l.size() == 2);
  }

  SECTION("Remove element from the middle") {
    l.remove(1);
    REQUIRE(l.to_string() == "1 7");
    REQUIRE(l.size() == 2);
  }

  SECTION("Remove element with invalid index") {
    l.remove(3);
    l.remove(5);
    l.remove(-100);
    REQUIRE(l.to_string() == "1 4 7");
    REQUIRE(l.size() == 3);
  }
}

TEST_CASE("Creating empty list") {
  SortedList list{};
  REQUIRE(list.is_empty() == true);
  REQUIRE(list.size() == 0);
  REQUIRE(list.to_string() == "");
}

TEST_CASE("Get element by index") {
  SortedList l{};
  l.insert(1);
  l.insert(4);
  l.insert(9);

  SECTION("Get value by valid index") {
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 4);
    CHECK(l.at(2) == 9);
  }

  SECTION("Out of range index") {
    CHECK(l.at(5) == -1);
    CHECK(l.at(-1) == -1);
  }
}

