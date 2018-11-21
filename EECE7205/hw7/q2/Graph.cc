//
// Created by Yaqiao on 2018/3/24.
//

#include <climits>
#include <iostream>
#include <queue>
#include "Graph.h"

Graph::Graph(int size)
{
    this->size = size;
    V = new Vertex[size]();
    for (int i = 0; i < size; i++)
    {
        V[i].color = White;
        V[i].parent = -1;
        V[i].distance = INT_MAX;
        V[i].time_in = -1;
        V[i].time_out = -1;
        V[i].edges = NULL;
    }
}
Graph::~Graph()
{
    for (int i = 0; i < size; i++)
    {
        while (V[i].edges)
        {
            Edge *edge = V[i].edges;
            V[i].edges = edge->next;
            delete edge;
        }
    }
    delete[] V;
}

void Graph::AddEdge(int u, int v, int weight)
{
    Edge *edge = new Edge();
    edge->v = v;
    edge->weight = weight;
    edge->next = V[u].edges;
    V[u].edges = edge;
}

void Graph::AddUndirectedEdge(int u, int v, int weight)
{
    AddEdge(u, v, weight);
    AddEdge(v, u, weight);
}
void Graph::Print()
{
    std::cout << "Printing graph:\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << "Vertex " << i << ":";
        if (V[i].parent >= 0)
            std::cout << " parent=" << V[i].parent;
        if (V[i].distance < INT_MAX)
            std::cout << " distance=" << V[i].distance;
        if (V[i].time_in >= 0)
            std::cout << " time_in=" << V[i].time_in;
        if (V[i].time_out >= 0)
            std::cout << " time_out=" << V[i].time_out;
        std::cout << ", edges={";
        for (Edge *edge = V[i].edges; edge; edge = edge->next)
            std::cout << ' ' << i << "->" << edge->v;
        std::cout << " }\n";
    }
}

void Graph::BFS(int s)
{
// Initialize
    for (int i = 0; i < size; i++)
    {
        V[i].color = White;
        V[i].distance = INT_MAX;
        V[i].parent = -1;
    }
// Initialize vertex s
    V[s].color = Gray;
    V[s].distance = 0;
// Insert s in queue
    std::queue<int> Q;
    Q.push(s);
// Process queue
    while (Q.size())
    {
// Extract vertex from queue
        int u = Q.front();
        Q.pop();
// Traverse adjacency list
        for (Edge *edge = V[u].edges; edge; edge = edge->next)
        {
            int v = edge->v;
            if (V[v].color == White)
            {
                V[v].color = Gray;
                V[v].parent = u;
                V[v].distance = V[u].distance + 1;
                Q.push(v);
            }
        }
// Finish processing vertex
        V[u].color = Black;
    }
}

Graph *Graph::getBFT(int s) {
    if (s >= size) {
        std::cerr<<"out of size";
    }
    // Initialize
    for (int i = 0; i < size; i++)
    {
        V[i].color = White;
        V[i].distance = INT_MAX;
        V[i].parent = -1;
    }
// Initialize vertex s
    V[s].color = Gray;
    V[s].distance = 0;
// Insert s in queue
    std::queue<int> Q;
    Q.push(s);
    Graph *BFT = new Graph(8);
// Process queue
    std::vector<std::vector<int>> tree;
    while (Q.size())
    {
// Extract vertex from queue
        int u = Q.front();
        Q.pop();
// Traverse adjacency list
        std::vector<int> currentlevel;
        for (Edge *edge = V[u].edges; edge; edge = edge->next) {

            int v = edge->v;
            if (V[v].color == White) {
                V[v].color = Gray;
                V[v].parent = u;
                V[v].distance = V[u].distance + 1;
                Q.push(v);
                currentlevel.push_back(v);
            }

        }
// Finish processing vertex
        V[u].color = Black;

        for (int i = 0; i < currentlevel.size(); i++) {
            BFT->AddUndirectedEdge(u, currentlevel[i]);
        }
    }

    return BFT;
}
