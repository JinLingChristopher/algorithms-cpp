#include <vector>
#include <iostream>

using namespace std;


int findMaxConsecutiveOnes(vector<int>& nums) {
    int result = 0, curr = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
            result = std::max(result, curr);
            curr = 0;
        } else {
            curr += 1;
        }
    }
    return std::max(result, curr);
}

int main() {
    vector<int> nums{1, 1, 0, 1, 1, 1};

    cout << findMaxConsecutiveOnes(nums) << endl;

    return 0;
}