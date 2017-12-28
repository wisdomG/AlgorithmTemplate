#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <cassert>
using namespace std;

/* Weighted Edge
 */
template<typename Weight>
class Edge{
private:
    int a, b;
    Weight weight;

public:
    Edge(int a, int b, Weight weight):
        a(a), b(b), weight(weight) {}

    Edge() {}
    ~Edge() {}

    int getStart() const { return a; }
    int getEnd() const { return b; }
    Weight getWeight() const {return weight; }

    int other(int x) const {
        assert(x == a || x == b);
        return x == a ? b : a;
    }

    friend ostream& operator<<(ostream &os, const Edge &e) {
        os << e.a << '-' << e.b << " : " << e.weight;
        return os;
    }

    bool operator<(const Edge &e) {
        return weight < e.getWeight();
    }

    bool operator<=(const Edge &e) {
        return weight <= e.getWeight();
    }

    bool operator>(const Edge &e) {
        return weight > e.getWeight();
    }

    bool operator>=(const Edge &e) {
        return weight >= e.getWeight();
    }

    bool operator==(const Edge &e) {
        return weight == e.getWeight();
    }

};

#endif

