#ifndef READ_GRAPG_H
#define READ_GRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
using namespace std;

template <typename Graph>
class ReadGraph {
private:
    vector<bool> visited();
public:
    ReadGraph(Graph &graph, const string &filename) {
        ifstream file(filename);
        string line;
        int v, e;

        assert(file.is_open());
        assert(getline(file, line));
        stringstream ss(line);
        ss >> v >> e;

        assert(v == graph.V());
        for (int i = 0; i < e; ++i) {
            assert(getline(file, line));
            stringstream ss(line);
            int a, b;
            ss >> a >> b;
            assert(a >= 0 && a < v);
            assert(b >= 0 && b < v);
            graph.addEdge(a, b);
        }
    }


};

#endif
