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

/* Bubble Sort
 * Compared the value of adjacent element and swap the larger one to the back
 * This algorithm always put the maximal element int the end
 */
template<typename T>
void bubbleSort(T arr[], int n) {
    // Outer loop control the right edge
    for (int i = n; i > 0; --i) {
        for (int j = 1; j < i; ++j) {
            if (arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);
        }
    }
}

/* Improved Bubble Sort
 * The bubble sort always find the maximal value before current position and put it on the current position
 * If there are no any swap operation after current, we can know that the array after current position is ordered.
 * Therefore, the next right boundary is current position, which improve the basic bubble sort method;
 * Besides, the time complexity is O(n) if the array is ordered, since it doesn't need any swap operation in this situation.
 */
template<typename T>
void bubbleSortImproved(T arr[], int n) {
    while (n > 1) {
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

/* Shell Sort
 * Choose a step length h and divide the array into h groups
 * Then use insertion sort for each group
 * reduce h and repeat the operations above until h = 1
 * We can see that shell sort is also an improved method based on insertion sort
 * And this method achieves the best performance among the four methods (Selection, Insertion, Bubble)
 */
template<typename T>
void shellSort(T arr[], int n) {
    int h = 1;
    while (h < n/3) h = 3 * h + 1;
    while (h >= 1) {
        for (int i = h; i < n; ++i) {
            // use insertion sort for arr[i], arr[i-h], arr[i-2*h]
            T e = arr[i];
            int j = i;
            for (; j >= h && e < arr[j-h]; j -= h) {
                arr[j] = arr[j-h];
            }
            arr[j] = e;
        }
        h /= 3;
    }
}

