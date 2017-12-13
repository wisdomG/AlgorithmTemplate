#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

/* Bubble Sort
 * Compared the value of adjacent element and swap the larger one to the back
 * This algorithm always put the maximal element int the end
 */
template<typename T>
void bubbleSortBasic(T arr[], int n) {
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
void bubbleSort(T arr[], int n) {
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

#endif
