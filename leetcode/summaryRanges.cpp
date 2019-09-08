#include <iostream>
#include <vector>
#include <string>

using namespace std;

string formatString(const vector<int> curr) {
    string s = std::to_string(curr[0]);
    int length = curr.size();
    if (length > 1) {
        s += "->";
        s += std::to_string(curr[length - 1]);
    }
    return s;
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    int length = nums.size();
    
    vector<int> curr;
    for (int i = 0; i < length; ++i) {
        if (curr.size() == 0 || curr[curr.size() - 1]  == nums[i] - 1) {
            curr.push_back(nums[i]);
        } else {
            string s = formatString(curr);
            result.push_back(s);
            curr.clear();
            curr.push_back(nums[i]);
        }
    }
    if (curr.size()) {
        auto s = formatString(curr);
        result.push_back(s);
    }
    return result;
}

int main() {
    vector<int> input{0, 1, 2, 4, 5, 7};

    auto result = summaryRanges(input);

    for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
        cout << *iter << endl;
    }

    return 0;
}