//
// Created by Edison King on 2020/3/15.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

vector<string> split(const string& str) {
    vector<string> result;
    string substr;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            if (!substr.empty()) {
                result.push_back(substr);
                substr.clear();
            }
        } else {
            substr.push_back(str[i]);
        }
    }
    if (!substr.empty()) {
        result.push_back(substr);
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    map<string, vector<string>> table;
    string str;
    for (int i = 0; i < N; ++i){
        cin >> noskipws >> str;
        auto result = split(str);
        for (const auto& item: result) {
            cout << item << " ";
        }
        cout << endl;
    }
//    for (auto iter = table.begin(); iter != table.end(); ++iter) {
//        auto key = iter->first;
//        auto value = iter->second;
//        cout << key << " ";
//        for (int i = 0; i < value.size(); ++i) {
//            cout << value[i];
//            if (i == value.size() - 1) {
//                cout << endl;
//            } else {
//                cout << " ";
//            }
//        }
//    }
    return 0;
}
