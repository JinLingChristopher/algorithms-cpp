#include <iostream>
#include <vector>

using namespace std;

int expand(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    return right - left - 1;
}

string longestPalindrome(const string& s) {
    int n = s.size();
    if (n <= 1) {
        return s;
    }
    int start, end, maxlen;
    start = end = maxlen = 0;
    for (int i = 0; i < n; ++i) {
        int l1 = expand(s, i, i);
        int l2 = expand(s, i, i + 1);
        maxlen = std::max(std::max(l1, l2), maxlen);
        if (maxlen > end - start + 1) {
            start = i - (maxlen - 1) / 2;
            end = i + maxlen / 2;
        }
    }
    return s.substr(start, maxlen);
}

int main() {
    string s{"ababd"};
    auto result = longestPalindrome(s);
    cout << result << endl;
    return 0;
}
