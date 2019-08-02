//
// Created by zhixiong ruan on 2019-08-02.
//

#ifndef SORTING_ALG_GRAPHEDGE_H
#define SORTING_ALG_GRAPHEDGE_H
#include <iostream>
#include <cassert>

using namespace std;

template<typename Weight>
class GraphEdge{
private:
    int a,b;
    Weight weight;
public:
    GraphEdge(int a, int b, Weight weight){
        this->a = a;
        this->b = b;
        this->weight = weight;
    }

    GraphEdge(){}

    ~GraphEdge(){}

    int v(){ return a;}

    int w(){ return b;}

    Weight wt(){ return weight;}

    int other(int x){
        assert( x == a || x == b );
        return x == a ? b : a;
    }

    friend ostream& operator<<(ostream &os, const GraphEdge &e){
        os<<e.a<<"-"<<e.b<<": "<<e.weight;
        return os;
    }

    bool operator<(GraphEdge<Weight>& e){
        return weight < e.wt();
    }

    bool operator<=(GraphEdge<Weight>& e){
        return weight <= e.wt();
    }

    bool operator>(GraphEdge<Weight>& e){
        return weight > e.wt();
    }

    bool operator>=(GraphEdge<Weight>& e){
        return weight >= e.wt();
    }

    bool operator==(GraphEdge<Weight>& e){
        return weight == e.wt();
    }
};

#endif //SORTING_ALG_GRAPHEDGE_H
