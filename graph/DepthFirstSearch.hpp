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

    void validateVertex(int v) {
        if (v < 0 || v >= graph.numOfVertices()) {
            throw std::invalid_argument("v is not valid vertex");
        }
    }

    int recursiveDFSWithOrder_helper(int s, int clock, std::vector<int>& prev, std::vector<int>& post);

public:
    DepthFirstSearch(const Graph_base& g):graph(g) {
        clearMarked();
    }

    void recursiveDFSWithOrder(int s);

};


#endif //ALGORITHM_CPP_DEPTHFIRSTSEARCH_HPP
