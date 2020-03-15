#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <limits>

using namespace std;

const vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void findOut(const vector<vector<int>>& grid, int a, int b, int& r, int& c) {
    int target = grid[a][b];
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == target) {
                if (i == r && j == c) {
                    continue;
                }
                r = i;
                c = j;
                return;
            }
        }
    }
}

void dfs(const vector<vector<int>>& grid, vector<vector<bool>>& marked, int r, int c, int& result, int count) {
    int rows = grid.size(), cols = grid[0].size();
    if (grid[r][c] == -3) {
        if (count < result) {
            result = count;
        }
        return;
    }
    if (grid[r][c] > 0) {
        int a = 0, b = 0;
        findOut(grid, r, c, a, b);
        if (!marked[a][b]) {
            marked[r][c] = true;
            dfs(grid, marked, a, b, result, count + 1);
            marked[r][c] = false;
        }
    }
    for (const auto& dir: directions) {
        int a = r + dir[0];
        int b = c + dir[1];
        if (a >= 0 && a < rows && b >= 0 && b < cols) {
            if (grid[a][b] == -1) {
                continue;
            }
            if (!marked[a][b]) {
                marked[a][b] = true;
                dfs(grid, marked, a, b, result, count + 1);
                marked[a][b] = false;
            }
        }
    }
}

int solver(const vector<vector<int>>& grid, const vector<int>& start) {
    int result = std::numeric_limits<int>::max();
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<bool>> marked(rows, vector<bool>(cols, false));
    marked[start[0]][start[1]] = true;
    dfs(grid, marked, start[0], start[1], result, 0);

    return result;
}

int main() {
    int width, height;
    cin >> width >> height;
    vector<vector<int>> grid(height, vector<int>(width, 0));
    vector<int> start(2, 0);
    vector<int> end(2, 0);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == -2) {
                start = {i, j};
            }
        }
    }
    cout << solver(grid, start) << endl;
    return 0;
}
