//
// Created by Edison King on 2020/3/9.
//
#include <iostream>

using namespace std;

int multiply(int A, int B) {
    if (!A || !B) {
        return 0;
    }
    if (A == 1) {
        return B;
    }
    if (B == 1) {
        return A;
    }
    if (B % 2) {
        return multiply(A << 1, B >> 1) + A;
    }
    return multiply(A << 1, B >> 1);
}

int main() {

    cout << multiply(1, 10) << endl;
    cout << multiply(4, 3) << endl;
    cout << multiply(3, 4) << endl;
    cout << multiply(1, 0) << endl;
    cout << multiply(1, 1) << endl;
    cout << multiply(3, 3) << endl;

    return 0;
}
