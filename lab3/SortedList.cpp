#include "SortedList.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void SortedList::clearList(SortedList &list) {
  Node *curr{list.head};
  while (curr != nullptr) {
    Node *next{curr->next};
    delete curr;
    curr = next;
  }
  list.head = nullptr;
}

// Constructor
SortedList::SortedList() : head(nullptr) {}

// Copy constructor
SortedList::SortedList(const SortedList &refList) : head(nullptr) {
  this->deepCopy(refList);
}

// Move constructor
SortedList::SortedList(SortedList &&refList) {
  this->head = refList.head;
  refList.head = nullptr;
}

// Destructor
SortedList::~SortedList() { clearList(*this); }

// Copy assignment operator
SortedList &SortedList::operator=(const SortedList &rhs) {
  // Self check
  if (this == &rhs)
    return *this;

  clearList(*this);
  this->deepCopy(rhs);

  return *this;
}

// Move assignment operator
SortedList &SortedList::operator=(SortedList &&rhs) {
  // Self check
  if (this == &rhs)
    return *this;

  clearList(*this);

  this->head = rhs.head;
  rhs.head = nullptr;

  return *this;
}

void SortedList::deepCopy(const SortedList &rightList) {
  Node *currRightList{rightList.head};

  while (currRightList != nullptr) {
    insert(currRightList->value);
    currRightList = currRightList->next;
  }
}

void SortedList::insert(int value) {
  Node *temp{new Node{value}};

  // Check if the list is empty
  if (head == nullptr) {
    head = temp;
    return;
  }

  // Checks if the new value is less the heads
  if (temp->value < head->value) {
    temp->next = head;
    head = temp;
    return;
  }

  insert_place(head, temp);
}

// Change the next ptr of the previous Node and the next prop of the new Node
void SortedList::insert_place(Node *currentNode, Node *newNode) {
  // Check if currentNode is the last element
  if (currentNode->next == nullptr) {
    currentNode->next = newNode;
    return;
  }

  if (newNode->value < currentNode->next->value) {
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    return;
  }

  insert_place(currentNode->next, newNode);
}

void SortedList::remove(int index) {

  // Guard agaist out of range index
  if (index > this->size() - 1 || index < 0) {
    return;
  }

  Node *curr{head};

  // Remove the first element
  if (index == 0) {
    head = head->next;
    delete curr;
    return;
  }

  int counter{0};
  while (curr->next != nullptr) {
    if (counter + 1 == index) {
      Node *temp{curr->next};
      curr->next = curr->next->next;
      delete temp;
      return;
    }
    curr = curr->next;
    ++counter;
  }

  cout << "The last value should be: " << curr->next->value << endl;
  // Remove the last element
  Node *temp{curr->next};
  curr->next = nullptr;
  delete temp;
}

bool SortedList::is_empty() const { return head == nullptr; }

void SortedList::print() const { cout << to_string() << endl; }

string SortedList::to_string() const {
  Node *curr{head};
  std::stringstream ss{};
  while (curr != nullptr) {
    ss << curr->value;
    // Only add whitespace if not the last element
    if (curr->next != nullptr) {
      ss << " ";
    }
    curr = curr->next;
  }
  return ss.str();
}

int SortedList::at(int index) const {
  Node *curr{head};
  for (int i = 0; i < this->size(); i++) {
    if (i == index) {
      return curr->value;
    }
    curr = curr->next;
  }

  // Undefined behaviour
  return -1;
}

int SortedList::size() const {
  int counter{0};
  Node *curr{head};
  while (curr != nullptr) {
    curr = curr->next;
    ++counter;
  }
  return counter;
}
