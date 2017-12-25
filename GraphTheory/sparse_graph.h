#include <iostream>
#include <vector>
using namespace std;

class SparseGraph {
private:
    int v, e;
    bool directed;
    vector<vector<int>> graph;

public:
    SparseGraph(int v, bool directed) : e(0), v(v), directed(directed) {
        for (int i = 0; i < v; ++i) {
            graph.push_back(vector<int>());
        }
    }

    int V() {return v;}
    int E() {return e;}

    void addEdge(int v1, int v2) {
        //hasEdge(v1, v2)
        graph[v1].push_back(v2);
        if (v1 != v2 && !directed)
            graph[v2].push_back(v1);
        ++e;
    }

    bool hasEdge(int v1, int v2) {
        for (int i = 0; i < graph[v1].size(); ++i)
            if (graph[v1][i] == v2) return true;
        return false;
    }

    class adjIterator{
    private:
        SparseGraph &G;
        int v;
        int index;
    public:
        adjIterator(SparseGraph &graph, int v) : G(graph), v(v), index(0){}

        int begin() {
            index = 0;
            if (G.graph[v].size())
                return G.graph[v][index];
            return -1;
        }

        int next() {
            ++index;
            if (index < G.graph[v].size()) {
                return G.graph[v][index];
            }
        }

        bool end() {
            return (index >= G.graph[v].size());
        }
    };
};
