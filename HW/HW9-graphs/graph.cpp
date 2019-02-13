#include<iostream>
#include<climits>
#include<list>
#include "Graph.hpp"
using namespace std;


Graph::Graph(){
}
Graph::~Graph(){
}

vertex * Graph::findVertex(string name){
  for (unsigned int i=0;i<vertices.size();i++){
    if (vertices[i].name == name){
      return &vertices[i];
    }
  }
  return NULL;
}

void Graph::addEdge(string v1, string v2, int distance){
  vertex * k = findVertex(v1);
  vertex * r = findVertex(v2);

  adjVertex thing;

  thing.distance=distance;
  thing.v=r;
  k->adj.push_back(thing);
}


void Graph::addVertex(string name){
  vertex v;
  v.name=name;
  v.district=-1;
  v.visited=false;
  v.ID=vertices.size();
  vertices.push_back(v);
}

void Graph::BFTraversalLabel(string startingCity, int distID){


  list<vertex*> queue;
  vertex *k = findVertex(startingCity);
  int location = k->ID;
  vertices[location].visited= true;
  vertices[location].district=distID;

  queue.push_back(&vertices[location]);



  while(!queue.empty()){
    k = queue.front();
    queue.pop_front();
    for (unsigned int i=0;i<k->adj.size();i++){
      if(k->adj[i].v->visited == false){
        k->adj[i].v->visited = true;
        k->adj[i].v->district=distID;
        queue.push_back(k->adj[i].v);
      }
    }
  }
}

void Graph::assignDistricts(){
  int id=1;
  for (unsigned int i=0;i<vertices.size();i++){
    if (vertices[i].district == -1){
      BFTraversalLabel(vertices[i].name,id);
      id++;
    }
  }
}

void Graph::displayEdges(){
  // If a city only has one edge
  for(unsigned int i=0;i<vertices.size();i++){
      cout << vertices[i].district<< ":"  << vertices[i].name << "-->";
      for (unsigned int j=0;j<vertices[i].adj.size();j++){
          cout<<vertices[i].adj[j].v->name;
          cout<<" (" << vertices[i].adj[j].distance << " miles)";
          if (j!= vertices[i].adj.size()-1){
              cout<< "***";
          }

      }
      cout<<endl;
    }
}
