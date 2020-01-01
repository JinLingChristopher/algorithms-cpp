#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(const string& s) {
    int result = 0;
    int lo = 0, hi = 0;

    while (hi < s.size()) {
        char c = s[hi];
        bool flag = true;
        for (int j = hi - 1; j >= lo; --j) {
            if (c == s[j]) {
                result = std::max(result, hi - lo);
                lo += 1;
                flag = false;
                break;
            }
        }
        hi += flag;
    }
    result = std::max(result, hi - lo);
    return result;
}

int main() {
    string s{"bbbbb"};
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}
