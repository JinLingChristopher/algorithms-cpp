#include <iostream>
#include <vector>

using namespace std;

void helper(const vector<int> &nums, int target, int curr, int idx,
            int &result) {
    if (idx == nums.size()) {
        if (curr == target) {
            result += 1;
        }
        return;
    }
    helper(nums, target, curr - nums[idx], idx + 1, result);
    helper(nums, target, curr + nums[idx], idx + 1, result);
}

int findTargetSumWays(const vector<int> &nums, int target) {
    int result = 0;
    helper(nums, target, 0, 0, result);

    return result;
}

int main() {
    vector<int> nums{1, 1, 1, 1, 1};
    int target = 3;
    cout << findTargetSumWays(nums, target) << endl;

    return 0;
}
