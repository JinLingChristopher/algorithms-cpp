//
// Created by king on 2019/8/7.
//

#ifndef ALGORITHM_CPP_BREATHFIRSTSEARCH_HPP
#define ALGORITHM_CPP_BREATHFIRSTSEARCH_HPP


#include <vector>
#include "Graph_base.hpp"


class BreathFirstSearch {
private:
    const Graph_base& graph;
    std::vector<bool> marked;

    void clearMarked() {
        marked = std::vector<int>(graph.numOfVertices(), false);
    }

public:

};


#endif //ALGORITHM_CPP_BREATHFIRSTSEARCH_HPP
