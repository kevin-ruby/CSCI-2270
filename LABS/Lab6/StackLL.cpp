#include <iostream>
#include "StackLL.hpp"

using namespace std;

StackLL::StackLL()
{
  stackHead=NULL;
}

StackLL::~StackLL()
{
  while(!isEmpty()) pop();
}

bool StackLL::isEmpty()
{
    return (stackHead==NULL);
}

void StackLL::push(int key)
{
  Node*tmp=new Node;
  tmp->key=key;
  tmp->next=stackHead;
  stackHead=tmp;
}

void StackLL::pop()
{
  if(!isEmpty())
  {
    Node*tmp=stackHead;
    stackHead=stackHead->next;
    delete tmp;
  }
  else
  {
    cout<<"Empty......."<<endl;
  }
}

int StackLL::peek()
{
  if(isEmpty()){
    cout<<"Empty... cannot peek"<<endl;
    return 0;
  }

  return stackHead->key;
}
