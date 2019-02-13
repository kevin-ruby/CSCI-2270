#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "MovieTree.hpp"
using namespace std;


void displayMenu(){
    cout << "======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Rent a movie" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "4. Quit" << endl;
}




int main(int argc, char*argv[]){
  if (argc!=2){
    cout<<"Usage"<<endl;
    return 0;
  }

  ifstream mainText;
  mainText.open(argv[1]);
  MovieTree kev;


  if (mainText.is_open()){
    string data;
    int ranking;
    string title;
    int year;
    int quant;
    while (getline(mainText,data)){
      stringstream ss(data);

      getline(ss,data,',');
      ranking=stoi(data);
      getline(ss,data,',');
      title=data;
      getline(ss,data,',');
      year=stoi(data);
      getline(ss,data,',');
      quant=stoi(data);


      kev.addMovieNode(ranking,title,year,quant);
    }

    int input=-1;
    string name;
    while (input!= 4){
      displayMenu();
      cin>>input;
      if(input==1){

        cout << "Enter title:" << endl;
        cin.ignore();
        getline(cin,name);
        kev.findMovie(name);
      }
      else if(input==2){

        cout << "Enter title:" << endl;
        cin.ignore();
        getline(cin,name);
        kev.rentMovie(name);
      }
      else if(input==3){
        kev.printMovieInventory();
      }
      else if(input==4){
        cout<< "Goodbye!"<<endl;
      }
      else{
          cout<<"Incorrect"<<endl;
          cin.clear();
          cin.ignore();
      }

    }




  }


}
