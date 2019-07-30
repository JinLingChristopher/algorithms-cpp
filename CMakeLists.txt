# cmake_minimum_required(VERSION <specify CMake version here>)
project(algorithm_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(n-queen backtracking/n-queen.cpp)
add_executable(test_graph graph/test_undirectedgraph.cpp graph/UndirectedGraph.cpp)