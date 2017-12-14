#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;


/* Insertion Sort
 * Always comparing the current value with the previous value
 * Then insert it in the proper position
 * This means that the array before current position is always ordered
 */
template<typename T>
void insertionSortBasic(T arr[], int n) {
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
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T e = arr[i];
        int j = i;
        for (; j > 0 && arr[j-1] > e; --j) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}
// sort arr[l, r]
template<typename T>
void insertionSort(T arr[], int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        T e = arr[i];
        int j = i;
        for (; j > l && arr[j-1] > e; --j) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

#endif
