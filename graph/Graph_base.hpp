//
// Created by king on 2019/7/31.
//

#ifndef ALGORITHM_CPP_GRAPH_BASE_HPP
#define ALGORITHM_CPP_GRAPH_BASE_HPP

#include <iostream>
#include <vector>
#include <set>


class Graph_base {
private:
    int V;

protected:
    int E;
    std::vector<std::set<int>> adjs;

public:

    Graph_base() = delete;

    Graph_base(int v): V(v), E(0) {
        std::cout << "Graph_base(int v) called" << std::endl;

        if (v <= 0) {
            throw std::invalid_argument("number of vertices should always be positive");
        }

        for (int i = 0; i < v; ++i) {
            adjs.push_back(std::set<int>());
        }
    }

    Graph_base(const Graph_base& rhs):V(rhs.V), E(rhs.E), adjs(rhs.adjs) {
        std::cout << "Graph_base(const Graph_base& rhs) called" << std::endl;
    }

    Graph_base& operator=(const Graph_base& rhs) {
        std::cout << "Graph_base& operator=(const Graph_base& rhs) called" << std::endl;

        if (this != &rhs) {
            this->V = rhs.V;
            this->E = rhs.E;
            this->adjs = rhs.adjs;
        }
        return *this;
    }

    virtual ~Graph_base() {
        std::cout << "~Graph_base() called" << std::endl;
    }

    const int numOfVertices() const {
        return this->V;
    }

    const int numOfEdges() const {
        return this->E;
    }

    virtual void addEdges(int v, int w) = 0;

    const int degree(int v) const {
        return adjs[v].size();
    }

    const std::set<int>& getAdj(int v) const {
        return adjs[v];
    }

};

#endif //ALGORITHM_CPP_GRAPH_BASE_HPP
