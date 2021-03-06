//
// Created by king on 2019/8/9.
//

#include "TopologicalSort.hpp"

int TopologicalSort::topologicalSortDFS(int v, int clock, std::vector<STATUS>& status, std::vector<int>& sorted) {
    status[v] = STATUS::ACTIVE;
    for (const auto item: graph.getAdj(v)) {
        if (status[item] == STATUS::NEW) {
            clock = topologicalSortDFS(item, clock, status, sorted);
        }
    }

    status[v] = STATUS::FINISHED;
    sorted[clock] = v;
    clock = clock - 1;

    return clock;
}

std::vector<int> TopologicalSort::topologicalSort() {
    DetectCycle detector(graph);
    if (!detector.isAcyclic()) {
        std::cout << "The given graph is not a dag, no topologicalsort" << std::endl;
        return std::vector<int>();
    }

    std::vector<int> sorted(graph.numOfVertices(), -1);
    std::vector<STATUS> status(graph.numOfVertices(), STATUS::NEW);
    int clock = graph.numOfVertices() - 1;
    for (int i = 0; i < graph.numOfVertices(); ++i) {
        if (status[i] == STATUS::NEW) {
            clock = topologicalSortDFS(i, clock, status, sorted);
        }
    }
    return sorted;
}

void TopologicalSort::postProcessDFS(int v, std::vector<bool> &marked, std::vector<STATUS> &status) {
    status[v] = STATUS::ACTIVE;
    for (const auto item: graph.getAdj(v)) {
        if (status[item] == STATUS::NEW) {
            postProcessDFS(item, marked, status);
        }
    }
    status[v] = STATUS::FINISHED;
    // process(v);    // process: some function that related to v, process in reversed topological order.
}

void TopologicalSort::postProcess() {
    DetectCycle detector(graph);
    if (!detector.isAcyclic()) {
        std::cout << "The given graph is not a dag, no topologicalsort" << std::endl;
        return;
    }

    std::vector<STATUS> status(graph.numOfVertices(), STATUS::NEW);
    std::vector<bool> marked(graph.numOfVertices(), false);
    for (int i = 0; i < graph.numOfVertices(); ++i) {
        if (!marked[i]) {
            postProcessDFS(i, marked, status);
        }
    }
}
