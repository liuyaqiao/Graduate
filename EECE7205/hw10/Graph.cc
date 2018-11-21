//
// Created by Yaqiao on 2018/4/17.
//

#include <climits>
#include "Graph.h"
#include <algorithm>
Graph::Graph(int size)
{
    this->size = size;
    E = new Edge[size * size]();
    for (int i = 0; i < size * size; i++)
        E[i].weight = INT_MAX;
}
Graph::~Graph()
{
    delete E;
}
Graph::Edge *Graph::getEdge(int u, int v)
{
    assert(u >= 0 && u < size);
    assert(v >= 0 && v < size);
    return &E[u * size + v];
}
void Graph::AddEdge(int u, int v, int weight)
{
    Edge *edge = getEdge(u, v);
    edge->weight = weight;
}
void Graph::AddUndirectedEdge(int u, int v, int weight)
{
    AddEdge(u, v, weight);
    AddEdge(v, u, weight);
}
void Graph::FloydWarshall()
{
// Initialize
    for (int i = 0; i < size; i++)
    {
        for (int j = 0 ; j < size; j++)
        {
            Edge *edge = getEdge(i, j);
            edge->parent = -1;
            edge->distance = edge->weight;
            if (i == j)
                edge->distance = 0;
            if (edge->weight != INT_MAX)
                edge->parent = i;
        }
    }
// Shortest paths
    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                Edge *i_j = getEdge(i, j);
                Edge *i_k = getEdge(i, k);
                Edge *k_j = getEdge(k, j);
                if (i_j->distance > i_k->distance + k_j->distance &&
                    i_k->distance != INT_MAX &&
                    k_j->distance != INT_MAX)
                {
                    i_j->distance = i_k->distance + k_j->distance;
                    i_j->parent = k_j->parent;
                }
            }
        }
    }
}
void Graph::PrintShortestPath(int u, int v)
{
    Edge *edge = getEdge(u, v);
    if (u == v)
    {
        std::cout << u;
    }
    else if (edge->parent == -1)
    {
        std::cout << "unreachable";
    }
    else
    {
        PrintShortestPath(u, edge->parent);
        std::cout << " -> " << v;
    }
}

bool Graph::isClique(std::vector<int> vertexes) {
    for (int i = 0; i < vertexes.size(); i++) {
        for (int j = 0; j < vertexes.size(); j++) {
            if (i == j) {
               // continue;
            } else {
                if (E[vertexes[i] * size + vertexes[j]].distance != 1) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Graph::helper(std::vector<std::vector<int> > &results,
            std::vector<int> &subset,
            std::vector<int> &nums,
            int start) {
    results.push_back(subset);

    for (int i = start; i < nums.size(); i++) {
        subset.push_back(nums[i]);
        helper(results, subset, nums, i + 1);
        subset.pop_back();
    }
}

std::vector<std::vector<int>> Graph::subset(std::vector<int> &nums) {
    std::vector<std::vector<int> > results;
    std::vector<int> subset;

    sort(nums.begin(), nums.end());
    helper(results, subset, nums, 0);

    return results;
}

bool Graph::CliqueExists(int k) {
    if (k > size) {
        std::cout<<"invalid input\n";
        return false;
    }
    std::vector<std::vector<int>> subsetVector;
    std::vector<int> vertex;
    for (int i = 0; i < size; i++) {
        vertex.push_back(i);
    }
    subsetVector = subset(vertex); //subset size = 128
    for (int i = 0; i < subsetVector.size(); i++) {
        if (subsetVector[i].size() >= k) {
            if (isClique(subsetVector[i])) {
                return true;
            }
        }
    }
    return false;
}

int Graph::getMaxClique() {
    std::vector<std::vector<int>> subsetVector;
    std::vector<int> vertex;
    for (int i = 0; i < size; i++) {
        vertex.push_back(i);
    }
    subsetVector = subset(vertex);

    int maxClique = 0;
    for (int i = 0; i < subsetVector.size(); i++) {
        if (isClique(subsetVector[i])) {
            if (maxClique < subsetVector[i].size()) {
                maxClique = subsetVector[i].size();
            }
        }
    }
    return maxClique;
}

void Graph::PrintGraph() {
    for (int i = 0; i < size * size; i++) {
        std::cout<<E[i].distance<<"  ";
        if ((i + 1) % size == 0) {
            std::cout<<"\n";
        }
    }
}
