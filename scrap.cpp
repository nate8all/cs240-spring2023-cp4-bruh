#include <stdio.h>
using namespace std;

// Assignment 6
//unfinished
int avgDepth(BST* node){
    int avgDepth = 0;
    int depthSum = 0;
    int leftDepth = BSTGetHeight(root->left);
    int rightDepth = BSTGetHeight(root->right);
    if(node == nullptr){
        return 0;
    }
    else{
        depthSum = leftDepth + rightDepth;
        //divide depthSum by # of nodes ?
    }
}



// Assignment 7
int BSTGetHeight(BST* node) {
   if (node == nullptr) {
      return -1;
   }
   int leftHeight = BSTGetHeight(node->left);
   int rightHeight = BSTGetHeight(node->right);
   return 1 + max(leftHeight, rightHeight);
}