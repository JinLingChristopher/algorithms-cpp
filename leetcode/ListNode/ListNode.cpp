#include "ListNode.hpp"

ListNode* buildList(std::initializer_list<int> l) {
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
