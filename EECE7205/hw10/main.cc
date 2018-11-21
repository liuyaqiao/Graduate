#include <iostream>
#include "Graph.h"

int main()
{
// Undirected graph shown in the trace for the Floyd-Warshall algorithm
// on this document.
    Graph g(7);
    g.AddUndirectedEdge(0,1);
    g.AddUndirectedEdge(0,2);
    g.AddUndirectedEdge(0,3);
    g.AddUndirectedEdge(0,5);
    g.AddUndirectedEdge(1,2);
    g.AddUndirectedEdge(1,4);
    g.AddUndirectedEdge(1,6);
    g.AddUndirectedEdge(2,3);
    g.AddUndirectedEdge(2,4);
    g.AddUndirectedEdge(3,4);
    g.AddUndirectedEdge(3,5);
    g.AddUndirectedEdge(3,6);
    g.AddUndirectedEdge(4,5);
    g.AddUndirectedEdge(4,6);
    g.AddUndirectedEdge(5,6);
    g.FloydWarshall();
    std::cout<<"\nMatrix of the graph after FW algorithms(distance)\n";
    g.PrintGraph();
    std::cout<<"\nIsClique test\n";
    std::vector<int> temp = {3,4,5,6};
    std::vector<int> temp2 = {1,3,4};
    std::cout<<"[d,e,f,g]   "<<g.isClique(temp)<<"\n";
    std::cout<<"[b,d,f]   "<<g.isClique(temp2)<<"\n";
    std::cout<<"\nCliqueExist test\n";
    std::cout<<"k = 4  "<<g.CliqueExists(4)<<"\n";
    std::cout<<"k = 5  "<<g.CliqueExists(5)<<"\n";
    std::cout<<"\nGetMaxClique test\n";
    std::cout<<g.getMaxClique()<<"\n";
}
