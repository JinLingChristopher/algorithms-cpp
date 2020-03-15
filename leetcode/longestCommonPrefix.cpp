//
// Created by Edison King on 2020/3/12.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    std::sort(strs.begin(), strs.end(), [](const string& a, const string& b) -> bool {
        return a.size() < b.size();
    });
    string result;
    for (int j = 0; j < strs[0].size(); ++j) {
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i][j] != strs[0][j]) {
                return result;
            }
        }
        result += strs[0][j];
    }
    return result;
}

int main() {
    vector<string> strs{"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs) << endl;

    strs = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(strs) << endl;

    return 0;
}
