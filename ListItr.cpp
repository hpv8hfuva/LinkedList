//Hunter Vaccaro
//hpv8hf
//9/10/2019
//ListItr.cpp

#include <iostream>
#include "ListNode.h"
#include "List.h"
#include "ListItr.h"

ListItr::ListItr() { //default constructor
  ListNode *temp = new ListNode();
  current = temp;
}
ListItr::ListItr(ListNode* theNode) {
  current = theNode;
}
bool ListItr::isPastEnd() const { //returns true if pointer is at the end 
  if(current -> next == NULL)
    return true;
  return false;
}
bool ListItr::isPastBeginning() const { //returns true if pointer is at the beginning
  if(current -> previous == NULL)
    return true;
  return false;
}
void ListItr::moveForward() { //moves pointer forward
  if(!isPastEnd())
  current=current->next;
}
void ListItr::moveBackward() { //moves pointer backward
  if(!isPastBeginning())
  current=current->previous;
}
int ListItr::retrieve() const{ //returns the value at the pointer
  return (current -> value);
}
