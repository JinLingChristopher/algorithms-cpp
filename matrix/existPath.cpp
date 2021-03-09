//
// Created by Edison King on 2020/2/26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solver(const vector<vector<char>>& board, const string& word,
        vector<vector<bool>>& marked, int idx, int r, int c, const vector<vector<int>>& direction) {
    if (idx == word.size()) {
        return true;
    }

    for (const auto& dire: direction) {
        int col = c + dire[0];
        int row = r + dire[1];
        if (col >= 0 && col < board[0].size() && row >= 0 && row < board.size()) {
            if (!marked[row][col] && board[row][col] == word[idx]) {
                marked[row][col] = true;
                if (solver(board, word, marked, idx + 1, row, col, direction)) {
                    return true;
                } else {
                    marked[row][col] = false;
                }
            }
        }
    }
    return false;
}

bool existPath(vector<vector<char>>& board, const string& word) {
    int row = board.size();
    if (!row || !word.size()) {
        return false;
    }
    int col = board[0].size();
    vector<vector<int>> direction = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<vector<bool>> marked(row, vector<bool>(col, false));

    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            if (board[r][c] == word[0]) {
                marked[r][c] = true;
                if (solver(board,word, marked, 1, r, c, direction)) {
                    return true;
                }
                marked[r][c] = false;
            }
        }
    }
    return false;
}


int main() {

    vector<vector<char>> board{{'a', 'b', 'c', 'e'},
                               {'s', 'f', 'c', 's'},
                               {'a', 'd', 'e', 'e'}};
    string word{"abcced"};
    cout << existPath(board, word) << endl;
    cout << existPath(board, "abasf") << endl;

    return 0;
}