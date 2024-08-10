#include <iostream>
using namespace std;

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
      int i = 0, j = 0, k = 0;

      while (i < leftSize && j < rightSize) {
            if (left[i] <= right[j]) {
                  arr[k++] = left[i++];
            } else {
                  arr[k++] = right[j++];
            }
      }

      while (i < leftSize) {
            arr[k++] = left[i++];
      }

      while (j < rightSize) {
            arr[k++] = right[j++];
      }
}

void mergeSort(int arr[], int size) {
      if (size <= 1) {
            return;
      }

      int mid = size / 2;
      int left[mid];
      int right[size - mid];

      for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
      }

      for (int i = mid; i < size; i++) {
            right[i - mid] = arr[i];
      }

      mergeSort(left, mid);
      mergeSort(right, size - mid);
      merge(arr, left, mid, right, size - mid);
}

int main() {
      int arr[] = {5, 2, 8, 12, 3};
      int size = sizeof(arr) / sizeof(arr[0]);

      cout << "Original array: ";
      for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
      }
      cout << endl;

      mergeSort(arr, size);

      cout << "Sorted array: ";
      for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
      }
      cout << endl;

      return 0;
}