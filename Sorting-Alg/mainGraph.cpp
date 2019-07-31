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

using namespace std;


int main() {

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

    return 0;
}