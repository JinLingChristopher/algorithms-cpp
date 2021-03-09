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
add_executable(translateNum leetcode/translateNum.cpp)
add_executable(existPath matrix/existPath.cpp)
add_executable(movingCount leetcode/movingCount.cpp)
add_executable(findNumberIn2DArray leetcode/findNumberIn2DArray.cpp)
add_executable(countDigitOne leetcode/countDigitOne.cpp)
add_executable(reversePairs recursion/reversePairs.cpp)
add_executable(problem1 playground/problem1.cpp)
add_executable(reverseWords leetcode/reverseWords.cpp)
add_executable(findNthDigit leetcode/findNthDigit.cpp)
add_executable(myPow leetcode/myPow.cpp)
add_executable(isNumber leetcode/isNumber.cpp)
add_executable(permute backtracking/permute.cpp)
add_executable(subset-sum backtracking/subset-sum.cpp)
add_executable(subsets leetcode/subsets.cpp)
add_executable(LRUCache leetcode/LRUCache.cpp)
add_executable(orangeRotting leetcode/orangeRotting.cpp)
add_executable(strToInt leetcode/strToInt.cpp)
add_executable(regIsMatch leetcode/regIsMatch.cpp)
add_executable(generateParenthesis backtracking/generateParenthesis.cpp)
add_executable(n-queen backtracking/n-queen.cpp)

add_executable(maxAliveYear leetcode/maxAliveYear.cpp)

add_executable(letterCasePermutation backtracking/letterCasePermutation.cpp)

add_executable(noRepeatPermutation leetcode/noRepeatPermutation.cpp)

add_executable(keyBoardUnlock leetcode/keyBoardUnlock.cpp)

add_executable(numIslands leetcode/numIslands.cpp)

add_executable(T9KeyBoard leetcode/T9KeyBoard.cpp)

add_executable(findMagicIndex leetcode/findMagicIndex.cpp)

add_executable(multiply leetcode/multiply.cpp)

add_executable(findCloset leetcode/findCloset.cpp)

add_executable(wiggleSort leetcode/wiggleSort.cpp)

add_executable(maxAreaOfIslands leetcode/maxAreaOfIslands.cpp)

add_executable(main leetcode/ListNode/main.cpp leetcode/ListNode/ListNode.cpp)

add_executable(edit leetcode/edit.cpp)

add_executable(catchKongLianShun leetcode/catchKongLianShun.cpp)

add_executable(missingNumber leetcode/missingNumber.cpp)

add_executable(longestCommonPrefix leetcode/longestCommonPrefix.cpp)

add_executable(majong leetcode/majong.cpp)

add_executable(mergeInterval leetcode/mergeInterval.cpp)

add_executable(catMove leetcode/catMove.cpp)

add_executable(minTravalCost leetcode/minTravalCost.cpp)

add_executable(coinChange leetcode/coinChange.cpp)

add_executable(robotJump leetcode/robotJump.cpp)

add_executable(zero-one dynamic-programming/knapsack/zero-one.cpp)

add_executable(canPartitionKSubsets array/canPartitionKSubsets.cpp)

add_executable(canPartition dynamic-programming/knapsack/canPartition.cpp)

add_executable(trap leetcode/trap.cpp)

add_executable(putOrange leetcode/putOrange.cpp)

add_executable(numToys leetcode/numToys.cpp)

add_executable(playground leetcode/playground.cpp)

add_executable(maxDistance leetcode/maxDistance.cpp)

add_executable(longWords longWords.cpp)

add_executable(groupAnagram leetcode/groupAnagram.cpp)

add_executable(maxSubArray dynamic-programming/maxSubArray.cpp)

add_executable(AnimalShelf leetcode/AnimalShelf.cpp)

add_executable(printBin leetcode/printBin.cpp)
add_executable(isValid leetcode/isValid.cpp)

add_executable(maxTree leetcode/maxTree.cpp)

add_executable(maxWidthOfVerticalAread leetcode/maxWidthOfVerticalAread.cpp)
