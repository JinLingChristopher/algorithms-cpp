//
// Created by king on 2019/8/15.
//

#ifndef ALGORITHM_CPP_DIRECTEDWEIGHTEDGRAPH_HPP
#define ALGORITHM_CPP_DIRECTEDWEIGHTEDGRAPH_HPP


#include <vector>
#include <set>
#include "DirectedWeightedGraph.hpp"
#include "Edge.hpp"


class DirectedWeightedGraph {
private:
    int V;
    int E;
    std::vector<std::set<Edge>> adjs;

public:
    DirectedWeightedGraph(int v):V(v), E(0) {
        std::cout << "DirectedWeightedGraph(int v) called" << std::endl;
        if (v <= 0) {
            throw std::invalid_argument("number of vertices should always be positive");
        }
        for (int i = 0; i < V; ++i) {
            adjs.push_back(std::set<Edge>());
        }
    }

    virtual ~DirectedWeightedGraph() {
        std::cout << "~DirectedWeightedGraph() called" << std::endl;
    }

    int numOfVertices() const {
        return this->V;
    }

    void addEdge(int from, int to, int weight) {
        Edge e(from, to, weight);
        adjs[from].insert(e);
    }

    int numOfEdges() const {
        return this->E;
    }

    int degree(int v) {
        return adjs[v].size();
    }

    const std::set<Edge>& getAdj(int v) const {
        return adjs[v];
    }

};

#endif