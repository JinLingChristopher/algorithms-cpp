#include <limits>
#include <vector>
#include <iostream>

using namespace std;

int lis_first(const vector<int>& nums, int i, int prev) {
    int best = 0;
    for (int j = i; j < nums.size(); j++) {
        if (nums[j] > prev) {
            best = std::max(best, lis_first(nums, j, nums[j]));
        }
    }
    return 1 + best;    
}

int lis_first(const vector<int>& nums) {
    int prev = std::numeric_limits<int>::min();
    int best = lis_first(nums, 0, prev);

    return best - 1;
}

int main() {
    vector<int> nums{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6};
    // vector<int> nums{0, -2, -1};
    int ret = lis_first(nums);
    cout << ret << endl;
    return 0;
}