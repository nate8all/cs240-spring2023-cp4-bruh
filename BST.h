#include <iostream>
#include <stdio.h>
using namespace std;

class BST {
    public:
        BST();
        BST(int);
        BST* insert(BST*, int);
        BST* remove(BST*, int);
        find();
        shuffle();
        shake();
        int avgDepth(BST* node);
        int BSTGetHeight(BST* node);
        reset();
        int getCount(BST* node);
        // additional functions below
        
    private:
        int data;
        BST *left;
        BST *right;
};