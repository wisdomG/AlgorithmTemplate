#include <iostream>
#include <ctime>
#include "sparse_graph.h"
#include "dense_graph.h"
#include "path.h"
#include "shortest_path.h"
#include "read_graph.h"
#include "component.h"
using namespace std;

const int n = 10;
int main() {
    DenseGraph<double> dg(n, false);
    ReadGraph<DenseGraph<double>, double> rg(dg, "in.txt");
    dg.show();

    return 0;
}
