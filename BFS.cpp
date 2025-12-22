#include "BFS.hpp"
#include <queue>
#include <vector>
#include <iostream>

void BFS:: onStart() {
    std::cout << "Старт BFS\n";
}

void BFS:: onEnd() {
    std::cout << "Конец BFS\n";
}

void BFS:: onVisitVertex(Graph::Vertex v) {
    std::cout << "Посещенная вершина :" << v << "\n";
}

void BFS:: onVisitEdge(Graph::Vertex from, Graph::Vertex to) {
    std::cout << "Посещенное ребро: " << from  << "->" << to << "\n";
}

void BFS::doTraverse(const Graph& graph, Graph::Vertex start) {
    size_t n = graph.getNumVertices();
    std::vector<bool> visited(n, false);
    std::queue<Graph::Vertex> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        Graph::Vertex v = q.front();
        q.pop();
        onVisitVertex(v);

        for (Graph::Vertex neighbor : graph.getAdjacencyList().at(v)) {
            onVisitEdge(v, neighbor);
            if (!visited[neighbor]) { 
                visited[neighbor] = true;
                q.push(neighbor); 
            }
        }
    }

}

