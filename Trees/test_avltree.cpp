//
// Created by king on 2019/8/3.
//

#include "gtest/gtest.h"
#include "AvlTree.hpp"


TEST(AVLTree, basic) {
    auto tree = AVLTree();
    tree.put(3, 0);
    tree.put(1, 0);
    tree.put(4, 0);
    tree.put(1, 0);
    tree.put(5, 0);
    tree.put(9, 0);
    tree.put(6, 0);
}