#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int maxProduct(const vector<int> &nums) {
    int max = 1, min = 1, result = numeric_limits<int>::min();
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < 0) {
            swap(max, min);
        }
        max = std::max(max * nums[i], nums[i]);
        min = std::min(min * nums[i], nums[i]);
        result = std::max(result, max);
    }
    return result;
}

int main() {
    vector<int> nums{-2, 3, -4};
    cout << maxProduct(nums) << endl;

    return 0;
}
