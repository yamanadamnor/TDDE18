#ifndef SORTEDLIST_H
#define SORTEDLIST_H

class SortedList
{
public:
  // constructor
  SortedList(): head(nullptr){};

  // Copy constructor
  // SortedList(SortedList const &list);

  // destructor
  // ~Sorted_list();

  struct Node
  {
    int value;
    Node *next;

    Node(int val=0): value(val), next(nullptr) {};
    Node(int val, Node *temp): value(val), next(temp) {};

    int get_value();
  };


  // function that adds a value to the list (in sorted order)
  void insert(int value);

  void insert_place(Node *currentNode, Node *insertNode);

  // function that removes a value (either by index or by value),
  void remove(int index);

  // function that prints all the values in the list (the formatting must be readable),
  void print();

  // function that return the value stored at a specified index
  void at(int index);

  int size();

  bool is_empty();

  Node *get_head();

private:
  // Head pointer
  Node *head;
};

#endif
