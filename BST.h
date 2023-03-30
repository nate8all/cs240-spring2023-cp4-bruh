#include <iostream>
#include <stdio.h>
using namespace std;

class BST {
    public:
        BST();
        BST(int);
        BST* insert(BST*, int);
        remove();
        find();
        
    private:
        int data;
        BST *left;
        BST *right;
};