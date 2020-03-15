#include "ListNode.hpp"
#include <iostream>
using namespace std;

ListNode* partition(ListNode* head, int x) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* h1 = nullptr, *h2 = nullptr;
    ListNode* t1 = nullptr, *t2 = nullptr;

    auto ptr = head;
    while (ptr) {
        auto t = ptr->next;
        ptr->next = nullptr;
        if (ptr->val < x) {
            if (!h1) {
                h1 = ptr;
                t1 = h1;
            } else {
                t1->next = ptr;
                t1 = t1->next;
            }
        } else {
            if (!h2) {
                h2 = ptr;
                t2 = h2;
            } else {
                t2->next = ptr;
                t2 = t2->next;
            }
        }
        ptr = t;
    }
    if (!t1) {
        return h2;
    }
    t1->next = h2;
    return h1;
}

int main() {
    ListNode *l1 = buildList({1, 1});
    auto result = partition(l1, 0);
    for (auto ptr = result; ptr; ptr = ptr->next) {
        cout << ptr->val << " ";
    }
    cout << endl;

    destroyList(result);
    return 0;
}
