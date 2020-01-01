#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraySum(vector<int> &nums, int k) {
    int result = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int curr = 0;
        for (int j = i; j < n; ++j) {
            if (nums[j] + curr > k) {
                break;
            }
            curr += nums[j];
            if (curr == k) {
                result += 1;
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums{-1, -1, 1};
    int k = 0;
    cout << subarraySum(nums, k) << endl;
    return 0;
}
