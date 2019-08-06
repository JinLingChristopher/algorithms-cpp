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

add_executable(test_linkedlist LinkedList/test_linkedlist.cpp LinkedList/LinkedList.cpp)
target_link_libraries(test_linkedlist ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_linkedlist ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_avltree Trees/AvlTree.cpp Trees/test_avltree.cpp)
target_link_libraries(test_avltree ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_avltree ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_undirectedgraphsearch graph/UndirectedGraphSearch.cpp graph/test_UndirectedGraphSearch.cpp)
target_link_libraries(test_undirectedgraphsearch ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_undirectedgraphsearch ${CMAKE_THREAD_LIBS_INIT})

add_test(Test test_undirectedgraph)
add_test(Test test_directedgraph)
add_test(Test test_linkedlist)
add_test(Test test_avltree)
add_test(Test test_undirectedgraphsearch)
enable_testing()

add_executable(class-schedule greedy/class-schedule.cpp)
add_executable(huffman-code greedy/huffman-code.cpp)