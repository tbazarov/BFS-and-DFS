#pragma once

#include "Graph.hpp"
#include <vector>
#include <queue>
#include <stack>

class TraversalStrategy {
    public:
    virtual ~TraversalStrategy() = default;
    void traverse(const Graph& graph, Graph::Vertex start);

    protected:
    virtual void onStart() = 0;
    virtual void onEnd() = 0;
    virtual void onVisitVertex(Graph::Vertex v) = 0;
    virtual void onVisitEdge(Graph::Vertex from, Graph::Vertex to) = 0;
    virtual void doTraverse(const Graph& graph, Graph::Vertex to) = 0;

};