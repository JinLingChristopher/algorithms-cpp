//
// Created by king on 2019/8/7.
//

#include "BreathFirstSearch.hpp"
#include <queue>

using namespace std;

void BreathFirstSearch::iterativeBFS(int s) {
    std::queue<int> bag;
    bag.push(s);
    while (!bag.empty()) {
        int v = bag.front();
        bag.pop();
        marked[v] = true;
        for (const auto item: graph.getAdj(v)) {
            bag.push(item);
        }
    }
}
