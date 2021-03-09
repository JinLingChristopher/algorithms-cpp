//
// Created by Edison King on 2020/2/29.
//

#include <iostream>
#include <cmath>

using namespace std;


int findNthDigit(int n) {
    long base = 9, digits = 1;
    while (n > base * digits){
        n -= base * digits;
        base *= 10;
        digits += 1;
    }

    int idx = n % digits;
    if (idx == 0){
        idx = digits;
    }
    long number = std::pow(10, digits - 1);
    number += n / digits - 1;
    if (idx != digits) {
        number += 1;
    }

    for (int i=idx;i<digits;i++) {
        number /= 10;
    }
    return number % 10;
}

int main() {
    cout << findNthDigit(3) << endl;
    cout << findNthDigit(10) << endl;
    cout << findNthDigit(11) << endl;
    cout << findNthDigit(35673) << endl;

    return 0;
}