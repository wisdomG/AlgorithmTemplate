#ifndef PATH_H
#define PATH_H

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* Path
 * find and output the path between two vertexs using dfs method
 */
template<typename Graph>
class Path{
private:
    Graph &g;
    int source;
    bool *visited;
    int *from;

    void dfs(int v) {
        visited[v] = true;
        typename Graph::adjIterator adj(g, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i]) {
                from[i] = v;
                dfs(i);
            }
        }
    }

public:
    Path(Graph &graph, int source): g(graph), source(source) {
        visited = new bool[g.V()];
        from = new int[g.V()];
        for (int i = 0; i < g.V(); ++i){
            visited[i] = false;
            from[i] = -1;
        }
        dfs(source);
    }

    ~Path() {
        delete[] visited;
        delete[] from;
    }

    bool hasPath(int w) {
        return visited[w];
    }

    void path(int w, vector<int> &vec) {
        stack<int> sta;
        while (w != -1) {
            sta.push(w);
            w = from[w];
        }
        vec.clear();
        while (!sta.empty()) {
            vec.push_back(sta.top());
            sta.pop();
        }
    }

    void showPath(int w) {
        if (!hasPath(w))  {
            cout << "No Path from " << source << " to " << w << endl;
            return;
        }
        vector<int> vec;
        path(w, vec);
        for (auto x : vec) {
            if (x == w) cout << x << endl;
            else cout << x << "->";
        }
    }
};

#endif
