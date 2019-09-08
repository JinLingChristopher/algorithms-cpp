//
// Created by king on 2019/8/6.
//


#include "gtest/gtest.h"
#include "UndirectedGraphSearch.hpp"

using namespace std;

const UndirectedGraph build_graph() {
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

TEST(UndirectedGraphSearch, RecursiveDFS) {
    UndirectedGraph g = build_graph();
    UndirectedGraphSearch solver(g);

    EXPECT_EQ(solver.countComponent(), 2);

    solver.recursiveDFSWithOrder(0);

}
