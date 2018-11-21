#include <iostream>
#include "Graph.h"
int main(int argc, char *argv[])
{
// Undirected graph shown in this document for the trace of the BFS
// algorithm.
    char *a = argv[1];
    double alpha = atof(a);
    Graph g(5, alpha);
    g.Print();

}