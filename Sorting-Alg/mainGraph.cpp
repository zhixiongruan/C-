//
// Created by zhixiong ruan on 2019-07-30.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <string>
#include "GraphDense.h"
#include "GraphSparse.h"
#include "GraphComponent.h"
#include "GraphRead.h"
#include "GraphPath.h"

using namespace std;


int main() {
#if 1
    string filename = "/Users/zhixiongruan/project/C-plus-plus/Sorting-Alg/data/testG2.txt";
    int V = 250;
    cout<<fixed<<setprecision(2);

    // Test Weighted Dense Graph
    GraphDense<double> g1 = GraphDense<double>(V, false);
    GraphRead<GraphDense<double>,double> readGraph1(g1, filename);
    g1.show();
    cout<<endl;

    // Test Weighted Sparse Graph
    GraphSparse<double> g2 = GraphSparse<double>(V, false);
    GraphRead<GraphSparse<double>,double> readGraph2(g2, filename);
    g2.show();
    cout<<endl;
#endif

#if 0
    string filename = "/Users/zhixiongruan/project/C-plus-plus/Sorting-Alg/testG2.txt";
    GraphSparse g = GraphSparse(7, false);
    ReadGraph<GraphSparse> readGraph(g, filename);
    g.show();
    cout<<endl;

    GraphPath<GraphSparse> dfs(g,0);
    cout<<"DFS : ";
    dfs.showPath(6);

    GraphPath<GraphSparse> bfs(g,0, true);
    cout<<"BFS : ";
    bfs.showPath(6);
#endif

    return 0;
}