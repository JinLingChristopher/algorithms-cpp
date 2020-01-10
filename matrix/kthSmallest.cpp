#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// int kthSmallest(vector<vector<int>>& matrix, int k) {
//     int left = matrix[0][0], right = matrix.back().back();
//     while (left < right) {
//         int mid = left + (right - left) / 2, cnt = 0;
//         for (int i = 0; i < matrix.size(); ++i) {
//             cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) -
//             matrix[i].begin();
//         }
//         if (cnt < k) left = mid + 1;
//         else right = mid;
//     }
//     return left;
// }

int kthSmallest(vector<vector<int>> &matrix, int k) {
    int left = matrix[0][0], right = matrix.back().back();
    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) -
                     matrix[i].begin();
        }
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {

    vector<vector<int>> matrix{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    auto result = kthSmallest(matrix, k);
    cout << result << endl;
    return 0;
}
