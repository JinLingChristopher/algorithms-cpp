#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int leastInterval(vector<char> &tasks, int n) {
    vector<int> counter(26, 0);
    for (auto c : tasks) {
        counter[c - 'A']++;
    }
    std::sort(counter.begin(), counter.end());
    int maxVal = counter[25] - 1;
    int idle = maxVal * n;
    for (int i = 24; i >= 0 && counter[i] > 0; --i) {
        idle -= std::min(counter[i], maxVal);
    }
    return idle > 0 ? idle + tasks.size() : tasks.size();
}

int main() {
    vector<char> tasks{'A', 'A', 'A', 'C', 'C', 'C',
                       'D', 'A', 'B', 'B', 'B', 'B'};
    int n = 4;
    cout << leastInterval(tasks, n) << endl;
    return 0;
}
