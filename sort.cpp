#include <iostream>
#include <utility>
#include <algorithm>
#include "sortTestHelper.h"
using namespace std;

/* Selection Sort
 * Always select the minimum value of unsorted array
 * Then add it to the tail of sorted array
 */
template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

/* Insertion Sort
 * Always comparing the current value with the previous value
 * Then insert it in the proper position
 * This means that the array before current position is always ordered
 */
template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0; --j) {
            if (arr[j] < arr[j-1])
                swap( arr[j], arr[j-1] );
            else
                break;
        }
    }
}

/* Improved Insertion Sort
 * The insertion sort mention above is time-consuming, since we use swap operation for many times
 * The improved insertion sort uses move operation instead of swap operation, so it is more time-saving.
 * Insertion Sort is very suitable for nearly ordered array
 * The time complexity is O(n) if the array is ordered
 */
template<typename T>
void insertionSortImproved(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > e; --j) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

template<typename T>
void bubbleSort(T arr[], int n) {
    for (int i = n; i > 0; --i) {
        for (int j = 1; j < i; ++j) {
            if (arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);
        }
    }
}

template<typename T>
void bubbleSortImproved(T arr[], int n) {
    while (n > 1) {
        cout << n << endl;
        int newn = 0;
        for (int j = 1; j < n; ++j) {
            if (arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
                newn = j;
            }
        }
        n = newn;
    }
}

template<typename T>
void shellSort(T arr[], int n) {

}


int main() {
    int n = 100;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSortImproved, arr, n);
    delete[] arr;
    return 0;
}
