#include "HW4-Todo-QueueArray.hpp"
#include <iostream>
using namespace std;

TodoQueueArray::TodoQueueArray(){
  queueFront=-1;
  queueEnd=-1;
}
bool TodoQueueArray::isEmpty(){
  return(queueFront==-1);
}
bool TodoQueueArray::isFull(){
  return((queueEnd+1)%MAX_QUEUE_SIZE==queueFront);
}
void TodoQueueArray::enqueue(string todoItem){
  TodoItem* temp=new TodoItem;
  temp->todo=todoItem;
  if (isFull())
  {
    cout << "Queue full, cannot add new todo item." << endl;
    return;
  }

  if (queueFront==-1)
  {
      queueFront=0;
      queueEnd=0;
  }
  else queueEnd = (queueEnd+1)%MAX_QUEUE_SIZE;
  queue[queueEnd]=temp;
}

void TodoQueueArray::dequeue(){
  if(!isEmpty())
  {
    TodoItem *temp=queue[queueFront];
    delete temp;
    if(queueFront==queueEnd){
        queueFront=-1;
        queueEnd=-1;
    }
    else queueFront=(queueFront+1) % MAX_QUEUE_SIZE;
  }
  else cout << "Queue empty, cannot dequeue an item." << endl;


}
TodoItem* TodoQueueArray::peek(){
  if (isEmpty()){
    cout << "Queue empty, cannot peek." << endl;
    return NULL;
  }
  return queue[queueFront];
}
a
