#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

bool canThreePartsEqualSum(vector<int>& A) {
    int total = std::accumulate(A.begin(), A.end(), 0);
    int target = total / 3;
    if (target * 3 != total) {
        return false;
    }
    int length = A.size();
    int count = 0;
    int curr = 0;
    for (int i = 0; i < length; ++i) {
        curr += A[i];
        if (curr == target) {
            count += 1;
            total = 0;
        }
    }
    return count == 3;
}

int main() {
    vector<int> nums{0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    bool ret = canThreePartsEqualSum(nums);
    cout << ret << endl;

    return 0;
}