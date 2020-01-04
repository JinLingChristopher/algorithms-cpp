#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void eat(vector<vector<int>> &breads) {
    int idx = -1;
    vector<int> best = breads[0];
    for (int i = 0; i < breads.size(); ++i) {
        if (breads[i][0] > best[0] && breads[i][0] > 0 &&
            breads[i][1] > best[1]) {
            best = breads[i];
            idx = i;
        }
    }
    if (idx != -1) {
        breads[idx][0] = -1;
        breads[idx][1] = -1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> breads;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        breads.push_back({a, b});
    }
    while (true) {
        for (int i = 0; i < 2; ++i) {
            eat(breads);
        }
        for (int i = 0; i < n; ++i) {
            if (breads[i][0] > 0) {
                breads[i][0] -= breads[i][1];
            }
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (breads[i][0] > 0) {
                count += 1;
            }
        }
        if (count < m) {
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (breads[i][0] == -1 && breads[i][1] == -1) {
            cout << -1 << endl;
        } else if (breads[i][0] > 0) {
            cout << breads[i][0] << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
