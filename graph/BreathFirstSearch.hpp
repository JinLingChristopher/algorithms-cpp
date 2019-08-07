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
        marked = std::vector<bool>(graph.numOfVertices(), false);
    }

    void validateVertex(int s) {
        if (s < 0 || s >= graph.numOfVertices()) {
            throw std::invalid_argument("v is not valid vertex");
        }
    }

public:
    BreathFirstSearch(const Graph_base& g): graph(g) {
        std::cout << "BreathFirstSearch(const Graph_base& g) called" << std::endl;
        clearMarked();
    }

    void iterativeBFS(int s);

};


#endif //ALGORITHM_CPP_BREATHFIRSTSEARCH_HPP
