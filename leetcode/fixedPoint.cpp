#include <vector>
#include <iostream>

using namespace std;

int helper(const vector<int>& nums, int lo, int hi) {
  if (hi > lo) {
    int mid = lo + (hi - lo) / 2;
    int ele = nums[mid];
    if (ele == mid) {
      int t = helper(nums, lo, mid - 1);
      if (t == -1) {
        return mid;
      } else {
        return t;
      }
    } else if (ele > mid) {
      return helper(nums, lo, mid - 1);
    } else {
      return helper(nums, mid + 1, hi);
    }
  }
  return -1;
}


int fixedPoint(const vector<int>& nums) {
  int hi = nums.size() - 1;
  return helper(nums, 0, hi);
}

int main() {
  vector<int> nums{-10, -5, -2, 0, 4, 5, 6, 7, 8, 9, 10};

  int ret = fixedPoint(nums);
  cout << ret << endl;

  return 0;
}
