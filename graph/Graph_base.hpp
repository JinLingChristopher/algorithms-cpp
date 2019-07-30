//
// Created by king on 2019/7/31.
//

#ifndef ALGORITHM_CPP_GRAPH_BASE_HPP
#define ALGORITHM_CPP_GRAPH_BASE_HPP

#include <iostream>
#include <vector>
#include <list>


class Graph_base {
private:
    const int V;


protected:
    int E;
    std::vector<std::list<int>> adj;
public:

    Graph_base(int v): V(v), E(0) {
        std::cout << "Graph_base(int v) called" << std::endl;
        for (int i = 0; i < v; ++i) {
            adj.push_back(std::list<int>());
        }
    }

    virtual ~Graph_base() {
        std::cout << "~Graph_base() called" << std::endl;
    }

    int numOfVertices() const {
        return this->V;
    }

    int numOfEdges() const {
        return this->E;
    }

    virtual void addEdges(int v, int w) = 0;

    int degree(int v) {
        return adj[v].size();
    }

    std::list<int> getAdj(int v) const {
        return adj[v];
    }

};


#endif //ALGORITHM_CPP_GRAPH_BASE_HPP
