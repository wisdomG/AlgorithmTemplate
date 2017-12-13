#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <iostream>
#include <utility>
#include <algorithm>
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

#endif
