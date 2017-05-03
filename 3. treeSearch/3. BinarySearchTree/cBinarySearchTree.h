#include "cNode.h"
#include <iostream>
#include <stdio.h>
using namespace std;
 
template <typename T>
class cBinarySearchTree{
friend class cNode<T>;
public:
    cBinarySearchTree(){
        root = 0;
    };
    ~cBinarySearchTree(){
    };
    void treeInsert(T x);
    void treeDelete(T x);
    void treePrint();
private:
    cNode<T>* treeInsert(cNode<T>* t, T x);
    void treeDelete(cNode<T>* t, cNode<T>* r, cNode<T>* p);   
    cNode<T>* deleteNode(cNode<T>* r);
    void treePrint(cNode<T>* t, int step);
    cNode<T>* root;
};

// public

template <typename T>
void cBinarySearchTree<T>::treeInsert(T x){
    root = treeInsert(root, x);
}


template <typename T>
void cBinarySearchTree<T>::treeDelete(T x){

    cNode<T>* p = 0;
    cNode<T>* r = root;
 
    while((r != 0) && (r->key != x)){
        p = r;
        if(x < r->key) r = r->left;
        else r = r->right;
    }

    if(r!=0) treeDelete(root, r, p);
}

template <typename T>
void cBinarySearchTree<T>::treePrint(){
    treePrint(root, 0);
}

// private
template <typename T>
cNode<T>* cBinarySearchTree<T>::treeInsert(cNode<T>* t, T x){

    if (t == 0) {
        cNode<T>* newNode = new cNode<T>(x);
        return newNode;
    }

    else {
        if(x < t->key) {
            t->left = treeInsert(t->left, x);
            return t;
        }
        else{
            t->right = treeInsert(t->right, x);
            return t;
        }
    }
}   

template <typename T>
void cBinarySearchTree<T>::treeDelete(cNode<T>* t, cNode<T>* r, cNode<T>* p){

    if(r == t) {
        root = deleteNode(t);
    }

    else if(r == p->left) {
        p->left = deleteNode(r);
    }
    else {
        p->right = deleteNode(r);
    }
}

template <typename T>
cNode<T>* cBinarySearchTree<T>::deleteNode(cNode<T>* r){

    cNode<T>* parent = new cNode<T>;
    cNode<T>* s  = new cNode<T>;

    // 자식 0개
    if(r->left == 0 && r->right == 0){ 
        return 0;
    } 
   
   // 자식 1개 
   else if(r->left == 0 && r->right != 0) return r->right;
   else if(r->left != 0 && r->right == 0) return r->left;
    // 자식 2개 
    else{ 
        s = r->right;
        while(s->left != 0){ 
            parent = s;
            s = s->left;
        }
        r->key = s->key;
        if(s == r->right) r->right = s->right;
        else parent->left = s->right;
        return r;
    } 
}

template <typename T>
void cBinarySearchTree<T>::treePrint(cNode<T>* t, int step){
    if(t == 0) {
        return;
    }
    for (int i = 0; i < step; i++){
        printf("    ");

    }
    printf("%d\n", t->key);
    step++;
    treePrint(t->left, step);
    treePrint(t->right, step);
}