#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string> &strs) {
    unordered_map<string, vector<string>> table;
    for (int i = 0; i < strs.size(); ++i) {
        auto key = strs[i];
        std::sort(key.begin(), key.end());
        table[key].push_back(strs[i]);
    }
    vector<vector<string>> result;
    for (auto iter = table.cbegin(); iter != table.cend(); ++iter) {
        result.push_back(iter->second);
    }
    return result;
}

int main() {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = groupAnagrams(strs);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
