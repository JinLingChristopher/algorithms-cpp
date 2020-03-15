//
// Created by Edison King on 2020/3/9.
//
#include <vector>
#include <iostream>

using namespace std;

void solver(vector<vector<int>>& grid, int row, int col, int& result) {
    static const vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (const auto& dir: directions) {
        int a = row + dir[0];
        int b = col + dir[1];
        if (a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size()) {
            if (grid[a][b]) {
                grid[a][b] = 0;
                result += 1;
                solver(grid, a, b, result);
            }
        }
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int rows = grid.size();
    if (rows == 0) {
        return 0;
    }
    int cols = grid[0].size();
    if (cols == 0) {
        return 0;
    }
    int result = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j]) {
                grid[i][j] = 0;
                int t = 1;
                solver(grid, i, j, t);
                result = max(result, t);
            }
        }
    }
    return result;
}

int main() {

    vector<vector<int>> island{{0,0,1,0,0,0,0,1,0,0,0,0,0},
                               {0,0,0,0,0,0,0,1,1,1,0,0,0},
                               {0,1,1,0,1,0,0,0,0,0,0,0,0},
                               {0,1,0,0,1,1,0,0,1,0,1,0,0},
                               {0,1,0,0,1,1,0,0,1,1,1,0,0},
                               {0,0,0,0,0,0,0,0,0,0,1,0,0},
                               {0,0,0,0,0,0,0,1,1,1,0,0,0},
                               {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << maxAreaOfIsland(island) << endl;

    return 0;
}
