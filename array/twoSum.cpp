#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;
    int n = numbers.size();
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        auto sum = numbers[lo] + numbers[hi];
        if (sum > target) {
            --hi;
        } else if (sum < target) {
            ++lo;
        } else {
            result.push_back(lo + 1);
            result.push_back(hi + 1);
            break;
        }
    }    
    return result;
}

int main() {
  vector<int> nums{2, 7, 11, 15};
  int target = 9;
  auto result = twoSum(nums, target);
  
  for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
    cout << *iter << " ";
  }
  cout << endl;

  return 0;
}
