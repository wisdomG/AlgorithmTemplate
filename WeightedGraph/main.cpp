#include <iostream>
#include <ctime>
#include "sparse_graph.h"
#include "dense_graph.h"
#include "read_graph.h"
#include "lazy_prime.h"
using namespace std;

const int n = 10;
int main() {
    DenseGraph<double> dg(n, false);
    ReadGraph<DenseGraph<double>, double> rg1(dg, "in.txt");
    dg.show();

    SparseGraph<double> sg(n, false);
    ReadGraph<SparseGraph<double>, double> rg2(sg, "in.txt");
    sg.show();

    LazyPrimeMST<DenseGraph<double>, double> mst1(dg);
    cout << "Total weights of minimum span tree : " << mst1.result() << endl;

    LazyPrimeMST<SparseGraph<double>, double> mst2(sg);
    cout << "Total weights of minimum span tree : " << mst2.result() << endl;

    return 0;
}
