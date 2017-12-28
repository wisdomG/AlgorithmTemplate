#ifndef LAZY_PRIME_H
#define LAZY_PRIME_H

#include <iostream>
#include <algorithm>
#include <ctime>
#include "min_heap.h"
#include "edge.h"
using namespace std;

/* Minimum Span Tree based on Lazy Prime
 * Cut property: always choose the edge with minimum weight between two cuts
 * as an edge in the MST
 */
template<typename Graph, typename Weight>
class LazyPrimeMST {
private:
    Graph &g;
    MinHeap<Edge<Weight>> pq; // priority queue
    bool *marked;
    Weight mstWeight;
    vector<Edge<Weight>> mst;

    void visit(int v) {
        marked[v] = true;
        typename Graph::adjIterator adj(g, v);
        for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
            if (!marked[e->other(v)]) pq.insert(*e);
        }
    }

public:
    LazyPrimeMST(Graph &graph): g(graph) {
        srand(time(NULL));
        marked = new bool[graph.V()];
        for (int i = 0; i < graph.V(); ++i)
            marked[i] = false;
        mst.clear();

        visit(rand()%graph.V());
        while (!pq.empty()) {
            Edge<Weight> e = pq.extractMin();
            if (marked[e.getStart()] == marked[e.getEnd()])
                continue;
            mst.push_back(e);
            //visit(e.getEnd());
            if (!marked[e.getStart()])
                visit(e.getStart());
            else visit(e.getEnd());
        }
        if (mst.size() == 0) {
            cout << "No adjacent Node" << endl;
            return;
        }
        mstWeight = mst[0].getWeight();
        for (int i = 1; i < mst.size(); ++i)
            mstWeight += mst[i].getWeight();
    }
    ~LazyPrimeMST() {
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges() {
        return mst;
    }

    Weight result() {
        return mstWeight;
    }

    void showMST() {
        for (int i = 0; i < mst.size(); ++i)
            cout << mst[i] << endl;
    }
};

#endif
