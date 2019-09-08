#include<iostream>
#include<vector>

using namespace std;

void helper(const vector<vector<int>>& mat, int i, vector<bool>& marked) {
    int length = mat.size();
    auto line = mat[i];
    marked[i] = true;
    for (int col = 0; col < length; ++col) {
        if (!marked[col] && line[col] == 1) {
            marked[col] = true;
            if (col != i) {
                helper(mat, col, marked);
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& M) {
    int length = M.size();
    vector<bool> marked(length, false);
    int count = 0;

    for (int i = 0; i < length; ++i) {
        if (!marked[i]) {
            count += 1;
            helper(M, i, marked);
        }
    }
    return count;
}

int main() {
    vector<vector<int>> input{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int count = findCircleNum(input);
    cout << count << endl;

    return 0;
}