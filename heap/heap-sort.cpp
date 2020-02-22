#include <iostream>
#include <vector>
using namespace std;

void sink(vector<int>& nums, int k, int n) {
    while (2 * k <= n) {
        int j = 2 * k;
        if (j < n && nums[j] < nums[j + 1]) {
            j += 1;
        }
        if (nums[k] >= nums[j]) {
            break;
        }
        swap(nums[k], nums[j]);
        k = j;
    }
}

void heapSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = n / 2; i >= 1; i--) {
        sink(nums, i, n);
    }
    while (n > 1) {
        swap(nums[1], nums[n--]);
        sink(nums, 1, n);
    }
}

int main() {
    vector<int> nums{ 3, 1, 4, 1, 5, 9, 2, 6, 7, 3, 8, 10, 0, 11, 9 };
    heapSort(nums);
    for (auto iter = nums.cbegin(); iter != nums.cend(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}
