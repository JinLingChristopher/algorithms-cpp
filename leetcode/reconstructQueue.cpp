#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    vector<vector<int>> result;
    if (people.size() == 0) {
        return result;
    }
    auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
        if (lhs[0] != rhs[0]) {
            return lhs[0] > rhs[0];
        }
        return lhs[1] < rhs[1];
    };
    std::sort(people.begin(), people.end(), cmp);
    for (const auto &p : people) {
        result.insert(result.begin() + p[1], p);
    }
    return result;
}

int main() {
    vector<vector<int>> people{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    auto result = reconstructQueue(people);
    for (const auto &item : result) {
        cout << item[0] << "->" << item[1] << endl;
    }
    return 0;
}
