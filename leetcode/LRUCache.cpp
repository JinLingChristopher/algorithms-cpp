//
// Created by Edison King on 2020/3/3.
//

#include "LRUCache.hpp"
#include <iostream>

using namespace std;


int main() {
    LRUCache cache(2);
    cache.put(2, 1);
    cache.put(2, 2);
    cout << cache.get(2) << endl;

    cache.put(1, 1);
    cache.put(4, 1);
    cout << cache.get(2) << endl;

    return 0;
}
