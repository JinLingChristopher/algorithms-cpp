#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool backtrace(const vector<vector<char>>& board, int row, int col, vector<vector<bool>>& marked, const string& word, int idx, const vector<vector<int>>& direction) {
    if (idx == word.size()) {
        return true;
    }
    for (const auto& xy : direction) {
        int curr_row = row + xy[0];
        int curr_col = col + xy[1];

        if (curr_row >= 0 && curr_row < board.size() && curr_col >= 0 && curr_col < board[0].size() && board[curr_row][curr_col] == word[idx]) {
            if (!marked[curr_row][curr_col]) {
                marked[curr_row][curr_col] = true;
                if (backtrace(board, curr_row, curr_col, marked, word, idx + 1, direction)) {
                    return true;
                } else {
                    marked[curr_row][curr_col] = false;
                }
            }
        }
    }
    return false;
}

bool wordSearch(vector<vector<char>>& board, const string& word) {
    int rows = board.size();
    if (rows == 0) {
        return false;
    }
    int cols = board[0].size();
    vector<vector<int>> direction{ { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    vector<vector<bool>> marked(rows, vector<bool>(cols, false));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == word[0]) {
                marked[i][j] = true;
                if (backtrace(board, i, j, marked, word, 1, direction)) {
                    return true;
                } else {
                    marked[i][j] = false;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board{ { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } };
    cout << wordSearch(board, "ABCCED") << endl;
    cout << wordSearch(board, "SEE") << endl;
    cout << wordSearch(board, "ABCB") << endl;
    return 0;
}
