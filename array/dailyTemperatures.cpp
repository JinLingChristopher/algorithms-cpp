#include <iostream>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(const vector<int> &nums) {
    int n = nums.size();
    vector<int> result(n, 0);
    for (int i = n - 2; i >= 0; --i) {
        int j = i + 1;
        while (j < n) {
            if (nums[j] > nums[i]) {
                result[i] = j - i;
                break;
            } else if (result[j] == 0) {
                break;
            } else {
                j += result[j];
            }
        }
    }

    return result;
}

int main() {
    vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
    auto result = dailyTemperatures(temperatures);
    for (auto item : result) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
