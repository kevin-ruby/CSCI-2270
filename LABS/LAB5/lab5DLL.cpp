#include<iostream>
using namespace std;


//node implementation for doubly linked list
struct Node
{
int key;
Node *previous;
Node *next;
};

 class DLL{
  private:
   Node * head;
   Node* tail;

  public:
    DLL(){
      head=NULL;
      tail=NULL;
    }
    void append(int val){
      Node* newnode= new Node;
      newnode->key=val;
      newnode->next=NULL;
      newnode->previous=NULL;

      if (tail==NULL){
        head=newnode;
        tail=newnode;
        return;
      }

      newnode->previous=tail;
      tail->next=newnode;
      tail=newnode;
      return;

    }
    void print(){
      Node* ptr=head;
      while(ptr!=NULL){
        cout<<ptr->key<<" ";
        ptr=ptr->next;

      }
      cout<<endl;
    }
    void printReverse(){
      Node* ptr=tail;
      while(ptr!=NULL){
        cout<<ptr->key<<" ";
        ptr=ptr->previous;

      }
      cout<<endl;
    }

    void InsertAt(int val, int index){
      int pos=0;
      Node *curr=head;

      while(pos<index and curr->next!=NULL ){
        curr=curr->next;
        pos++;
      }

      Node* newnode= new Node;
      newnode->key=val;
      newnode->next=curr->next;
      newnode->previous=curr;

      if(newnode->previous)
        newnode->previous->next=newnode;
      else
        head=newnode;
      if(newnode->next)
        newnode->next->previous=newnode;
      else
        tail=newnode;

    }
 };

int main()
{
  DLL list;
  cout<<"Appending 1,3,5"<<endl;

  list.append(1);
  list.append(3);
  list.InsertAt(2,2);
  list.append(5);
  list.print();
  list.printReverse();

  return 0;



}
