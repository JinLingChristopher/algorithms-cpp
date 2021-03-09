//
// Created by Edison King on 2020/3/4.
//

#include <iostream>
#include <string>
#include <limits>

using namespace std;


string& trim(string& s) {
    if (s.empty()) {
        return s;
    }
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

bool isLegalFirst(const char& c) {
    return c == '+' || c == '-' || (c >= '0' && c <= '9');
}

int strToInt(const string& str) {
    auto& s = trim(const_cast<string&>(str));
    if (!isLegalFirst(s[0])) {
        return 0;
    }
    int result = 0, base = 10;
    bool isNegative = s[0] == '-';
    int i = 0 + s[0] == '-' || s[0] == '+';
    auto threshold = std::numeric_limits<int>::max() / base;
    bool overflow = false;
    while (i < s.size()) {
        if (!(s[i] >= '0' && s[i] <= '9')) {
            break;
        }
        overflow = result > threshold;
        if (overflow) {
            break;
        }
        result *= base;
        int digit = s[i] - '0';
        overflow = (std::numeric_limits<int>::max() - result < digit);
        if (overflow) {
            break;
        }
        result += digit;
        ++i;
    }

    if (overflow) {
        if (isNegative) {
            return std::numeric_limits<int>::min();
        }
        return std::numeric_limits<int>::max();
    }
    if (isNegative) {
        result = 0 - result;
    }
    return result;
}

int main() {
    cout << strToInt("2147483648") << endl;
    cout << strToInt("2147483646") << endl;
    cout << strToInt("4193  with words") << endl;
    cout << strToInt("  -0012a42") << endl;
    cout << strToInt("  0000000000012345678") << endl;
    cout << strToInt("   ") << endl;
    cout << strToInt("3.1415") << endl;
    cout << strToInt("-91283472332") << endl;
    cout << strToInt("42") << endl;
    cout << strToInt("    -42") << endl;
    cout << strToInt("  words with 987") << endl;
    cout << strToInt("") << endl;
    return 0;
}