//
// Created by king on 2019/8/8.
//

#include "DetectCycle.hpp"

bool DetectCycle::isAcyclicDFS(int v) {
    status[v] = STATUS::ACTIVE;
    for (const auto item: graph.getAdj(v)) {
        if (status[item] == STATUS::ACTIVE) {
            return false;
        } else if (status[item] == STATUS::NEW) {
            if (isAcyclicDFS(item) == false) {
                return false;
            }
        }
    }
    status[v] = STATUS::FINISHED;
    return true;
}


bool DetectCycle::isAcyclic() {
    clearStatus();
    for (int i = 0; i < status.size(); ++i) {
        if (status[i] == STATUS::NEW) {
            if (isAcyclicDFS(i) == false) {
                return false;
            }
        }
    }
    return true;
}

