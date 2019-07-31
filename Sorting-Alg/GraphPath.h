//
// Created by zhixiong ruan on 2019-08-01.
//

#ifndef SORTING_ALG_GRAPHPATH_H
#define SORTING_ALG_GRAPHPATH_H

#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <cassert>

using namespace std;


template <typename Graph>
class GraphPath {

private:
    Graph &G;
    int s;
    bool *visited;//是否被遍历
    int *from;//路径
    int *ord;//最短路径节点数

    void dfs(int v){
        visited[v] = true;
        typename Graph::AdjIterator abj(G, v);
        for(int i = abj.begin(); !abj.end(); i = abj.next()) {
            if(!visited[i]){
                from[i] = v;
                dfs(i);
            }
        }
    }

public:
    GraphPath(Graph &graph, int a):G(graph){
        visited = new bool[G.V()];
        from = new int[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
        }

        dfs(a);
    }
    ~GraphPath(){
        delete[] visited;
        delete[] from;
        delete[] ord;
    }

    GraphPath(Graph &graph, int s, bool isSort):G(graph){

            // 算法初始化
            assert( s >= 0 && s < graph.V() );

            visited = new bool[graph.V()];
            from = new int[graph.V()];
            ord = new int[graph.V()];
            for( int i = 0 ; i < graph.V() ; i ++ ){
                visited[i] = false;
                from[i] = -1;
                ord[i] = -1;
            }
            this->s = s;

            queue<int> q;

            // 无向图最短路径算法
            q.push( s );
            visited[s] = true;
            ord[s] = 0;
            while( !q.empty() ){
                int v = q.front();
                q.pop();

                typename Graph::AdjIterator adj(G,v);
                for( int i = adj.begin() ; !adj.end() ; i = adj.next() )
                    if( !visited[i] ){
                        visited[i] = true;
                        from[i] = v;
                        ord[i] = ord[v] + 1;
                        q.push(i);
                    }
            }
    }

    void path(int w, vector<int> &vec){

        assert( w >= 0 && w < G.V() );

        stack<int> s;

        int p = w;
        while( p != -1 ){
            s.push(p);
            p = from[p];
        }

        vec.clear();
        while( !s.empty() ){
            vec.push_back( s.top() );
            s.pop();
        }
    }

    void showPath(int w){

        assert( w >= 0 && w < G.V() );

        vector<int> vec;
        path(w, vec);
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i];
            if( i == vec.size()-1 )
                cout<<endl;
            else
                cout<<" -> ";
        }
    }
};

#endif //SORTING_ALG_GRAPHPATH_H
