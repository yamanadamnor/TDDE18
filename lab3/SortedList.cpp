#include "SortedList.hpp"

void Sorted_list::insert(int value)
{
  Node *temp{new Node{value}};
  insert_place(head, temp->value);
  delete temp;
}

void *Sorted_list::insert_place(Node *currentNode, Node *comparisonNode)
{
  if (currentNode->next == nullptr)
  {
    comparisonNode->next = currentNode->next;
    currentNode->next = comparisonNode;
  };

  if (comparisonNode->value < currentNode->value){
    comparisonNode->next = currentNode->next;
    currentNode->
  }

  insert_place(comparisonNode->next, comparisonNode);

}