//
// Created by king on 2019/7/31.
//

#include "DirectedGraph.hpp"

using namespace std;

std::ostream& operator<<(std::ostream &os, const DirectedGraph &g) {
    for (int i = 0; i < g.numOfVertices(); ++i) {
        os << i << ": ";
        const set<int>& ref = g.getAdj(i);
        for (auto iter = ref.cbegin(); iter != ref.cend(); ++iter) {
            os << *iter <<" ";
        }
        os << endl;
    }
    return os;
}