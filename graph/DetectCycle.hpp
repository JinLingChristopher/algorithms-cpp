//
// Created by king on 2019/8/8.
//

#ifndef ALGORITHM_CPP_DETECTCYCLE_HPP
#define ALGORITHM_CPP_DETECTCYCLE_HPP


#include "Graph_base.hpp"

enum class STATUS {
    NEW,
    ACTIVE,
    FINISHED
};

class DetectCycle {
private:
    const Graph_base& graph;

    bool isAcyclicDFS(int v, std::vector<STATUS>& status);

public:

    DetectCycle(const Graph_base& g):graph(g) {
        std::cout << "DetectCycle (const Graph_base&) called" << std::endl;
    }

    bool isAcyclic();
};


#endif //ALGORITHM_CPP_DETECTCYCLE_HPP
