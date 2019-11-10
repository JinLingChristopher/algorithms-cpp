#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> result;
    for(int i = 0; i <= rowIndex; ++i){
        result.push_back(1);
        for(int j = i - 1; j > 0; --j){
            result[j] += result[j - 1];
        }
    }
    return result;
}

int main() {

    auto result = getRow(3);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}