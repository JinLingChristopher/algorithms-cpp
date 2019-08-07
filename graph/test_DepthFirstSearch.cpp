//
// Created by king on 2019/8/7.
//

#include "gtest/gtest.h"
#include "DepthFirstSearch.hpp"
#include "DirectedGraph.hpp"
#include "UndirectedGraph.hpp"

using namespace std;

const UndirectedGraph buildUndirectedGraph() {
    UndirectedGraph g(13);
    g.addEdges(0, 1);
    g.addEdges(1, 2);
    g.addEdges(2, 3);
    g.addEdges(0, 4);
    g.addEdges(1, 4);
    g.addEdges(1, 5);
    g.addEdges(2, 5);
    g.addEdges(2, 6);
    g.addEdges(3, 6);
    g.addEdges(4, 5);
    g.addEdges(5, 6);
    g.addEdges(4, 7);
    g.addEdges(4, 6);
    g.addEdges(6, 8);

    g.addEdges(9, 10);
    g.addEdges(9, 11);
    g.addEdges(9, 12);
    g.addEdges(10, 11);
    g.addEdges(11, 12);

    return g;
}

const DirectedGraph buildDirectedGraph() {
    DirectedGraph g(16);
    g.addEdges(0, 1);
    g.addEdges(1, 5);
    g.addEdges(4, 5);
    g.addEdges(4, 8);
    g.addEdges(5, 6);
    g.addEdges(6, 0);
    g.addEdges(6, 2);
    g.addEdges(2, 7);
    g.addEdges(7, 3);
    g.addEdges(3, 2);
    g.addEdges(6, 10);
    g.addEdges(5, 11);
    g.addEdges(7, 11);
    g.addEdges(10, 7);
    g.addEdges(12, 8);
    g.addEdges(8, 13);
    g.addEdges(13, 9);
    g.addEdges(9, 12);
    g.addEdges(9, 10);
    g.addEdges(10, 11);
    g.addEdges(11, 14);
    g.addEdges(11, 15);
    g.addEdges(13, 14);
    g.addEdges(14, 10);

    return g;
}

TEST(DepthFirstSearch, DirectedGraph) {
    const DirectedGraph& g = buildDirectedGraph();
    DepthFirstSearch solver(g);
    solver.iterativeDFS(5);

    solver.recursiveDFS(5);
}

//
//TEST(UndirectedGraphSearch, RecursiveDFS) {
//    UndirectedGraph g = build_graph();
//    UndirectedGraphSearch solver(g);
//
//    EXPECT_EQ(solver.countComponent(), 2);
//
//    solver.recursiveDFSWithOrder(0);
//
//}
