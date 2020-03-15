//
// Created by Edison King on 2020/3/9.
//
#include <vector>
#include <iostream>

using namespace std;

void wiggleSort(vector<int>& nums) {
    for(int i = 1; i < nums.size(); ++i){
        if (i % 2 == 0 && nums[i] < nums[i - 1]) {
            swap(nums[i], nums[i - 1]);
        } else if (nums[i] > nums[i - 1]) {
            swap(nums[i], nums[i - 1]);
        }
    }
}

int main() {
    vector<int> nums{5, 3, 1, 2, 3};
    wiggleSort(nums);
    for (const auto& item: nums) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
