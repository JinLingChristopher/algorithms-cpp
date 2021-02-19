//
// Created by Edison King on 2020/3/1.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subsets(const vector<int>& nums) {
    vector<vector<int>> result = {{}};
    for (const auto& item: nums) {
        int n = result.size();
        for (int i = 0; i < n; ++i) {
            auto t = result[i];
            t.push_back(item);
            result.push_back(t);
        }
    }
    return result;
}

void solver(const vector<int>& nums, int index, vector<vector<int>>& result, vector<int>& curr) {
    if (index == nums.size()) {
        return;
    }

    curr.push_back(nums[index]);
    result.push_back(curr);
    solver(nums, index + 1, result, curr);

    curr.pop_back();
    solver(nums, index + 1, result, curr);
}

vector<vector<int>> subsets_dfs(const vector<int>& nums) {
    vector<vector<int>> result{{}};
    vector<int> curr;
    solver(nums, int index, result, curr);

    return result;
}

int main() {
    vector<int> nums{1, 2, 3};
    auto result = subsets(nums);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
