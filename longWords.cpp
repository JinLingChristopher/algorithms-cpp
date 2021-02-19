//
// Created by Edison King on 2020/3/30.
//
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        if (s.size() <= 10) {
            cout << s << endl;
        } else {
            cout <<s[0] << s.size()-2 << s.back() << endl;
        }
    }
    return 0;
}
