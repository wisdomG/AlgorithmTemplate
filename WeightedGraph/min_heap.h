#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <vector>
#include <iostream>
using namespace std;

/* MinHeap
 * Implement by myself
 */
template<typename T>
class MinHeap {
private:
    vector<T> heap;

public:

    // insert an element and use shiftup method to maintain the minimum heap
    void insert(T ele) {
        heap.push_back(ele);
        int cur = heap.size()-1;
        int par = (cur - 1) / 2;
        while (par >= 0 && heap[par] > heap[cur]) {
            swap(heap[par], heap[cur]);
            cur = par;
            if (cur == 0) break;
            par = (cur - 1) / 2;
        }
    }

    // remove and return heap[0], then use shiftdown method to maintain the heap
    T extractMin() {
        T ret = heap[0];
        swap(heap[0], heap.back());
        heap.pop_back();
        int cur = 0;
        while(2*cur + 1 < heap.size()) {
            int lchild = 2*cur + 1;
            if (lchild+1 < heap.size() && heap[lchild+1] < heap[lchild]) {
                lchild += 1;
            }
            if (heap[cur] < heap[lchild]) break;
            swap(heap[cur], heap[lchild]);
            cur = lchild;
        }
        return ret;
    }

    bool empty() {
        return heap.size() == 0;
    }

    void show() {
        for (int i = 0; i < heap.size(); ++i) {
            cout << heap[i] << ' ';
        }
        cout << endl;
    }
};

#endif
