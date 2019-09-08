#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums, vector<int>& aux, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; ++k) {
        aux[k] = nums[k];
    }
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; ++k) {
        if (i > mid) {
            nums[k] = aux[j++];
        } else if (j > hi) {
            nums[k] = aux[i++];
        } else if (aux[i] < aux[j]) {
            nums[k] = aux[i++];
        } else {
            nums[k] = aux[j++];
        }
    }
}

void mergeSortBu(vector<int>& nums) {
    int n = nums.size();
    vector<int> aux(n, 0);

    for (int len = 1; len < n; len *= 2) {
        for (int lo = 0; lo < n - len; lo = lo + len * 2) {
            int mid = lo + len - 1;
            int hi = std::min(lo + 2 * len - 1, n - 1);
            merge(nums, aux, lo, mid, hi);
        }
    }
}


int main() {
    std::vector<int> nums(20);
    std::generate(nums.begin(), nums.end(), std::rand);
    for (auto i = 0; i < nums.size(); ++i) {
        nums[i] = nums[i] % 100;
    }

    mergeSortBu(nums);
    for (auto iter = nums.cbegin(); iter != nums.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}