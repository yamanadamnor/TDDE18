#ifndef SORTEDLIST_H
#define SORTEDLIST_H

class Sorted_list
{
public:
  // constructor
  Sorted_list() : head(nullptr){};

  // destructor
  ~Sorted_list();

  struct Node
  {
    int value;
    Node *next;
  };

  // function that adds a value to the list (in sorted order)
  void insert(int value);

  void *insert_place(Node *currentNode, Node *comparisonNode);

  // function that removes a value (either by index or by value),
  void remove(int index);

  // function that prints all the values in the list (the formatting must be readable),
  void print();

  // function that return the value stored at a specified index
  void at(int index);

private:
  // Head pointer
  Node *head{};
};

#endif
