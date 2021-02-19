//
// Created by Edison King on 2020/3/16.
//
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool canPartition(const vector<int>& nums) {
    int n = nums.size();
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) {
        return false;
    }
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    for (int i = 1; i <= n; ++i) {
        int val = nums[i - 1];
        for (int curr = target; curr >= val; --curr) {
            if (curr == val) {
                dp[curr] = true;
            } else {
                dp[curr] = dp[curr - val] || dp[curr];
            }
        }
    }
    return dp[target];
}

int main() {
    vector<int> nums{1, 5, 11, 5};
    cout << canPartition(nums) << endl;

    return 0;
}
