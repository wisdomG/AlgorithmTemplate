#include <iostream>
#include <ctime>
#include "sparse_graph.h"
#include "dense_graph.h"
#include "read_graph.h"
#include "lazy_prime.h"
#include "kruskal.h"
using namespace std;

const int n = 10;
int main() {
    DenseGraph<double> dg(n, false);
    ReadGraph<DenseGraph<double>, double> rg1(dg, "in.txt");
    dg.show();

    SparseGraph<double> sg(n, false);
    ReadGraph<SparseGraph<double>, double> rg2(sg, "in.txt");
    sg.show();

    cout << "Lazy_Prime" << endl;
    LazyPrimeMST<DenseGraph<double>, double> mst1(dg);
    cout << "DenseGraph: " << mst1.result() << endl;
    LazyPrimeMST<SparseGraph<double>, double> mst2(sg);
    cout << "SparseGraph: " << mst2.result() << endl;
    mst1.showMST();

    cout << "Kruskal" << endl;
    KruskalMST<DenseGraph<double>, double> mst3(dg);
    cout << "DenseGraph: " << mst3.result() << endl;
    KruskalMST<SparseGraph<double>, double> mst4(sg);
    cout << "SparseGraph: " << mst4.result() << endl;
    mst3.showMST();


    return 0;
}
