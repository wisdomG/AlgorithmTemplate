#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <cassert>
using namespace std;

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

    int getStart() { return a; }
    int getEnd() { return b; }
    Weight getWeight() {return weight; }

    int other(int x) {
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

