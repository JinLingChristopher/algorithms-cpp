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

//TEST(Edge, basic) {
//    const Edge e1(1, 2, 3);
//    const Edge e2(0, 2, 10);
//    const Edge e3(1, 2, 5);
//
//    EXPECT_EQ(e1.getFrom(), 1);
//    EXPECT_EQ(e2.getWeight(), 10);
//    EXPECT_EQ(e3.getOther(e3.getFrom()), 2);
//
//    Edge e4(1, 2, 3);
//    EXPECT_EQ(e4.getFrom(), 1);
//    EXPECT_EQ(e4.getOther(e4.getFrom()), 2);
//    EXPECT_EQ(e4.getWeight(), 3);
//
//    Edge e5(e4);
//    EXPECT_EQ(e5.getFrom(), e4.getFrom());
//    EXPECT_EQ(e5.getOther(e5.getFrom()), e4.getOther(e4.getFrom()));
//    EXPECT_EQ(e5.getWeight(), e4.getWeight());
//}
//
