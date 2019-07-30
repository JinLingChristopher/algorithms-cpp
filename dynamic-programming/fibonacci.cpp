#include <iostream>
#include <vector>

using namespace std;

int fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_iterative(int n) {
    vector<int> memo{0, 1};
    for (int i = 2; i <= n; i++) {
        memo.push_back(memo[i - 1] + memo[i - 2]);
    }
    return memo[n];
}

int fibonacci_iterative2(int n) {
    int prev = 1;
    int curr = 0;
    for (int i = 1; i <= n; ++i) {
        int next = curr + prev;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {

    // vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> memo;
    int ret = fibonacci_iterative(10);
    int ret2 = fibonacci_iterative2(10);
    cout << ret << endl;
    cout << ret2 << endl;

    // for (auto iter = nums.cbegin(); iter != nums.cend(); ++iter) {
    //     cout << *iter << " : " << fibonacci(*iter, memo) << endl;
    // }

    return 0;
}