#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int findUnsortedSubarray(const vector<int> &nums) {
    int min = numeric_limits<int>::max(), max = numeric_limits<int>::min();
    int n = nums.size();

    for (int i = 1; i < n; ++i) {
        if (nums[i] < nums[i - 1]) {
            min = std::min(min, nums[i]);
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        if (nums[i] > nums[i + 1]) {
            max = std::max(max, nums[i]);
        }
    }
    int l, r;
    for (l = 0; l < n; ++l) {
        if (min < nums[l]) {
            break;
        }
    }
    for (r = n - 1; r >= 0; --r) {
        if (max > nums[r]) {
            break;
        }
    }
    return r < l ? 0 : r - l + 1;
}

int main() {
    vector<int> nums{2, 6, 4, 8, 10, 9, 15};
    cout << findUnsortedSubarray(nums) << endl;
    return 0;
}
