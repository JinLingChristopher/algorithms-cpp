//
// Created by Edison King on 2020/2/29.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> solver(const vector<int>& nums) {
    vector<int> result;
    for (size_t i = 0; i < nums.size(); ++i) {
        int count = 0;
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] > nums[j]) {
                count += 1;
            }
        }
        result.push_back(count);
    }
    return result;
}


int main() {

    vector<int> nums{4, 3, 9, 2};

    auto result = solver(nums);
    string s = "[";
    for (int i = 0; i < result.size(); ++i) {
        s += to_string(result[i]);
        if (i != result.size() - 1) {
            s += ", ";
        }
    }
    s += "]";
    cout << s << endl;
    return 0;
}