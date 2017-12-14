#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>
#include <utility>
#include <ctime>
#include <algorithm>
#include "insertion_sort.h"
using namespace std;

/* __merge
 * merge arr[l, mid] and arr[mid+1, r]
 */
template<typename T>
void __merge(T arr[], int l, int mid, int r) {
    T aux[r-l+1];
    for (int i = l; i <= r; ++i)
        aux[i-l] = arr[i];
    int i = l, j = mid+1;
    for (int k = l; k <= r; ++k) {
        if (i > mid) {
            arr[k] = aux[j-l], ++j;
        } else if (j > r) {
            arr[k] = aux[i-l], ++i;
        } else if (aux[j-l] > aux[i-l]){
            arr[k] = aux[i-l], ++i;
        } else {
            arr[k] = aux[j-l], ++j;
        }
    }
}

/* __mergesort
 * mergesort arr[l, r]
 */
template<typename T>
void __mergeSort(T arr[], int l, int r) {
    if (l >= r) return ;
    // improve: when the number of elements is less than a threshold, employ insertion sort
    //if (r-l < 15) {insertionSort(arr, l, r); return;}
    int mid = l + (r - l) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    if (arr[mid] > arr[mid+1])
        __merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n-1);
}

/* Merge sort from bottom to top
 * It is suitable for linked list
 */
template<typename T>
void mergeSortBU(T arr[], int n) {
    for (int sz = 1; sz <= n; sz += sz) {
        for (int i = 0; i + sz < n; i += sz*2) {
            if (arr[i+sz-1] > arr[i+sz])
                __merge(arr, i, i+sz-1, min(i+sz*2-1, n-1));
        }
    }
}

#endif
