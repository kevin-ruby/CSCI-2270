#include<iostream>
#include<climits>
#include "PriorityQueue.hpp"
#include <string>
using namespace std;

void swap(PatientNode *x, PatientNode *y)
{
    PatientNode temp = *x;
    *x = *y;
    *y = temp;
}

PriorityQueue::PriorityQueue(int _queueSize){
  currentQueueSize=0;
  maxQueueSize=_queueSize;
  priorityQueue=new PatientNode[_queueSize+1];
}

PriorityQueue::~PriorityQueue(){
  delete [] priorityQueue;
}

bool PriorityQueue::isFull(){
  return currentQueueSize==maxQueueSize;
}
bool PriorityQueue::isEmpty(){
  return !currentQueueSize;
}

string PriorityQueue::peekName(){
  if (!isEmpty())
  {
    return priorityQueue[1].name;
  }
  return 0;

}
int PriorityQueue::peekTreatmentTime(){
  if (!isEmpty()){
    return priorityQueue[1].treatmentTime;
  }
  return 0;
}
int PriorityQueue::peekInjurySeverity(){
  if (!isEmpty()){
    return priorityQueue[1].injurySeverity;
  }
  return 0;
}

void PriorityQueue::enqueue (string _name, int _injurySeverity, int _treatmentTime){
    if (!isFull()){
      PatientNode tmp;
      tmp.name=_name;
      tmp.injurySeverity=_injurySeverity;
      tmp.treatmentTime=_treatmentTime;
      currentQueueSize++;
      priorityQueue[currentQueueSize]=tmp;
      repairUpward(currentQueueSize);
    }
}

void PriorityQueue::dequeue(){
  if (currentQueueSize<=0){
    return;
  }
  if (currentQueueSize==0){
    currentQueueSize--;
    return;
  }
  priorityQueue[1]=priorityQueue[currentQueueSize];
  currentQueueSize--;
  repairDownward(1);
}


// like ReverseHeapify --  from lab
void PriorityQueue::repairUpward(int nodeIndex){
  int p =nodeIndex/2;
  if (p!=0 and priorityQueue[p].injurySeverity < priorityQueue[nodeIndex].injurySeverity){
    swap(&priorityQueue[p],&priorityQueue[nodeIndex]);
    repairUpward(p);
  }
  if (p!=0 and priorityQueue[p].injurySeverity==priorityQueue[nodeIndex].injurySeverity and priorityQueue[p].treatmentTime > priorityQueue[nodeIndex].treatmentTime){
    swap(&priorityQueue[p],&priorityQueue[nodeIndex]);
    repairUpward(p);
  }
}


// like MinHeapify -- from lab
void PriorityQueue::repairDownward(int nodeIndex){
  int l = nodeIndex*2;
  int r =nodeIndex*2 +1;
  int small=nodeIndex;


  if (l<=currentQueueSize and priorityQueue[l].injurySeverity > priorityQueue[small].injurySeverity){
    small=l;
  }
  if (l<=currentQueueSize and priorityQueue[l].injurySeverity==priorityQueue[small].injurySeverity and priorityQueue[l].treatmentTime < priorityQueue[small].treatmentTime){
      small=l;
  }

  if (r<=currentQueueSize and priorityQueue[r].injurySeverity > priorityQueue[small].injurySeverity){
    small=r;
  }
  if (r<=currentQueueSize and priorityQueue[r].injurySeverity==priorityQueue[small].injurySeverity and priorityQueue[r].treatmentTime < priorityQueue[small].treatmentTime){
      small=r;
  }

  if (small!=nodeIndex){
    swap(&priorityQueue[nodeIndex],&priorityQueue[small]);
    repairDownward(small);
  }
}
