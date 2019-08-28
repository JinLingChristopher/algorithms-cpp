#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

int binarySearch(const vector<int>& nums, int target, int left, int right) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            return binarySearch(nums, target, left, mid - 1);
        } else {
            return binarySearch(nums, target, mid+1, right);
        }
    }
    return -1;
}

void helper(const vector<int>& nums, set<vector<int>>& result, vector<int>& current) {
    if (current.size() == 3) {
        result.insert(current);
        return;
    } 
    for (int i = 0; i < nums.size(); ++i) {
        current.push_back(nums[i]);
        for (int j = i + 1; j < nums.size(); ++j) {
            current.push_back(nums[j]);
            int target = 0 - nums[i] - nums[j];
            int index = binarySearch(nums, target, j + 1, nums.size() - 1);
            if (index != -1) {
                current.push_back(nums[index]);
                helper(nums, result, current);
                current.pop_back();
            }
            current.pop_back();
        }
        current.pop_back();
    }
}

vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    set<vector<int>> result;
    vector<int> current;

    for (int i = 0; i < nums.size(); ++i) {
        current.push_back(nums[i]);
        for (int j = i + 1; j < nums.size(); ++j) {
            current.push_back(nums[j]);
            int target = 0 - nums[i] - nums[j];
            int index = binarySearch(nums, target, j + 1, nums.size() - 1);
            if (index != -1) {
                current.push_back(nums[index]);
                result.insert(current);
                current.pop_back();
            }
            current.pop_back();
        }
        current.pop_back();
    }
    vector<vector<int>> res;
    for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
        res.push_back(*iter);
    }
    return res;
}

// vector<vector<int>> threeSum(vector<int>& nums) {
//     std::sort(nums.begin(), nums.end());
//     vector<int> current;
//     set<vector<int>> result;

//     helper(nums, result, current);
//     vector<vector<int>> res;
//     for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
//         res.push_back(*iter);
//     }

//     return res;
// }

int main() {
    vector<int> nums{0};
    auto result = threeSum(nums);
    for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
        for (const auto item: *iter) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}