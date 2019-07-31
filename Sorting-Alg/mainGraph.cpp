//
// Created by zhixiong ruan on 2019-07-30.
//

#include <iostream>
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
#if 0
    // TestG1.txt
    string filename1 = "/Users/zhixiongruan/project/C-plus-plus/Sorting-Alg/testG1.txt";
    GraphSparse g1 = GraphSparse(13, false);
    ReadGraph<GraphSparse> readGraph1(g1, filename1);
    GraphComponent<GraphSparse> component1(g1);
    cout<<"TestG1.txt, Component Count: "<<component1.count()<<endl;

    cout<<endl;

    // TestG2.txt
    string filename2 = "/Users/zhixiongruan/project/C-plus-plus/Sorting-Alg/testG2.txt";
    GraphSparse g2 = GraphSparse(7, false);
    ReadGraph<GraphSparse> readGraph2(g2, filename2);
    GraphComponent<GraphSparse> component2(g2);
    cout<<"TestG2.txt, Component Count: "<<component2.count()<<endl;
#endif

#if 1
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