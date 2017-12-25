#include <iostream>
#include <ctime>
#include "sparse_graph.h"
#include "dense_graph.h"
using namespace std;

int main() {
    srand(time(NULL));
    int v = 20, e = 100;

    SparseGraph sg(v, false);
    DenseGraph dg(v, false);

    for(int i = 0; i < e; ++i) {
        int v1 = rand() % v;
        int v2 = rand() % v;
        sg.addEdge(v1, v2);
        dg.addEdge(v1, v2);
    }

    for (int i = 0; i < v; ++i) {
        cout << i << " : ";
        SparseGraph::adjIterator adj1(sg, i);
        for (int j = adj1.begin(); !adj1.end(); j = adj1.next())
            cout << j << " ";
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < v; ++i) {
        cout << i << " : ";
        DenseGraph::adjIterator adj2(dg, i);
        for (int j = adj2.begin(); !adj2.end(); j = adj2.next())
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
