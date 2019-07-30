#include <algorithm>
#include <iostream>

using namespace std;


int get_pivot(int* arr, int lo, int hi) {
  	int mi = lo + (hi - lo) / 2;
  	int a = arr[lo];
  	int b = arr[mi];
  	int c = arr[hi];

    int median = a + b + c - std::max(std::max(a, b), c) - std::min(std::min(a, b), c);

    if (median == a) {
        return lo;
    } else if (median == b) {
        return mi;
    } else {
        return hi;
    }
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

int mom_select(int* arr, int lo, int hi, int k) {
    int n = hi - lo + 1;
    if (n <= 25) {
        int mid = n / 2;
        if (n % 2 == 1) {
            mid += 1;
        }
        return quick_select(arr, lo, hi, mid);
    }
    int m = n / 5;
    if (n % 5 != 0) {
        m += 1;
    }
    
    int* medians = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        medians[i] = quick_select(arr, i * 5, i * 5 + 4, i * 5 + 2);
    }
    int mom = mom_select(medians, 0, m - 1, m / 2);
    free(medians);

    int r = lomuto_partition(arr, lo, hi, mom);
    if (k < r) {
        return mom_select(arr, lo, r - 1, k);
    } else if (k > r) {
        return mom_select(arr, lo + 1, hi, k - r);
    } else {
        return mom;
    }
}

int mom_select(int* arr, int n, int k) {
    return mom_select(arr, 0, n - 1, k);
}

int main() {
    int arr[] = {9, 22, 3, 6, 17, 16, 7, 8, 5, 1, 3, 18, 2, 11, 12, 4, 5, 10, 1, 4, 13, 14, 14, 19, 20, 21, 15, 2, 5, 6};
    int median = mom_select(arr, sizeof(arr) / sizeof(arr[0]), 5);
    cout << "median: " << median << endl;

    return 0;
}