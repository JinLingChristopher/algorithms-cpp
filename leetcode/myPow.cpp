//
// Created by Edison King on 2020/2/29.
//


#include <iostream>

using namespace std;

double myPow(double x, int n) {
    if (x == 0) {
        return 0;
    }
    double result = 1.0;
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }
    while (n) {
        if ((n & 1) == 1) {
            result *= x;
        }
        x *= x;
        n >>= 1;
    }
    return result;
}


int main() {

    cout << myPow(0, 1) << endl;
    cout << myPow(1, 0) << endl;
    cout << myPow(0.00001, 1 << 32) << endl;


    return 0;
}