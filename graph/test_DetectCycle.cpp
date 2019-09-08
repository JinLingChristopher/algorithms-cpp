//
// Created by king on 2019/8/9.
//

#include "gtest/gtest.h"
#include "DirectedGraph.hpp"
#include "DetectCycle.hpp"

const DirectedGraph buildNoDag() {
    DirectedGraph g(4);
    g.addEdges(0, 1);
    g.addEdges(1, 2);
    g.addEdges(2, 0);
    g.addEdges(0, 3);
    g.addEdges(3, 1);

    return g;
}

const DirectedGraph buildDag() {
    DirectedGraph g(16);
    g.addEdges(0, 1);
    g.addEdges(5, 1);
    g.addEdges(5, 6);
    g.addEdges(6, 0);
    g.addEdges(4, 8);
    g.addEdges(3, 2);
    g.addEdges(6, 2);
    g.addEdges(7, 2);
    g.addEdges(8, 13);
    g.addEdges(12, 8);
    g.addEdges(9, 12);
    g.addEdges(9, 13);
    g.addEdges(9, 10);
    g.addEdges(13, 14);
    g.addEdges(14, 10);
    g.addEdges(10, 11);
    g.addEdges(14, 11);
    g.addEdges(11, 15);
    g.addEdges(11, 7);
    g.addEdges(7, 3);
    g.addEdges(10, 7);
    g.addEdges(5, 11);
    g.addEdges(6, 10);

    return g;
}

TEST(DetectCycle, basic) {
    auto dag = buildDag();
    auto solver = DetectCycle(dag);
    EXPECT_EQ(solver.isAcyclic(), true);

    auto nodag = buildNoDag();
    auto solver2 = DetectCycle(nodag);
    EXPECT_EQ(solver2.isAcyclic(), false);

}