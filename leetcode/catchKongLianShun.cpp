//
// Created by Edison King on 2020/3/11.
//

#include <iostream>
#include <vector>

using namespace std;

bool isLegal(const vector<int>& curr, int pos, int dist) {
    if (curr.empty()) {
        return true;
    }
    return pos - curr[0] <= dist;
}

void helper(const vector<int>& buildings, int dist, int start, vector<int>& curr, int& result) {
    if (curr.size() == 3) {
        result += 1;
        return;
    }

    if (curr.empty() && start + 2 == buildings.size()) {
        return;
    }

    for (int i = start; i < buildings.size(); ++i) {
        if (isLegal(curr, buildings[i], dist)) {
            curr.push_back(buildings[i]);
            helper(buildings, dist, i + 1, curr, result);
            curr.pop_back();
        }
    }
}

int solver(const vector<int>& buildings, int dist) {
    int result = 0;
    vector<int> curr;
    helper(buildings, dist, 0, curr, result);

    return result;
}

long long C(long long n) {
    return n * (n - 1) / 2;
}

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> nums(N, 0);
    int j = 0;
    long long result = 0;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        while (i >= 2 && (nums[i] - nums[j]) > D) {
            ++j;
        }
        result += C(i - j);
    }
    cout << result % 99997867 << endl;
    return 0;
}

//int main() {
//    vector<int> nums{1, 2, 3, 4};
//    cout << solver(nums, 3) << endl;
//
//    cout << solver({1, 10, 20, 30, 50}, 19) << endl;
//
//    return 0;
//}
