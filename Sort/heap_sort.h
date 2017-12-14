#include <iostream>
#include "../Heap/heap.h"
using namespace std;

template<typename T>
void heapSort(T arr[], int n) {
    MaxHeap<T> maxHeap(arr, n);
    for (int i = n - 1; i >= 0; --i) {
        arr[i] = maxHeap.extractMax();
    }
}
