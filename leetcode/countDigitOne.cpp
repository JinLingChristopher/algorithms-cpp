#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// return the total count of 1 from 1 ~ n
//int countDigitOne(int n) {
//    if (n <= 0) {
//        return 0;
//    }
//    int high = n;
//    int i = 1;
//    int result = 0;
//    while (high) {
//        high = n / std::pow(10, i);
//        int temp = n / std::pow(10, i - 1);
//        int curr = temp % 10;
//        int low = n - temp * std::pow(10, i - 1);
//        if (curr > 1) {
//            result += (high + 1) * std::pow(10, i - 1);
//        } else if (curr < 1) {
//            result += high * std::pow(10, i - 1);
//        } else {
//            result += high * std::pow(10, i - 1);
//            result += low + 1;
//        }
//        ++i;
//    }
//    return result;
//}

int countDigitOne(int n) {
    int res = 0;
    for (long k = 1; k <= n; k *= 10) {
        int r = n / k;
        int m = n % k;
        res += (r + 8) / 10 * k;
        if (r % 10 == 1) {
            res += m + 1;
        }
    }
    return res;
}

int main() {
    cout << countDigitOne(123456) << endl;
    cout << countDigitOne(12) << endl;
    cout << countDigitOne(13) << endl;
    cout << countDigitOne(9) << endl;
    cout << countDigitOne(100) << endl;
    cout << countDigitOne(500) << endl;
    cout << countDigitOne(1000) << endl;
    cout << countDigitOne(1410065408) << endl;
    return 0;
}