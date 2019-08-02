//
// Created by king on 2019/7/31.
//

#include "gtest/gtest.h"
#include "UndirectedGraph.hpp"


using namespace std;

TEST(UndirectedGraph, basic) {
    UndirectedGraph ug(5);
    EXPECT_EQ(ug.numOfVertices(), 5);

    ug.addEdges(0, 4);
    EXPECT_EQ(ug.numOfEdges(), 1);

    ug.addEdges(1, 3);
    EXPECT_EQ(ug.numOfEdges(), 2);

    EXPECT_EQ(ug.degree(1), 1);
    EXPECT_EQ(ug.degree(3), 1);
    EXPECT_EQ(ug.degree(2), 0);


    cout << ug << endl;
}
