#include <vector>
#include <iostream>

using namespace std;

int longest_common_subsequences(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    int m = b.size();
    int table[n+1][m+1];
    for (int i = 0; i < n + 1; i++) {
        table[i][0] = 0;
    }
    for (int i = 0; i < m + 1;i++) {
        table[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (a[i-1] == b[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
            } else {
                table[i][j] = std::max(table[i-1][j], table[i][j-1]);
            }
        }
    }
    return table[n][m];
}


int main() {
    vector<int> vec1{1, 2, 3, 4, 5};
    vector<int> vec2{1, 3, 5};
    int length = longest_common_subsequences(vec1, vec2);

    cout << length << endl;

    return 0;
}