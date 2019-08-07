cmake_minimum_required(VERSION 3.14)
project(algorithm_cpp)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_undirectedgraph graph/UndirectedGraph.cpp)
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

add_executable(test_DepthFirstSearch graph/DepthFirstSearch.cpp graph/test_DepthFirstSearch.cpp)
target_link_libraries(test_DepthFirstSearch ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_DepthFirstSearch ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_BreathFirstSearch graph/BreathFirstSearch.cpp graph/test_BreathFirstSearch.cpp)
target_link_libraries(test_BreathFirstSearch ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_BreathFirstSearch ${CMAKE_THREAD_LIBS_INIT})

add_test(Test test_undirectedgraph)
add_test(Test test_directedgraph)
add_test(Test test_linkedlist)
add_test(Test test_avltree)

add_test(Test test_DepthFirstSearch)
add_test(Test test_BreathFirstSearch)

enable_testing()

add_executable(class-schedule greedy/class-schedule.cpp)
add_executable(huffman-code greedy/huffman-code.cpp)