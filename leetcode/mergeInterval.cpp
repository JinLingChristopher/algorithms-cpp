//
// Created by Edison King on 2020/3/14.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    if (intervals.size() == 0) {
        return result;
    }
    std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
       return a[0] < b[0];
    });

    int lo = intervals[0][0];
    int hi = intervals[0][1];
    for (int i = 0; i < intervals.size(); ++i) {
        int a = intervals[i][0];
        int b = intervals[i][1];
        if (hi >= b) {
            continue;
        } else if (hi < a) {
            result.push_back(vector<int>{lo, hi});
            lo = a;
            hi = b;
        } else if (hi >= a) {
            hi = b;
        }
    }
    result.push_back(vector<int>{lo, hi});
    return result;
}

int main() {
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto result = merge(intervals);
    for (const auto& item: result) {
        for (const auto& t : item) {
            cout << t << " ";
        }
        cout << "---";
    }
    cout << endl;

    intervals = {{1, 4}, {4, 5}};
    result = merge(intervals);
    for (const auto& item: result) {
        for (const auto& t : item) {
            cout << t << " ";
        }
        cout << "---";
    }
    cout << endl;

    intervals = {{1, 4}, {0, 4}};
    result = merge(intervals);
    for (const auto& item: result) {
        for (const auto& t : item) {
            cout << t << " ";
        }
        cout << "---";
    }
    cout << endl;

    intervals = {{1, 4}, {2, 3}};
    result = merge(intervals);
    for (const auto& item: result) {
        for (const auto& t : item) {
            cout << t << " ";
        }
        cout << "---";
    }
    cout << endl;

    return 0;
}
