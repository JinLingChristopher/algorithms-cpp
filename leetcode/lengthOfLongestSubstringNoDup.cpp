//
// Created by Edison King on 2020/2/23.
//

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;


int lengthOfLongestSubstringNoDup(const string& s) {
    int result = 0;
    string curr;
    int start = 0;
    unordered_map<char, int> lastIndex;
    while (start != s.size()) {
        result = std::max(result, (int)curr.size());
        curr.clear();
        lastIndex.clear();
        int j = start;
        for (; j < s.size(); ++j) {
            if (lastIndex.find(s[j]) == lastIndex.end()) {
                curr.push_back(s[j]);
                lastIndex[s[j]] = j;
            } else {
                start = lastIndex[s[j]] + 1;
                break;
            }
        }
        start += 1;
    }
    result = std::max(result, (int)curr.size());
    return result;
}

int lengthOfLengthSubstringNoDupDp(const string& s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int result = 0;
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            dp[i][j] = (dp[i][j - 1] && dp[i + 1][j] && s[i] != s[j]);
            if (dp[i][j]) {
                result = std::max(result, j - i + 1);
            }
        }
    }
    return result;
}

int lengthOfLongestSubstring(const string& s) {
    int result = 0;
    int lo = 0, hi = 0;

    while (hi < s.size()) {
        char c = s[hi];
        bool flag = true;
        for (int j = hi - 1; j >= lo; --j) {
            if (c == s[j]) {
                result = std::max(result, hi - lo);
                // lo += 1;
                lo = j + 1;
                flag = false;
                break;
            }
        }
        hi += flag;
    }
    result = std::max(result, hi - lo);
    return result;
}

int main() {
    string s{"pwwekw"};
    cout << lengthOfLongestSubstring(s) << endl;
    cout << lengthOfLongestSubstringNoDup(s) << endl;
    cout << lengthOfLengthSubstringNoDupDp(s) << endl;
    return 0;
}
