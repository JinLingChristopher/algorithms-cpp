#include <algorithm>
#include <iostream>

using namespace std;


int get_pivot(int* arr, int lo, int hi) {
  	int mi = lo + (hi - lo) / 2;
  	int a = arr[lo];
  	int b = arr[mi];
  	int c = arr[hi];
  	int mid = std::max(std::min(a, b), c);

	int argmid = -1;
	if (mid == a) {
		argmid = lo;
	} else if (mid == b) {
		argmid = mi;
	} else if (mid == c) {
		argmid = hi;
	}
	return argmid;
}

int lomuto_partition(int* arr, int lo, int hi, int p) {
	std::swap(arr[p], arr[hi]);
	int j = lo - 1;
	for (int i = lo; i < hi; ++i) {
		if (arr[i] < arr[hi]) {
			j += 1;
			std::swap(arr[j], arr[i]);
		}
	}
	std::swap(arr[hi], arr[j + 1]);
	return j + 1;
}

/**
 * quick-select, find the kth element in an unordered array
*/

int quick_select(int*arr, int lo, int hi, int k) {
    if ((hi - lo) == 0) {
        return arr[lo];
    }
    int p = get_pivot(arr, lo, hi);
    int r = lomuto_partition(arr, lo, hi, p);
    if (k < r) {
        return quick_select(arr, lo, r - 1, k);
    } else if (k > r) {
        return quick_select(arr, r + 1, hi, k);
    } else {
        return arr[r];
    }
}

int quick_select(int* arr, int n, int k) {
    return quick_select(arr, 0, n - 1, k);
}

int main() {
    int arr[] = {1, 3, 2, 4, 7, 8, 5, 6, 10, 9};
    int kth[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++) {
        int ret = quick_select(arr, sizeof(arr) / sizeof(arr[0]), i);
        cout << "the " << kth[i] << " element is " << ret << endl;
    }

    return 0;
}