#include <iostream>
#include <stdio.h>
using namespace std;

class BST {
    public:
        BST();
        BST(int);
        BST* find(BST* root, int key);
        BST* insert(BST* root, int key);
        BST* remove(BST* root, int key);
        void shuffle(int S);
        void shake(int S, int R);
        int avgDepth(BST* root);
        int BSTGetHeight(BST* root);
        void reset();
        int getCount(BST* root);
        // additional functions below
        
    private:
        int data;
        BST *left;
        BST *right;
};