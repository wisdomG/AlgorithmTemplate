#include <iostream>
#include <vector>
#include "edge.h"
using namespace std;

/* DenseGraph
 * represent the dense graph using adjacent matrix
 */
template<typename Weight>
class DenseGraph{
private:
    int v, e;
    bool directed;
    vector<vector<Edge<Weight>*>> graph;

public:
    DenseGraph(int v, bool directed) : e(0), v(v), directed(directed){
        for (int i = 0; i < v; ++i) {
            graph.push_back(vector<Edge<Weight>*>(v, NULL));
        }
    }

    ~DenseGraph() {
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j)
                if (graph[i][j] != NULL) delete graph[i][j];
        }
    }

    int V() {return v;}
    int E() {return e;}

    void addEdge(int v1, int v2, Weight weight) {
        if (hasEdge(v1, v2)) {    // cover the old edge
            delete graph[v1][v2];
            if (!directed)
                delete graph[v2][v1];
            --e;
        }
        graph[v1][v2] = new Edge<Weight>(v1, v2, weight);
        if (!directed)
            graph[v2][v1] = new Edge<Weight>(v2, v1, weight);
        ++e;
    }

    bool hasEdge(int v1, int v2) {
        return graph[v1][v2] != NULL;
    }

    void show() {
        for (int i = 0; i < v; ++i) {
            cout << i << " : ";
            for(int j = 0; j < v; ++j) {
                if (graph[i][j])
                    cout << graph[i][j]->getWeight() << ' ';
                else
                    cout << "NULL" << ' ';
            }
            cout << endl;
        }
    }

    class adjIterator{
    private:
        DenseGraph &G;
        int v;
        int index;
    public:
        adjIterator(DenseGraph &graph, int v) : G(graph), v(v), index(0){}

        Edge<Weight>* begin() {
            index = -1;
            return next();
        }

        Edge<Weight>* next() {
            for (index += 1; index < G.V(); index++) {
                if (G.graph[v][index]) return G.graph[v][index];
            }
            return NULL;
        }

        bool end() {
            return (index >= G.V());
        }
    };


};
