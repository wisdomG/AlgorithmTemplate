#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <iostream>
using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r-l) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

template<typename T>
__binary_search(T arr[], int l, int r, T target) {

}

template<typename T>
int binarySearch2(T arr[], int n, T target) {
    __binary_search(arr, 0, n, target);
}


// floor and ceil
// floor 返回比tar小的数的最后位置，ceil返回比tar大的最开始位置
#endif
