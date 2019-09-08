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

int hoare_partition(int* arr, int lo, int hi, int p) {
	std::swap(arr[p], arr[hi]);
	int i = lo, j = hi - 1;
	while (i < j) {
		while (arr[i] < arr[hi]) {
			i++;
		}
		while (arr[j] > arr[hi]) {
			j--;
		}
		if (i >= j) {
			break;
		}
		std::swap(arr[i++], arr[j--]);
	}
	std::swap(arr[hi], arr[j + 1]);
	return j + 1;
}

void quick_sort(int* arr, int lo, int hi) {
	if ((hi - lo) > 0) {
		int pivot = get_pivot(arr, lo, hi);
		// int r = lomuto_partition(arr, lo, hi, pivot);
		int r = hoare_partition(arr, lo, hi, pivot);
		quick_sort(arr, lo, r - 1);
		quick_sort(arr, r + 1, hi);
	}
}

void quick_sort(int* arr, int n) {
  	quick_sort(arr, 0, n-1);
}

int main() {
	int arr[] = {2, 1};
	quick_sort(arr, sizeof(arr) / sizeof(arr[0]));
	for (const int& item: arr) {
		cout << item << " ";
	}
	cout << endl;
	return 0;
}
