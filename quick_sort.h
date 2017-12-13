#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>
#include <utility>
#include <ctime>
#include <algorithm>
#include "insertion_sort.h"
using namespace std;

/*
 * partition for arr[l, r]
 * return p, s.t. arr[l, p-1] < arr[p] < arr[p+1, r]
 */
template<typename T>
int __partition(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r-l+1) + l]);
    T v = arr[l];
    // maintain arr[l+1, j] < v, arr[j+1, i) > v
    int j = l;
    for (int i = l + 1; i <= r; ++i) {
        if (arr[i] < v) {
            swap(arr[j+1], arr[i]);
            ++j;
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

template<typename T>
int __partition2(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r-l+1) + l]);
    T v = arr[l];
    // arr[l+1, i) <= v, arr(j,r] >= v
    int i = l + 1, j = r;
    while (1) {
        while (i <= r && arr[i] < v) ++i;
        while (j >= l+1 && arr[j] > v) --j;
        if (i > j) break;
        swap(arr[i], arr[j]);
        ++i, --j;
    }
    swap(arr[l], arr[j]);
    return j;
}

template<typename T>
void __quickSort(T arr[], int l, int r) {
    if (l >= r) return;
    // can be improved with insertion sort
    int p = __partition2(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

/*
 * If we use the first element as our anchor, it will become O(n^2) when the array is nearly ordered.
 * So we select anchor randomly
 */
template<typename T>
void quickSort(T arr[], int n) {
    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}

/* __quickSort3Ways
 * arr[l, lt] < v; arr[lt+1, gt-1] == v; arr[gt, r] >= v
 */
template<typename T>
void __quickSort3Ways(T arr[], int l, int r) {
    if (l >= r) return ;
    // can be improved with insertion sort
    // partition
    swap(arr[l], arr[rand() % (r-l+1) + l]);
    T v = arr[l];
    int lt = l; // arr[l+1, lt] < v;
    int gt = r + 1; // arr[gt, r] > v;
    int i = l+1; // arr[lt+1, i) = t
    while (i < gt) {
        if (arr[i] < v) {
            swap(arr[i], arr[lt+1]);
            ++lt, ++i;
        } else if (arr[i] > v) {
            swap(arr[i], arr[gt-1]);
            --gt;
        } else ++i;
    }
    swap(arr[l], arr[lt]);
    __quickSort3Ways(arr, l, lt);
    __quickSort3Ways(arr, gt, r);
}

/* quickSort3Ways
 * It's suitable for the array that contains many repeating elements
 */
template<typename T>
void quickSort3Ways(T arr[], int n){
    srand(time(NULL));
    __quickSort(arr, 0, n-1);

}

#endif
