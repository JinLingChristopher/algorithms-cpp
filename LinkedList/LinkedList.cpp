//
// Created by king on 2019/8/2.
//

#include "LinkedList.hpp"

using namespace std;

std::ostream& operator<<(std::ostream& os, const LinkedList& t) {
    auto ptr = t.getHead();
    while (ptr) {
        os << ptr->getVal() << " ";
        ptr = ptr->getNext();
    }
    os << endl;

    return os;
}