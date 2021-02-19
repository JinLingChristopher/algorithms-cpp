#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& line : matrix) {
        for (const auto& x : line) {
            cout << x << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n <= 1) {
        return intervals;
    }

    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

    vector<vector<int>> result;
    for (const auto& item : intervals) {
        if (!result.size() || item[0] > result.back()[1]) {
            result.push_back(item);
        } else if (result.back()[1] >= item[1]) {
            continue;
        } else if (result.back()[1] >= item[0]) {
            result.back()[1] = item[1];
        }
    }

    return result;
}

int main() {
    vector<vector<int>> intervals2{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> intervals1{{1, 4}, {4, 5}};
    vector<vector<int>> intervals3{{1, 4}, {2, 3}};

    auto result1 = merge(intervals1);
    auto result2 = merge(intervals2);

    printMatrix(result1);
    printMatrix(result2);
    printMatrix(merge(intervals3));

    return 0;
}
