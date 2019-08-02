//
// Created by zhixiong ruan on 2019-07-27.
//

#ifndef SORTING_ALG_GRAPHSPARSE_H
#define SORTING_ALG_GRAPHSPARSE_H
#include <iostream>
#include <vector>
#include <cassert>
#include "GraphEdge.h"

using namespace std;


// 稀疏图 - 邻接表
template<typename Weight>
class GraphSparse {
private:
    int n, m;
    bool directed;
    vector<vector<GraphEdge<Weight> *>> graph;
public:
    GraphSparse(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; i++)
            graph.push_back( vector<GraphEdge<Weight> *>() );
    }

    ~GraphSparse() {
        for( int i = 0 ; i < n ; i ++ )
            for( int j = 0 ; j < graph[i].size() ; j ++ )
                delete graph[i][j];
    }

    int V() { return n; }

    int E() { return m; }

    bool hasEdge( int v , int w ){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );
        for( int i = 0 ; i < graph[v].size() ; i ++ )
            if( graph[v][i]->other(v) == w )
                return true;
        return false;
    }

    void addEdge(int v, int w, Weight weight){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );
        graph[v].push_back(new GraphEdge<Weight>(v, w, weight));
        if( v != w && !directed )
            graph[w].push_back(new GraphEdge<Weight>(w, v, weight));
        m ++;
    }

    void show(){

        for( int i = 0 ; i < n ; i ++ ){
            cout<<"vertex "<<i<<":\t";
            for( int j = 0 ; j < graph[i].size() ; j ++ )
                cout<<"( to:"<<graph[i][j]->w()<<",wt:"<<graph[i][j]->wt()<<")\t";
            cout<<endl;
        }
    }

    class AdjIterator {
    private:
        GraphSparse &G;
        int index;
        int v;
    public:
        AdjIterator(GraphSparse &graph, int v):G(graph) {
            this->index = 0;
            this->v = v;
        }

        GraphEdge<Weight>* begin(){
            index = 0;
            if( G.graph[v].size() )
                return G.graph[v][index];
            return NULL;
        }

        GraphEdge<Weight>* next(){
            index += 1;
            if( index < G.graph[v].size() )
                return G.graph[v][index];
            return NULL;
        }

        bool end(){
            return index >= G.graph[v].size();
        }
    };
};
#endif //SORTING_ALG_GRAPHSPARSE_H
