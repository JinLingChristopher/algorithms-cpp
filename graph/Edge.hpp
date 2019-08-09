//
// Created by king on 2019/8/9.
//

#ifndef ALGORITHM_CPP_EDGE_HPP
#define ALGORITHM_CPP_EDGE_HPP


class Edge {
private:
    int from;
    int to;
    doubel weight;

public:
    Edge(int v, int w, double weight){
        std::cout << "Edge(int v, int w, double weight) called" << std::endl;
        if (v < 0) {
            throw std::invalid_argument("argument v is invalid");
        } else if (w < 0) {
            throw std::invalid_argument("argument w is invalid");
        }
        this->from = v;
        this->to = w;
        this->weight = weight;
    }

    double getWeight() {
        return weight;
    }

    int getFrom() {
        return from;
    }

    int getOther(int vertex) {
        if (vertex == from) {
            return to;
        } else if (vertex == to) {
            return from;
        }
        throw std::invalid_argument("argument vertex is invalid");
    }


};


#endif //ALGORITHM_CPP_EDGE_HPP