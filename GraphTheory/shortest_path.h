#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/* ShortestPath
 * find and output the shortest path between two vertexs with breadth-first search
 */
template<typename Graph>
class ShortestPath{
private:
    Graph &g;
    int source;
    bool *visited;
    int *from;
    int *ord; // record the level or order of a vertex

public:
    ShortestPath(Graph &graph, int s): g(graph), source(s) {
        visited = new bool[g.V()];
        from = new int[g.V()];
        ord = new int[g.V()];

        for (int i = 0; i < g.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }

        queue<int> q;
        q.push(source);
        visited[source] = true;
        ord[source] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            typename Graph::adjIterator adj(g, v);
            for (int i = adj.begin(); !adj.end(); i = adj.next()) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                    from[i] = v;
                    ord[i] = ord[v] + 1;
                }
            }
        }
    }

    ~ShortestPath() {
        delete[] visited;
        delete[] from;
        delete[] ord;
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
        if (!hasPath(w)){
            cout << "No path from " << source << " to " << w << endl;
            return ;
        }
        vector<int> vec;
        path(w, vec);
        for (auto x : vec) {
            if (x == w) cout << x << endl;
            else cout << x << "->";
        }
    }

    int length(int w) {
        return ord[w];
    }

};

#endif
