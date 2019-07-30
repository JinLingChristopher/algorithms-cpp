#include <vector>
#include <iostream>

using namespace std;

bool subset_sum_dynamic(const vector<int>& nums, int target) {
    int n = nums.size();
    int table[n + 1][target + 1];
    table[n + 1][0] = 1;
    for (int i = 1; i < target; i++) {
        table[n + 1][i] = 0;
    }

    for (int i = n; i >= 0; --i) {
        table[i][0] = 1;
        for (int t = 1; t < nums[i]; ++t) {
             table[i][t] = table[i+1][t];
        }
        for (int t = nums[i]; t <= 15; ++t) {
            table[i][t] = (table[i + 1][t] || table[i + 1][t - nums[i]]); 
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= target; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    return table[0][target];
}

int main() {

    vector<int> nums{8, 6, 7, 5, 3, 10, 9};
    cout << subset_sum_dynamic(nums, 15) << endl;

    return 0;
}