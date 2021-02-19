//
// Created by Edison King on 2020/4/2.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    unordered_map<int, string> ordered;
    for (const auto& s: strs) {
        bool flag = false;
        auto t = s;
        std::sort(t.begin(), t.end());
        for (auto iter = ordered.begin(); iter != ordered.end(); ++iter) {
            if (iter->second == t) {
                result[iter->first].push_back(s);
                flag = true;
                break;
            }
        }
        if (!flag) {
            vector<string> vec;
            vec.push_back(s);
            result.push_back(vec);
            ordered[ordered.size()] = t;
        }
    }
    return result;
}

int main() {
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};
    auto result = groupAnagrams(strs);
    for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
        for (int i = 0; i < iter->size(); ++i) {
            cout << iter->at(i) << " ";
        }
        cout << endl;
    }
    return 0;
}
