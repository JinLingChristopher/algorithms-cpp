//
// Created by 金灵 on 2019/12/26.
//

#ifndef ALGORITHM_CPP_LISTNODE_HPP
#define ALGORITHM_CPP_LISTNODE_HPP

#include <initializer_list>
#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {
        std::cout << "ListNode(int x) called" << std::endl;
    }

    ~ListNode() {
        std::cout << "~ListNode()" << std::endl;
        ListNode* curr = this;
        ListNode* ptr = nullptr;
        while (curr) {
            ptr = curr;
            curr = curr->next;
            delete ptr;
        }
    }
};

ListNode* buildList(std::initializer_list<int> l) {
    if (l.size() == 0) {
        return nullptr;
    }
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (auto iter = l.begin(); iter != l.end(); ++iter) {
        ListNode* curr = new ListNode(*iter);
        if (!head) {
            head = curr;
        }
        if (tail) {
            tail->next = curr;
        }
        tail = curr;
    }
    return head;
}


#endif //ALGORITHM_CPP_LISTNODE_HPP
