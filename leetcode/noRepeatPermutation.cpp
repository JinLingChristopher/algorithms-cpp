//
// Created by Edison King on 2020/3/7.
//
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

void solver(const string& s, set<string>& result, vector<bool>& marked, string curr) {
    if (curr.size() == s.size()) {
        result.insert(curr);
        return;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (!marked[i]) {
            marked[i] = true;
            solver(s, result, marked, curr + s[i]);
            marked[i] = false;
        }
    }
}

vector<string> permutation(const string& s) {
    set<string> result;
    vector<bool> marked(s.size(), false);
    solver(s, result, marked, "");
    return vector<string>(result.begin(), result.end());
}

void solver(const string& s, vector<string>& result, vector<bool>& marked, string curr) {
    if (curr.size() == s.size()) {
        result.push_back(curr);
        return;
    }
    char last = ' ';
    for (int i = 0; i < s.size(); ++i) {
        if (!marked[i] && s[i] != last) {
            marked[i] = true;
            solver(s, result, marked, curr + s[i]);
            last = s[i];
            marked[i] = false;
        }
    }
}

vector<string> noRepeatPermutation(string s) {
    std::sort(s.begin(), s.end());
    vector<string> result;
    vector<bool> marked(s.size(), false);
    solver(s, result, marked, "");

    return result;
}


int main() {
    auto r2 = noRepeatPermutation("ppe");
    for (const auto& item: r2) {
        cout << item << endl;
    }
    cout << endl;

    return 0;
}
