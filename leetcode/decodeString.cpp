#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decodeString(const string& s) {
    stack<int> numStack;
    stack<string> resStack;
    int num = 0;
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            res.push_back(s[i]);
        } else if (isdigit(s[i])) {
            num = num * 10 + s[i] - '0';
        } else if (s[i] == '[') {
            resStack.push(res);
            res = "";
            numStack.push(num);
            num = 0;
        } else {
            int n = numStack.top();
            numStack.pop();

            for (int j = 0; j < n; ++j) {
                resStack.top() += res;
            }
            res = resStack.top();
            resStack.pop();
        }
    }
    return res;
}

int main() {
    string s = "3[a2[c]]";
    auto result = decodeString(s);
    cout << result << endl;
    return 0;
}
