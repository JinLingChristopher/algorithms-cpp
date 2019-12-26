//
// Created by 金灵 on 2019/12/26.
//

#include "gtest/gtest.h"
#include "ListNode.hpp"

using namespace std;

TEST(ListNode, basic) {
    ListNode* list = buildList({1, 2, 3, 4, 5});
    for (auto ptr = list; ptr != nullptr; ptr = ptr->next) {
        cout << ptr->val << " ";
    }
    cout << endl;
}

