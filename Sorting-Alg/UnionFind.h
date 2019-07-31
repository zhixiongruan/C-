//并查集
// Created by zhixiong ruan on 2019-07-26.
//

#ifndef SORTING_ALG_UNIONFIND_H
#define SORTING_ALG_UNIONFIND_H

namespace UF{
    class UnionFind{
    private:
        int *node;
        int *rank;//rank[i]表示以i为根的集合所表示的树的层数
        int count;

    public:
        UnionFind(int n){
            count = n;
            node = new int[n];
            rank = new int[n];
            for(int i = 0; i < n; i++){
                node[i] = i;
                rank[i] = 1;
            }
        }
        ~UnionFind(){
            delete[] node;
            delete[] rank;
        }

        int findRootNode(int i) {
            while (i != node[i]) {
                node[i] = node[node[i]];
                i = node[i];
            }
            return i;
        }

        bool isConnection(int p, int q){
            return findRootNode(p) == findRootNode(q);
        }

        void unionElements(int p, int q){
            int pNode = findRootNode(p);
            int qNode = findRootNode(q);
            if(pNode == qNode) {
                return;
            }
            if(rank[pNode] < rank[qNode]) {
                node[pNode] = qNode;
            } else if(rank[qNode] < rank[pNode]) {
                node[qNode] = pNode;
            } else {
                node[pNode] = qNode;
                rank[qNode] ++;
            }
        }
    };
}

#endif //SORTING_ALG_UNIONFIND_H
