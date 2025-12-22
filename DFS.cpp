#include "DFS.hpp"
#include <stack>
#include <vector>
#include <iostream>

void DFS:: onStart() {
    std::cout << "Старт DFS\n";
}

void DFS:: onEnd() {
    std::cout << "Конец DFS\n";
}

void DFS:: onVisitVertex(Graph::Vertex v) {
    std::cout << "Посещенная вершина :" << v << "\n";
}

void DFS:: onVisitEdge(Graph::Vertex from, Graph::Vertex to) {
    std::cout << "Посещенное ребро: " << from  << "->" << to << "\n";
}

void DFS::doTraverse(const Graph& graph, Graph::Vertex start) {
    size_t n = graph.getNumVertices();
    std::vector<bool> visited(n, false);
    std::stack<Graph::Vertex> stack;
    stack.push(start);

    while (!stack.empty()) {
        Graph::Vertex v = stack.top();
        stack.pop();


        if (visited[v]) continue;
        visited[v] = true;
        onVisitVertex(v);

        std::vector<Graph::Vertex> neighbors(
            graph.getAdjacencyList().at(v).rbegin(),
            graph.getAdjacencyList().at(v).rend()
        );
        for (Graph::Vertex neighbor : neighbors) {
            onVisitEdge(v, neighbor);
            if (!visited[neighbor]) { stack.push(neighbor); }
        }
    }

}
