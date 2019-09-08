//
// Created by king on 2019/8/15.
//

#include "gtest/gtest.h"
#include "DirectedWeightedGraph.hpp"

using namespace std;

const DirectedWeightedGraph buildWeightedGraphNoNegative() {
    DirectedWeightedGraph g(7);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 3, 4);
    g.addEdge(1, 0, 4);
    g.addEdge(1, 3, 8);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 12);
    g.addEdge(3, 4, 0);
    g.addEdge(3, 5, 5);
    g.addEdge(4, 1, 10);
    g.addEdge(4, 6, 3);
    g.addEdge(5, 4, 1);
    g.addEdge(5, 6, 2);

    return g;
}

TEST(DirectedWeightedGraph, basic) {
    auto graph = buildWeightedGraphNoNegative();
    EXPECT_EQ(graph.numOfVertices(), 7);
    EXPECT_EQ(graph.numOfEdges(), 12);
}

