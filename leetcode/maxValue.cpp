//
// Created by 金灵 on 2020/2/19.
//

#include <iostream>
#include <vector>

using namespace std;

int maxValue(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int top = 0, left = 0;
            if (i > 0) {
                top = grid[i][j] + grid[i - 1][j];
            }
            if (j > 0) {
                left = grid[i][j] + grid[i][j - 1];
            }
            grid[i][j] = std::max(grid[i][j], std::max(top, left));
        }
    }
    return grid[rows - 1][cols - 1];
}

int main() {
    vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    auto result = maxValue(grid);
    cout << result << endl;

    return 0;
}
