#include <vector>
#include <iostream>

using namespace std;


void duplicateZeros(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        count += !arr[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        if (!arr[i]) {
            count -= 1;
            if (i + count < n) {
                arr[i + count] = 0;
            }
            if (i + count + 1 < n) {
                arr[i + count + 1] = 0;
            }
        } else if (i + count < n) {
            arr[i + count] = arr[i];
        }
    }

}

int main() {
    vector<int> nums{1, 0, 2, 3, 0, 4, 5, 0};

    duplicateZeros(nums);

    for (auto iter = nums.cbegin(); iter != nums.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}