#include <iostream>
#include "Graph.h"


int main( )
{
// Undirected graph shown in this document for the trace of the BFS


    Graph g(10);
    g.AddUndirectedEdge(0, 1);
    g.AddUndirectedEdge(0, 2);
    g.AddUndirectedEdge(1, 4);
    g.AddUndirectedEdge(2, 3);
    g.AddUndirectedEdge(3, 4);
    g.AddUndirectedEdge(3, 6);
    g.AddUndirectedEdge(5, 6);
    g.AddUndirectedEdge(6, 7);
    g.AddUndirectedEdge(5, 8);
    g.AddUndirectedEdge(7, 9);
    g.AddUndirectedEdge(8, 9);
    g.BellmanFord(0);
    std::cout << "\n** final state **\n";
    g.Print();
    for (int i = 0; i < g.getSize(); i++)
    {
        std::cout << "Shorted path from s to " << node[i] << ": ";
        g.PrintShortestPath(0, i);
        std::cout << '\n';
    }
    std::cout << '\n';

}