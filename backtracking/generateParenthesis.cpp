#include <vector>
#include <string>
#include <iostream>

using namespace std;

void helper(int n, vector<string>& result, string current, int left, int right) {
    if (right == n) {
        result.push_back(current);
        return;
    }
    if (right < left) {
        if (left < n) {
            helper(n, result, current + '(', left + 1, right);
        }
        helper(n, result, current + ')', left, right+1);
    } else {
        helper(n, result, current + '(', left+1, right);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    helper(n, result, "", 0, 0);

    return result;
}

int main() {
    int n = 4;
    auto result = generateParenthesis(n);
    for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
        cout << *iter << endl;
    }

    return 0;
}