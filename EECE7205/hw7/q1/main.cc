#include <iostream>
#include "Graph.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Graph g(8);
    g.AddUndirectedEdge(0, 1);
    g.AddUndirectedEdge(0, 4);
    g.AddUndirectedEdge(1, 5);
    g.AddUndirectedEdge(2, 3);
    g.AddUndirectedEdge(2, 5);
    g.AddUndirectedEdge(2, 6);
    g.AddUndirectedEdge(3, 6);
    g.AddUndirectedEdge(3, 7);
    g.AddUndirectedEdge(5, 6);
    g.AddUndirectedEdge(6, 7);
    g.DeleteVertex(1);
    g.Print();
    return 0;
}
