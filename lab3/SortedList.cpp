#include <iostream>
#include <sstream>
#include <string>
#include "sorted_list.hpp"
using namespace std;

int SortedList::Node::get_value()
{
  return value;
}

// Copy constructor
// void SortedList::SortedList(SortedList list) {}

void SortedList::insert(int value)
{
  Node *temp{new Node{value}};

  if (head == nullptr)
  {
    head = temp;
    return;
  }

  if (temp->value < head->value)
  {
    temp->next = head;
    head = temp;
    return;
  }

  insert_place(head, temp);
  // delete temp;
}

// Change the next ptr of the previous Node and the next prop of the new Node
void SortedList::insert_place(Node *currentNode, Node *newNode)
{
  // head: 0x0023 -> 0x0
  // currentNode: 0x82312 -> 0x0

  // newnode: 0x99384

  // 0x82312 = 0x99384 // ekvivalent med currentNode = newNode
  // currentNode: 0x82312 -> 0x99384 // currentNodes address -> currentNodes värde

  // Check if currentNode is the last element
  if (currentNode->next == nullptr)
  {
    currentNode->next = newNode;
    return;
  }

  if (newNode->value < currentNode->next->value)
  {
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    return;
  }

  insert_place(currentNode->next, newNode);
}

bool SortedList::is_empty()
{
  return head == nullptr;
}

string SortedList::print()
{
  Node *curr{head};
  std::stringstream ss{};
  while (curr != nullptr)
  {
    ss << curr->value;
    // Only add whitespace if not the last element
    if (curr->next != nullptr)
    {
      ss << " ";
    }
    curr = curr->next;
  }
  return ss.str();
}

int SortedList::size()
{
  int counter{0};
  Node *curr{head};
  while (curr != nullptr)
  {
    curr = curr->next;
    ++counter;
  }
  return counter;
}

SortedList::Node *SortedList::get_head()
{
  return head;
}