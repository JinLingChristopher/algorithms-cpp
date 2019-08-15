//
// Created by king on 2019/8/15.
//

#include "gtest/gtest.h"
#include "Edge.hpp"

using namespace std;

TEST(Edge, basic) {
    const Edge e1(1, 2, 3);
    const Edge e2(0, 2, 10);
    const Edge e3(1, 2, 5);

    EXPECT_EQ(e1.getFrom(), 1);
    EXPECT_EQ(e2.getWeight(), 10);
    EXPECT_EQ(e3.getOther(e3.getFrom()), 2);

    Edge e4(1, 2, 3);
    EXPECT_EQ(e4.getFrom(), 1);
    EXPECT_EQ(e4.getOther(e4.getFrom()), 2);
    EXPECT_EQ(e4.getWeight(), 3);
}

