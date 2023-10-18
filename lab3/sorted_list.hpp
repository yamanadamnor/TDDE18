#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#include <string>

class SortedList
{
public:
  // constructor
  SortedList() : head(nullptr){};

  // Copy constructor
  SortedList(const SortedList &list);

  // Move constructor
  SortedList(SortedList &&list);

  // destructor
  ~SortedList();

  // Copy assignment operator
  SortedList &operator=(const SortedList &refList);

  // Move assignment operator
  SortedList &operator=(SortedList &&refList);

  struct Node
  {
    int value;
    Node *next;

    Node(int val = 0) : value(val), next(nullptr){};
    Node(int val, Node *temp) : value(val), next(temp){};
  };
  // function that adds a value to the list (in sorted order)
  void
  insert(int value);

  void insert_place(Node *currentNode, Node *insertNode);

  // function that removes a value (either by index or by value),
  void remove(int index);

  // function that prints all the values in the list (the formatting must be readable),
  void print();

  std::string to_string();

  // function that return the value stored at a specified index
  int at(int index);

  int size();

  bool is_empty();

private:
  // Function that deep copies rightList into this
  void deepCopy(const SortedList &rightList);

  // Head pointer
  Node *head;
};

#endif
