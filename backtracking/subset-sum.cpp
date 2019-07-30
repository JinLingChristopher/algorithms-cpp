#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

void subset_sum(int* arr, int n, int start, vector<int>& record, int target) {
    int total = std::accumulate(record.begin(), record.end(), 0);
    if (total == target) {
        for (auto iter = record.cbegin(); iter != record.cend(); ++iter) {
            cout << *iter << " ";
        }
        cout << endl;
    }
    for(int i = start; i < n; i++) {
        if ((total + arr[i]) <= target) {
            record.push_back(arr[i]);
            subset_sum(arr, n, i + 1, record, target);
        }
    }
    record.pop_back();
}


int main() {
    int nums[] = {8, 6, 7, 5, 3, 10, 9};
    vector<int> subset;
    subset_sum(nums, sizeof(nums) / sizeof(nums[0]), 0, subset, 15);

    return 0;
}