//
// Created by king on 2019/8/7.
//

#include <stack>
#include "DepthFirstSearch.hpp"

using namespace std;

void DepthFirstSearch::iterativeDFS(int s) {
    validateVertex(s);
    clearMarked();

    stack<int> bag;
    bag.push(s);
    while (!bag.empty()) {
        int v = bag.top();
        bag.pop();
        if (!marked[v]) {
            marked[v] = true;
            // cout << v << " ";
            for (const auto node: graph.getAdj(v)) {
                if (!marked[node]) {
                    bag.push(node);
                }
            }
        }
    }
    cout << endl;
}

void DepthFirstSearch::recursiveDFS_helper(int s) {
    validateVertex(s);
    if (!marked[s]) {
        marked[s] = true;
        // cout << s << " ";
        for (const auto w: graph.getAdj(s)) {
            recursiveDFS_helper(w);
        }
    }
}
void DepthFirstSearch::recursiveDFS(int s) {
    clearMarked();
    recursiveDFS_helper(s);
}

void DepthFirstSearch::dfsAll() {
    clearMarked();
    for (int i = 0; i < marked.size(); ++i) {
        if (!marked[i]) {
            recursiveDFS_helper(i);
        }
    }
}

int DepthFirstSearch::countComponent() {
    clearMarked();
    int counter = 0;
    for (int i = 0; i < marked.size(); ++i) {
        if (!marked[i]) {
            counter += 1;
            iterativeDFS(i);
        }
    }
    return counter;
}

int DepthFirstSearch::recursiveDFSWithOrder_helper(int s, int clock, std::vector<int> &prev, std::vector<int> &post, std::vector<int>& parent) {
    marked[s] = true;
    clock += 1;
    prev[s] = clock;
    for (const auto w: graph.getAdj(s)) {
        if (!marked[w]) {
            parent[w] = s;
            clock = recursiveDFSWithOrder_helper(w, clock, prev, post, parent);
        }
    }
    clock += 1;
    post[s] = clock;

    return clock;
}

void DepthFirstSearch::recursiveDFSWithOrder(int s) {
    clearMarked();
    int clock = -1;
    std::vector<int> prev(graph.numOfVertices(), -1);
    std::vector<int> post(graph.numOfVertices(), -1);
    std::vector<int> parent(graph.numOfVertices(), -1);
    recursiveDFSWithOrder_helper(s, clock, prev, post, parent);

    std::cout << "prev: ";
    printVector(prev);

    std::cout << "post: ";
    printVector(post);

    std::cout << "parent: ";
    printVector(parent);
}

void DepthFirstSearch::recursiveDFSWithOrderAll() {
    clearMarked();
    int clock = -1;
    std::vector<int> prev(graph.numOfVertices(), -1);
    std::vector<int> post(graph.numOfVertices(), -1);
    std::vector<int> parent(graph.numOfVertices(), -1);

    for (int i = 0; i < marked.size(); ++i) {
        if (!marked[i]) {
            clock = recursiveDFSWithOrder_helper(i, clock, prev, post, parent);
        }
    }
    std::cout << "prev: ";
    printVector(prev);

    std::cout << "post: ";
    printVector(post);

    std::cout << "parent: ";
    printVector(parent);
}
