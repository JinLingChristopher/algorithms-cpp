//
// Created by king on 2019/8/2.
//

#ifndef ALGORITHM_CPP_LISTNODE_HPP
#define ALGORITHM_CPP_LISTNODE_HPP

class LinkedList{
private:
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

            void setNext(ListNode* other) {
                this->next = other;
            }

            ~ListNode() {

            }
    };

    ListNode* head;
    int length;

public:
    LinkedList(): head(nullptr), length(0) {

    }

    ~LinkedList() {
        ListNode* t = this->head;
        while (this->head) {
            t = t->getNext();
            delete this->head;
            this->head = t;
            --length;
        }
    }

    void insert(int val) {
        ListNode* t = new ListNode(val);
        t->setNext(head);
        head = t;
        ++length;
    }

};

#endif //ALGORITHM_CPP_LISTNODE_HPP
