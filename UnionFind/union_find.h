#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <iostream>
#include <cassert>
using namespace std;

class UnionFind {
private:
    int *parent;
    int *rank;
    int count;

public:
    UnionFind( int n ) {
        parent = new int[n];
        rank = new int[n]; // store the depth when current node is the root
        count = n;
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    ~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

    int find1(int p) {
        assert(p >= 0 && p < count);
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    // find the root and modify the depth as the same time with recursive method
    int find(int p) {
        assert(p >= 0 && p < count);
        if (p != parent[p]) {
            parent[p] = find([parent[p]]);
        }
        return parent[p];
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) return ;
        // compare the depth, and always union the node with smaller rank to another node
        // at the same time, maintain the rank array
        if (rank[pRoot] < rank[qRoot]) {
            parent[pRoot] = qRoot;
        } else if (rank[qRoot] < rank[pRoot]){
            parent[qRoot] = pRoot;
        } else {
            parent[pRoot] = qRoot;
            rank[qRoot] += 1;
        }
    }
};

#endif
