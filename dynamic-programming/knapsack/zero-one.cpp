#include <iostream>
#include <vector>

using namespace std;


// values:  1, 6, 18, 22, 28
// weights: 1, 2, 5,  6,  7
// 第一列：total = 0，无法选择的，因此全为 0
// 第一行：没有一个物品，没有可选的，因此全为 0
// 第二行：只有 value = 1， weight = 1 的商品可以选择，且能被成功选取，所以全为 1

//0 1 2 3 4 5  6  7  8  9  10 11

//0 0 0 0 0 0  0  0  0  0  0  0
//0 1 1 1 1 1  1  1  1  1  1  1
//0 1 6 7 7 7  7  7  7  7  7  7
//0 1 6 7 7 18 19 24 25 25 25 25
//0 1 6 7 7 18 22 24 28 29 29 40
//0 1 6 7 7 18 22 28 29 34 35 40

int solver(const vector<int> &values, const vector<int> &weights, int total) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));
    // 随着 i 变大，越来越多的商品可供选择。
    for (int i = 1; i <= n; ++i) {
        int val = values[i - 1], w = weights[i - 1];
        for (int j = 1; j <= total; ++j) {
            if (w > j) { // 当前商品重量大于最大容纳，因此无法选取，等于前一个值。
                dp[i][j] = dp[i - 1][j];
            } else { // 可以被选择，那么就要分析是否选择。选取最大值。
                // dp[i - 1][j] 是不选择的情况
                // dp[i - 1][j - w] 是选择情况
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - w] + val);
            }
        }
    }
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[0].size(); ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][total];
}

int solver2(const vector<int>& values, const vector<int>& weights, int total) {
    int n = values.size();
    vector<int> dp(total + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int val = values[i - 1], weight = weights[i - 1];
        for (int w = total; w >= 0; --w) {
            if (w >= weight) { // 在更新一个值之前，需要判断是否有足够的重量，防止越界
                dp[w] = std::max(dp[w], dp[w - weight] + val);
            }
        }
    }
    return dp[total];
}

int main() {
    vector<int> values{1, 6, 18, 22, 28};
    vector<int> weights{1, 2, 5, 6, 7};
    int totalWeight = 11;

    auto result = solver2(values, weights, totalWeight);
    cout << result << endl;

    return 0;
}
