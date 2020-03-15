//
// Created by Edison King on 2020/3/7.
//
#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int> record, int n, int r, vector<vector<string>>& solutions) {
    if (r == n) {
        vector<string> sol;
        for (int i = 0; i < n; i++) {
            sol.push_back(string(n, '.'));
        }
        for (int i = 0; i < n; i++) {
            sol[i][record[i]] = 'Q';
        }
        solutions.push_back(sol);
    }
    for (int j = 0; j < n; ++j) {
        bool legal = true;
        for (int i = 0; i < r; i++) {
            if ((record[i] == j) || (record[i] == j + r - i) || (record[i] == j - r + i)) {
                legal = false;
            }
        }
        if (legal) {
            record.push_back(j);
            helper(record, n, r+1, solutions);
            record.pop_back();
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<int> record;
    vector<vector<string>> res;
    helper(record, n, 0, res);

    return res;
}

int main() {

    auto result = solveNQueens(11);
    cout << "There are total " << result.size() << " solutions" << endl;
    for (const auto& sol : result) {
        for (const auto& line: sol) {
            cout << line << endl;
        }
        cout << "---------" << endl;
    }

    return 0;
}
