#include "ListNode.hpp"

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
