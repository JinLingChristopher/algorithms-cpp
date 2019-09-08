#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(vector<int>& nums, int a, int b) {
    int t = nums[a];
    nums[a] = nums[b];
    nums[b] = t;
}

void insertionSort(vector<int>& nums, int lo, int hi) {
    for (int i = lo; i <= hi; ++i) {
        int j = i;
        while (j > 0) {
            if (nums[j] < nums[j - 1]) {
                swap(nums, j, j - 1);
            }
            j--;
        }
    }
}

void insertionSort(vector<int>& nums) {
    insertionSort(nums, 0, nums.size());
}

int main() {
    std::vector<int> nums(20);
    std::generate(nums.begin(), nums.end(), std::rand);
    for (auto i = 0; i < nums.size(); ++i) {
        nums[i] = nums[i] % 100;
    }

    insertionSort(nums);

    for (auto iter = nums.cbegin(); iter != nums.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}