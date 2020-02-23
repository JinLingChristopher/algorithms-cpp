//
// Created by 金灵 on 2020/2/23.
//

#include <vector>
#include <iostream>

using namespace std;

int cuttingRope(int n) {
    vector<int> dp(n + 1, 0);
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        for (int j = 2; j < i; ++j) {
            dp[i] = std::max(dp[i], dp[j] * (i - j));
            dp[i] = std::max(dp[i], (i - j) * j);
        }
    }
    return dp[n];
}

//0 1 2 3 4 5 6 7 8 9 10
//0 0 1 2 4

int main() {
    cout << cuttingRope(2) << endl;
    cout << cuttingRope(10) << endl;
    cout << cuttingRope(3) << endl;
    cout << cuttingRope(58) << endl;

    return 0;
}