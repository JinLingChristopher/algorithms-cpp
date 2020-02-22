//
// Created by 金灵 on 2020/2/22.
//

#include <vector>
#include <stack>
#include <iostream>

using namespace std;


bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int i = 0;
    for (const auto& item: pushed) {
        st.push(item);
        while (i < popped.size() && !st.empty() && popped[i] == st.top()) {
            st.pop();
            i += 1;
        }
    }
    while (i != popped.size()) {
        if (st.top() != popped[i]) {
            return false;
        }
        st.pop();
        i += 1;
    }
    return st.empty();
}

int main() {
    vector<int> a{2, 1, 0};
    vector<int> b{1, 2, 0};
    auto result = validateStackSequences(a, b);
    cout << result << endl;
    return 0;
}