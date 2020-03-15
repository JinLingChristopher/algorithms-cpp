//
// Created by Edison King on 2020/3/7.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxAliveYear(vector<int>& birth, vector<int>& death) {
    int n = birth.size();
    vector<int> hist(1000, 0);
    const int offset = 1900;
    for (int i = 0; i < n; ++i) {
        int lo = birth[i] - offset;
        int hi = death[i] - offset;
        for (int j = lo; j <= hi; ++j) {
            hist[j] += 1;
        }
    }
    auto p = std::max_element(hist.begin(), hist.end());
    return std::distance(hist.begin(), p) + offset;
}



int main() {

    vector<int> a{1900, 1901, 1950};
    vector<int> b{1948, 1951, 2000};

    cout << maxAliveYear(a, b) << endl;

    return 0;
}
