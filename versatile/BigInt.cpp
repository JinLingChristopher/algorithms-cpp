#include <iostream>
#include <vector>

using namespace std;

vector<int> bigIntAddtion(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int length = a.size() < b.size() ? a.size() : b.size();
    int carry = 0;
    int i;
    for (i = 0; i < length; ++i) {
        int r = a[i] + b[i] + carry;
        if (r >= 10) {
            carry = r / 10;
            r = r % 10;
        }
        result.push_back(r);
    }
    vector<int> remained;
    if (a.size() > length) {
        remained = a;
    } else {
        remained = b;
    }
    for (; i < remained.size(); ++i) {
        int r = remained[i] + carry;
        if (r >= 10) {
            carry = r / 10;
            r = r % 10;
        }
        result.push_back(r);
    }
    return result;
}

vector<int> bigIntMultiplication(const vector<int>& a, const vector<int>& b) {
    vector<int> current, result;
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int k = 0; k < i; ++k) {
            current.push_back(0);
        }
        for (int j = 0; j < b.size(); j++) {
            int r = a[i] * a[j];
            r += carry;
            if (r >= 10) {
                carry = r / 10;
                r = r % 10;
            } else {
                carry = 0;
            }
            current.push_back(r);
        }
        if (carry) {
            current.push_back(carry);
            carry = 0;
        }
        if (result.empty()) {
            result = current;
        } else {
            result = bigIntAddtion(result, current);
        }
        current.clear();
    }
    return result;
}

int main() {
    vector<int> a{9, 9, 9};
    vector<int> b{9, 9, 9};

    vector<int> result = bigIntMultiplication(a, b);
    for(auto iter = result.rbegin(); iter != result.rend(); ++iter) {
        cout << *iter << endl;
    }

    return 0;
}