#include <iostream>
#include <vector>

using namespace std;

int coinChange(const vector<int> &nums, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (auto coin : nums) {
            if (coin <= i) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> coins{1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount) << endl;

    return 0;
}
