#include <string>
#include <iostream>

using namespace std;

char firstUniqChar(const string& s) {
    int arr[26] = {0};
    for (int i = 0; i < s.size(); ++i) {
        int idx = s[i] - 'a';
        arr[idx] += 1;
    }
    for (const auto& c: s) {
        int idx = c - 'a';
        if (arr[idx] == 1) {
            return c;
        }
    }
    return ' ';
}

int main() {
    string s{"loveleetcode"};
    auto result = firstUniqChar(s);
    cout << result << endl;

    return 0;
}