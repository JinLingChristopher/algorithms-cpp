//
// Created by Edison King on 2020/2/26.
//

#include <iostream>
#include <vector>

using namespace std;

void solver(const string& s, int&result, int start) {
    if (start == s.size()) {
        result += 1;
        return;
    }
    solver(s, result, start + 1);

    if (s[start] != '0' && start + 2 <= s.size()) {
        int t = stoi(s.substr(start, 2));
        if (t <= 25) {
            solver(s, result, start + 2);
        }
    }
}

int translateNum(int n) {
    string s = to_string(n);
    int result = 0;
    solver(s, result, 0);
    return result;
}

int main() {
    int num = 1225800;
    cout << translateNum(num) << endl;

    return 0;
}