#include <iostream>
#include <algorithm>
#include <cassert>
#include <utility>
using namespace std;

/* MaxHeap
 * the index is from 1
 * parent of i: i/2
 * left child of i: i * 2;
 * right child of i: i * 2 + 1
 */
template<typename T>
class MaxHeap {
private:
    T *data;
    int cnt;
    int capacity;

    // Shife Up, comparing with the parent node
    void shiftUp(int k) {
        while (k > 1 && data[k/2] < data[k]) {
            swap(data[k/2], data[k]);
            k /= 2;
        }
    }
    // Shift Down, comparing with the child node
    void shiftDown(int k) {
        while (k * 2 <= cnt) {
            int j = k * 2; //record the position that may swap with k
            if (j + 1 <= cnt && data[j+1] > data[j])
                j += 1;
            if (data[k] >= data[j])
                break;
            swap(data[k], data[j]);
            k = j;
        }
    }

public:
    MaxHeap(int capacity) {
        data = new T[capacity + 1];
        cnt = 0;
        this->capacity = capacity;
    }
    // heapify O(n)
    // Since we heapify the heap using half of nodes
    MaxHeap(T arr[], int n) {
        data = new T[n+1];
        capacity = n;
        for (int i = 0; i < n; ++i)
            data[i+1] = arr[i];
        cnt = n;
        for (int i = cnt/2; i >= 1; --i)
            shiftDown(i);
    }
    ~MaxHeap() { delete[] data; }
    int size() { return cnt; }
    bool empty() { return cnt == 0; }

    // insert into last position and adjust heap with shiftUp
    void insert(T item) {
        assert(cnt + 1 <= this->capacity);
        data[cnt + 1] = item;
        ++cnt;
        shiftUp(cnt);
    }

    // return the maximal element, the use the last element as the top of heap and adjust it with shiftDown
    T extractMax() {
        assert(cnt > 0);
        T item = data[1];
        swap(data[1], data[cnt]);
        --cnt;
        shiftDown(1);
        return item;
    }

    void print() {
        for_each(data+1, data+cnt+1, [](T item){ cout << item << " ";});
        cout << endl;
    }
};

