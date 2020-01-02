#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> findAnagrams(const string &s, const string &p) {
    vector<int> result;
    int n = s.size(), m = p.size();
    if (n < m || m == 0) {
        return result;
    }
    unordered_map<char, int> table;
    for (auto c : p) {
        table[c]++;
    }
    int i = 0, j = 0;
    while (j < n) {
        if (!table.count(s[j]) || !table[s[j]]) {
            while (i < j && s[i] != s[j]) {
                table[s[i++]]++;
            }
            i++;
        } else {
            table[s[j]]--;
        }
        if (table.count(s[j]) && !table[s[j]] && (m == (j - i + 1))) {
            result.push_back(i);
        }
        j++;
    }
    return result;
}

int main() {
    string s{"cbaebabacd"}, p{"abc"};
    auto result = findAnagrams(s, p);
    for (auto item : result) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
