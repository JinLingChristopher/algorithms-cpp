#include <iostream>
#include <vector>

using namespace std;

double new21Game(int N, int K, int W) {
    vector<double> dp(N + W + 1, 0);
    for (int k = K; k <= N; ++k) {
        dp[k] = 1.0;
    }
    double s = std::min(N - K + 1, W);
    for (int k = K - 1; k >= 0; --k) {
        dp[k] = s / W;
        s += dp[k] - dp[k + W];
    }
    return dp[0];
}

int main() {
    int N = 21, K = 17, W = 10;
    auto result = new21Game(N, K, W);
    cout << result << endl;

    return 0;
}
