#include <vector>
#include <iostream>

using namespace std;

void solver(const vector<vector<char>>& grid, vector<vector<bool>>& marked, int row, int col) {
    const vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (const auto& dir: directions) {
        int a = row + dir[0];
        int b = col + dir[1];
        if (a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size()) {
            if (grid[a][b] == '1' && !marked[a][b]) {
                marked[a][b] = true;
                solver(grid, marked, a, b);
            }
        }
    }
}

int numIslands(const vector<vector<char>>& grid) {
    int rows = grid.size();
    if (rows == 0) {
        return 0;
    }
    int cols = grid[0].size();
    if (cols == 0) {
        return 0;
    }
    vector<vector<bool>> marked(rows, vector<bool>(cols, false));
    int result = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '1' && !marked[i][j]) {
                result += 1;
                marked[i][j] = true;
                solver(grid, marked, i, j);
            }
        }
    }
    return result;
}

int main() {
    vector<vector<char>> island{{'1', '1', '1', '1', '0'},
                                {'1', '1', '0', '1', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '0', '0', '0'}};
    cout << numIslands(island) << endl;

    vector<vector<char>> island2 {{'1', '1', '0', '0', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '1', '0', '0'},
                                  {'0', '0', '0', '1', '1'}};
    cout << numIslands(island2) << endl;

    return 0;
}
