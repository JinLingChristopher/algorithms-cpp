#include <vector>
#include <iostream>

using namespace std;

vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    int** table = (int**)malloc(sizeof(int*)*N);
    for (int i = 0; i < N; ++i) {
        table[i] = (int*)malloc(sizeof(int)*N);
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                table[i][j] = 0;
            } else {
                table[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < edges.size(); ++i) {
        vector<int>& e = edges[i];
        table[e[0]][e[1]] = 1;
        table[e[1]][e[0]] = 1;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (table[i][j] == -1) {
                for (int k = 0; k < N; ++k) {
                    if ((table[i][k] != -1) && (table[k][j] != -1)) {
                        if (table[i][j] == -1) {
                            table[i][j] = table[i][k] + table[k][j];
                        } else {
                            table[i][j] = std::min(table[i][k] + table[k][j], table[i][j]);
                        }
                    }
                }
            }
        }
    }

    vector<int> result;
    for (int i = 0; i < N; ++i) {
        int t = 0;
        for (int j = 0; j < N; j++) {
            t += table[i][j];
        }
        result.push_back(t);
    }

    for (int i = 0; i < N; ++i) {
        free(table[i]);
    }
    free(table);

    return result;
}

int main() {
    int n = 6;
    vector<vector<int>> edges{{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    auto result = sumOfDistancesInTree(n, edges);

    for (auto iter = result.cbegin(); iter != result.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}