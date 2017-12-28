#ifndef _KRUSKAL_H
#define _KRUSKAL_H

#include <iostream>
#include <vector>
#include "edge.h"
#include "min_heap.h"
#include "union_find.h"
using namespace std;

/* Kruskal algorithm for Minimum Spanning Tree
 * Always choose the edge with minimum weight
 * if there a loop, discard current edge and go on choose next edge
 */
template<typename Graph, typename Weight>
class KruskalMST{
private:
    vector<Edge<Weight>> mst;
    Weight mstWeight;

public:
    KruskalMST(Graph &graph) {
        MinHeap<Edge<Weight>> pq;
        for (int i = 0; i < graph.V(); ++i) {
            typename Graph::adjIterator adj(graph, i);
            for (auto e = adj.begin(); !adj.end(); e = adj.next()) {
                if (e->getStart() < e->getEnd())
                    pq.insert(*e);
            }
        }

        UnionFind uf(graph.V());
        while (!pq.empty() && mst.size() < graph.V() - 1) {
            Edge<Weight> e = pq.extractMin();
            if (uf.isConnected(e.getEnd(), e.getStart()))
                continue;
            mst.push_back(e);
            uf.unionElements(e.getEnd(), e.getStart());
        }

        mstWeight = mst[0].getWeight();
        for (int i = 1; i < mst.size(); ++i)
            mstWeight += mst[i].getWeight();
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
