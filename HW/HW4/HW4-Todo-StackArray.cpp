#include "HW4-Todo-StackArray.hpp"
#include <iostream>
using namespace std;

TodoStackArray::TodoStackArray()
{
  stackTop=-1;
}

bool TodoStackArray::isEmpty()
{
  return (stackTop==-1);
}

bool TodoStackArray::isFull()
{
  if (stackTop==4)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void TodoStackArray::push(string str)
{
  if (!isFull()){
  TodoItem*temp=new TodoItem;
  temp->todo=str;
  stackTop++;
  stack[stackTop]=temp;


}
else
{
  cout << "Stack full, cannot add new todo item." << endl;
}
}
void TodoStackArray::pop()
{
  if(!isEmpty())
  {
    TodoItem*tmp=stack[stackTop];
    delete tmp;
    stackTop--;
  }
  else
  {
    cout << "Stack empty, cannot pop an item." << endl;
  }
}

TodoItem* TodoStackArray::peek()
{
  if (isEmpty())
  {
    cout << "Stack empty, cannot peek." << endl;
    return NULL;
  }
  else
  {
    return stack[stackTop];
  }

}
