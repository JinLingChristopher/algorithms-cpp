#include <string>
#include <iostream>
using namespace std;

int edit_distance(const string& str1, const string& str2) {
    int n = str1.size();
    int m = str2.size();

    int table[n+1][m+1];
    for (int i = 0; i < n; ++i) {
        table[i][0] = i;
    }
    for (int i = 0; i < m; ++i) {
        table[0][i] = i;
    }

    for (int i = 0; i < m + 1; ++i) {
        table[0][i] = i;
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            int a = i - 1, b = j - 1;
            int min = std::min(table[i][j-1] + 1, table[i - 1][j] + 1);
            min = std::min(min, table[i - 1][j - 1] + (str1[a] != str2[b]));
            table[i][j] = min;
        }
    }

    int ret = table[n][m];
    return ret;
}

int main() {
    const string str1("intention");
    const string str2("execution");

    int dist = edit_distance(str1, str2);
    cout << dist << endl;

    return 0;
}