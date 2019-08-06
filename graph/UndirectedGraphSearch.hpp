//
// Created by king on 2019/8/6.
//

#ifndef ALGORITHM_CPP_UNDIRECTEDGRAPHSEARCH_HPP
#define ALGORITHM_CPP_UNDIRECTEDGRAPHSEARCH_HPP

#include "UndirectedGraph.hpp"


class UndirectedGraphSearch {
private:
    UndirectedGraph graph;
    std::vector<bool> marked;

    void validateVertex(int v) {
        if (v < 0 || v >= graph.numOfVertices()) {
            throw std::invalid_argument("v is not valid vertex");
        }
    }

    void clearMarked() {
        marked = std::vector<bool>(graph.numOfVertices(), false);
    }

public:

    UndirectedGraphSearch(const UndirectedGraph& g):graph(g) {
        clearMarked();
    }

    void RecursiveDFS(int s);
    void IterativeDFS(int s);

    void IterativeBFS(int s);

    void IterativeDFSAll();

    int countComponent();

};


#endif //ALGORITHM_CPP_UNDIRECTEDGRAPHSEARCH_HPP
