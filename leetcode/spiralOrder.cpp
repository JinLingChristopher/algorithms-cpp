#include <vector>
#include <iostream>

using namespace std;

vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    int size = rows * cols;
    vector<int> result(size, 0);
    int l = 0, r = cols - 1, t = 0, b = rows - 1;

    int curr = 0;
    while (curr != size) {
        for (int i = l; i <= r; ++i) {
            result[curr++] = matrix[t][i];
        }
        if (++t > b) {
            break;
        }
        for (int i = t; i <= b; ++i) {
            result[curr] = matrix[i][r];
            curr++;
        }
        if (--r < l) {
            break;
        }
        for (int i = r; i >= l; --i) {
            result[curr] = matrix[b][i];
            curr++;
        }
        if (--b < t) {
            break;
        }
        for (int i = b; i >= t; --i) {
            result[curr] = matrix[i][l];
            curr++;
        }
        if (++l > r) {
            break;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto result = spiralOrder(matrix);

    for (auto item: result) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
