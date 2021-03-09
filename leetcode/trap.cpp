//
// Created by Edison King on 2020/3/17.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int trap(const vector<int>& height) {
    int n = height.size();
    if (n == 0) {
        return 0;
    }
    int result = 0, curr = 0;
    stack<int> st;
    while (curr < n) {
        while (!st.empty() && height[curr] > height[st.top()]) {
            int l = st.top();
            st.pop();
            if (st.empty()) {
                break;
            }
            int dist = curr - st.top() - 1;
            int hi = min(height[curr], height[st.top()]) - height[l];
            result += dist * hi;
        }
        st.push(curr++);
    }
    return result;
}


int main() {
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height) << endl;
    return 0;
}
