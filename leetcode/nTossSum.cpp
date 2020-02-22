//
// Created by 金灵 on 2020/2/21.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


vector<double> nTossSum(int n) {
    vector<vector<double>> dp(n + 1, vector<double>(6 * n + 1, 0));
    for (int s = 1; s <= 6; ++s) {
        dp[1][s] = 1;
    }
    for (int k = 2; k <= n; ++k) {
        for (int s = k; s <= 6 * k; ++s) {
            for (int d = 1; d <= 6; ++d) {
                if (s - d <= 0) {
                    break;
                }
                dp[k][s] += dp[k - 1][s - d];
            }
        }
    }

    int deno = std::pow(6, n);
    for (auto& item: dp[n]) {
        item /= deno;
    }
    vector<double> result;
    auto& t = dp[n];
    for (auto iter = t.begin() + n; iter != t.end(); ++iter) {
        result.push_back(*iter);
    }
    return result;
}


int main() {

    int n = 4;
    auto result = nTossSum(n);
    for (const auto& item: result) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}