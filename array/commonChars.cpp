#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> commonChars(vector<string>& A) {
    vector<string> result;
    vector<vector<int>> table(A.size(), vector<int>(26, 0));
    
    for (int i = 0; i < A.size(); ++i) {
        auto& str = A[i];
        for (int j = 0; j < str.size(); ++j) {
            table[i][str[j] - 'a'] += 1;
        }
    }
    
    vector<int>& mins = table[0];
    for (int i = 1; i < A.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            mins[j] = std::min(mins[j], table[i][j]);
        }
    }
    
    for (int i = 0; i < mins.size(); ++i) {
        for (int j = 0; j < mins[i]; ++j) {
            result.push_back(string{'a' + i});
        }
    }
    
    return result;
}

int main() {
    vector<string> strs{"bella", "label", "roller"};

    auto result = commonChars(strs);

    for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}