#include "Graph.hpp"
#include <stdexcept>

Graph::Graph(size_t numVertices) : numVertices_(numVertices) {
    adjList_.resize(numVertices_);
}

void Graph::addEdge(Vertex from, Vertex to) {
    if (from >= numVertices_ || to >= numVertices_) {
        throw std::out_of_range("Вершина вышла за предел");
    }
    adjList_[from].push_back(to);
}

const std::vector<Graph::AdjList>& Graph::getAdjacencyList() const {
    return adjList_;
}

size_t Graph::getNumVertices() const {
    return numVertices_;
}