//
// Created by Edison King on 2021/3/9.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    std::sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0] || (a[1] == b[1] && a[0] < b[0]);
    });

    int result = 0;
    for (int i = 1; i < points.size(); ++i) {
        int width = points[i][0] - points[i - 1][0];
        result = max(result, width);
    }

    return result;
}

int main() {

    vector<vector<int>> area1 = {{8, 7}, {9, 9}, {7, 4}, {9, 7}};
    vector<vector<int>> area2 = {{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};

    cout << maxWidthOfVerticalArea(area1) << endl;
    cout << maxWidthOfVerticalArea(area2) << endl;

    return 0;
}
