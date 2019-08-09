//
// Created by king on 2019/8/9.
//

#ifndef ALGORITHM_CPP_UNDIRECTEDWEIGHTEDGRAPH_HPP
#define ALGORITHM_CPP_UNDIRECTEDWEIGHTEDGRAPH_HPP

#include "UndirectedGraph.hpp"

class UndirectedWeightedGraph: public UndirectedGraph {

private:
    int weight;

public:
    UndirectedWeightedGraph() = delete;

    UndirectedWeightedGraph(int v): UndirectedGraph(v) {
        std::cout << "UndirectedWeightedGraph(int v) called" << std::endl;
    }

};


#endif //ALGORITHM_CPP_UNDIRECTEDWEIGHTEDGRAPH_HPP
