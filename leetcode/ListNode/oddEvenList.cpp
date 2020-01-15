#include "ListNode.hpp"
#include <iostream>

using namespace std;

ListNode *oddEvenList(ListNode *head) {
    if (!head || !head->next || !head->next->next) {
        return head;
    }
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *oddTail = odd;
    ListNode *evenTail = even;
    int idx = 3;

    auto curr = head->next->next;
    while (curr) {
        auto ptr = curr;
        curr = curr->next;
        ptr->next = nullptr;
        if (idx % 2 != 0) {
            oddTail->next = ptr;
            oddTail = oddTail->next;
        } else {
            evenTail->next = ptr;
            evenTail = evenTail->next;
        }
        idx += 1;
    }

    oddTail->next = even;
    evenTail->next = nullptr;
    
    return odd;
}

int main() {
    ListNode *list = buildList({1, 2, 3});

    list = oddEvenList(list);
    for (auto ptr = list; ptr; ptr = ptr->next) {
        cout << ptr->val << " ";
    }
    cout << endl;
}
