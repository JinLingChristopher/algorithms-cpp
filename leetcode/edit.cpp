#include <iostream>

using namespace std;

string solver(const string& s) {
    int n = s.size();
    if (n < 3) {
        return s;
    }
    string result;
    for (int i = 0; i < n; ++i) {
        if (result.size() < 2) {
            result.push_back(s[i]);
        } else {
            int t = result.size();
            if (s[i] == result[t - 1] && s[i] == result[t - 2]) {
                continue;
            } else if (s[i] == result[t - 1] && result[t - 2] == result[t- 3]) {
                continue;
            }
            result.push_back(s[i]);
        }
    }
    return result;
}

int main() {
    string a{"helloo"};
    string b{"hellloo"};
    string c{"wooooooow"};

    cout << solver(a) << endl;
    cout << solver(b) << endl;
    cout << solver(c) << endl;
    cout << solver({"lllooo111ffddffffgggddss"});

    return 0;
}
