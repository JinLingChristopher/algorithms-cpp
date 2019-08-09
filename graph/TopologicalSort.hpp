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

public:
    TopologicalSort(const Graph_base& g): graph(g) {
        std::cout << "TopologicalSort (const Graph_base& g) called" << std::endl;
    }

    std::vector<int> topologicalSort();
};


#endif //ALGORITHM_CPP_TOPOLOGICALSORT_HPP
