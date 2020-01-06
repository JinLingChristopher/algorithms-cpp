#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &image) {
    int n = image.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            swap(image[i][j], image[n - 1 - j][n - 1 - i]);
        }
    }
    std::reverse(image.begin(), image.end());
}

int main() {
    vector<vector<int>> image{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rotate(image);
    for (int i = 0; i < image.size(); ++i) {
        for (int j = 0; j < image[i].size(); ++j) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
