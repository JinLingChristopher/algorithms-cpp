#include <vector>
#include <iostream>

using namespace std;

int fastlis(const vector<int>& nums) {
    vector<int> dp;
    for (int i = 0; i < nums.size(); ++i) {
        int x = 1;
        for (int j = i - 1; j >= 0; --j) {
            if (nums[j] < nums[i]) {
                x = std::max(x, dp[j] + 1);
            }
        }
        dp.push_back(x);
    }

    int res = 0;
    for (int i = 0; i < dp.size(); ++i) {
        res = std::max(res, dp[i]);
    }

    return res;
}

int main() {
    vector<int> nums{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6};
    int ret = fastlis(nums);
    cout << ret << endl;
    return 0;
}