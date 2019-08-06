//
// Created by king on 2019/8/7.
//

#include "DepthFirstSearch.hpp"

using namespace std;

int DepthFirstSearch::recursiveDFSWithOrder_helper(int s, int clock, std::vector<int> &prev, std::vector<int> &post) {
    validateVertex(s);
    if (!marked[s]) {
        marked[s] = true;
        clock += 1;
        prev[s] = clock;
        for (const auto node: graph.getAdj(s)) {
            if (!marked[node]) {
                clock = recursiveDFSWithOrder_helper(s, clock, prev, post);
            }
        }
        clock += 1;
        post[s] = clock;
    }
    return clock;
}

void DepthFirstSearch::recursiveDFSWithOrder(int s) {
    clearMarked();

    vector<int> prev(graph.numOfVertices(), -1);
    vector<int> post(graph.numOfVertices(), -1);
    int clock = -1;

    for (int i = 0; i < marked.size(); ++i) {
        if (!marked[i]) {
            clock = recursiveDFSWithOrder_helper(i, clock, prev, post);
        }
    }

    cout << "prevorder: ";
    for (auto iter = prev.cbegin(); iter != prev.cend(); ++iter) {
        cout << *iter <<" ";
    }
    cout << endl;

    cout << "postorder: ";
    for (auto iter = post.cbegin(); iter != post.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

