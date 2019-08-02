//
// Created by king on 2019/7/31.
//

#ifndef ALGORITHM_CPP_DIRECTEDGRAPH_HPP
#define ALGORITHM_CPP_DIRECTEDGRAPH_HPP

#include "Graph_base.hpp"


class DirectedGraph: public Graph_base {

private:
    friend std::ostream& operator<<(std::ostream& os, const DirectedGraph& g);

public:
    DirectedGraph(int v): Graph_base(v) {
        std::cout << "DirectedGraph called()" << std::endl;
    }

    ~DirectedGraph() {
        std::cout << "~DirectedGraph called()" << std::endl;
    }

    void addEdges(int from, int to) {
        if (from >= this->numOfVertices()) {
            // todo: abort the program
        }
        if (to >= this->numOfVertices()) {
            // todo: abort the program
        }
        adj[from].insert(to);
        ++this->E;
    }
};

std::ostream& operator<<(std::ostream& os, const DirectedGraph& g);


#endif //ALGORITHM_CPP_DIRECTEDGRAPH_HPP
