//
// Created by Edison King on 2020/3/9.
//

#include <vector>
#include <string>
#include <iostream>
using namespace std;

int findClosest(vector<string>& words, string word1, string word2) {
    vector<int> pos(words.size(), 0);
    for (int i = 0; i < words.size(); ++i) {
        if (words[i] == word1) {
            pos[i] = 1;
        } else if (words[i] == word2) {
            pos[i] = 2;
        }
    }
    int a = -1, b = -1, result = 0x7fffffff;
    for (int i = 0; i < words.size(); ++i) {
        if (pos[i] == 1) {
            a = i;
        }
        if (pos[i] == 2) {
            b = i;
        }
        if (a != -1 && b != -1) {
            result = min(result, std::abs(a - b));
        }
    }
    return result;
}

int main() {
    vector<string> words{"I", "am", "a", "student", "from",
                         "a", "university", "in", "a", "city"};
    string w1{"a"};
    string w2{"student"};

    cout << findClosest(words, w1, w2) << endl;

    return 0;
}
