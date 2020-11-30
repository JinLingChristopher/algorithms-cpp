#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(const vector<int>& vec) {
    for (const auto& item : vec) {
        cout << item << " ";
    }
    cout << endl;
}

void adjustIndex(int& x, int thresh) {
    if (x < 0) {
        x = 0;
    } else if (x == thresh) {
        x = thresh - 1;
    }
}

vector<int> findDiagonalOrder(const vector<vector<int>>& matrix) {
    vector<int> result;
    int rows = matrix.size();
    if (rows == 0) {
        return result;
    }

    int cols = matrix[0].size();
    int i = 0, j = 0;
    while (i < rows && j < cols) {
        int a = i, b = j;
        vector<int> t;
        while (a < rows && b >= 0) {
            t.push_back(matrix[a][b]);
            a += 1;
            b -= 1;
        }
        if ((i + j) % 2 == 1) {
            std::reverse(t.begin(), t.end());
        }
        result.insert(result.end(), t.begin(), t.end());
        if (j < (cols - 1)) {
            j += 1;
        } else {
            i += 1;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> matrix1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto result = findDiagonalOrder(matrix1);
    printVector(result);

    return 0;
}
