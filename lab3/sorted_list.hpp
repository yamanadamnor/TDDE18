// TODO: Complementary work needed: Be consistent in naming your files.

// TODO: Complementary work needed: The Node type should be invisible and
// inaccessible to programmers that use the list.
// From assignment:
// “The link class and any functions pertaining to it should thus be stashed
// away and be inaccessible to the programmer.”

// TODO: Complementary work needed: Function implementations should not be
// done in the header file.
//
// (This includes when it is only a member initalizer list and an empty body)

// TODO: Complementary work needed: Member functions that don't modify the
// list should be declared const.

#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#include <string>

class SortedList {
private:
  struct Node {
    int value;
    Node *next;

    Node(int val = 0) : value(val), next(nullptr){};
    Node(int val, Node *temp) : value(val), next(temp){};
  };

  // Function that deep copies rightList into this
  void deepCopy(const SortedList &rightList);

  // Head pointer
  Node *head;

public:
  // constructor
  SortedList();

  // Copy constructor
  SortedList(const SortedList &list);

  // Move constructor
  SortedList(SortedList &&list);

  // Destructor
  ~SortedList();

  // Copy assignment operator
  SortedList &operator=(const SortedList &rhs);

  // Move assignment operator
  SortedList &operator=(SortedList &&rhs);

  // function that adds a value to the list (in sorted order)
  void insert(int value);

  void insert_place(Node *currentNode, Node *insertNode);

  // function that removes a value (either by index or by value),
  void remove(int index);

  // function that prints all the values in the list (the formatting must be
  // readable),
  void print();

  std::string to_string();

  // function that return the value stored at a specified index
  int at(int index);

  int size();

  bool is_empty();
};

#endif
