//
// Created by zhixiong ruan on 2019-07-27.
//

#ifndef SORTING_ALG_GRAPHDENSE_H
#define SORTING_ALG_GRAPHDENSE_H
#include <iostream>
#include <vector>
#include <cassert>
#include "GraphEdge.h"

using namespace std;
// 稠密图 - 邻接矩阵
template <typename Weight>
class GraphDense{
private:
    int n,m;
    bool dericted;
    vector<vector<GraphEdge<Weight> *>> graph;
public:
    GraphDense(int n, bool dericted){
        this->n = n;
        this->m = 0;
        this->dericted = dericted;
        for(int i = 0; i < n; i++){
            this->graph.push_back(vector<GraphEdge<Weight> *>(n,NULL));
        }
    }
    ~GraphDense(){
        for( int i = 0 ; i < n ; i ++ )
            for( int j = 0 ; j < n ; j ++ )
                if( graph[i][j] != NULL )
                    delete graph[i][j];
    };

    int V(){ return n;};
    int E(){ return m;};

    bool hasEdge(int v, int w) {
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );
        return graph[v][w] != NULL;
    }

    void addEdge(int v, int w, Weight weight){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        if( hasEdge( v , w  ) ){
            delete  graph[v][w];
            if( !dericted )
                delete graph[w][v];
            m --;
        }

        graph[v][w] = new GraphEdge<Weight>(v, w, weight);
        if( !dericted )
            graph[w][v] = new GraphEdge<Weight>(w, v, weight);
        m ++;
    }

    void show(){

        for( int i = 0 ; i < n ; i ++ ){
            for( int j = 0 ; j < n ; j ++ )
                if( graph[i][j] )
                    cout<<graph[i][j]->wt()<<"\t";
                else
                    cout<<"NULL\t";
            cout<<endl;
        }
    }

    class AdjIterator{
    private:
        GraphDense &G;
        int index;
        int v;
    public:
        AdjIterator(GraphDense &graph, int v):G(graph) {
            this->index = -1;
            this->v = v;
        }

        GraphEdge<Weight>* begin(){
            index = -1;
            return next();
        }

        GraphEdge<Weight>* next(){
            for( index += 1 ; index < G.V() ; index ++ )
                if( G.g[v][index] )
                    return G.g[v][index];

            return NULL;
        }

        bool end(){
            return index >= G.V();
        }
    };
};

#endif //SORTING_ALG_GRAPHDENSE_H
