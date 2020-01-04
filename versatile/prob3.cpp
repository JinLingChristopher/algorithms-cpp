#include <iomanip>
#include <iostream>
using namespace std;

double solver(int m, int a, int r) {
    if (a >= m) {
        return 1;
    }
    if (m <= r) {
        return m / r;
    }
    return 0;
}

int main() {
    int m, a, r;
    cin >> m >> a >> r;

    double result = solver(m, a, r);
    cout << fixed << setprecision(5) << result << endl;

    return 0;
}
