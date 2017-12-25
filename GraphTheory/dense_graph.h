#include <iostream>
#include <vector>
using namespace std;

class DenseGraph{
private:
    int v, e;
    bool directed;
    vector<vector<bool>> graph;

public:
    DenseGraph(int v, bool directed) : e(0), v(v), directed(directed){
        for (int i = 0; i < v; ++i) {
            graph.push_back(vector<bool>(v, false));
        }
    }

    ~DenseGraph() {}

    int V() {return v;}
    int E() {return e;}

    void addEdge(int v1, int v2) {
        if (hasEdge(v1, v2)) return;
        graph[v1][v2] = true;
        if (!directed) graph[v2][v1] = true;
        ++e;
    }

    bool hasEdge(int v1, int v2) {
        return graph[v1][v2];
    }

    class adjIterator{
    private:
        DenseGraph &G;
        int v;
        int index;
    public:
        adjIterator(DenseGraph &graph, int v) : G(graph), v(v), index(0){}

        int begin() {
            index = -1;
            return next();
        }

        int next() {
            for (index += 1; index < G.V(); index++) {
                if (G.graph[v][index]) return index;
            }
            return -1;
        }

        bool end() {
            return (index >= G.V());
        }
    };

};
