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

ListNode* buildLists(std::initializer_list<int> l) {
    ListNode* head, *tail;
    head = tail = nullptr;

    for (auto iter = l.begin(); iter != l.end(); ++iter) {
        auto n = new ListNode(*iter);
        if (!head) {
            head = n;
            tail = n;
        } else {
            tail->next = n;
            tail = tail->next;
        }
    }
    return head;
}

void destroyList(ListNode* head) {
    ListNode* ptr = nullptr;
    while (head) {
        ptr = head;
        ptr->next = nullptr;
        head = head->next;
        delete ptr;
    }
}



#endif //ALGORITHM_CPP_LISTNODE_HPP
