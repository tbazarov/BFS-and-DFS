#include "DFS.hpp"
#include "BFS.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <sstream>
#include <iostream>

// Тестовый граф:
//     0
//    / \
//   1   2
//  /     \
// 3       4

class MockTraversal : public TraversalStrategy {
public:
    std::vector<int> visitedVertices;
    std::vector<std::pair<int, int>> traversedEdges;
    bool started = false;
    bool ended = false;

protected:
    void onStart() override {
        started = true;
        visitedVertices.clear();
        traversedEdges.clear();
        ended = false;
    }

    void onEnd() override {
        ended = true;
    }

    void onVisitVertex(Graph::Vertex v) override {
        visitedVertices.push_back(v);
    }

    void onVisitEdge(Graph::Vertex from, Graph::Vertex to) override {
        traversedEdges.emplace_back(from, to);
    }

    // pure virtual, нужно реализовать
    void doTraverse(const Graph& graph, Graph::Vertex start) override {
        // Не используется — наследники переопределят
        (void)graph; (void)start;
    }
};

TEST(DFSTest, TraversalOrder) {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    DFS dfs;
}


class TestableDFS : public DFS {
public:
    std::vector<int> visitedVertices;
    std::vector<std::pair<int, int>> traversedEdges;
    bool started = false;
    bool ended = false;

protected:
    void onStart() override {
        started = true;
        visitedVertices.clear();
        traversedEdges.clear();
        ended = false;
        DFS::onStart(); 
    }

    void onEnd() override {
        ended = true;
        DFS::onEnd();
    }

    void onVisitVertex(Graph::Vertex v) override {
        visitedVertices.push_back(v);
        DFS::onVisitVertex(v);
    }

    void onVisitEdge(Graph::Vertex from, Graph::Vertex to) override {
        traversedEdges.emplace_back(from, to);
        DFS::onVisitEdge(from, to);
    }
};

class TestableBFS : public BFS {
public:
    std::vector<int> visitedVertices;
    std::vector<std::pair<int, int>> traversedEdges;
    bool started = false;
    bool ended = false;

protected:
    void onStart() override {
        started = true;
        visitedVertices.clear();
        traversedEdges.clear();
        ended = false;
        BFS::onStart();
    }

    void onEnd() override {
        ended = true;
        BFS::onEnd();
    }

    void onVisitVertex(Graph::Vertex v) override {
        visitedVertices.push_back(v);
        BFS::onVisitVertex(v);
    }

    void onVisitEdge(Graph::Vertex from, Graph::Vertex to) override {
        traversedEdges.emplace_back(from, to);
        BFS::onVisitEdge(from, to);
    }
};

TEST(DFSTest, FullTraversal) {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    TestableDFS dfs;
    dfs.traverse(g, 0);

    EXPECT_TRUE(dfs.started);
    EXPECT_TRUE(dfs.ended);
    EXPECT_EQ(dfs.visitedVertices, std::vector<int>({0, 1, 3, 2, 4}));
}

TEST(BFSTest, FullTraversal) {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    TestableBFS bfs;
    bfs.traverse(g, 0);

    EXPECT_TRUE(bfs.started);
    EXPECT_TRUE(bfs.ended);
    EXPECT_EQ(bfs.visitedVertices, std::vector<int>({0, 1, 2, 3, 4}));

    std::vector<std::pair<int, int>> expectedEdges = {
        {0,1}, {0,2}, {1,3}, {2,4}
    };
    EXPECT_EQ(bfs.traversedEdges, expectedEdges);
}

TEST(TraversalTest, SingleVertex) {
    Graph g(1);
    TestableDFS dfs;
    dfs.traverse(g, 0);
    EXPECT_EQ(dfs.visitedVertices, std::vector<int>({0}));
    EXPECT_TRUE(dfs.started);
    EXPECT_TRUE(dfs.ended);
}

TEST(TraversalTest, DisconnectedGraph) {
    Graph g(3);
    g.addEdge(0, 1); 
    TestableBFS bfs;
    bfs.traverse(g, 0);
    EXPECT_EQ(bfs.visitedVertices, std::vector<int>({0, 1}));
}