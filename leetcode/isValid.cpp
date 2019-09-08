#include <vector>
#include <iostream>

using namespace std;

bool isValid(const vector<int>& nums) {
    int length = nums.size();
    if (length < 2) {
        return true;
    }
    for (int i = 0; i < length - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {

    vector<int> input{1, 1};

    bool ret = isValid(input);
    cout << ret << endl;

    return 0;
}