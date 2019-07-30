//
// Created by king on 2019/7/31.
//

#include "UndirectedGraph.hpp"

using namespace std;

int main() {
    UndirectedGraph ug(5);

    ug.addEdges(0, 4);
    ug.addEdges(1, 3);

    cout << "There are total " << ug.numOfEdges() << endl;

    cout << ug << endl;

    return 0;
}