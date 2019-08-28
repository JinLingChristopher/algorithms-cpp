#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void helper(const string& digits, const map<char, string>& table, vector<string>& result, string& current) {
    if (current.size() == digits.size()) {
        result.push_back(current);
        return;
    }
    int i = current.size();
    char c = digits[i];
    const string& s = table.at(c);
    for (int j = 0; j < s.size(); ++j) {
        current.push_back(s[j]);
        helper(digits, table, result, current);
        current.pop_back();
    }

    // for (int i = current.size(); i < digits.size(); ++i) {
    //     char c = digits[i];
    //     const string& s = table.at(c);
    //     for (int j = 0; j < s.size(); ++j) {
    //         current.push_back(s[j]);
    //         helper(digits, table, result, current);
    //         current.pop_back();
    //     }
    // }
}

map<char, string> generate_table() {
    map<char, string> mapper;
    mapper['2'] = "abc";
    mapper['3'] = "def";
    mapper['4'] = "ghi";
    mapper['5'] = "jkl";
    mapper['6'] = "mno";
    mapper['7'] = "pqrs";
    mapper['8'] = "tuv";
    mapper['9'] = "wxyz";
    
    return mapper;
}

vector<string> letterCombinations(string digits) {
    auto table = generate_table();
    vector<string> result;
    string current;
    helper(digits, table, result, current);

    return result;
}

int main() {
    string input("234");
    auto result = letterCombinations(input);

    for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
        cout << *iter << endl;
    }

    return 0;
}