#ifndef SORTTESTHELPER_H
#define SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

namespace SortTestHelper {

    int* generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    void printArray(int arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }

    bool isSorted(int arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i+1]) return false;
        }
        return true;
    }

    void testSort(const string sortName, void(*sort)(int arr[], int n), int arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << ": " << double(endTime-startTime)/CLOCKS_PER_SEC << " s" << endl;
    }

    int* copyIntArray(int a[], int n) {
        int* arr = new int[n];
        copy(a, a+n, arr);
        return arr;
    }
}

#endif
