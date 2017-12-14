#ifndef SHELL_SORT_H
#define SEHLL_SORT_H

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

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

#endif
