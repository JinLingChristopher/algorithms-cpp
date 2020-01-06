#include <iostream>
#include <vector>

using namespace std;

int solver(const vector<int> &values, const vector<int> &weights, int target) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 1; i <= n; ++i) {
        int val = values[i - 1], w = weights[i - 1];
        for (int j = 1; j <= target; ++j) {
            if (w <= j) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - w] + val);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
}

int main() {
    vector<int> values{1, 6, 18, 22, 28};
    vector<int> weights{1, 2, 5, 6, 7};
    int totalWeight = 11;

    auto result = solver(values, weights, totalWeight);
    cout << result << endl;

    return 0;
}
