#include "TraversalStrategy.hpp"

void TraversalStrategy::traverse(const Graph& graph, Graph::Vertex start) {
    onStart();
    doTraverse(graph, start);
    onEnd();
}