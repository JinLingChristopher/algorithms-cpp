#include "ListNode.hpp"

ListNode* rotateRight(ListNode* head, int k) {
    if (!head) {
        return head;
    }
    ListNode* tail = head;
    int length = 0;
    while (tail->head) {
        length += 1;
        tail = tail->next;
    }
    tail->next = head;

    k = length - k % length;
    while (k - 1) {
        head = head->next;
        --k;
    }

    tail = head;
    head = head->next;
    tail->next = nullptr;

    return head;
}
