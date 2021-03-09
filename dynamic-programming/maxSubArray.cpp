#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int maxSubArray(const vector<int> &nums) {
    int total, result;
    total = result = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        total = std::max(nums[i], total + nums[i]);
        result = std::max(result, total);
    }
    return result;
}

int divide(const vector<int>& nums, int lo, int hi) {
    if (lo == hi) {
        return nums[lo];
    }
    int mid = lo + (hi - lo) / 2;
    int left = divide(nums, lo, mid);
    int right = divide(nums, mid + 1, hi);

    int leftTotal = 0, leftMax = std::numeric_limits<int>::min();
    for (int i = mid; i >= lo; --i) {
        leftTotal += nums[i];
        leftMax = max(leftMax, leftTotal);
    }

    int rightTotal = 0, rightMax = std::numeric_limits<int>::min();
    for (int i = mid + 1; i <= hi; ++i) {
        rightTotal += nums[i];
        rightMax = max(rightMax, rightTotal);
    }
    return max(max(left, right), leftMax + rightMax);
}

int maxSubArrayDC(const vector<int>& nums) {
    return divide(nums, 0, nums.size() - 1);
}


int main() {
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto result = maxSubArray(nums);
    cout << result << endl;

    cout << maxSubArrayDC(nums) << endl;
    return 0;
}
