//
// Created by Edison King on 2020/2/26.
//

#include <vector>
#include <iostream>

using namespace std;


bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int i = rows - 1, j = 0;
    while (i >= 0 && j < cols) {
        if (matrix[i][j] > target) {
            i -= 1;
        } else if (matrix[i][j] < target) {
            j += 1;
        } else {
            return true;
        }
    }
    return false;
}


int main() {
    vector<vector<int>> matrix{{1, 4, 7, 11, 15},
                               {2, 5, 8, 12, 19},
                               {3, 6, 9, 16, 22},
                               {10, 13, 14, 17, 24},
                               {18, 21, 23, 26, 30}};

    cout << findNumberIn2DArray(matrix, 5) << endl;
    cout << findNumberIn2DArray(matrix, 20) << endl;

    return 0;
}