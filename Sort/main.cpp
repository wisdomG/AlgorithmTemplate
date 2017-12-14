#include <iostream>
#include "selection_sort.h"
#include "insertion_sort.h"
#include "bubble_sort.h"
#include "shell_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"
#include "sort_test_helper.h"
using namespace std;

const int n = 10000;

enum testCase {BasicArray, NearlyOrderedArray, RepeatingArray};

void testCase(int caseNum, string name, void (*sort)(int[], int)) {
    if (caseNum == BasicArray) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        SortTestHelper::testSort(name, sort, arr, n);
        delete[] arr;
    } else if (caseNum == NearlyOrderedArray) {
        int *arr = SortTestHelper::generateNearlyOrderedArray(n, 10);
        SortTestHelper::testSort(name, sort, arr, n);
        delete[] arr;
    } else if (caseNum == RepeatingArray) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, 10);
        SortTestHelper::testSort(name, sort, arr, n);
        delete[] arr;
    }
}

void testSort() {
    cout << "============BasicArray=================" << endl;
    testCase(BasicArray, "Selection Sort", selectionSort);
    testCase(BasicArray, "Insertion Sort", insertionSort);
    testCase(BasicArray, "   Bubble Sort", bubbleSort);
    testCase(BasicArray, "    Shell Sort", shellSort);
    testCase(BasicArray, "    Merge Sort", mergeSort);
    testCase(BasicArray, "    Quick Sort", quickSort);
    testCase(BasicArray, "  Quick Sort 3", quickSort);
    testCase(BasicArray, "     Heap Sort", heapSort);

    cout << "============NearlyOrderedArray=========" << endl;
    testCase(NearlyOrderedArray, "Selection Sort", selectionSort);
    testCase(NearlyOrderedArray, "Insertion Sort", insertionSort);
    testCase(NearlyOrderedArray, "   Bubble Sort", bubbleSort);
    testCase(NearlyOrderedArray, "    Shell Sort", shellSort);
    testCase(NearlyOrderedArray, "    Merge Sort", mergeSort);
    testCase(NearlyOrderedArray, "    Quick Sort", quickSort);
    testCase(NearlyOrderedArray, "  Quick Sort 3", quickSort);
    testCase(NearlyOrderedArray, "     Heap Sort", heapSort);

    cout << "============RepeatingArray=============" << endl;
    testCase(RepeatingArray, "Selection Sort", selectionSort);
    testCase(RepeatingArray, "Insertion Sort", insertionSort);
    testCase(RepeatingArray, "   Bubble Sort", bubbleSort);
    testCase(RepeatingArray, "    Shell Sort", shellSort);
    testCase(RepeatingArray, "    Merge Sort", mergeSort);
    testCase(RepeatingArray, "    Quick Sort", quickSort);
    testCase(RepeatingArray, "  Quick Sort 3", quickSort3Ways);
    testCase(RepeatingArray, "     Heap Sort", heapSort);

}

int main() {
    testSort();
    return 0;
}
