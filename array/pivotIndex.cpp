#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int pivotIndex(const vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if ((leftSum * 2 + nums[i]) == total) {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}

int main() {
    vector<int> nums{1, 7, 3, 6, 5, 6};
    int result = pivotIndex(nums);
    cout << result << endl;
    return 0;
}
