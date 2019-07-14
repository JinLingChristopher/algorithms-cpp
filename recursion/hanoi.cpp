#include <iostream>

using namespace std;


void hanoi(int n, const char* src, const char* tmp, const char* dst) {
    if (n > 0) {
        hanoi(n-1, src, dst, tmp);
        cout << "move " << n << " from " << src << " to " << dst << endl;
        hanoi(n-1, tmp, src, dst);
    }
}

int main() {
    hanoi(1, "src", "tmp", "dst");
    cout << "-----------" << endl;

    hanoi(5, "src", "tmp", "dst");

    return 0;
}