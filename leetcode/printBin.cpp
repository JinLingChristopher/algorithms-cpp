//
// Created by Edison King on 2020/4/10.
//

#include <iostream>
#include <vector>

using namespace std;


string printBin(double num) {
    if (num >= 1.0 || num < 0) {
        return "ERROR";
    }
    string result("0.");
    while (num > 0.0000001) {
        num *= 2;
        if (num >= 1) {
            result += '1';
            num -= 1;
        } else {
            result += '0';
        }
        if (result.size() > 32) {
            break;
        }
    }
    if (result.size() > 32) {
        return "ERROR";
    }
    return result;
}

int main() {
    cout << printBin(1.0) << endl;
    cout << printBin(0.625) << endl;
    cout << printBin(0.1) << endl;

    return 0;
}
