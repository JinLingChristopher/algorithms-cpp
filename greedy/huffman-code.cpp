//
// Created by king on 2019/8/5.
//

#include <string>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

//struct ComparedSecond {
//    bool operator()(const std::pair<string, int>& left, const std::pair<string, int>& right) {
//        return left.second < right.second;
//    }
//};
//
//pair<string, int> extractMin(map<string, int>& mapper) {
//    pair<string, int> ret = *min_element(mapper.begin(), mapper.end(), ComparedSecond());
//    mapper.erase(ret.first);
//    return ret;
//}
//
//void build_huffman(map<string, int>& mapper, vector<int>& left, vector<int>& right, vector<int>& parent) {
//    for (int i = 0; i < mapper.size() * 2; ++i) {
//        left.push_back(-1);
//        right.push_back(-1);
//        parent.push_back(-1);
//    }
//
//    int total;
//    while (mapper.size() != 1) {
//       auto x = extractMin(mapper);
//       auto y = extractMin(mapper);
//       total = x.second + y.second;
//       mapper.insert(make_pair(x.first+y.first, total));
//       left.push_back(x.first);
//       right.push_back(y.first);
//       parent.
//    }
//
//}

auto cmp = [](const pair<string, int>& lhs, const pair<string, int>& rhs) {
    return lhs.second < rhs.second;
};

using priority_queue_huffman = priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)>;

void build_huffman(priority_queue_huffman& q, vector<int>& left, vector<int>& right, vector<int>& parent) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
        left.push_back(-1);
        right.push_back(-1);
    }
    for (int i = n; i < 2 * n; i++) {
        auto x = q.top();
        q.pop();
        auto y = q.top();
        q.pop();
        auto val = x.second + y.second;
        auto key = x.first + y.first;
        q.push(make_pair(key, val));

//        left.push_back()
    }
}


priority_queue_huffman build_mapper(const string& str) {
    map<string, int> record;
    for (int i = 0; i < str.size(); ++i) {
        char c = str[i];
        if (std::isalpha(c)) {
            string key(1, std::toupper(c));
            record[key] += 1;
        }
    }

    priority_queue_huffman q(cmp);

    //priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> q(cmp);
    for (auto iter = record.cbegin(); iter != record.cend(); ++iter) {
        q.push(*iter);
    }
    return q;
}


int main() {
    const string str("This sentence contains three a's, three c's, two d's, twenty-six e's,"
                     "five f's, three g's, eight h's, thirteen i's, two l's, sixteen n's, nine o's, six r's,"
                     "twenty-seven s's, twenty-two t's, two u's, five v's, eight w's, four x's, five y's,"
                     "and only one z.");

    auto mapper = build_mapper(str);
    vector<int> left, right, parent;

    return 0;
}
