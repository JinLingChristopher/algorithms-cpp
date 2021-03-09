//
// Created by Edison King on 2020/2/26.
//

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int digitSum(int n) {
    int result = 0;
    while (n) {
        result += n % 10;
        n = n / 10;
    }
    return result;
}

int movingCount(int m, int n, int k) {
    int result = 0;
    int row = 0, col = 0;
    vector<vector<int>> directions {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<vector<bool>> marked(m, vector<bool>(n, false));
    stack<int> rst, cst;
    rst.push(0);
    cst.push(0);
    while (!rst.empty()) {
        int row = rst.top();
        rst.pop();
        int col = cst.top();
        cst.pop();
        if (!marked[row][col] && digitSum(row) + digitSum(col) <= k) {
            marked[row][col] = true;
            result += 1;
            for (const auto& dire : directions) {
                int r = row + dire[0];
                int c = col + dire[1];
                if (r >= 0 && r < m && c >= 0 && c < n && !marked[r][c]) {
                    rst.push(r);
                    cst.push(c);
                }
            }
        }
    }
    return result;
}


int main() {
    cout << movingCount(2, 3, 1) << endl;
    cout << movingCount(3, 1, 0) << endl;
    cout << movingCount(16, 8, 4) << endl;
    return 0;
}