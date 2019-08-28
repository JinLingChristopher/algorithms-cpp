#include <vector>
#include <string>
#include <iostream>

using namespace std;

void helper(const string& s, vector<string>& result, vector<string>& current, int idx) {
    if (current.size() == 4) {
        string ss("");
        string delimiter("");
        for (int i = 0; i < current.size(); ++i) {
            ss += delimiter;
            ss += current[i];
            delimiter = ".";
        }
        if (ss.size() == (s.size() + 3)) {
            result.push_back(ss);
        }
        return;
    }
    for (int i = 3; i > 0; --i) {
        if ((idx + i) <= s.size()) {
            string sub = s.substr(idx, i);
            if (std::stoi(sub) <= 255) {
                if (!((sub.size() != 1) && (sub[0] == '0'))) {
                    current.push_back(sub);
                    helper(s, result, current, idx+i);
                    current.pop_back();
                }
            }
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> result, current;
    if (s.size() < 4) {
        return result;
    }
    helper(s, result, current, 0);

    return result;
}

int main() {
    string input("010010");
    auto result = restoreIpAddresses(input);
    for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}