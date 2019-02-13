#include "HW4-Todo-QueueLinkedList.hpp"
#include <iostream>
using namespace std;

TodoQueueLinkedList::TodoQueueLinkedList(){
  queueFront=NULL;
  queueEnd=NULL;
}
TodoQueueLinkedList::~TodoQueueLinkedList(){
  while(!isEmpty()){
    dequeue();
  }
}
bool TodoQueueLinkedList::isEmpty(){
  return(!queueFront or !queueEnd);
}
void TodoQueueLinkedList::enqueue(string todoItem){
  TodoItem*tmp= new TodoItem;
  tmp->todo=todoItem;
  tmp->next=NULL;

  if (isEmpty()){
    queueFront=tmp;
    queueEnd=tmp;
  }
  else {
    queueEnd->next=tmp;
    queueEnd=tmp;
  }
}
void TodoQueueLinkedList::dequeue(){
  if(!isEmpty()){
  TodoItem*tmp=queueFront;
  queueFront=queueFront->next;

  if(queueFront==NULL)
    queueEnd=queueFront;
  delete tmp;
  }
  else cout << "Queue empty, cannot dequeue an item." << endl;
}

TodoItem* TodoQueueLinkedList::peek(){
  if(isEmpty())
  {
    cout << "Queue empty, cannot peek." << endl;
  }

  return queueFront;
}
