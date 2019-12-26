#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int findShortestSubArray(vector<int>& nums) {
    map<int, int> counter;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        counter[nums[i]] += 1;
    }
    
    using pairtype = std::pair<int, int>;
    auto max = *max_element(counter.begin(), counter.end(), [](const pairtype& p1, const pairtype& p2) {
        return p1.second < p2.second;
    });
    
    auto key = max.first;
    auto degree = max.second;
    
    int start = -1, end = -1;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == key) {
            if (start == -1) {
                start = i;
            }
            end = i;
        }
    }
    return end - start + 1; 
}

int main() {
    vector<int> nums{1, 2, 2, 3, 1};
    auto result = findShortestSubArray(nums);
    cout << result << endl;

    return 0;
}