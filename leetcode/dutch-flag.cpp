#include <iostream>
#include <vector>

using namespace std;

void dutchFlag(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    int i = 0;
    while (i <= hi) {
        if (nums[i] == 0) {
            swap(nums[i++], nums[lo++]);
        } else if (nums[i] == 2) {
            swap(nums[i], nums[hi--]);
        } else {
            ++i;
        }
    }
}

int main() {
    vector<int> nums{ 2, 0, 2, 1, 1, 0 };
    dutchFlag(nums);
    for (const auto& item : nums) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
