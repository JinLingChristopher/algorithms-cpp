//
// Created by 金灵 on 2020/2/21.
//

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;


vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> result;
    for (int start = 1; start <= target / 2; ++start) {
        vector<int> curr;
        int total = 0;
        for (int i = start; i <= target / 2 + 1; ++i) {
            if (total == 0 || i == curr.back() + 1) {
                curr.push_back(i);
                total += i;
            }
            if (total == target) {
                result.push_back(curr);
                break;
            } else if (total > target) {
                break;
            }
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