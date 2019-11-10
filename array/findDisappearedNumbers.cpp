#include <vector>
#include <iostream>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        int idx = (nums[i] - 1) % nums.size();
        nums[idx] += nums.size();
    }
    
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] <= nums.size()) {
            result.push_back(i + 1);
        }
    }
    
    return result;
}

int main() {
    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};

    auto result = findDisappearedNumbers(nums);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}