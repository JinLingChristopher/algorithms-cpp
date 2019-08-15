//
// Created by king on 2019/8/15.
//

#include "gtest/gtest.h"
#include "UndirectedGraph.hpp"


TEST(UndirectedGraph, basic) {
    UndirectedGraph g(5);
    g.addEdges(0, 1);
    g.addEdges(1, 3);
    g.addEdges(2, 3);
    g.addEdges(3, 4);
    g.addEdges(4, 2);

    EXPECT_EQ(g.numOfVertices(), 5);
    EXPECT_EQ(g.numOfEdges(), 5);

    std::cout << g << std::endl;

}