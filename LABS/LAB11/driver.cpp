#include<iostream>
#include<climits>
#include "graph.hpp"
using namespace std;

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    cout << "Following is depth First Traversal "
         << "(starting from vertex 0) \n" <<endl;
    g.DFS(0);
    cout << "\nFollowing is breadth First Traversal "
         << "(starting from vertex 0) \n"<<endl;
    g.BFS(0);

    return 0;
}
