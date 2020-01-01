#include "ListNode.hpp"
#include <iostream>
using namespace std;


int main() {
    ListNode *l1 = buildList({9, 8});
    ListNode* l2 = buildList({1});

    auto result = addTwoLists(l1, l2);
    destroyList(result);
    return 0;
}
