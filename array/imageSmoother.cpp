#include <iostream>
#include <vector>

using namespace std;
    
vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    int rows = M.size(), cols = M[0].size();
    vector<vector<int>> result(rows, vector<int>(cols, 0));
    
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int count = 0;
            for (int i = r - 1; i <= r + 1; ++i) {
                for (int j = c - 1; j <= c + 1; ++j) {
                    if ((0 <= i && i < rows) && (0 <= j && j < cols)) {
                        result[r][c] += M[i][j];
                        count += 1;
                    }
                }
            }
            result[r][c] /= count;
        }
    }
    
    return result;
}

int main() {
    vector<vector<int>> image(3, vector<int>{1, 1, 1});
    image[1][1] = 0;

    auto result = imageSmoother(image);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}