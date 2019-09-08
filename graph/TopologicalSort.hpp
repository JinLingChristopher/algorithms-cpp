//
// Created by king on 2019/8/9.
//

#ifndef ALGORITHM_CPP_TOPOLOGICALSORT_HPP
#define ALGORITHM_CPP_TOPOLOGICALSORT_HPP

#include <vector>
#include "Graph_base.hpp"
#include "DetectCycle.hpp"

class TopologicalSort {
private:
    const Graph_base& graph;

    int topologicalSortDFS(int v, int clock, std::vector<STATUS>& status, std::vector<int>& sorted);
    void postProcessDFS(int v, std::vector<bool>& marked, std::vector<STATUS>& status);

public:
    TopologicalSort(const Graph_base& g): graph(g) {
        std::cout << "TopologicalSort (const Graph_base& g) called" << std::endl;
    }

    std::vector<int> topologicalSort();
    void postProcess();
};


#endif //ALGORITHM_CPP_TOPOLOGICALSORT_HPP
