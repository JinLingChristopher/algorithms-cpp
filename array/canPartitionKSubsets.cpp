#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool backtrace(const vector<int> &nums, vector<int> &sums, int i, int k,
               int s) {
    if (i == nums.size()) {
        return true;
    }
    for (int j = 0; j < k; ++j) {
        if (sums[j] < s && nums[i] + sums[j] <= s) {
            sums[j] += nums[i];
            if (backtrace(nums, sums, i + 1, k, s)) {
                return true;
            }
            sums[j] -= nums[i];
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int> &nums, int k) {
    int s = accumulate(nums.begin(), nums.end(), 0);
    if (s % k != 0)
        return false;

    sort(nums.begin(), nums.end(), greater<int>());
    vector<int> sums(k, 0);
    return backtrace(nums, sums, 0, k, s / k);
}

int main() {
    vector<int> nums{10, 10, 10, 7, 7, 7, 7, 7, 7, 6, 6, 6};
    int k = 3;

    cout << canPartitionKSubsets(nums, k) << endl;

    return 0;
}
