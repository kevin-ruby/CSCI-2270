#include "graph1.hpp"
#include<iostream>
#include<set>
#include<list>
#include<algorithm>
using namespace std;


Graph::Graph(int nodeCount) {
   n = nodeCount;
   adjList = new list<node>[n];
}

void Graph::showList(int src, list<node> lt) {
   list<node> :: iterator i;
   node tempNode;

   for(i = lt.begin(); i != lt.end(); i++) {
      tempNode = *i;
      cout << "(" << src << ")---("<<tempNode.dest << "|"<<tempNode.cost<<") ";
   }
   cout << endl;
}



void Graph::addEdge(int source, int dest, int cost)
{
  node newNode;
  newNode.dest=dest;
  newNode.cost=cost;
  adjList[source].push_back(newNode);

  node newNode2;
  newNode2.dest=source;
  newNode2.cost=cost;
  adjList[dest].push_back(newNode2);

}

void Graph::displayEdges()
{
   for(int i = 0; i<n; i++)
   {
      list<node> tempList = adjList[i];
      showList(i, tempList);
   }
}

int Graph:: min_element(int dist[], bool visited[])
{
   // Initialize min value
   int min = INT_MAX, min_index = -1;
   for (int v =0;v<n;v++){
     if (!visited[v] && dist[v]<=min){
       min = dist[v];
       min_index=v;
     }
   }

   return min_index;
}

void Graph::dijkstra( int *dist, int *prev, int start)
{
  bool visited[n];
  for (int u=0;u<n;u++){
    dist[u]= INT_MAX;
    prev[u]=-1;
    visited[u]=false;
  }
  dist[start]=0;

  for(int i=0;i<n-1;i++){
    int u = min_element(dist,visited);
    visited[u]=true;

    for (auto it=adjList[u].begin();it!=adjList[u].end();it++){
      if (dist[u]+(it->cost) < dist[it->dest]){
        dist[it->dest] = dist[u]+(it->cost);
        prev[it->dest]=u;
      }
    }
  }

}
