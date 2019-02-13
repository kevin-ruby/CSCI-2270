#ifndef GRAPH_HPP
#define GRAPH_HPP
#include<list>
using namespace std;
// This class represents a directed graph using
// adjacency list representation

typedef struct node {
   int dest;
   int cost;
}node;

class Graph
{
private:
    int n;    // No. of vertices
    list<node> *adjList;

    void showList(int src, list<node> lt);
    int min_element(int dist[], bool visited[]);
public:

    Graph(int n);  // Constructor

    // function to add an edge to graph
    void addEdge(int source, int destination, int cost);
    void displayEdges();
    void dijkstra(int *dist, int *prev, int start);


};
#endif
