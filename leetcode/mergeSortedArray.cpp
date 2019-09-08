#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int idx = m + n - 1;
    int i = m - 1, j = n - 1;
    while (i >= 0 || j >= 0) {
        if (i < 0) {
            nums1[idx] = nums2[j];
            j -= 1;
        } else if (j < 0) {
            nums1[idx] = nums1[i];
            i -= 1;
        } else if (nums1[i] > nums2[j]) {
            nums1[idx] = nums1[i];
            i -= 1;
        } else {
            nums1[idx] = nums2[j];
            j -= 1;
        }
        idx -= 1;
    }
}

int main() {
    vector<int> nums1 {1, 2, 3, 0, 0, 0};
    vector<int> nums2 {2, 5, 6};

    merge(nums1, 3, nums2, 3);

    return 0;
}