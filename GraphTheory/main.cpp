#include <iostream>
#include <ctime>
#include "sparse_graph.h"
#include "dense_graph.h"
#include "path.h"
#include "shortest_path.h"
#include "read_graph.h"
#include "component.h"
using namespace std;

int main() {
    srand(time(NULL));
    int v = 10, e = 10;

    SparseGraph sg(v, false);
    DenseGraph dg(v, false);
    // generate the graph randomly
    for(int i = 0; i < e; ++i) {
        int v1 = rand() % v;
        int v2 = rand() % v;
        sg.addEdge(v1, v2);
        dg.addEdge(v1, v2);
    }
    sg.show();
    cout << endl;
    dg.show();
    cout << endl;
    // test the iterator
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
        DenseGraph::adjIterator adj1(dg, i);
        for (int j = adj1.begin(); !adj1.end(); j = adj1.next())
            cout << j << " ";
        cout << endl;
    }
    cout << endl;

    // test and output the total component of a graph
    cout << "components of sparse graph: " << Component<SparseGraph>(sg).count() << endl;
    cout << "components of dense graph: " << Component<DenseGraph>(dg).count() << endl;

    // test and output the path from 0 to 5
    cout << "path from 0 to 5" << endl;
    Path<SparseGraph>(sg, 0).showPath(5);
    cout << endl;
    cout << "path from 0 to 5" << endl;
    Path<DenseGraph>(dg, 0).showPath(5);
    cout << endl;

    //test and output the shortest path from 0 to 5
    cout << "shortest path from 0 to 5" << endl;
    ShortestPath<SparseGraph>(sg, 0).showPath(5);
    cout << endl;
    cout << "shortest path from 0 to 5" << endl;
    ShortestPath<DenseGraph>(dg, 0).showPath(5);
    cout << endl;

    return 0;
}
