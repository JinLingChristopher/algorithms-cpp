//
// Created by king on 2019/8/15.
//

#include "ShortestPath.hpp"
#include "TopologicalSort.hpp"
#include <limits>
#include <queue>

void ShortestPath::init() {
    dist = std::vector<int>(graph.numOfVertices(), std::numeric_limits<int>::max());
    pred = std::vector<int>(graph.numOfVertices(), -1);
}

const std::set<Edge> ShortestPath::getAllEdges() const {
    std::set<Edge> result;
    for (int i = 0; i < graph.numOfVertices(); ++i) {
        auto edges = graph.getAdj(i);
        for (const auto& item: edges) {
            result.insert(item);
        }
    }
    return result;
}

void ShortestPath::relax(int u, int v) {
    dist[v] = dist[u] + graph.getEdge(u, v).getWeight();
    pred[v] = u;
}

void ShortestPath::bfsShortestPath(int s) {
    init();
    dist[s] = 0;
    std::queue<int> bag;
    bag.push(s);

    while (!bag.empty()) {
        int u = bag.front();
        bag.pop();
        for (const auto& item: graph.getAdj(u)) {
            int v = item.getTo();
            if (dist[v] > dist[u] + item.getWeight()) {
                dist[v] = dist[u] + item.getWeight();
                pred[v] = u;
                bag.push(v);
            }
        }
    }
}

void ShortestPath::bellman_ford(int s) {
    init();
    dist[s] = 0;
    std::vector<bool> onQueue(graph.numOfVertices(), false);

    std::queue<int> bag;
    bag.push(s);
    onQueue[s] = true;

    while (!bag.empty()) {
        int v = bag.front();
        bag.pop();
        onQueue[v] = false;

        for (const auto& item: graph.getAdj(v)) {
            int w = item.getTo();
            if (dist[w] > dist[v] + item.getWeight()) {
                dist[w] = dist[v] + item.getWeight();
                pred[w] = v;
                if (!onQueue[w]) {
                    bag.push(w);
                    onQueue[w] = true;
                }
            }
        }
    }
}

void ShortestPath::dijkstra(int s) {
    auto cmp = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    };

    init();
    dist[s] = 0;
    std::vector<std::pair<int, int>> min_heap;
    min_heap.push_back(std::make_pair(s, 0));

    while (!min_heap.empty()) {
        auto pair = min_heap.front();
        std::pop_heap(min_heap.begin(), min_heap.end());
        min_heap.pop_back();
        int u = pair.first;
        for (const auto& item: graph.getAdj(u)) {
            int v = item.getTo();
            if (dist[v] > dist[u] + item.getWeight()) {
                dist[v] = dist[u] + item.getWeight();
                pred[v] = u;
                int find = -1;
                for (int i = 0; i < min_heap.size(); ++i) {
                    if (min_heap[i].first == v) {
                        find = i;
                        break;
                    }
                }
                if (find != -1) {
                    min_heap[find].second = dist[v];
                } else {
                    min_heap.push_back(std::make_pair(v, dist[v]));
                }
            }
        }
        std::make_heap(min_heap.begin(), min_heap.end(), cmp);
    }
}

const std::vector<int> &ShortestPath::getDist() const {
    return this->dist;
}

