//
// Created by king on 2019/7/31.
//

#ifndef ALGORITHM_CPP_UNDIRECTEDGRAPH_HPP
#define ALGORITHM_CPP_UNDIRECTEDGRAPH_HPP

/*
 * A simple adjacent list representation of graph data structure
*/

#include <list>  // todo: check docs of list and forward_list
#include <vector>
#include <iostream>

#include "Graph_base.hpp"


class UndirectedGraph: public Graph_base {
private:
    friend std::ostream& operator<<(std::ostream& os, const UndirectedGraph& g);

public:
    UndirectedGraph(int v): Graph_base(v) {
        std::cout << "UndirectedGraph(int v) called" << std::endl;
    }

    ~UndirectedGraph() {
        std::cout << "~UndirectedGraph() called" << std::endl;
    }

    void addEdges(int v, int w) {
        adj[v].insert(w);
        adj[w].insert(v);
        ++this->E;
    }

};

std::ostream& operator<<(std::ostream& os, const UndirectedGraph& g);

#endif //ALGORITHM_CPP_UNDIRECTEDGRAPH_HPP
