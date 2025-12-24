#include "BFS.hpp"
#include <queue>
//#include <vector>
#include <unordered_set>
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
    // size_t n = graph.getNumVertices();
    // std::vector<bool> visited(n, false);
    std::unordered_set<Graph::Vertex> visited;
    std::queue<Graph::Vertex> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        Graph::Vertex v = q.front();
        q.pop();
        onVisitVertex(v);

        for (Graph::Vertex neighbor : graph.getAdjacencyList().at(v)) {
            onVisitEdge(v, neighbor);
            if (visited.find(neighbor) == visited.end()) { 
                visited.insert(neighbor);
                q.push(neighbor); 
            }
        }
    }

}

