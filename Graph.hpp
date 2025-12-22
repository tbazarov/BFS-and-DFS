#pragma once

#include <vector>
#include <stdlib.h>
#include <list>

class Graph
{
    public:
    using Vertex = int;
    using AdjList = std::list<Vertex>;

    explicit Graph(size_t numVertices);

    void addEdge(Vertex from, Vertex to);
    const std::vector<AdjList>& getAdjacencyList() const;
    size_t getNumVertices() const;

    private:
    std::vector<AdjList> adjList_;
    size_t numVertices_;
};