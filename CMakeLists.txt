cmake_minimum_required(VERSION 3.14)
project(algorithm_cpp)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_UndirectedGraph graph/test_UndirectedGraph.cpp graph/UndirectedGraph.cpp)
target_link_libraries(test_UndirectedGraph ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_UndirectedGraph ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_DirectedGraph graph/test_DirectedGraph.cpp graph/DirectedGraph.cpp)
target_link_libraries(test_DirectedGraph ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_DirectedGraph ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_linkedlist LinkedList/test_linkedlist.cpp LinkedList/LinkedList.cpp)
target_link_libraries(test_linkedlist ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_linkedlist ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_DepthFirstSearch graph/DepthFirstSearch.cpp graph/test_DepthFirstSearch.cpp)
target_link_libraries(test_DepthFirstSearch ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_DepthFirstSearch ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_BreathFirstSearch graph/BreathFirstSearch.cpp graph/test_BreathFirstSearch.cpp)
target_link_libraries(test_BreathFirstSearch ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_BreathFirstSearch ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_DetectCycle graph/DetectCycle.cpp graph/test_DetectCycle.cpp)
target_link_libraries(test_DetectCycle ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_DetectCycle ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_TopologicalSort graph/TopologicalSort.cpp graph/DetectCycle.cpp graph/test_TopologicalSort.cpp)
target_link_libraries(test_TopologicalSort ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_TopologicalSort ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_Edge graph/Edge.cpp graph/test_Edge.cpp)
target_link_libraries(test_Edge ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_Edge ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_DirectedWeightedGraph graph/test_DirectedWeightedGraph.cpp graph/DirectedWeightedGraph.cpp graph/Edge.cpp)
target_link_libraries(test_DirectedWeightedGraph ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_DirectedWeightedGraph ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_ShortestPath graph/ShortestPath.cpp graph/test_ShortestPath.cpp graph/DirectedWeightedGraph.cpp)
target_link_libraries(test_ShortestPath ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_ShortestPath ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_AvlTree Trees/AvlTree.cpp Trees/test_avltree.cpp)
target_link_libraries(test_AvlTree ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_AvlTree ${CMAKE_THREAD_LIBS_INIT})

#add_executable(test_ListNode leetcode/ListNode/test_ListNode.cpp leetcode/ListNode/ListNode.cpp)
#target_link_libraries(test_ListNode ${GTEST_BOTH_LIBRARIES})
#target_link_libraries(test_ListNode ${CMAKE_THREAD_LIBS_INIT})

add_test(Test test_UndirectedGraph)
add_test(Test test_DirectedGraph)
add_test(Test test_linkedlist)
add_test(Test test_DepthFirstSearch)
add_test(Test test_BreathFirstSearch)
add_test(Test test_DetectCycle)
add_test(Test test_TopologicalSort)
add_test(Test test_Edge)
add_test(Test test_DirectedWeightedGraph)
add_test(Test test_ShortestPath)
# add_test(Test test_ListNode)

enable_testing()

add_executable(ListNode leetcode/ListNode/ListNode.cpp)
add_executable(MyLinkedList leetcode/MyLinkedList/MyLinkedList.cpp leetcode/MyLinkedList/MyLinkedList.hpp)
add_executable(maxValue leetcode/maxValue.cpp)
#add_executable(class-schedule greedy/class-schedule.cpp)
#add_executable(huffman-code greedy/huffman-code.cpp)
add_executable(findContinuousSequence leetcode/findContinuousSequence.cpp)
add_executable(findUniqChar leetcode/findUniqChar.cpp)
add_executable(getLeastNumbers leetcode/getLeastNumbers.cpp)
add_executable(nTossSum leetcode/nTossSum.cpp)
add_executable(validateStackSequence leetcode/validateStackSequence.cpp)
add_executable(maxProfit leetcode/maxProfit.cpp)
add_executable(cuttingRope dynamic-programming/cuttingRope.cpp)
add_executable(lastRemaining leetcode/lastRemaining.cpp)
add_executable(MedianFinder leetcode/MedianFinder.cpp)
add_executable(verifyPostOrder leetcode/verifyPostOrder.cpp)
add_executable(rotateArrayMin array/rotateArrayMin.cpp)
add_executable(lengthOfLongestSubstringNoDup leetcode/lengthOfLongestSubstringNoDup.cpp)