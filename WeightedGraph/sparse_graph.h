#include <iostream>
#include <vector>
#include "edge.h"
using namespace std;

/* SparseGraph
 * represent sparse graph using adjacent list
 */
template<typename Weight>
class SparseGraph {
private:
    int v, e;
    bool directed;
    vector<vector<Edge<Weight>*>> graph;

public:
    SparseGraph(int v, bool directed) : e(0), v(v), directed(directed) {
        for (int i = 0; i < v; ++i) {
            graph.push_back(vector<Edge<Weight>*>());
        }
    }

    ~SparseGraph() {
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < graph[i].size(); ++j)
                delete graph[i][j];
        }
    }

    int V() {return v;}
    int E() {return e;}

    void addEdge(int v1, int v2, Weight weight) {
        //hasEdge(v1, v2)
        graph[v1].push_back(new Edge<Weight>(v1, v2, weight));
        if (v1 != v2 && !directed)
            graph[v2].push_back(new Edge<Weight>(v2, v1, weight));
        ++e;
    }

    bool hasEdge(int v1, int v2) {
        for (int i = 0; i < graph[v1].size(); ++i)
            if (graph[v1][i]->other() == v2) return true;
        return false;
    }

    void show() {
        for(int i = 0; i < v; ++i) {
            cout << i << " : ";
            for(int j = 0; j < graph[i].size(); ++j) {
                cout << '{' << graph[i][j]->getEnd() << ", " << graph[i][j]->getWeight() << "} " ;
            }
            cout << endl;
        }
    }

    class adjIterator{
    private:
        SparseGraph &G;
        int v;
        int index;
    public:
        adjIterator(SparseGraph &graph, int v) : G(graph), v(v), index(0){}

        Edge<Weight>* begin() {
            index = 0;
            if (G.graph[v].size())
                return G.graph[v][index];
            return NULL;
        }

        Edge<Weight>* next() {
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
