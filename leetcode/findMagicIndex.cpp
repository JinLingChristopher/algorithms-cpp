//
// Created by Edison King on 2020/3/9.
//
#include <iostream>
#include <vector>

using namespace std;


int findMagicIndex(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        if (i == nums[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> nums{0, 2, 3, 4, 5};
    cout << findMagicIndex(nums) << endl;

    return 0;
}
