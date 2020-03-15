//
// Created by Edison King on 2020/3/8.
//

#include <vector>
#include <iostream>
using namespace std;

void solver(int m, int n, int& result, vector<vector<bool>>& marked, int row, int col, int count) {
    if (count >= m && count <= n) {
        result += 1;
        if (count == n) {
            return;
        }
    }

    for (int i = 0 ; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == row && (j == col || abs(col - j) > 1)) {
                continue;
            }
            if (j == col && abs(row - i) > 1) {
                continue;
            }
            if (i + row == j + col && i + row == 2) {
                continue;
            }
            if (!marked[i][j]) {
                marked[i][j] = true;
                solver(m, n, result, marked, i, j, count + 1);
                marked[i][j] = false;
            }
        }
    }
}

int unlockKeyBoard(int m, int n) {
    vector<vector<bool>> marked(3, vector<bool>(3, false));
    int result = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!marked[i][j]) {
                marked[i][j] = true;
                solver(m, n, result, marked, i, j, 1);
                marked[i][j] = false;
            }
        }
    }
    return result;
}

int main() {
    cout << unlockKeyBoard(1, 9) << endl;
    cout << unlockKeyBoard(9, 9) << endl;
    cout << unlockKeyBoard(2, 2) << endl;
    cout << unlockKeyBoard(1, 2) << endl;
    cout << unlockKeyBoard(1, 3) << endl;
    cout << unlockKeyBoard(1, 1) << endl;

    return 0;
}
