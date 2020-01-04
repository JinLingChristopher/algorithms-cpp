
using namespace std;

void eat(vector<vector<int>> &breads) {
    int idx = -1;
    vector<int> best = breads[0];
    for (int i = 0; i < breads.size(); ++i) {
        if (breads[i][0] > best[0] && breads[i][0] > 0 &&
            breads[i][1] > best[1]) {
            best = breads[i];
            idx = i;
        }
            }
    }
