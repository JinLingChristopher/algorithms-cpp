//
// Created by Edison King on 2020/2/29.
//

#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

map<char, set<char>> buildFSM() {
    map<char, set<char>> fsm;
    fsm['#'].insert('+');
    fsm['#'].insert('-');
    fsm['#'].insert('.');
    fsm['.'].insert('\0');
    fsm[' '].insert(' ');
    fsm[' '].insert('\0');
    fsm['+'].insert('.');
    fsm['.'].insert('e');
    fsm['-'].insert('.');
    fsm['e'].insert('+');
    fsm['e'].insert('-');
    for (char a = '0'; a <= '9'; ++a) {
        fsm['#'].insert(a);
        fsm['+'].insert(a);
        fsm['-'].insert(a);
        fsm['.'].insert(a);
        fsm['e'].insert(a);
        fsm['E'].insert(a);
        fsm[a].insert('\0');
        fsm[a].insert('e');
        fsm[a].insert('E');
        fsm[a].insert('.');
        fsm[a].insert(' ');
        for (char b = '0'; b <= '9'; ++b) {
            fsm[a].insert(b);
        }
    }
    return fsm;
}

bool legalKey(map<char, set<char>>& fsm, char k) {
    if (fsm.find(k) != fsm.end()) {
        return true;
    }
    return false;
}


bool legal(map<char, set<char>>& fsm, char k, char v) {
    auto s = fsm[k];
    return s.find(v) != s.end();
}

string trim(const string& s) {
    int i = 0, j = s.size() - 1;
    while (i < s.size() && s[i] == ' ') {
        ++i;
    }
    if (i > j) {
        return "";
    }
    while (j > 0 && s[j] == ' ') {
        --j;
    }
    if (i == 0 && j == s.size() - 1) {
        return s;
    }
    return s.substr(i, j - i + 1);
}

bool isNumber(const string& s) {
    auto t = trim(s);
    if (t.size() == 0) {
        return false;
    }
    auto fsm = buildFSM();
    char k = '#';
    int dot = 0;
    int e = 0;
    int i = 0, n = t.size();
    while (i <= n) {
        char v = t[i];
        if (!legalKey(fsm, k)) {
            return false;
        }
        if (v == '.') {
            if (e) {
                return false;
            }
            dot += 1;
            if (dot > 1) {
                return false;
            }
        }
        if (legal(fsm, k, v)) {
            if (v == '.') {
                if (i == 0 && i == n - 1) {
                    return false;
                } else if (i + 1 < n && t[i+1] == 'e' && i == 0) {
                    return false;
                } else if (i == n - 1 && t[i - 1] == '-') {
                    return false;
                }
            } else if (v == 'e') {
                e += 1;
                if (e > 1) {
                    return false;
                }
            }
            k = v;
        } else {
            return false;
        }
        ++i;
    }
    return true;
}

int main() {
    cout << isNumber("-.") << endl;
    cout << isNumber("-.3e6") << endl;
    cout << isNumber(".1") << endl;
    cout << isNumber("3.") << endl;
    cout << isNumber("0..") << endl;
    cout << isNumber(".") << endl;
    cout << isNumber("   ") << endl;
    cout << isNumber(" 1") << endl;
    cout << isNumber(" .1") << endl;
    cout << isNumber("") << endl;
    cout << isNumber(" ") << endl;
    cout << isNumber("1 ") << endl;
    cout << isNumber("-1E-16") << endl;
    cout << isNumber("+100") << endl;
    cout << isNumber("5e2") << endl;
    cout << isNumber("-123") << endl;
    cout << isNumber("3.1416") << endl;
    cout << isNumber("0123") << endl;
    cout << isNumber("12e") << endl;
    cout << isNumber("1a3.14") << endl;
    cout << isNumber("1.2.3") << endl;
    cout << isNumber("+-5") << endl;
    cout << isNumber("12e+5.4") << endl;
}

