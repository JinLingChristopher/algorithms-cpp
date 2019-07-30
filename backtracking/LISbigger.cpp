#include <limits>
#include <iostream>
#include <vector>

using namespace std;

int lis_bigger(const vector<int>& nums, int i, int j) {
    if (i == 0 && i == j) {
        return 1 + lis_bigger(nums, i, i + 1);
    }
    if (j == nums.size()) {
        return 0;
    } else if (nums[j] <= nums[i]) {
        return lis_bigger(nums, i, j + 1);
    } else {
        int skip = lis_bigger(nums, i, j + 1);
        int take = lis_bigger(nums, j, j + 1) + 1;
        return std::max(skip, take);
    }
}


int main() {
    // vector<int> nums{1, 3, 2, 4, 0, 5, 2, 4};
    // vector<int> nums{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6};
    vector<int> nums{-2, -1};
    // int ret = lis_bigger(nums, numeric_limits<int>::min(), 0);
    int ret = lis_bigger(nums, 0, 0);
    cout << ret << endl;

    return 0;
}