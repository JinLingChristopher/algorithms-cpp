//
// Created by king on 2019/8/6.
//

#include <stack>
#include <queue>
#include "UndirectedGraphSearch.hpp"

using namespace std;

void UndirectedGraphSearch::RecursiveDFS(int s) {
    validateVertex(s);

    if (!marked[s]) {
        marked[s] = true;
        for (const auto node: graph.getAdj(s)) {
            RecursiveDFS(node);
        }
    }
}

void UndirectedGraphSearch::IterativeDFS(int s) {
    validateVertex(s);

    stack<int> bag;
    bag.push(s);

    while(!bag.empty()) {
        int v = bag.top();
        bag.pop();
        if (!marked[v]) {
            marked[v] = true;
            for (const auto node: graph.getAdj(v)) {
                if (!marked[node]) {
                    bag.push(node);
                }
            }
        }
    }

}

void UndirectedGraphSearch::IterativeBFS(int s) {
    validateVertex(s);

    queue<int> bag;
    bag.push(s);

    while (!bag.empty()) {
        int v = bag.front();
        bag.pop();
        if (!marked[v]) {
            marked[v] = true;
            for (const auto node: graph.getAdj(v)) {
                if (!marked[node]) {
                    bag.push(node);
                }
            }
        }
    }
}

void UndirectedGraphSearch::IterativeDFSAll() {
    for (int i = 0; i < marked.size(); ++i) {
        if (!marked[i]) {
            IterativeDFS(i);
        }
    }
}

int UndirectedGraphSearch::countComponent() {
    int counter = 0;
    for (int i = 0; i < marked.size(); ++i) {
        if (!marked[i]) {
            counter += 1;
            IterativeDFS(i);
        }
    }

    return counter;
}


