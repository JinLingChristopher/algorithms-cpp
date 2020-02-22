//
// Created by 金灵 on 2020/2/21.
//

#include <vector>
#include <iostream>

using namespace std;

int partition(vector<int>& nums, int lo, int hi) {
    int p = nums[lo], k = lo;
    while (lo < hi) {
        while (lo < hi && nums[hi] >= p) {
            --hi;
        }
        while (lo < hi && nums[lo] <= p) {
            ++lo;
        }
        swap(nums[lo], nums[hi]);
    }
    swap(nums[k], nums[lo]);
    return lo;
}

vector<int> getLeastNumbers(vector<int>& nums, int k) {
    if (nums.size() == k) {
        return nums;
    }
    vector<int> result;
    if (k == 0) {
        return result;
    }
    int lo = 0, hi = nums.size() - 1;
    int lt = partition(nums, lo, hi);
    while (lt != k - 1) {
        if (lt < k - 1) {
            lt = partition(nums, lt + 1, hi);
        } else {
            lt = partition(nums, lo, lt - 1);
        }
    }
    for (int i = 0; i < k; ++i) {
        result.push_back(nums[i]);
    }
    return result;
}

int main() {
    vector<int> nums{0, 1, 1, 2, 4, 4, 1, 3, 3, 2};
    int k = 6;

    auto result = getLeastNumbers(nums, k);
    for (const auto& item: result) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}