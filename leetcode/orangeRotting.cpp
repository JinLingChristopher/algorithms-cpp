//
// Created by Edison King on 2020/3/4.
//

#include <iostream>
#include <vector>

using namespace std;


int orangeRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int result = 0;
    const vector<vector<int>>& directions {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    while (true) {
        int count = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    for (const auto& dir : directions) {
                        int a = i + dir[0];
                        int b = j + dir[1];
                        if (a >= 0 && a < rows && b >= 0 && b < cols) {
                            if (grid[a][b] == 1) {
                                count += 1;
                                grid[a][b] = -1;
                            }
                        }
                    }
                }
            }
        }
        if (!count) {
            break;
        }
        result += 1;
    }
    return result;
}

int main() {

    vector<vector<int>> grid{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangeRotting(grid) << endl;

    return 0;
}