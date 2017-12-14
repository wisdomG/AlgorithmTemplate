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
class IndexMaxHeap {
private:
    T *data;
    int *indexes;
    int *reverse;
    int cnt;
    int capacity;

    // Shife Up, comparing with the parent node
    void shiftUp(int k) {
        while (k > 1 && data[indexes[k/2]] < data[indexes[k]]) {
            swap(indexes[k/2], indexes[k]);
            reverse[indexes[k/2]] = k/2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }
    // Shift Down, comparing with the child node
    void shiftDown(int k) {
        while (k * 2 <= cnt) {
            int j = k * 2; //record the position that may swap with k
            if (j + 1 <= cnt && data[indexes[j+1]] > data[indexes[j]])
                j += 1;
            if (data[indexes[k]] >= data[indexes[j]])
                break;
            swap(indexes[k], indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

public:
    IndexMaxHeap(int capacity) {
        data = new T[capacity + 1];
        indexes = new int[capacity + 1];
        reverse = new int[capacity + 1];
        for (int i = 0; i <= capacity; ++i)
            reverse[i] = 0;
        cnt = 0;
        this->capacity = capacity;
    }

    ~IndexMaxHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }
    int size() { return cnt; }
    bool empty() { return cnt == 0; }

    // idx >= 0
    void insert(int idx, T item) {
        assert(cnt + 1 <= this->capacity);
        assert(idx + 1 >= 1 && idx + 1 <= this->capacity);

        idx += 1;
        data[idx] = item;
        indexes[cnt+1] = idx;
        reverse[idx] = cnt + 1;
        ++cnt;
        shiftUp(cnt);
    }

    // return the maximal element, the use the last element as the top of heap and adjust it with shiftDown
    T extractMax() {
        assert(cnt > 0);
        T ret = data[indexes[1]];
        swap(indexes[1], indexes[cnt]);
        reverse[indexes[1]] = 1;
        reverse[indexes[cnt]] = 0;
        --cnt;
        shiftDown(1);
        return ret;
    }

    int extractMaxIndex() {
        assert(cnt > 0);
        int ret = indexes[1] - 1;
        swap(indexes[1], indexes[cnt]);
        reverse[indexes[1]] = 1;
        reverse[indexes[cnt]] = 0;
        --cnt;
        shiftDown(1);
        return ret;
    }

    bool contain(int i) {
        assert(i + 1 >= 1 && i + 1 <= capacity);
        return reverse[i+1] != 0;
    }

    T getItem(int i) {
        assert(contain(i));
        return data[i+1];
    }

    void change(int i, T item) {
        assert(contain(i));

        i += 1;
        data[i] = item;
        int j = reverse[i];

        shiftUp(j);
        shiftDown(j);
        /* O(n)
        for (int j = 1; j <= cnt; ++j) {
            if (indexes[j] == i) {
                shiftUp(j);
                shiftDown(j);
                return ;
            }
        }*/
    }

};

