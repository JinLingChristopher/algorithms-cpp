//
// Created by Edison King on 2020/3/3.
//

#ifndef ALGORITHM_CPP_LRUCACHE_HPP
#define ALGORITHM_CPP_LRUCACHE_HPP

#include <unordered_map>
#include <list>


class LRUCache {
private:
    int cap;
    std::list<std::pair<int, int>> data;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> looker;

public:
    LRUCache(int capacity): cap(capacity) {

    }

    int get(int key) {
        if (looker.find(key) == looker.end()) {
            return -1;
        }
        auto iter = looker[key];
        data.push_front(*iter);
        data.erase(iter);
        looker[key] = data.begin();
        return data.front().second;
    }

    void put(int key, int value) {
        auto iter = looker.find(key);
        if (iter != looker.end()) {
            data.push_front(*iter->second);
            data.begin()->second = value;
            data.erase(iter->second);
            looker[key] = data.begin();
            return;
        }
        if (data.size() < cap) {
            data.push_front(std::make_pair(key, value));
            looker[key] = data.begin();
            return;
        }
        auto lastKey = data.back().first;
        looker.erase(lastKey);
        data.pop_back();

        data.push_front(std::make_pair(key, value));
        looker[key] = data.begin();
    }
};


#endif //ALGORITHM_CPP_LRUCACHE_HPP
