#ifndef READ_GRAPG_H
#define READ_GRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
using namespace std;

/* Read a graph from a file
 */
template <typename Graph, typename Weight>
class ReadGraph {
private:
    vector<bool> visited();
public:
    ReadGraph(Graph &graph, const string &filename) {
        ifstream file(filename);
        string line;
        int v, e;
        Weight w;

        assert(file.is_open());
        assert(getline(file, line));
        stringstream ss(line);
        ss >> v >> e;

        assert(v == graph.V());
        for (int i = 0; i < e; ++i) {
            assert(getline(file, line));
            stringstream ss(line);
            int a, b;
            ss >> a >> b >> w;
            //cout << a << b << w << endl;
            assert(a >= 0 && a < v);
            assert(b >= 0 && b < v);
            graph.addEdge(a, b, w);
        }
    }
};

#endif
