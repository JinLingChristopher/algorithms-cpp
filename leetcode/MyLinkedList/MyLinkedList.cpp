//
// Created by 金灵 on 2019/12/27.
//

#include "MyLinkedList.hpp"

int main() {
    auto l = new MyLinkedList();

    l->addAtHead(2);
    l->deleteAtIndex(1);
    l->addAtHead(2);
    l->addAtHead(7);
    l->addAtHead(3);
    l->addAtHead(2);
    l->addAtHead(5);
    l->addAtTail(5);
    l->get(5);
    l->deleteAtIndex(6);
    l->deleteAtIndex(4);

    delete l;

    return 0;
}