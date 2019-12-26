//
// Created by king on 2019/8/2.
//

#include "gtest/gtest.h"
#include "LinkedList.hpp"

using namespace std;

TEST(LinkedList, basic) {
    LinkedList l;
    EXPECT_EQ(l.getLength(), 0);

    l.insert(1);
    EXPECT_EQ(l.getLength(), 1);
    cout << l << endl;

    l.insert(2);
    EXPECT_EQ(l.getLength(), 2);
    cout << l << endl;

    l.insert(3);
    EXPECT_EQ(l.getLength(), 3);
    cout << l << endl;

    l.removeFirst();
    EXPECT_EQ(l.getLength(), 2);
    cout << l << endl;

    l.removeFirst();
    EXPECT_EQ(l.getLength(), 1);
    cout << l << endl;
}
