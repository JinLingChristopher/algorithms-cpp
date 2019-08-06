//
// Created by king on 2019/8/7.
//

#ifndef ALGORITHM_CPP_DEPTHFIRSTSEARCH_HPP
#define ALGORITHM_CPP_DEPTHFIRSTSEARCH_HPP


#include "Graph_base.hpp"

class DepthFirstSearch {

private:
    const Graph_base& graph;
    std::vector<bool> marked;

    void clearMarked() {
        marked = std::vector<bool>(graph.numOfVertices(), false);
    }

public:
    DepthFirstSearch(const Graph_base& g):graph(g) {
        clearMarked();
    }


};


#endif //ALGORITHM_CPP_DEPTHFIRSTSEARCH_HPP
