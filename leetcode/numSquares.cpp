#include <iostream>
#include <vector>

using namespace std;

int numSquares(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < dp.size(); ++i) {
        dp[i] = i;
        for (int j = 0; i - j * j >= 0; ++j) {
            dp[i] = std::min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

int main() {
    int n = 12;
    cout << numSquares(n) << endl;
    return 0;
}
