#include <vector>
#include <iostream>

using namespace std;

void revert(vector<int>& row) {
    for (int i = 0; i < row.size(); ++i) {
        row[i] = 1 - row[i];
    }
}

int explain(const vector<int>& row) {
    int result = 0;
    for (int i = 0; i < row.size(); ++i) {
        result = result * 2 + row[i];
    }

    return result;
}

int matrixScore(vector<vector<int>>& matrix) {
    // make every row, 1st element is 1
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][0] == 0) {
            revert(matrix[i]);
        }
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < cols; ++i) {
        int count = 0;
        for (int j = 0; j < rows; ++j) {
            if (matrix[j][i] == 1) {
                count += 1;
            }
        }
        if ((count * 2) < rows) {
            for (int j = 0; j < rows; ++j) {
                matrix[j][i] = 1 - matrix[j][i];
            }
        }
    }

    int result = 0;
    for (int i = 0; i < rows; ++i) {
        result += explain(matrix[i]);
    }

    return result;
}

int main() {
    vector<vector<int>> A{{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
    cout << matrixScore(A) << endl;

    return 0;
}
