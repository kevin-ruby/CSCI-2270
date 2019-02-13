#include "HW4-Todo-StackLinkedList.hpp"
#include <iostream>
using namespace std;

TodoStackLinkedList::TodoStackLinkedList(){
  stackHead=NULL;
}

TodoStackLinkedList::~TodoStackLinkedList(){
  while(!isEmpty()) pop();
}
bool TodoStackLinkedList::isEmpty(){
  return (stackHead==NULL);
}
void TodoStackLinkedList::push(string todoItem){
    TodoItem * temp = new TodoItem;
    temp->todo=todoItem;
    temp->next=stackHead;
    stackHead=temp;
}
void TodoStackLinkedList::pop(){
  if (!isEmpty())
  {
    TodoItem *tmp=stackHead;
    stackHead=stackHead->next;
    delete tmp;
  }
  else cout << "Stack empty, cannot pop an item." << endl;

}
TodoItem* TodoStackLinkedList::peek(){
  if(isEmpty())
  {
    cout << "Stack empty, cannot peek." << endl;
    return NULL;
  }
  return stackHead;
}
