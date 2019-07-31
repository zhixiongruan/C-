//
// Created by zhixiong ruan on 2019-07-30.
//

#ifndef SORTING_ALG_GRAPHCOMPONENT_H
#define SORTING_ALG_GRAPHCOMPONENT_H
#include <iostream>
#include <cassert>
using namespace std;


template <typename Graph>
class GraphComponent {

private:
    Graph &G;
    bool *visited;
    int ccount = 0;
    int *id;
    //深度优先遍历
    void dfs(int v){
        visited[v] = true;
        id[v] = ccount;
        typename Graph::AdjIterator abj(G, v);
        for(int i = abj.begin(); !abj.end(); i = abj.next()) {
            if(!visited[i]){
                dfs(i);
            }
        }
    }

public:
    GraphComponent(Graph &graph):G(graph){

        visited = new bool[G.V()];
        id = new int[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ ){
            visited[i] = false;
            id[i] = -1;
        }
        ccount = 0;

        for( int i = 0 ; i < G.V() ; i ++ )
            if( !visited[i] ){
                dfs(i);
                ccount += 1;
            }
    }

    ~GraphComponent(){

        delete [] visited;
        delete [] id;
    }

    int count(){
        return ccount;
    }

    bool isConnected( int v , int w ){

        assert( v >= 0 && v < G.V() );
        assert( w >= 0 && w < G.V() );
        assert( id[v] != -1 && id[w] != -1 );
        return id[v] == id[w];
    }
};

#endif //SORTING_ALG_GRAPHCOMPONENT_H
