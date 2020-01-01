#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target) {
    int n = nums.size();
    if (n == 0) {
        return -1;
    }
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[lo] <= nums[mid]) {
            if (target < nums[mid] && target >= nums[lo]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else {
            if (target > nums[mid] && target <= nums[hi]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    cout << search(nums, 0) << endl;
    return 0;
}
