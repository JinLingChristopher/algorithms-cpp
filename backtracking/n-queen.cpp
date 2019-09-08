#include <iostream>
#include <vector>

using namespace std;


void place_queen(int* queen, int n, int r, int* count) {
    if (r == n) {
        *count += 1;
        for (int i = 0; i < n; ++i) {
            cout << queen[i] << " ";
        }
        cout << endl;
    }
    for (int j = 0; j < n; j++) {  
        int legal = 1;  // 每一行的每个位置都可能是合法的
        for (int i = 0; i < r; ++i) { // 查看先前行的位置，如果在同一列，斜线上，则非法，若合法则放置。
            if ((queen[i] == j) || (queen[i] == j + r - i) || (queen[i] == j - r + i)) {
                legal = 0;
            }
        }
        if (legal) {
            queen[r] = j;
            place_queen(queen, n, r + 1, count);
        }
    }
}

int main() {
    int n = 4;
    int queen[4];
    int count = 0;
    place_queen(queen, n, 0, &count);
    cout << "for n = " << n << " there is total " << count << " solutions." << endl;

    return 0;
}