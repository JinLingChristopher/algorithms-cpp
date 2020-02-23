//
// Created by 金灵 on 2020/2/23.
//

#include <list>
#include <iostream>

using namespace std;

int lastRemaining(int n, int m) {
    list<int> circle;
    for (int i = 0; i < n; ++i) {
        circle.push_back(i);
    }
    auto iter = circle.begin();
    while (circle.size() > 1) {
        for (int i = 1; i < m; ++i) {
            ++iter;
            if (iter == circle.end()) {
                iter = circle.begin();
            }
        }
        // if iter is at the last element, after erase, it will at end
        // so reset iter to the begin of the list.
        iter = circle.erase(iter);
        if (iter == circle.end()) {
            iter = circle.begin();
        }
    }
    return *circle.begin();
}


int main() {
    int n = 70866, m = 116922;
    cout << lastRemaining(n, m) << endl;

    return 0;
}