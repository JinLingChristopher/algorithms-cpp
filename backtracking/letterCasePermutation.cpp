#include <vector>
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

void helper(string s, vector<string>& result, string current) {
    if (current.size() == s.size()) {
        result.push_back(current);
        return;
    }
    int i = current.size();
    char c = s[i];
    if (std::isdigit(c)) {
        current.push_back(c);
        helper(s, result, current);
        current.pop_back();
    } else {
        current.push_back(std::tolower(c));
        helper(s, result, current);
        current.pop_back();

        current.push_back(std::toupper(c));
        helper(s, result, current);
        current.pop_back();
    }
}

vector<string> letterCasePermutation(string S) {
    vector<string> ret;
    string current;
    helper(S, ret, current);

    return ret;
}

int main() {
    string S("a1b2");
    auto result = letterCasePermutation(S);
    for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
