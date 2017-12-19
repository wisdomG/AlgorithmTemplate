#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <iostream>
#include <cassert>
using namespace std;

/* binarySearch
 */
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

/* binarySearch
 * recurrence function
 */
template<typename T>
int __binary_search(T arr[], int l, int r, T target) {
    if (l > r) return -1;
    int mid = l + (r-l)/2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] > target)
        return __binary_search(arr, l, mid-1, target);
    else
        return __binary_search(arr, mid+1, r, target);
}

/* binarySearch
 * recurrence version
 */
template<typename T>
int binarySearch2(T arr[], int n, T target) {
    return  __binary_search(arr, 0, n-1, target);
}

/* floor
 * return the index of lash element less than target
 * if there are no elements less than target, then return -1;
 */
template<typename T>
int floor(T arr[], int n, T target) {
    int l = 0, r = n - 1;
    while (l <= r) {
        if ( l == r || l + 1 == r ) {
            while (r >= 0 && arr[r] >= target) --r;
            return r;
        }
        int mid = l + (r-l) / 2;
        if (arr[mid] >= target)
            r = mid - 1;
        else l = mid;
    }
}

/* ceil
 * return the index of first element greater than target
 * if there are no elements greater than target, then return n
 */
template<typename T>
int ceil(T arr[], int n, T target) {
    int l = 0, r = n - 1;
    while (l <= r) {
        if (l == r || l + 1 == r) {
            while (l < n && arr[l] <= target) ++l;
            return l;
        }
        int mid = l + (r-l) / 2;
        if (arr[mid] <= target)
            l = mid + 1;
        else r = mid;
    }
}

#endif
