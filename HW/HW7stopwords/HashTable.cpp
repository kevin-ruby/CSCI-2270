// CPP program to implement hashing with chaining
#include<iostream>
#include <fstream>

#include "HashTable.hpp"

using namespace std;

HashTable::HashTable(int hashTableSize){
  this-> hashTableSize=hashTableSize;
  hashTable=new wordItem * [hashTableSize];
  for (int i =0;i<hashTableSize;i++){
    hashTable[i]=NULL;
  }
  numItems=0;
  numCollisions=0;

}

HashTable::~HashTable() {
    wordItem* tmp;
    wordItem* kev;
    for (int i = 0; i<hashTableSize; i++) {
        tmp = hashTable[i];
        while(tmp) {
            kev = tmp->next;
            delete tmp;
            tmp = kev;
        }
        hashTable[i] = NULL;
    }
    delete [] hashTable;

}


unsigned int HashTable::getHash(string word)
{
    unsigned int hash= 5381;
    for (unsigned int i =0;i<word.length();i++){
      hash= hash*33 +word[i];
    }
    return hash%hashTableSize;
}

wordItem * HashTable::searchTable(string word){
  int index=getHash(word);
  wordItem*tmp=hashTable[index];
  while (tmp){
    if (tmp->word==word){
      return tmp;

    }
    tmp=tmp->next;

  }
  return NULL;
}

//**** NEED isInTable DIRECTLY AFTER THIS note*****//
bool HashTable::isInTable(string word){
  wordItem * tmp=searchTable(word);
  if (tmp!=NULL){
    return true;
  }
  else return false;
}


int insertIntoSortedArray(wordItem* myArray[], int numEntries, wordItem *word)
{
    int track=-1;

    for (int i=0;i<numEntries;i++)
    {
        if(word->count>myArray[i]->count)
        {
            track=i;
            break;
        }
    }
    if (track==-1)
    {
        track=numEntries;
    }

    for (int i=numEntries;i>track;i--)
    {
        myArray[i]=myArray[i-1];
    }

    myArray[track]=word;

    numEntries++;

    return numEntries;
}

void HashTable::printTopN(int n)
{
    int tot=numItems+numCollisions;
    wordItem**array=new wordItem*[tot];
    int count=0;
    for (int i =0;i<hashTableSize;i++){
      wordItem *tmp=hashTable[i];
      while(tmp){
        count=insertIntoSortedArray(array,count,tmp);
        tmp=tmp->next;
      }
    }
    for(int i = 0; i<n; i++) {
        cout << array[i]->count << " - " << array[i]->word << endl;
    }

    delete [] array;
}


int HashTable::getTotalNumWords()
{
    int total=0;
    for (int i =0;i<hashTableSize;i++){
      wordItem * tmp =hashTable[i];
      while (tmp){
        total= total +tmp->count;
        tmp=tmp->next;
      }
    }
    return total;
}

void HashTable::addWord(string word)
{
    if (!isInTable(word)){
        int index=getHash(word);
        wordItem * tmp= new wordItem;
        tmp->word=word;
        tmp->count=1;
        tmp->next=hashTable[index];
        numItems++;

        if(hashTable[index]!= NULL){
          numCollisions++;
        }
        hashTable[index]=tmp;

    }
}



int HashTable::getNumCollisions(){
  return numCollisions;
}
int HashTable::getNumItems(){
  return numItems;
}

bool isStopWord(string word, HashTable&stopWordsTable){
  return stopWordsTable.isInTable(word);
}

void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable)
{
    ifstream stopstream;
    stopstream.open(ignoreWordFileName);
    string word;
    if (stopstream.is_open()){
      while (getline(stopstream,word)){
        stopWordsTable.addWord(word);
      }
    }
}

void HashTable::incrementCount(string word) {
    wordItem * tmp = searchTable(word);
    if (tmp){
        tmp->count++;
    }
}
