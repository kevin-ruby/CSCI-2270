// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
#include "heap.hpp"
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);


// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
  heap_size = 0;
  capacity = cap;
  harr = new int[cap+1];
}

// Return the index of parent of the node at index i
int MinHeap::parent(int i)
{
    return i/2;
}

// Return index of left child of node at index i
int MinHeap::left(int i)
{
    return i*2;
}

// Return index of right child of node at index i
int MinHeap::right(int i)
{
    return i*2 + 1;
}

// Return the minimum value in the heap
int MinHeap::getMin()
{
    if (!heap_size) { cout << "Empty my man" << endl; return -1; }
    return harr[1];
}

// Inserts a new key 'k'
void MinHeap::pushMinHeap(int k)
{
  if(heap_size == capacity) {
    cout << "Overflow, heap is full my man" << endl;
    return;
  }
  heap_size++;
  harr[heap_size] = k;
  ReverseHeapify(heap_size);
}

// Heapify after inserting an element to the heap
void MinHeap::ReverseHeapify(int i)
{
  int p = parent(i);
  if (p!=0 && harr[p] > harr[i]) {
    swap(&harr[p], &harr[i]);
    ReverseHeapify(p);
  }
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l =left(i);
    int r =right(i);
    int smallest= i;
    if (l <= heap_size and harr[l] <= harr[smallest]){
      smallest=l;
    }
    if (r <= heap_size and harr[r] <= harr[smallest]){
      smallest=r;
    }
    if (smallest!=i){
      swap(&harr[i],&harr[smallest]);
      MinHeapify(smallest);
    }
}

// Method to remove minimum element (or root) from min heap
void MinHeap::popMinHeap()
{
  if (heap_size <= 0) {
    cout << "Empty my man" << endl;
    return;
  }
  if (heap_size == 1) {
    heap_size--;
    return;
  }
  harr[1] = harr[heap_size];
  heap_size--;
  MinHeapify(1);

}

void MinHeap::printMinHeap()
{
    for(int i=1;i<=heap_size;i++) cout<<i<<":"<<harr[i]<<endl;
}
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
