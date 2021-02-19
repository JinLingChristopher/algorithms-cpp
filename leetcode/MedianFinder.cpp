//
// Created by 金灵 on 2020/2/23.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> large;
    priority_queue<int, vector<int>, std::greater<int>> small;

public:

    MedianFinder() {

    }

    void add(int n) {
        if (small.empty() && large.empty()) {
            small.push(n);
            return;
        }
        if (n > small.top()) {
            small.push(n);
            if (small.size() > large.size() + 1) {
                large.push(small.top());
                small.pop();
            }
            return;
        }
        large.push(n);
        if (large.size() > small.size() + 1) {
            small.push(large.top());
            large.pop();
        }
    }

    double median() {
        if (large.size() > small.size()) {
            return static_cast<double>(large.top());
        } else if (large.size() < small.size()) {
            return static_cast<double>(small.top());
        }
        return (small.top() + large.top()) / 2.0;
    }

};

int main() {
    vector<int> nums{-1, -2, -3, -4, -5};
    MedianFinder finder;
    for (int i = 0; i < nums.size(); ++i) {
        finder.add(nums[i]);
        cout << finder.median() << endl;
    }
    return 0;
}
