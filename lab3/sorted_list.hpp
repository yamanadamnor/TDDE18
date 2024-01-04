// TODO: Complementary work needed: Function implementations should not be
// done in the header file.
//
// (This includes when it is only a member initalizer list and an empty body)

#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#include <string>

class SortedList {
private:
  struct Node {
    int value;
    Node *next;

    // Constructor
    // This cant be implemented anywhere else because it is a private inner
    // class
    Node(int value = 0) : value(value), next(nullptr){};
    Node(int value, Node *next) : value(value), next(next){};
  };

  // Function that deep copies rightList into this
  void deepCopy(const SortedList &rightList);

  // Head pointer
  Node *head;

public:
  // Constructor
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

  void clearList(SortedList &list);

  // function that prints all the values in the list (the formatting must be
  // readable),
  void print() const;

  std::string to_string() const;

  // function that return the value stored at a specified index
  int at(int index) const;

  int size() const;

  bool is_empty() const;
};

#endif
