#include <vector>
#include <iostream>
#include <numeric>
using namespace std;


bool canThreePartsEqualSum(vector<int>& A) {
    auto sum = std::accumulate(A.cbegin(), A.cend(), 0);
    auto target = sum / 3;
    if (target * 3 != sum) {
        return false;
    }

    int count = 0, curr = 0, n = A.size();
    for (int i = 0; i < n; ++i) {
        curr += A[i];
        if (curr == target) {
            count += 1;
            curr = 0;
        }
    }
    return count == 3 && curr == 0;
}

int main() {
    vector<int> nums{0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    cout << canThreePartsEqualSum(nums) << endl;

    return 0;
}