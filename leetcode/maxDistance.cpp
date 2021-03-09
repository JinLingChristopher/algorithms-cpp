//
// Created by Edison King on 2020/3/29.
//
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


int maxDistance(vector<vector<int>>& grid) {
    static const vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<int> xs, ys;
    int rows = grid.size(), cols = grid[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j]) {
                xs.push(i);
                ys.push(j);
            }
        }
    }

    bool hasOcean = false;
    int r = -1, c = -1;
    while (!xs.empty()) {
        r = xs.front();
        c = ys.front();
        xs.pop();
        ys.pop();
        for (const auto& dir: directions) {
            int a = r + dir[0];
            int b = c + dir[1];
            if (a >= 0 && a < rows && b >= 0 && b < cols && grid[a][b] == 0) {
                grid[a][b] = grid[r][c] + 1;
                hasOcean = true;
                xs.push(a);
                ys.push(b);
            }
        }
    }
    if (r == -1 || !hasOcean) {
        return -1;
    }
    return grid[r][c] - 1;
}

int main() {
    vector<vector<int>> grid{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    cout << maxDistance(grid) << endl;

    return 0;
}
