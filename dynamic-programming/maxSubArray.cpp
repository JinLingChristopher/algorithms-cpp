#include <vector>
#include <iostream>

using namespace std;

int maxSubArray(const vector<int>& nums) {
    int total, result;
    total = result = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        total = std::max(nums[i], total + nums[i]);
        result = std::max(result, total);
    }
    return result;
}

int main() {
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto result = maxSubArray(nums);
    cout << result << endl;

    return 0;
}