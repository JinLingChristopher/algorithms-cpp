#include <vector>
using namespace std;

void solver(const vector<int>& rating, int start, vector<int> curr,
            int& count) {
    if (curr.size() == 3) {
        count += 1;
        return;
    }
    for (int i = start; i < rating.size(); ++i) {
        if (curr.size() == 0) {
            curr.push_back(rating[i]);
            solver(rating, start + 1, curr, count);
        } else if (rating[i] > curr.back() || rating[i] < curr.back()) {
            curr.push_back(rating[i]);
            solver(rating, start + 1, curr, count);
        }
    }
}

int numTeams(vector<int>& rating) {
    int result = 0;
    vector<int> t;
    solver(rating, 0, t, result);

    return result;
}

int main() {
    vector<int> rating{2, 5, 3, 4, 1};
    int result = numTeams(rating);
    return 0;
}
