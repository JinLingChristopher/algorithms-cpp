#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    auto sumA = std::accumulate(A.begin(), A.end(), 0);
    auto sumB = std::accumulate(B.begin(), B.end(), 0);
    auto delta = (sumB - sumA) / 2;

    for (int i = 0; i < A.size(); ++i) {
        int y = A[i] + delta;
        if (binary_search(B.cbegin(), B.cend(), y)) {
            return vector<int>{A[i], y};
        }
    }
    return vector<int>{};
}

int main() {

    vector<int> A{35, 17, 4, 24, 10}, B{63, 21};
    auto result = fairCandySwap(A, B);

    for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}