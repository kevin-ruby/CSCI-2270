#include<iostream>
#include<climits>
#include "graph1.hpp"
using namespace std;

int main() {
   int n = 9;
   Graph g(n);
   int dist[n], prev[n];
   int start = 0;

   /*g.addEdge(0, 1, 3);
   g.addEdge(0, 2, 6);
   g.addEdge(1, 0, 3);
   g.addEdge(1, 2, 2);
   g.addEdge(1, 3, 1);
   g.addEdge(2, 1, 6);
   g.addEdge(2, 1, 2);
   g.addEdge(2, 3, 1);
   g.addEdge(2, 4, 4);

   g.addEdge(2, 5, 2);
   g.addEdge(3, 1, 1);
   g.addEdge(3, 2, 1);
   g.addEdge(3, 4, 2);
   g.addEdge(3, 6, 4);
   g.addEdge(4, 2, 4);
   g.addEdge(4, 3, 2);
   g.addEdge(4, 5, 2);
   g.addEdge(4, 6, 1);
   g.addEdge(5, 2, 2);
   g.addEdge(5, 4, 2);
   g.addEdge(5, 6, 1);
   g.addEdge(6, 3, 4);
   g.addEdge(6, 4, 1);
   g.addEdge(6, 5, 1);*/

   g.addEdge(0, 1, 4);
   g.addEdge(0, 7, 8);
   g.addEdge(1, 7, 11);
   g.addEdge(1, 2, 8);
   g.addEdge(7, 8, 7);
   g.addEdge(7, 6, 1);
   g.addEdge(2, 8, 2);
   g.addEdge(8, 6, 6);
   g.addEdge(2, 3, 7);
   g.addEdge(6, 5, 2);
   g.addEdge(2, 5, 4);
   g.addEdge(3, 5, 14);
   g.addEdge(3, 4, 9);
   g.addEdge(5, 4, 10);

   g.dijkstra( dist, prev, start);
   cout<<"Graph represented as adjacency list"<<endl;
   g.displayEdges();
   cout<<endl;
   cout<<"Source to Destination costs and path"<<endl;
   for(int i = 0; i<n; i++)
      if(i != start)
         cout<<start<<" to "<<i<<", Cost: "<<dist[i]<<" Previous: "<<prev[i]<<endl;
   return 0;
}
