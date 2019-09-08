//
// Created by king on 2019/8/9.
//

#include "gtest/gtest.h"
#include "TopologicalSort.hpp"
#include "DirectedGraph.hpp"

const DirectedGraph buildDag() {
    DirectedGraph g(16);

    g.addEdges(0, 1);
    g.addEdges(3, 2);
    g.addEdges(4, 8);
    g.addEdges(5, 1);
    g.addEdges(5, 6);
    g.addEdges(5, 11);
    g.addEdges(6, 0);
    g.addEdges(6, 2);
    g.addEdges(6, 10);
    g.addEdges(7, 2);
    g.addEdges(7, 3);
    g.addEdges(8, 13);
    g.addEdges(9, 10);
    g.addEdges(9, 12);
    g.addEdges(9, 13);
    g.addEdges(10, 7);
    g.addEdges(10, 11);
    g.addEdges(11, 7);
    g.addEdges(12, 8);
    g.addEdges(13, 14);
    g.addEdges(14, 10);
    g.addEdges(14, 11);
    g.addEdges(11, 15);

    return g;
}

TEST(DirectedGraph, basic) {
    auto graph = buildDag();
    auto solver = TopologicalSort(graph);
    auto result = solver.topologicalSort();

    for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
        std::cout << *iter << " ";
    }   // 9 12 5 6 4 8 13 14 10 11 15 7 3 2 0 1
    std::cout << std::endl;
}