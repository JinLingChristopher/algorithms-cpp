#include "ListNode.hpp"


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
