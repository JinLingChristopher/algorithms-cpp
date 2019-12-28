//
// Created by 金灵 on 2019/12/27.
//

#ifndef ALGORITHM_CPP_MYLINKEDLIST_HPP
#define ALGORITHM_CPP_MYLINKEDLIST_HPP


class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int val): val(val), next(nullptr) {

        }
    };

    Node* head;
    Node* tail;
    int length;
public:
    /** Initialize your data structure here. */

    MyLinkedList():head(nullptr), tail(nullptr), length(0) {

    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= length) {
            return -1;
        }
        auto ptr = head;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next;
        }
        return ptr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* t = new Node(val);
        t->next = head;
        head = t;
        if (!tail) {
            tail = t;
        }
        length += 1;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* t = new Node(val);
        if (!tail) {
            head = t;
        } else {
            tail->next = t;
        }
        tail = t;
        length += 1;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > length) {
            return;
        } else if (index == length) {
            addAtTail(val);
        } else if (index == 0) {
            addAtHead(val);
        } else {
            auto ptr = head;
            for (int i = 0; i < index - 1; ++i) {
                ptr = ptr->next;
            }
            Node* t = new Node(val);
            t->next = ptr->next;
            ptr->next = t;
            length += 1;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) {
            return;
        } else if (index == 0) {
            auto t = head;
            head = head->next;
            if (!head) {
                tail = nullptr;
            }
            delete t;
            t = nullptr;
        } else {
            auto curr = head;
            for (int i = 0; i < index - 1; ++i) {
                curr = curr->next;
            }
            auto t = curr->next;
            curr->next = t->next;
            if (!curr->next) {
                tail = curr;
            }
            delete t;
            t = nullptr;

        }
        length -= 1;
    }
};

#endif //ALGORITHM_CPP_MYLINKEDLIST_HPP
