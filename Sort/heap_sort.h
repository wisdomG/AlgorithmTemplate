#include <iostream>
#include "../Heap/heap.h"
using namespace std;

/* heapSort with heap class
 */
template<typename T>
void heapSort0(T arr[], int n) {
    MaxHeap<T> maxHeap(arr, n);
    for (int i = n - 1; i >= 0; --i) {
        arr[i] = maxHeap.extractMax();
    }
}

template<typename T>
void __shiftDown(T arr[], int n, int k) {
    while (2*k + 1 < n) {
        int j = 2 * k + 1;
        if (j + 1 < n && arr[j+1] > arr[j]) {
            j += 1;
        }
        if (arr[k] >= arr[j])
            break;
        swap(arr[k], arr[j]);
        k = j;
    }
}

/* heapSort at position
 * parent (i-1)/2
 * left child: i*2 + 1
 * right child: i*2 + 2
 * the index of last non-leaf node is (n-1)/2
 */
template<typename T>
void heapSort(T arr[], int n) {
    for (int i = (n-1)/2; i >= 0; --i) {
        __shiftDown(arr, n, i);
    }
    for (int i = n-1; i > 0; --i) {
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }

}
