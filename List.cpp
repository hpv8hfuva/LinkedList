//Hunter Vaccaro
//hpv8hf
//09/03/2019
//List.cpp

#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;


List::List() { //default constructor
  count = 0;
  head=new ListNode;
  tail=new ListNode;
  head -> next = tail;
  tail -> previous = head;  
}
List::List(const List& source){ // copy  Constructor
  head= new ListNode;
  tail = new ListNode;
  head->next=tail;
  tail->previous=head;
  count=0;
  ListItr iter(source.head->next);
  while(!iter.isPastEnd()){
    insertAtTail(iter.retrieve());
    iter.moveForward();
    }
}

List& List::operator=(const List& source){ 
  if(this==&source)
    return *this;
  else{
    makeEmpty();
    ListItr iter(source.head->next);
    while(!iter.isPastEnd()){
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

List::~List() { //destructor
  ListItr *front = new ListItr(head);
  while(!isEmpty()){
    front->current = front->current->next;
    delete front->current->previous;
    count--;
  }
}

void List::makeEmpty() { //empties the entire list and deletes the pointer when finished
  ListItr *point = new ListItr(tail);
  while(!isEmpty()){
    remove(point->current->previous->value);
  }
  delete point;
}

bool List::isEmpty() const { //checks if list is empty
  return (count==0)?true:false;
}

ListItr List::first(){ //returns pointer to head
  ListItr *beginning = new ListItr(head);
  return *beginning;
}
ListItr List::last() { //returns pointer to tail
  ListItr *ending = new ListItr(tail);
  ending -> moveForward();
  return *ending;
}

void List::insertAfter(int x, ListItr position) { //inserts at position + 1
  ListNode *after = new ListNode();
  after -> value = x;
  after -> next = (position.current->next);
  after -> next -> previous = after;
  position.current->next=after;
  after -> previous = position.current;
  count++;
}

void List::insertBefore(int x, ListItr position) { //inserts at position -1 & increase length
  ListNode *before = new ListNode();
  before -> value = x; 
  position.current -> previous -> next = before;
  before -> previous = (position.current -> previous); 
  position.current -> previous = before;
  before -> next = position.current;
  count++;
}

void List::insertAtTail(int x) { //inserts at tail & increase length
  ListNode *back = new ListNode();
  back -> value = x;
  back -> next = tail;
  tail -> previous -> next = back;
  back -> previous = tail -> previous;
  tail -> previous = back;
  count++;
}
void List::remove(int x) {//removes the listNode with value x
  if(find(x).retrieve()==x){ // if x exists
    ListItr *helper = new ListItr(head);
    while(helper->retrieve()!=find(x).retrieve()) {
      helper -> moveForward();
    }
    helper ->current -> previous ->next = helper ->current -> next;
    helper ->current ->  next -> previous = helper -> current -> previous;
    count--;
    delete helper->current;
    delete helper;
  }
}
ListItr List::find(int x) { //returns the pointer to the listNode with value x
  ListItr *helper = new ListItr(head);
  while(!helper->isPastEnd()) {
    if(helper -> current -> value == x) {
      return *helper;
    }
    else{
      helper->moveForward();
    }
  }
  return *helper;
}

int List::size() const { //returns the length
  return count;
}

void printList(List& source, bool direction){ //prints every value (forward/backward)
  if(direction) {
    ListItr helper = source.first();
    helper.moveForward();
    while(!(helper.isPastEnd())){
      cout << "[" << helper.retrieve()<< "] ";
      helper.moveForward();
    }
    cout <<endl;
  }
  else {
    ListItr helper = source.last();
    helper.moveBackward();
    while(!(helper.isPastBeginning())){
      cout << "[" << helper.retrieve() << "] ";
      helper.moveBackward();
    }
    cout <<endl;
    }
}



