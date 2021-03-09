//
// Created by Edison King on 2020/3/14.
//
#include <iostream>
#include <limits>
#include <map>
#include <vector>
using namespace std;

int TravelingSalesMan(map<int, vector<int>>& tickets) {
    int n = tickets.size();
    int v = 1 << (n - 1);
    vector<vector<int>> dp(n, vector<int>(v, 0));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = tickets[i][0];
    }
    for (int j = 1; j < v; ++j) {
        for (int i = 0; i < n; ++i) {
            dp[i][j] = std::numeric_limits<int>::max();
            if (((j >> (i - 1)) & 1) != 0) {
                continue;
            }
            for (int k = 1; k < n; ++k) {
                if (((j >> (k - 1)) & 1) == 1) {
                    dp[i][j] = std::min(dp[i][j], tickets[i][k] + dp[k][j ^ (1 << (k - 1))]);
                }
            }
        }
    }
    return dp[0][v-1];
}

int main() {
    map<int, vector<int>> tickets;
    tickets[0] = {0, 2, 6, 5};
    tickets[1] = {2, 0, 4, 4};
    tickets[2] = {6, 4, 0, 2};
    tickets[3] = {5, 4, 2, 0};

    cout << TravelingSalesMan(tickets) << endl;
    return 0;
}
