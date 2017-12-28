#ifndef _UNION_FIND_H
#define _UNION_FIND_H

#include <iostream>
#include <vector>
using namespace std;

/* Union Find
 * implemented by myself
 */
class UnionFind{
private:
    vector<int> par;

public:
    UnionFind(int n) {
        par = vector<int>(n, -1);
    }

    bool isConnected(int a, int b) {
        return findRoot(a) == findRoot(b);
    }

    void unionElements(int a, int b) {
        int roota = findRoot(a);
        int rootb = findRoot(b);
        if (roota == rootb) return ;
        par[roota] = rootb;
    }

    int findRootBasic(int x) {
        while (par[x] != -1) {
            x = par[x];
        }
        return x;
    }

    int findRoot(int x) {
        if (par[x] == -1) return x;
        par[x] = findRoot(par[x]);
        return par[x];
    }
};

#endif
