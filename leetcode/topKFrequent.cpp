#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> topKFrequent(const vector<int> &nums, int k) {
    map<int, int> table;
    for (auto item : nums) {
        table[item] += 1;
    }
    for (auto iter = table.cbegin(); iter != table.cend(); ++iter) {
        cout << iter->first << "->" << iter->second << endl;
    }

    return vector<int>();
}

int main() {
    vector<int> nums{1, 1, 1, 2, 2, 3};
    int k = 2;
    auto result = topKFrequent(nums, k);
    return 0;
}
