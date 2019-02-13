#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

#include "Graph.hpp"

using namespace std;

int main(int argc, char*argv[]){
  if (argc!=2){
    cout<<"Usage"<<endl;
    return 0;
  }

  Graph kev;
  vector<string> cityVector;

  ifstream yuh;
  yuh.open(argv[1]);
  if (!yuh.is_open()){
    cout<<"error.."<<endl;
    return 0;
  }
  string city;
  string line;

  getline(yuh,line);
  stringstream ss(line);
  while(getline(ss,city,',')){
    if (city != "cities"){
      kev.addVertex(city);
      cityVector.push_back(city);
    }
  }

  int counter=-1;

  int distance=0;
  string hi;
  while(!yuh.eof()){
    
    string s;
    //if (!getline(yuh,s)) break;
    counter =-1;
    getline(yuh,s);
    stringstream ss(s);
    while(getline(ss,hi,',')){

        if (counter == -1){
          city = hi;
        }
        else {
        if (hi != "-1" and hi != "0"){
          distance = stoi(hi);
          cout << " ... Reading in " << city << " -- " << cityVector[counter] << " -- " 	<< distance << endl;

          kev.addEdge(city,cityVector[counter],distance);
          }
        }
        counter ++;
    }
  }

  kev.assignDistricts();
  kev.displayEdges();
}
