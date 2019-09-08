//
// Created by king on 2019/8/5.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

vector<int> greedy_schedule(const vector<int>& start, const vector<int>& finish) {
    vector<size_t> idx(finish.size());
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(), [&finish](size_t i1, size_t i2) {
        return finish[i1] < finish[i2];
    });
    vector<int> ret;
    ret.push_back(idx[0]);
    for (int i = 1; i < idx.size(); ++i) {
        if (start[idx[i]] > finish[ret.back()]) {
            ret.push_back(idx[i]);
        }
    }

    return ret;
}


int main() {

    vector<int> start{5, 7, 1, 3, 8};
    vector<int> finish{6, 9, 2, 4, 9};

    vector<int> result = greedy_schedule(start, finish);

    for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}