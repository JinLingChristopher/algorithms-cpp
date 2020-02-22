//
// Created by 金灵 on 2020/2/22.
//

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int maxProfit(const vector<int>& prices) {
    int now = std::numeric_limits<int>::max();
    int result = 0;

    for (int i = 0; i < prices.size(); ++i) {
        now = std::min(now, prices[i]);
        result = std::max(result, prices[i] - now);
    }

    return result;
}


int main() {
    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;

    return 0;
}