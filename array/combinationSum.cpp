#include <vector>
#include <iostream>

using namespace std;

void helper(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& curr, int start) {
    if (target == 0) {
        result.push_back(curr);
        return;
    }
    for (int i = start; i < candidates.size(); ++i) {
        auto item = candidates[i];
        if (item <= target) {
            curr.push_back(item);
            helper(candidates, target - item, result, curr, i);
            curr.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> curr;
    helper(candidates, target, result, curr, 0);
    return result;    
}

int main() {
    vector<int> candidates{2, 3, 6, 7};
    int target = 7;
    
    auto result = combinationSum(candidates, target);

    for (const auto& item: result) {
        for (int i = 0; i < item.size(); ++i) {
            cout << item[i] << " ";
        }
        cout << endl;
    }

    return 0;
}