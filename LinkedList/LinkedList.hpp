//
// Created by king on 2019/8/2.
//

#ifndef ALGORITHM_CPP_LISTNODE_HPP
#define ALGORITHM_CPP_LISTNODE_HPP

#include <iostream>


class LinkedList{
private:
    friend std::ostream& operator<<(std::ostream& os, const LinkedList& t);
    class ListNode {
        private:
            int val;
            ListNode* next;

        public:
            ListNode(int val): val(val), next(nullptr) {

            }

            ListNode* getNext() {
                return this->next;
            }

            int getVal() {
                return this->val;
            }

            void setNext(ListNode* other) {
                this->next = other;
            }

            ~ListNode() {

            }
    };

    ListNode* head;
    int length;

    ListNode* getHead() const {
        return this->head;
    }

public:
    LinkedList(): head(nullptr), length(0) {

    }

    int getLength() {
        return this->length;
    }

    ~LinkedList() {
        ListNode* t = nullptr;
        while (head) {
            t = head->getNext();
            delete head;
            head = t;
            --length;
        }
    }

    void insert(int val) {
        ListNode* t = new ListNode(val);
        t->setNext(head);
        head = t;
        ++length;
    }

    void removeFirst() {
        ListNode* t = head;
        head = head->getNext();
        delete t;
        --length;
    }

};

std::ostream& operator<<(std::ostream& os, const LinkedList& t);

#endif //ALGORITHM_CPP_LISTNODE_HPP
