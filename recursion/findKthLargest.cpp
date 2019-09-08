#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

int get_pivot(const vector<int>& nums, int lo, int hi) {
  	int mi = lo + (hi - lo) / 2;
  	int a = nums[lo];
  	int b = nums[mi];
  	int c = nums[hi];
  	
    int mid;
    if (a > b) {
        if (b > c) {
            mid = b;
        } else if (a > c) {
            mid = c;
        } else {
            mid = a;
        }
    } else {
        if (a > c) {
            mid = a;
        } else if (b > c) {
            mid = c;
        } else {
            mid = b;
        }
    }

	int argmid = -1;
	if (mid == a) {
		argmid = lo;
	} else if (mid == b) {
		argmid = mi;
	} else if (mid == c) {
		argmid = hi;
	}
	return argmid;
}

int hoare_partition(vector<int>& nums, int lo, int hi) {
    int p = get_pivot(nums, lo, hi);
    std::swap(nums[p], nums[hi]);
    int i = lo;
    int j = hi - 1;
    while (i <= j) {
        while (nums[i] >= nums[hi] && i < hi) {
            i++;
        }
        while (nums[j] <= nums[hi] && j > lo) {
            j--;
        }
        if (i >= j) {
            break;
        }
        std::swap(nums[i], nums[j]);
    }
    std::swap(nums[i], nums[hi]);
    return i;
}

int helper(vector<int>& nums, int lo, int hi, int k) {
    int p = hoare_partition(nums, lo, hi);
    if((p - lo + 1 ) == k) {
        return nums[p];
    } else if ((p - lo + 1) > k) {
        return helper(nums, lo, p - 1, k);
    } else {
        return helper(nums, p + 1, hi, k + lo - p - 1);
    }
}

int findKthLargest(vector<int>& nums, int k) {
    int hi = nums.size() - 1;
    int ret = helper(nums, 0, hi, k);
    return ret;
}

int main() {

    // vector<int> nums1{3, 2, 3, 1, 2, 4, 5, 5, 6};
    // int k1 = 4;
    // cout << findKthLargest(nums1, k1) << endl;

    // vector<int> nums2{3, 2, 1, 5, 6, 4};
    // int k2 = 2;
    // cout << findKthLargest(nums2, k2) << endl;

    // vector<int> nums3{2, 1};
    // int k3 = 1;
    // cout << findKthLargest(nums3, k3) << endl;

    // vector<int> nums4{3, 3, 3, 3, 3, 3, 3, 3, 3};
    // int k4 = 8;
    // cout << findKthLargest(nums3, k3) << endl;

    // vector<int> nums5{5, 2, 4, 1, 3, 6, 0};
    // int k5 = 4;
    // cout << findKthLargest(nums5, k5) << endl;

    vector<int> nums6{3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k6 = 9;
    cout << findKthLargest(nums6, k6) << endl;

    return 0;
}