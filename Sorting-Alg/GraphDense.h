//
// Created by zhixiong ruan on 2019-07-27.
//

#ifndef SORTING_ALG_GRAPHDENSE_H
#define SORTING_ALG_GRAPHDENSE_H
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
// 稠密图 - 邻接矩阵
class GraphDense{
private:
    int n,m;
    bool dericted;
    vector<vector<bool>> graph;
public:
    GraphDense(int n, bool dericted){
        this->n = n;
        this->m = 0;
        this->dericted = dericted;
        for(int i = 0; i < n; i++){
            this->graph.push_back(vector<bool>(n, false));
        }
    }
    ~GraphDense(){};

    int V(){ return n;};
    int E(){ return m;};

    bool hasEdge(int v, int w) {
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < m );
        return graph[v][w];
    }

    void addEdge(int v, int w){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        if( hasEdge( v , w  ) )
            return;

        graph[v][w] = true;
        if( !dericted )
            graph[w][v] = true;
        m ++;
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

        int begin(){
            this->index = -1;
            return next();
        }

        int next(){
            for (index += 1; index < G.V(); index++) {
                if(G.graph[v][index]) {
                    return index;
                }
            }
            return -1;
        }

        bool end(){
            return index >= G.V();
        }
    };
};

#endif //SORTING_ALG_GRAPHDENSE_H
