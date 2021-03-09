//
// Created by Edison King on 2020/3/17.
//
#include <iostream>
#include <vector>

using namespace std;

//int solver(const vector<int> &values, const vector<int> &weights, int total) {
//    int n = weights.size();
//    vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));
//    // 随着 i 变大，越来越多的商品可供选择。
//    for (int i = 1; i <= n; ++i) {
//        int val = values[i - 1], w = weights[i - 1];
//        for (int j = 1; j <= total; ++j) {
//            if (w > j) { // 当前商品重量大于最大容纳，因此无法选取，等于前一个值。
//                dp[i][j] = dp[i - 1][j];
//            } else { // 可以被选择，那么就要分析是否选择。选取最大值。
//                // dp[i - 1][j] 是不选择的情况
//                // dp[i - 1][j - w] 是选择情况
//                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - w] + val);
//            }
//        }
//    }
//    for (int i = 0; i < dp.size(); ++i) {
//        for (int j = 0; j < dp[0].size(); ++j) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return dp[n][total];
//}

int numToys(const vector<int>& prices, int k) {
    int n = prices.size();
    if (n == 0 || k == 0) {
        return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; ++i) {
        int p = prices[i - 1];
        for (int j = 0; j <= k; ++j) {
            if (p > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - p] + 1);
            }
        }
    }
    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> prices(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    cout << numToys(prices, k) << endl;

    return 0;
}
