//
// Created by Edison King on 2020/3/9.
//

#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;

vector<string> getValidT9Words(string num, vector<string>& words) {
    vector<string> result;
    if (!num.size() || !words.size()) {
        return result;
    }
    vector<int> nums{2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
    for (const auto& w: words) {
        bool flag = true;
        for (int i = 0; i < w.size(); ++i) {
            char c = nums[w[i] - 'a'] + '0';
            if (c != num[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            result.push_back(w);
        }
    }
    return result;
}

int main() {
    auto num = "8733";
    vector<string> words {"tree", "used"};

    auto result = getValidT9Words(num, words);
    for (const auto& item : result) {
        cout << item << endl;
    }

    return 0;
}
