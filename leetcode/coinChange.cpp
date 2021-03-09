//
// Created by Edison King on 2020/3/15.
//
#include <iostream>
#include <vector>

using namespace std;

int minCoinChange(int n) {
    int result = 0;
    int amount = 1024 - n;
    if (amount == 0) {
        return result;
    }
    vector<int> coins{1, 4, 16, 64};
    int idx = coins.size() - 1;
    while (amount != 0) {
        if (amount >= coins[idx]) {
            amount -= coins[idx];
            result += 1;
        } else if (idx > 0){
            idx -= 1;
        }
    }
    return result;
}

int main() {

    int n = 200;
    cout << minCoinChange(200) << endl;

    return 0;
}
