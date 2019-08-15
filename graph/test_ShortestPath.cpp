//
// Created by king on 2019/8/15.
//

#include "gtest/gtest.h"
#include "ShortestPath.hpp"

const DirectedWeightedGraph buildWeightedGraphNoNegative() {
    DirectedWeightedGraph g(7);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 3, 4);
    g.addEdge(1, 0, 4);
    g.addEdge(1, 3, 8);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 12);
    g.addEdge(3, 4, 0);
    g.addEdge(3, 5, 5);
    g.addEdge(4, 1, 10);
    g.addEdge(4, 6, 3);
    g.addEdge(5, 4, 1);
    g.addEdge(5, 6, 2);

    return g;
}

TEST(ShortestPath, dijkstra) {
    auto graph = buildWeightedGraphNoNegative();
    ShortestPath solver(graph);
    solver.dijkstra(0);

    std::vector<int> expected{0, 14, 3, 4, 4, 9, 7};
    auto result = solver.getDist();
    EXPECT_EQ(result, expected);

    for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}