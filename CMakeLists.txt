cmake_minimum_required(VERSION 3.14)
project(Graph_Traversal)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(GTest REQUIRED)
add_executable(GraphTraversal
  Graph.cpp
  TraversalStrategy.cpp
  DFS.cpp
  BFS.cpp
  TraversalTest.cpp
)

target_link_libraries(GraphTraversal GTest::gtest GTest::gtest_main)