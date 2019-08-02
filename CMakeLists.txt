cmake_minimum_required(VERSION 3.14)
project(algorithm_cpp)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_undirectedgraph graph/test_undirectedgraph.cpp graph/UndirectedGraph.cpp)
target_link_libraries(test_undirectedgraph ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_undirectedgraph ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_directedgraph graph/test_directedgraph.cpp graph/DirectedGraph.cpp)
target_link_libraries(test_directedgraph ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_directedgraph ${CMAKE_THREAD_LIBS_INIT})


add_test(Test test_undirectedgraph)
add_test(Test test_directedgraph)
enable_testing()

add_executable(test_linkedlist LinkedList/test_linkedlist.cpp)