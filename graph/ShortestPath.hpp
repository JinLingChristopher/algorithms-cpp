//
// Created by king on 2019/8/15.
//

#ifndef ALGORITHM_CPP_SHORTESTPATH_HPP
#define ALGORITHM_CPP_SHORTESTPATH_HPP

#include "DirectedWeightedGraph.hpp"

class ShortestPath {
private:
    const DirectedWeightedGraph& graph;
    std::vector<int> dist;
    std::vector<int> pred;

    void init();
    void relax(int u, int v);

    const std::set<Edge> getAllEdges() const;

public:
    ShortestPath(const DirectedWeightedGraph& g): graph(g) {
        std::cout << "ShortestPath(const DirectedWeightedGraph& g) called" << std::endl;
        init();
    }

    void dijkstra(int s);

    void bfsShortestPath(int s);

    void bellman_ford(int s);

    const std::vector<int>& getDist() const;
};


#endif //ALGORITHM_CPP_SHORTESTPATH_HPP
