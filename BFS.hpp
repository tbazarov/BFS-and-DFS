#pragma once
#include "TraversalStrategy.hpp"

class BFS : public TraversalStrategy {
    protected:
    void onStart() override;
    void onEnd() override;
    void onVisitVertex(Graph::Vertex v) override;
    void onVisitEdge(Graph::Vertex from, Graph::Vertex to) override;
    void doTraverse(const Graph& graph, Graph::Vertex start) override;
};