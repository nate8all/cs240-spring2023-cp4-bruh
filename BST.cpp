#include <stdio.h>
#include "BST.h"

BST::BST() {
    data = 0;
    left = nullptr;
    right = nullptr;
    countComparisons = 0;
}

BST::BST(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
    countComparisons = 0;
}

// Assignment 1 (find)
BST* BST::find(BST* root, int key){
    if(root == nullptr) {
        return nullptr;
    }
    int diff = root->data - key;

    if(diff == 0) {
        countComparisons++;
        return root;
    }
    if(diff > 0) {
        countComparisons++;
        return find(root->left, key);
    }
    countComparisons++;
    return find(root->right, key);
}

// Assignment 2
BST* BST::insert(BST* root, int key) {
    if(root == nullptr) {
        return new BST(key);
    }

    if(key < root->data) {
        countComparisons++;
        root->left = insert(root->right, key);
    }
    else if(key == root->data) {
        countComparisons++;
        return root;
    }
    else {
        countComparisons++;
        root->right = insert(root->right, key);
    }

    return root;
}

// Assignment 3
BST* BST::remove(BST* root, int key) {
    if(root == nullptr) {
        return root;
    }

    if(key < root->data) {
        countComparisons++;
        root->left = remove(root->left, key);
        return root;
    }
    else if(key > root->data) {
        countComparisons++;
        root->right = remove(root->right, key);
        return root;
    }

    if(root->left == nullptr) {
        BST* temp = root->right;
        delete root;
        return temp;
    }
    else if(root->right == nullptr) {
        BST* temp = root->left;
        delete root;
        return temp;
    }
    else {
        BST* succParent = root;
        BST* succ = root->right;
        while(succ->left != nullptr) {
            succParent = succ;
            succ = succ->left;
        }
        if(succParent != root) {
            succParent->left = succ->right;
        }
        else {
            succParent->right = succ->right;
        }
        root->data = succ->data;
        delete succ;
        return root;
    }
}

// Assignment 4
void BST::shuffle(int S){
    for(int i = 0; i < S; i++) {
        // shuffle values in a vector by performing random swaps of two elements
    }
}

// Assignment 5
void BST::shake(int S, int R) {

}

// Assignment 6
int BST::avgDepth(BST* root){
    return 0;
}

// Assignment 7
int BST::BSTGetHeight(BST* root){
    int leftHeight = 0;
    int rightHeight = 0;
    if(root == nullptr){
        return 0;
    }
    else {
        leftHeight = BSTGetHeight(root->left);
        rightHeight = BSTGetHeight(root->right);
    }
    return 1 + max(leftHeight, rightHeight);
}

// Assignment 8.1
void BST::reset(BST* root) {
    root->countComparisons = 0;
}

// Assignment 8.2
int BST::getCount(BST* root){
    reset(root);
    if(root!=nullptr){
        getCount(root->left);
        countComparisons++;
        getCount(root->right);
    }
    return countComparisons;
}