//
// Created by zhixiong ruan on 2019-07-19.
//

#ifndef SORTING_ALG_BINARYSEARCHTREE_H
#define SORTING_ALG_BINARYSEARCHTREE_H


#include <cassert>
#include <iostream>
#include <queue>

template <typename KEY, typename VALUE>
class BinarySearchTree{
private:
    struct Node{
        KEY key;
        VALUE value;
        Node *leftNode;
        Node *rigthNode;

        Node(KEY key, VALUE value){
            this->key = key;
            this->value = value;
            this->leftNode = NULL;
            this->rigthNode = NULL;
        }

        Node(Node *node){
            this->key = node->key;
            this->value = node->value;
            this->rigthNode = node->rigthNode;
            this->leftNode = node->leftNode;
        }
    };
    Node *root;
    int count;
public:
    BinarySearchTree(){
        root = NULL;
        count = 0;
    }
    ~BinarySearchTree(){
        destroy(root);
        assert( count == 0 );
    }
    // 返回二叉树的元素个数
    int size(){
        return count;
    }
    /**
     * 插入节点
     * @param key
     * @param value
     */
    void insertNode(KEY key, VALUE value){
        root = insertNode(root, key, value);
    }
    /**
     * 查看节点是否包含key节点
     * @param key
     * @return
     */
    bool contain(KEY key){
        return contain(root, key);
    }

    // 在二叉树中寻找键值为key的value值
    VALUE* search(KEY key){
        return search(root, key);
    }

    // 前序遍历
    void preOrder(){
        preOrder(root);
    }

    // 中序遍历
    void inOrder(){
        inOrder(root);
    }

    // 后序遍历
    void postOrder(){
        postOrder(root);
    }

    // 层序遍历
    void levelOrder(){
        std::queue<Node*> q;
        q.push(root);
        while( !q.empty() ){
            Node *node = q.front();
            q.pop();
            std::cout<< node->key << ";";
            if( node->leftNode )
                q.push(node->leftNode);
            if( node->rigthNode )
                q.push(node->rigthNode);
        }
    }

    // 寻找最小的键值
    KEY minimum(){
        assert( count != 0 );
        Node* minNode = minimum(root);
        return minNode->key;
    }

    // 寻找最大的键值
    KEY maximum(){
        assert( count != 0 );
        Node* maxNode = maximum(root);
        return maxNode->key;
    }

    // 从二叉树中删除最小值所在节点
    void removeMin(){
        if( root )
            root = removeMin( root );
    }

    // 从二叉树中删除最大值所在节点
    void removeMax(){
        if( root )
            root = removeMax( root );
    }

    // 从二叉树中删除键值为key的节点
    void remove(KEY key){
        root = remove(root, key);
    }
private:
    //释放内存空间
    void destroy(Node* node){
        if( node != NULL){
            destroy(node->leftNode);
            destroy(node->rigthNode);
            delete node;
            count--;
        }
    }
    // 向以node为根的二叉搜索树中,插入节点(key, value)
    // 返回插入新节点后的二叉搜索树的根
    Node* insertNode(Node *node, KEY key, VALUE value) {
        if (node == NULL) {
            count++;
            return new Node(key, value);
        }
        if(node->key == key) {
            node->value = value;
        } else if(key > node->key) {
            node->rigthNode = insertNode(node->rigthNode, key, value);
        } else {
            node->leftNode = insertNode(node->leftNode, key, value);
        }
        return node;
    }

    // 查看以node为根的二叉搜索树中是否包含键值为key的节点
    bool contain(Node *node, KEY key) {
        if(node == NULL) {
            return false;
        }
        if (node->key == key){
            return true;
        } else if(key > node->key) {
            return contain(node->rigthNode, key);
        } else {
            return contain(node->leftNode, key);
        }
    }

    // 在以node为根的二叉搜索树中查找key所对应的value
    VALUE* search(Node *node, KEY key) {
        if(node == NULL) {
            return NULL;
        }
        if (node->key == key){
            return node->value;
        } else if(key > node->key) {
            return search(node->rigthNode, key);
        } else {
            return search(node->leftNode, key);
        }
    }

    // 对以node为根的二叉搜索树进行前序遍历
    void preOrder(Node *node) {
        if (node != NULL){
            std::cout<< node->key << ":" << node->value<< ";";
            preOrder(node->leftNode);
            preOrder(node->rigthNode);
        }
    }

    // 对以node为根的二叉搜索树进行中序遍历
    void inOrder(Node *node) {
        if (node != NULL){
            inOrder(node->leftNode);
            std::cout<< node->key << ":" << node->value<< ";";
            inOrder(node->rigthNode);
        }
    }

    // 对以node为根的二叉搜索树进行后序遍历
    void postOrder(Node *node) {
        if (node != NULL){
            postOrder(node->leftNode);
            postOrder(node->rigthNode);
            std::cout<< node->key << ":" << node->value<< ";";
        }
    }

    // 在以node为根的二叉搜索树中,返回最小键值的节点
    Node* minimum(Node *node){
        if (node->leftNode == NULL) {
            return node;
        }
        return minimum(node->leftNode);
    }

    // 在以node为根的二叉搜索树中,返回最大键值的节点
    Node* maximum(Node *node){
        if (node->rigthNode == NULL) {
            return node;
        }
        return maximum(node->rigthNode);
    }

    // 删除掉以node为根的二分搜索树中的最小节点
    // 返回删除节点后新的二分搜索树的根
    Node* removeMin(Node *node){
        if (node->leftNode == NULL) {
            Node* rigthNode = node->rigthNode;
            delete node;
            count--;
            return rigthNode;
        }

        node->leftNode = removeMin(node->leftNode);
        return node;
    }

    // 删除掉以node为根的二分搜索树中的最大节点
    // 返回删除节点后新的二分搜索树的根
    Node* removeMax(Node* node){

        if( node->rigthNode == NULL ){
            Node* leftNode = node->leftNode;
            delete node;
            count --;
            return leftNode;
        }

        node->rigthNode = removeMax( node->rigthNode );
        return node;
    }

    // 删除掉以node为根的二分搜索树中键值为key的节点
    // 返回删除节点后新的二分搜索树的根
    Node* remove(Node *node, KEY key) {
        if (node == NULL) {
            return NULL;
        }
        if (key < node->key) {
            node->leftNode = remove(node->leftNode, key);
            return node;
        } else if(key > node->key) {
            node->rigthNode = remove(node->rigthNode, key);
            return node;
        } else {
            if(node->leftNode == NULL) {
                Node* rigthNode = node->rigthNode;
                delete node;
                count--;
                return rigthNode;
            }

            if(node->rigthNode == NULL) {
                Node* leftNode = node->leftNode;
                delete node;
                count--;
                return leftNode;
            }
            assert( node->leftNode != NULL && node->rigthNode != NULL );
            Node* stayNode = new Node(maximum(node->leftNode));
            count++;
            stayNode->leftNode = removeMax(node->leftNode);
            stayNode->rigthNode = node->rigthNode;
            delete node;
            count--;
            return stayNode;
        }
    }
};

#endif //SORTING_ALG_BINARYSEARCHTREE_H
