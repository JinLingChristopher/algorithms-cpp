//
// Created by 金灵 on 2020/2/21.
//

#include <vector>
#include <iostream>
#include <numeric>
#include <deque>

using namespace std;


vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> result;
    deque<int> q;
    int curr = 0;
    for (int i = 1; i <= target / 2 + 1; ++i) {
        q.push_back(i);
        curr += i;
        while (curr > target) {
            int t = q.front();
            q.pop_front();
            curr -= t;
        }
        if (curr == target) {
            result.push_back(vector<int>(q.begin(), q.end()));
        }
    }
    return result;
}


int main() {
    int target = 15;
    auto result = findContinuousSequence(target);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}