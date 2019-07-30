#include <vector>
#include <iostream>

using namespace std;

void permute(const vector<int>& nums, bool* marked, int count, vector<int>& line, vector<vector<int>>& result) {
    if (count == nums.size()) {
        result.push_back(line);
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (!marked[i]) {
            marked[i] = true;
            line.push_back(nums[i]);
            permute(nums, marked, count + 1, line, result);
            line.pop_back();
            marked[i] = false;
        }
    }
}

vector<vector<int>> permute(const vector<int>& nums) {
    int length = nums.size();
    vector<vector<int>> permutations;
    if (length == 0) {
        return permutations;
    }

    bool marked[length];
    for (int i = 0; i < length; ++i) {
        marked[i] = false;
    }

    vector<int> line;
    permute(nums, marked, 0, line, permutations);

    return permutations;
}

int main() {
    vector<int> nums{1, 2, 3, 4};

    auto permutations = permute(nums);
    for (const auto& item: permutations) {
        for (int i = 0; i < item.size(); ++i) {
            cout << item[i] << " ";
        }
        cout << endl;
    }

    return 0;
}