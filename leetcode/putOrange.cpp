//
// Created by Edison King on 2020/3/17.
//
#include <iostream>
#include <vector>
using namespace std;

int putOrange(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == 1 || j == 1) {
                dp[i][j] = 1;
            } else if (i == j) {
                dp [i][j] = i;
            } else if (i > j) {
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            } else {
                dp[i][j] = dp[i][i];
            }
        }
    }
    return dp[a][b];
}

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cout << putOrange(a, b) << endl;
    }

    return 0;
}
