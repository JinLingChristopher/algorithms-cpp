#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void swap(vector<int>& nums, int a, int b) {
    int t = nums[a];
    nums[a] = nums[b];
    nums[b] = t;
}

void insertionSort(vector<int>& nums, int lo, int hi) {
    for (int i = lo; i <= hi; ++i) {
        int j = i;
        while (j > lo) {
            if (nums[j] < nums[j - 1]) {
                swap(nums, j, j - 1);
                j--;
            } else {
                break;
            }
        }
    }
}

void merge(vector<int>& src, vector<int>& dst, int lo, int mid, int hi) {
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++) {
        if (i > mid) {
            dst[k] = src[j++];
        } else if (j > hi) {
            dst[k] = src[i++];
        } else if (src[i] < src[j]) {
            dst[k] = src[i++];
        } else {
            dst[k] = src[j++];
        }
    }
}

void helper(vector<int>& nums, vector<int>& aux, int lo, int hi) {
    const int CUTOFF = 7;
    if (hi <= lo + CUTOFF) {
        insertionSort(aux, lo, hi);
        return;
    }
    int mid = lo + (hi - lo) / 2;
    helper(aux, nums, lo, mid);
    helper(aux, nums, mid + 1, hi);

    if (nums[mid + 1] >= nums[mid]) {
        for (int i = lo; i <= hi; i++) {
            aux[i] = nums[i];
        }
        return;
    }

    merge(nums, aux, lo, mid, hi);
}

void mergeSortOptimized(vector<int>& nums) {
    vector<int> aux(nums.cbegin(), nums.cend());
    helper(aux, nums, 0, nums.size() - 1);
}

int main() {
    std::vector<int> nums(20);
    std::generate(nums.begin(), nums.end(), std::rand);
    for (auto i = 0; i < nums.size(); ++i) {
        nums[i] = nums[i] % 100;
    }

    mergeSortOptimized(nums);

    for (auto iter = nums.cbegin(); iter != nums.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}