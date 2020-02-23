//
// Created by Edison King on 2020/2/23.
//

#include <vector>
#include <iostream>

using namespace std;

int minArray(const vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[hi]) {
            lo = mid + 1;
        } else if (nums[mid] < nums[hi]) {
            hi = mid;
        } else {
            hi -= 1;
        }
    }
    return nums[lo];
}


int main() {

    vector<int> nums{3, 4, 5, 6, 1, 2};
    cout << minArray(nums) << endl;

    return 0;
}