//
// Created by Edison King on 2020/2/28.
//

#include <vector>
#include <iostream>
using namespace std;


int merge(vector<int>& nums, int lo, int mid, int hi, vector<int>& aux) {
    int result = 0;
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; ++k) {
        if (j > hi) {
            aux[k] = nums[i++];
        } else if (i > mid) {
            aux[k] = nums[j++];
        } else if (nums[j] < nums[i]) {
            aux[k] = nums[j++];
            result += (mid - i) + 1;
        } else {
            aux[k] = nums[i++];
        }
    }

    for (int k = lo; k <= hi; k++) {
        nums[k] = aux[k];
    }

    return result;
}

int solver(vector<int>& nums, int lo, int hi, vector<int>& aux) {
    if (hi > lo) {
        int mid = lo + (hi - lo) / 2;
        int a = solver(nums, lo, mid, aux);
        int b = solver(nums, mid + 1, hi, aux);
        int c = merge (nums, lo, mid, hi, aux);
        return a + b + c;
    }
    return 0;
}

int reversePairs(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
        return 0;
    }
    vector<int> aux(n, 0);
    return solver(nums, 0, n - 1, aux);
}

int main() {
    vector<int> nums{7, 5, 6, 4};
    cout << reversePairs(nums) << endl;

    return 0;
}