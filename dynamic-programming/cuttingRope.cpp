//
// Created by 金灵 on 2020/2/23.
//

#include <vector>
#include <iostream>
#include <cmath>

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

int cuttingRope2(int n) {
    vector<int> dp(n + 1, 1);
    const int remainder = 1e9+7;
    for (int i = 3; i <= n; ++i) {
        for (int j = 2; j < i; ++j) {
            int a = dp[j] * (i - j) % remainder;
            int b = j * (i - j) % remainder;
            a = std::max(a, b);
            dp[i] = std::max(dp[i], a);
        }
    }
    return dp[n];
}

int cuttingRope3(int n) {
    if (n <= 3) {
        return n - 1;
    }
    int b = n % 3, p = 1000000007;
    int result = 1, x = 3;
    for (int a = n / 3 -1; a > 0; a /= 2) {
        if (a % 2 == 1) {
            result = (result * x) % p;
        }
        x = (x * x) % p;
    }
    if (b == 0) {
        return result * 3 % p;
    } else if (b == 1) {
        return result * 4 % p;
    }
    return result * 6 % p;
}

int main() {
    cout << cuttingRope3(2) << endl;
    cout << cuttingRope3(10) << endl;
    cout << cuttingRope3(3) << endl;
    cout << cuttingRope3(58) << endl;

    return 0;
}