#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(const string &s) {
    int length = s.size();
    int i = 0, j = length - 1;
    while (i < j && i < length && j > 0) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void solver(const string &s, vector<vector<string>> &result,
            vector<string> curr, int idx) {
    int n = s.length();
    if (idx == n) {
        result.push_back(curr);
        return;
    }
    for (int i = idx; i < n; ++i) {
        string t = s.substr(idx, i - idx + 1);
        if (isPalindrome(t)) {
            curr.push_back(t);
            solver(s, result, curr, idx + 1);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(const string &s) {
    vector<vector<string>> result;
    vector<string> curr;
    solver(s, result, curr, 0);
    return result;
}

int main() {
    string s("aab");
    auto result = partition(s);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
