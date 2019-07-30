#include <iostream>
#include <vector>


using namespace std;


void helper(const vector<int>& nums, int prev, int index, vector<int>& current, vector<int>& result) {
    if (result.size() < current.size()) {
        result = current;
    }

    for (int i = index; i < nums.size(); ++i) {
        if (nums[i] > prev) {
            current.push_back(nums[i]);
            helper(nums, nums[i], i + 1, current, result);
            current.pop_back();
        }
    }
}

vector<int> longest_increasing_subsequence(const vector<int>& nums) {
    vector<int> result, current;
    helper(nums, -1, 0, current, result);

    return result;
}

int main() {
    vector<int> nums{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6};
    vector<int> lis = longest_increasing_subsequence(nums);
    
    for (auto iter = lis.cbegin(); iter != lis.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}