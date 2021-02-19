//
// Created by Edison King on 2020/4/8.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class AnimalShelf {
    list<vector<int>> animals;

  public:
    AnimalShelf() {

    }

    void enqueue(vector<int> animal) {
        animals.push_back(animal);
    }

    vector<int> dequeueAny() {
        if (animals.size()) {
            auto t = animals.front();
            animals.pop_front();
            return t;
        }
        return vector<int>{-1, -1};
    }

    vector<int> dequeueDog() {
        for (auto iter = animals.begin(); iter != animals.end(); ++iter) {
            if ((*iter)[1] == 1) {
                auto t = *iter;
                animals.erase(iter);
                return t;
            }
        }
        return vector<int>{-1, -1};
    }

    vector<int> dequeueCat() {
        for (auto iter = animals.begin(); iter != animals.end(); ++iter) {
            if ((*iter)[1] == 0) {
                auto t = *iter;
                animals.erase(iter);
                return t;
            }
        }
        return vector<int>{-1, -1};
    }
};

void printAnimal(const vector<int>& animal) {
    cout << animal[0] << " " << animal[1] << endl;
}

int main() {
    AnimalShelf as;
    as.enqueue(vector<int>{0, 0});
    as.enqueue(vector<int>{1, 0});
    auto t = as.dequeueCat();
    printAnimal(t);

    t = as.dequeueDog();
    printAnimal(t);

    t = as.dequeueAny();
    printAnimal(t);


    return 0;
}
