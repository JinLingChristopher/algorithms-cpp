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



    void clearMarked() {
        marked = std::vector<bool>(graph.numOfVertices(), false);
    }

    void recursiveDFS_helper(int s);

    int recursiveDFSWithOrder_helper(int s, int* clock, std::vector<int>& prev, std::vector<int>& post);

public:

    UndirectedGraphSearch(const UndirectedGraph& g):graph(g) {
        std::cout << "UndirectedGraphSearch(const UndirectedGraph& g) called" << std::endl;
        clearMarked();
    }

    ~UndirectedGraphSearch() {
        std::cout <<"~UndirectedGraphSearch() called" << std::endl;
    }

    void RecursiveDFS(int s);
    void IterativeDFS(int s);

    void IterativeBFS(int s);

    void IterativeDFSAll();

    int countComponent();

    void recursiveDFSWithOrder(int s);

};


#endif //ALGORITHM_CPP_UNDIRECTEDGRAPHSEARCH_HPP
