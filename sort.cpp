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

//template <typename T>

int main() {
    int n = 100;
    int *arrSelection = SortTestHelper::generateRandomArray(n, 0, n);
    int *arrInsertion = SortTestHelper::copyIntArray(arrSelection, n);
    int *arrInsertion2 = SortTestHelper::copyIntArray(arrSelection, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arrSelection, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arrInsertion, n);
    SortTestHelper::testSort("Insertion Sort2", insertionSortImproved, arrInsertion2, n);
    delete[] arrSelection;
    delete[] arrInsertion;
    delete[] arrInsertion2;
    return 0;
}
