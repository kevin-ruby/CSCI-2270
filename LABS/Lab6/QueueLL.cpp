#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
  queueFront=NULL;
  queueEnd=NULL;
}

QueueLL::~QueueLL()
{
  while(!isEmpty())
  {
    dequeue();
  }
}

bool QueueLL::isEmpty()
{

    return (!queueFront or !queueEnd);
}

void QueueLL::enqueue(int key)
{
  Node*tmp= new Node;
  tmp->key=key;
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

void QueueLL::dequeue()
{
  if(!isEmpty()){
  Node*tmp=queueFront;
  queueFront=queueFront->next;
  if(queueFront==NULL)
    queueEnd=queueFront;
  delete tmp;
  }
}

int QueueLL::peek()
{

    if(isEmpty())
    {
      cout<<"Empty"<<endl;
    }

    return queueFront->key;
}
