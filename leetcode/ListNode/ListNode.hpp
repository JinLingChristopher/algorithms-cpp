//
// Created by 金灵 on 2019/12/26.
//

#ifndef ALGORITHM_CPP_LISTNODE_HPP
#define ALGORITHM_CPP_LISTNODE_HPP

#include <initializer_list>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {

    }
};

ListNode* buildList(std::initializer_list<int> l);
void destroyList(ListNode* head);
ListNode* rotateRight(ListNode* head, int k);
ListNode* addTwoLists(ListNode* l1, ListNode* l2);

#endif //ALGORITHM_CPP_LISTNODE_HPP
