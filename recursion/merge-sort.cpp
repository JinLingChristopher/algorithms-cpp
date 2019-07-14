#include <stdio.h>


void merge(int* arr, int lo, int mid, int hi, int* aux) {
  int i = lo, j = mid + 1;
  for (int k = lo; k <= hi; ++k) {
    if (j > hi) {
      aux[k] = arr[i++];
    } else if (i > mid) {
      aux[k] = arr[j++];
    } else if (arr[i] < arr[j]) {
      aux[k] = arr[i++];
    } else {
      aux[k] = arr[j++];
    }
  }

  for (int k = lo; k <= hi; k++) {
    arr[k] = aux[k];
  }
}

void merge_sort(int* arr, int lo, int hi, int* aux) {
  if ((hi - lo + 1) > 1) {
    int mid = lo + (hi - lo) / 2;
    merge_sort(arr, lo, mid, aux);
    merge_sort(arr, mid+1, hi, aux);
    merge(arr, lo, mid, hi, aux);
  }
}

void merge_sort(int* arr, int n) {
  int* aux = new int[n];
  merge_sort(arr, 0, n-1, aux);
  delete[] aux;
}


int main() {
  int arr1[] = {};
  merge_sort(arr1, 0);

  int arr2[] = {3, 1, 4, 1, 5, 9, 2, 6, 7, 2, 10, 8, 10};
  merge_sort(arr2, sizeof(arr2)/sizeof(arr2[0]));
  
  int n = sizeof(arr2) / sizeof(arr2[0]);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr2[i]);
  }
  printf("\n");
  
  return 0;
}
