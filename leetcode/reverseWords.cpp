//
// Created by Edison King on 2020/2/29.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string reverseWord(const string& s) {
    stack <string> st;
    size_t start = 0, n = s.size();
    while (start != n) {
        while (s[start] == ' ') {
            ++start;
        }
        if (s[start] == '\0') {
            break;
        }
        size_t end = start;
        while (s[end] != ' ' && s[end] != '\0') {
            ++end;
        }
        st.push(s.substr(start, end - start));
        start = end;
    }
    string result;
    while (!st.empty()) {
        auto t = st.top();
        st.pop();
        result += t;
        if (!st.empty()) {
            result += " ";
        }
    }
    return result;
}

int main() {
    cout << reverseWord("the sky is blue") << endl;
    cout << reverseWord("   hello world!   ") << endl;

    return 0;
}