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
//    std::vector<int> prev;
//    std::vector<int> post;
//    std::vector<int> parent;

    void clearMarked() {
        marked = std::vector<bool>(graph.numOfVertices(), false);
//        prev = std::vector<int>(graph.numOfVertices(), -1);
//        post = std::vector<int>(graph.numOfVertices(), -1);
//        parent = std::vector<int>(graph.numOfVertices(), -1);
    }

    static void printVector(const std::vector<int>& vec) {
        for(auto iter = vec.cbegin(); iter != vec.cend(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }

    void validateVertex(int v) {
        if (v < 0 || v >= graph.numOfVertices()) {
            throw std::invalid_argument("v is not valid vertex");
        }
    }

    void recursiveDFSHelper(int s);

    int recursiveDFSWithOrderHelper(int s, int clock, std::vector<int>& prev, std::vector<int>& post, std::vector<int>& parent);

public:
    DepthFirstSearch(const Graph_base& g):graph(g) {
        clearMarked();
    }

    void iterativeDFS(int s);

    void recursiveDFS(int s);

    void dfsAll();

    int countComponent();


    void recursiveDFSWithOrder(int s);

    void recursiveDFSWithOrderAll();

};


#endif //ALGORITHM_CPP_DEPTHFIRSTSEARCH_HPP
