#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

vector<int> topKFrequent(const vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for (auto item: nums) {
        ++count[item];
    }
    using value_t = pair<int, int>;
    auto cmp = [](const value_t& lhs, const value_t& rhs) {
        return lhs.second > rhs.second;
    };
    priority_queue<value_t, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for (auto iter = count.begin(); iter != count.end(); ++iter) {
        pq.push(*iter);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().first);
        pq.pop();
    }
    return result;
}

int main() {
    vector<int> nums{1, 1, 1, 2, 2, 3};
    int k = 2;
    auto result = topKFrequent(nums, k);
    for (auto item: result) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
