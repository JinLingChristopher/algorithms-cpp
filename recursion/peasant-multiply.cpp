#include<iostream>
using namespace std;

int peasant_multiply(int x, int y) {
    if (x == 0) {
        return 0;
    } else {
        int _x = x / 2;
        int _y = y * 2;
        int prod = peasant_multiply(_x, _y);
        if (x % 2 == 1) {
            prod += y;
        }
        return prod;
    }
}

int main() {
    int a = 3, b = 4;
    cout << "3 x 4 = " << peasant_multiply(a, b) << endl;

    a = 4; 
    b = 3;
    cout << "4 x 3 = " << peasant_multiply(a, b) << endl;

    a = 0;
    b = 10;
    cout << "0 x 10 = " << peasant_multiply(a, b) << endl;

    return 0;
}