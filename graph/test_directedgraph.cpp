//
// Created by king on 2019/7/31.
//

#include "gtest/gtest.h"
#include "DirectedGraph.hpp"

TEST(DirectedGraph, basic) {
    DirectedGraph g(5);
    EXPECT_EQ(g.numOfVertices(), 5);

    g.addEdges(1, 3);
    EXPECT_EQ(g.numOfEdges(), 1);

    g.addEdges(3, 1);
    EXPECT_EQ(g.numOfEdges(), 2);

    g.addEdges(2, 4);
    EXPECT_EQ(g.numOfEdges(), 3);

    g.addEdges(4, 0);
    EXPECT_EQ(g.numOfEdges(), 4);

    std::cout << g << std::endl;

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
