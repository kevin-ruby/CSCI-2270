// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"

using namespace std;

node* HashTable::createNode(string key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
  tableSize=bsize;
  table= new node *[tableSize];
  for (int i=0;i<bsize;i++){
    table[i]=nullptr;

  }

}

//function to calculate hash function
unsigned int HashTable::hashFunction(string key)
{
    unsigned int hash = 0;
    for (int i=0;i<key.length();i++)
    {
      hash+=key[i];
    }

    return hash %tableSize;
}

//function to search
node* HashTable::searchItem(string key)
{
    int index = hashFunction(key);
    node*tmp= table[index];
    while(tmp!=nullptr){
      if (tmp->key==key){
        return tmp;
      }
      tmp=tmp->next;
    }
    return nullptr;
}

//function to insert
bool HashTable::insertItem(string key)
{
    if (!searchItem(key)){
      int index=hashFunction(key);
      node *tmp=createNode(key,nullptr);
      if (table[index]==nullptr){
        table[index] = tmp;
      }
      else {
        tmp->next=table[index];
        table[index]=tmp;
      }
      return true;
    }

    return false;
}

// function to delete
bool HashTable::deleteItem(string key)
{
    int index=hashFunction(key);
    node *tmp=table[index];
    bool found=false;
    if (tmp==nullptr){
      return found;
    }
    else if (tmp->key==key){
      table[index] = tmp->next ;
      delete tmp;
      tmp=nullptr;

    }
    else {
      while(tmp->next and !found){
        if (tmp->next->key==key)
          found =true;
          else
            tmp=tmp->next;
      }
      if (found){
        node *del = tmp->next;
        tmp->next=tmp->next->next;
        delete del;
        del= NULL;
      }

    }

    return found;
}

// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        node* temp = table[i];
        while(temp)
        {
            cout<< temp->key;
            if(temp->next!=nullptr)
            {
                cout<<"-->";
            }
            temp = temp->next;
        }
        cout<<endl;

    }
}
