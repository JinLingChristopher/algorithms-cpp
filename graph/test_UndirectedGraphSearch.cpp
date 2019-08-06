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

    EXPECT_EQ()

}

//TEST(UndirectedGraph, basic) {
//UndirectedGraph ug(5);
//EXPECT_EQ(ug.numOfVertices(), 5);
//
//ug.addEdges(0, 4);
//EXPECT_EQ(ug.numOfEdges(), 1);
//
//ug.addEdges(1, 3);
//EXPECT_EQ(ug.numOfEdges(), 2);
//
//EXPECT_EQ(ug.degree(1), 1);
//EXPECT_EQ(ug.degree(3), 1);
//EXPECT_EQ(ug.degree(2), 0);
//
//
//cout << ug << endl;
//}
