//
// Created by Edison King on 2020/3/14.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;


void printVector(const vector<int>& nums) {
    for (const auto& item: nums) {
        cout << item << " ";
    }
    cout << endl;
}

bool solver(vector<int>& counts, int start) {
    if (std::accumulate(counts.begin(), counts.end(), 0) == 0) {
        return true;
    }
    if (counts[start] == 0) {
        return solver(counts, start + 1);
    }
    if (counts[start] == 3) {
        counts[start] -= 3;
        if (solver(counts, start + (counts[start] != 0))) {
            return true;
        }
        counts[start] += 3;
    }
    if (counts[start] >= 1 && counts[start + 1] >= 1 && counts[start + 2] >= 1) {
        for (int i = 0; i < 3; ++i) {
            counts[start +i] -= 1;
        }
        if (solver(counts, start)) {
            return true;
        }
        for (int i = 0; i < 3; ++i) {
            counts[start +i] += 1;
        }
    }
    return false;
}

bool canHu(vector<int> counts) {
    for (int i = 1; i < counts.size(); ++i) {
        if (counts[i] >= 2) {
            counts[i] -= 2;
            if (solver(counts, 1)) {
                return true;
            }
            counts[i] += 2;
        }
    }
    return false;
}

vector<int> majong(const vector<int>& nums) {
    vector<int> result;
    vector<int> counts(10, 0);
    for (const auto& item: nums) {
        counts[item] += 1;
    }
    for (int i = 1; i < 10; ++i) {
        if (counts[i] < 4) {
            counts[i] += 1;
            if (canHu(counts)) {
                result.push_back(i);
            }
            counts[i] -= 1;
        }
    }
    if (result.size() == 0) {
        result.push_back(0);
    }
    return result;
}

int main() {

    vector<int> nums = {1, 1, 1, 1, 2, 2, 3, 3, 5, 6, 7, 8, 9};
    auto result = majong(nums);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    nums = {1, 1, 1, 2, 2, 2, 3, 3, 3, 5, 7, 7, 9};
    result = majong(nums);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    nums = {3, 3, 3, 4, 4, 4, 6, 6, 6, 8, 8, 9, 9};
    result = majong(nums);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    nums = {1, 1, 1, 2, 2, 2, 5, 5, 5, 6, 6, 6, 9};
    result = majong(nums);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
