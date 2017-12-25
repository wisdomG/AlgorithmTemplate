#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
using namespace std;

template<typename Graph>
class Component {
private :
    Graph &g;
    bool *visited;
    int cnt;
    int *id;

    void dfs(int v) {
        visited[v] = true;
        id[v] = cnt;
        typename Graph::adjIterator adj(g, v);
        for (int i = adj.begin; !adj.end(); i = adj.next()) {
            if (!visited(i)) {
                dfs(i);
            }
        }
    }
public:
    Component(Graph &graph): g(graph) {
        visited = new bool(g.V());
        id = new int(g.V());
        for (int i = 0; i < g.V(); ++i) {
            id[i] = -1;
            visited[i] = false;
        }
        for (int i = 0; i < g.V(); ++i) {
            if (!visited[i]) {
                dfs(i);
                ++cnt;
            }
        }
    }
    ~Component() {
        delete[] visited;
        delete[] id;
    }

    int count() {return cnt;}

    bool isConnect(int v1, int v2) {
        return id[v1] == id[v2];
    }
};

#endif
