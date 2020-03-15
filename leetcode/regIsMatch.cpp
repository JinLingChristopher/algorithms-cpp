//
// Created by Edison King on 2020/3/5.
//

#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool solver(const string& s, int i, const string& p, int j) {
    // 如果 pattern 为空，s 空则 true，反之则 false
    if (j == p.size()) {
        return i == s.size();
    }
    // text 不为空，并且 第一个字符 匹配
    auto first_match = (i != s.size()) && (p[j] == s[i] || p[j] == '.');
    if (p.size() - j >= 2 && p[j + 1] == '*') {
        return solver(s, i, p, j + 2) || (first_match && solver(s, i + 1, p, j));
    }
    return first_match && solver(s, i + 1, p, j + 1);
}


bool isMatch(const string& s, const string& p) {
    return solver(s, 0, p, 0);
}

bool isMatch3(string s, string p) {
    s=" "+s;//防止该案例：""\n"c*"
    p=" "+p;
    int m=s.size(),n=p.size();
    bool dp[m+1][n+1];
    memset(dp,false,(m+1)*(n+1));
    dp[0][0]=true;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==p[j-1] || p[j-1]=='.'){
                dp[i][j]=dp[i-1][j-1];
            }
            else if(p[j-1]=='*'){
                if(s[i-1]!=p[j-2] && p[j-2]!='.')
                    dp[i][j]=dp[i][j-2];
                else{
                    dp[i][j]=dp[i][j-1] || dp[i][j-2] || dp[i-1][j];

                }
            }
        }
    }
    return dp[m][n];
}

bool isMatchDP(const string& s, const string& p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                if (p[j - 2] != s[i - 1] && p[j - 2] != '.') {
                    dp[i][j] = dp[i][j - 2];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
                }
            }
        }
    }
    return dp[n][m];
}

int main() {
    cout << isMatchDP("aa", "a") << endl;
    cout << isMatchDP("aa", "a*") << endl;
    cout << isMatchDP("ab", ".*") << endl;
    cout << isMatchDP("ab", ".*c") << endl;
    cout << isMatchDP("aab", "c*a*b") << endl;
    cout << isMatchDP("mississippi", "mis*is*p*.") << endl;

    return 0;
}