//
// Created by king on 2019/8/9.
//

#ifndef ALGORITHM_CPP_EDGE_HPP
#define ALGORITHM_CPP_EDGE_HPP

#include <iostream>


class Edge {
private:
    int from;
    int to;
    int weight;

public:

    Edge() = delete;

    Edge(int v, int w, double weight){
        // std::cout << "Edge(int v, int w, double weight) called" << std::endl;
        if (v < 0) {
            throw std::invalid_argument("argument v is invalid");
        } else if (w < 0) {
            throw std::invalid_argument("argument w is invalid");
        }
        this->from = v;
        this->to = w;
        this->weight = weight;
    }

    Edge(const Edge& other):from(other.from), to(other.to), weight(other.weight) {
        std::cout << "Edge(const Edge& other) called" << std::endl;
    }

    Edge(Edge&& other) noexcept : from(std::move(other.from)), to(std::move(other.to)), weight(std::move(other.weight)) {
        std::cout << "Edge(const Edge&& other) called" << std::endl;
    }

    ~Edge() {
        std::cout << "~Edge() called" << std::endl;
    }

    int getWeight() const {
        return weight;
    }

    int getFrom() const {
        return from;
    }

    int getOther(int vertex) const {
        if (vertex == from) {
            return to;
        } else if (vertex == to) {
            return from;
        }
        throw std::invalid_argument("argument vertex is invalid");
    }

    int getTo() const {
        return to;
    }

    bool operator==(const Edge& other) const {
        bool from = this->from == other.from;
        bool to = this->to == other.to;
        bool weight = this->weight == other.weight;

        return from && to && weight;
    }

    bool operator!=(const Edge& other) const {
        return !(*this == other);
    }

    bool operator<(const Edge& other) const {
        bool from = this->from < other.from;
        bool to = this->to < other.to;
        bool weight = this->weight < other.weight;

        if (from) {            /* order matters here. */
            return true;
        } else if (to) {
            return true;
        } else if (weight) {
            return true;
        } else {
            return false;
        }
    }
};


#endif //ALGORITHM_CPP_EDGE_HPP
