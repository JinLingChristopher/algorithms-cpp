//
// Created by 金灵 on 2020/2/23.
//

#include <vector>
#include <iostream>
#include <limits>
#include <stack>

using namespace std;

bool solver(const vector<int>& arr, int lo, int hi) {
    if (lo >= hi) {
        return true;
    }
    int root = arr[hi];
    int l = lo;
    while (l < hi && arr[l] < root) {
        ++l;
    }
    int r = l;
    while (r < hi && arr[r] > root) {
        ++r;
    }
    if (r != hi) {
        return false;
    }
    return solver(arr, lo, l - 1) && solver(arr, l, hi - 1);
}

bool verifyPostOrder(const vector<int>& nums) {
    return solver(nums, 0, nums.size() - 1);
}

bool verifyPostOrderIterative(const vector<int>& nums) {
    stack<int> st;
    int prev = std::numeric_limits<int>::max();
    for (int i = nums.size() - 1; i >= 0; --i) {
        if (nums[i] > prev) {
            return false;
        }
        while (!st.empty() && nums[i] < st.top()) {
            prev = st.top();
            st.pop();
        }
        st.push(nums[i]);
    }
    return true;
}

int main() {
    vector<int> arr{4, 6, 7, 5};
    cout << verifyPostOrder(arr) << endl;
    cout << verifyPostOrderIterative(arr) << endl;
    return 0;
}