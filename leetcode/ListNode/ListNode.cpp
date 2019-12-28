//
// Created by 金灵 on 2019/12/26.
//

#include "ListNode.hpp"
#include <iostream>
using namespace std;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1) {
        return l2;
    } else if (!l2) {
        return l1;
    }
    ListNode *ret;
    if (l1->val < l2->val) {
        ret = l1;
        l1 = l1->next;
        ret->next = nullptr;
    } else {
        ret = l2;
        l2 = l2->next;
        ret->next = nullptr;
    }
    ret->next = mergeTwoLists(l1, l2);
    return ret;
}

ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;

    slow->next = nullptr;
    slow = head;

    ListNode *left = sortList(slow);
    ListNode *right = sortList(fast);
    return mergeTwoLists(left, right);
}

int main() {
    ListNode *l = buildLists({4, 2, 1, 3});

    l = sortList(l);

    for (auto ptr = l; ptr != nullptr; ptr = ptr->next) {
        cout << ptr->val << " ";
    }
    cout << endl;

    destroyList(l);
    return 0;
}
