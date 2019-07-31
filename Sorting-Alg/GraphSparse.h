//
// Created by zhixiong ruan on 2019-07-27.
//

#ifndef SORTING_ALG_GRAPHSPARSE_H
#define SORTING_ALG_GRAPHSPARSE_H
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


// 稀疏图 - 邻接表
class GraphSparse {
private:
    int n, m;
    bool directed;
    vector<vector<int>> graph;
public:
    GraphSparse(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; i++)
            graph.push_back(vector<int>());
    }

    ~GraphSparse() {

    }

    int V() { return n; }

    int E() { return m; }

    bool hasEdge( int v , int w ){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );
        for( int i = 0 ; i < graph[v].size() ; i ++ )
            if( graph[v][i] == w )
                return true;
        return false;
    }

    void addEdge(int v, int w){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );
        graph[v].push_back(w);
        if(v != w && !directed){
            graph[w].push_back(v);
        }
        this->m++;
    }
    void show(){

        for( int i = 0 ; i < n ; i ++ ){
            cout<<"vertex "<<i<<":\t";
            for( int j = 0 ; j < graph[i].size() ; j ++ )
                cout<<graph[i][j]<<"\t";
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

        int begin(){
            index = 0;
            if( G.graph[v].size() )
                return G.graph[v][index];
            return -1;
        }

        int next(){
            index += 1;
            if( index < G.graph[v].size() )
                return G.graph[v][index];
            return -1;
        }

        bool end(){
            return index >= G.graph[v].size();
        }
    };
};
#endif //SORTING_ALG_GRAPHSPARSE_H
