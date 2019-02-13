#include <iostream>
#include "MovieTree.hpp"
using namespace std;



MovieTree::MovieTree(){
  root=NULL;
}
MovieTree::~MovieTree(){

}


MovieNode* addMovieNodeHelper(MovieNode* currNode, int rank, string tit, int releaseYear, int quant){
  string currNodetitle="";

  if(currNode!=NULL){
   currNodetitle=currNode->title;
  }

  if (currNode==NULL){
    MovieNode *temp=new MovieNode;
    temp->ranking=rank;
    temp->title=tit;
    temp->year=releaseYear;
    temp->quantity=quant;

    temp->leftChild=NULL;
    temp->rightChild=NULL;
    return temp;
  }
  if (currNodetitle.compare(tit)>0){
    currNode->leftChild=addMovieNodeHelper(currNode->leftChild,rank,tit,releaseYear,quant);
  }
  else if (currNodetitle.compare(tit)<0){
    currNode->rightChild=addMovieNodeHelper(currNode->rightChild,rank,tit,releaseYear,quant);
  }
  return currNode;
}

void MovieTree::addMovieNode(int rank,string tit, int releaseYear, int quant){
  if (root==NULL){
    MovieNode *temp=new MovieNode;
    temp->ranking=rank;
    temp->title=tit;
    temp->year=releaseYear;
    temp->quantity=quant;

    temp->leftChild=NULL;
    temp->rightChild=NULL;
    root= temp;
  }
  else {
    addMovieNodeHelper(root,rank,tit,releaseYear,quant);
  }
}

MovieNode * printMovieInventoryHelper(MovieNode * node){
  if(node==NULL){
      return NULL;
  }

  printMovieInventoryHelper(node->leftChild);
  cout << "Movie: " << node->title << " " << node->quantity << endl;
  printMovieInventoryHelper(node->rightChild);
  return node;

}

void MovieTree::printMovieInventory(){
  if (root==NULL){
    return;
  }
  else{
    printMovieInventoryHelper(root);
  }
}

MovieNode * searchHelper(MovieNode*node , string title){
  string currNodetitle="";

  if(node!=NULL){
   currNodetitle=node->title;
  }

  if (node==NULL or node->title == title){
    return node;
  }
  if (currNodetitle.compare(title)>0){
    return searchHelper(node->leftChild,title);
  }
  else if(currNodetitle.compare(title)<0){
    return searchHelper(node->rightChild,title);
  }
  return node;
}

void MovieTree::findMovie(string title){
  MovieNode*node=searchHelper(root,title);
  if (node==NULL){
    cout << "Movie not found." << endl;
    return;
  }
  else{
    cout << "Movie " << "'"<< node->title <<"' Info:"<< endl;
	  cout << "================================" << endl;
	  cout << "Ranking : " << node->ranking << endl;
	  cout << "Title   : " << node->title << endl;
	  cout << "Year    : " << node->year << endl;
	  cout << "Quantity: " << node->quantity << endl;
    return;
  }

}



void MovieTree::rentMovie(string title){
  MovieNode* node=searchHelper(root,title);
  if (node ==NULL){
      cout<<"Movie not found."<<endl;
      return;
  }

  if (node->quantity==0){
    cout<<"Movie out of stock."<<endl;
  }
  else{
  node->quantity--;
  cout << "Movie has been rented." << endl;
  cout << "Movie " << "'"<< node->title <<"' Info:"<< endl;
	cout << "================================" << endl;
	cout << "Ranking : " << node->ranking << endl;
	cout << "Title   : " << node->title << endl;
	cout << "Year    : " << node->year << endl;
	cout << "Quantity: " << node->quantity << endl;
  return;
}
}
