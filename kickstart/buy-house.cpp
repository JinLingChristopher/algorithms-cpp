#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, b;
        cin >> n >> b;
        vector<int> houses(n, 0);
        for (int j = 0; j < n; ++j) {
            cin >> houses[j];
        }
        sort(houses.begin(), houses.end());
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (houses[j] <= b) {
                ans += 1;
                b -= houses[j];
            }
        }
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }


    return 0;
}
