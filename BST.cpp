#include <stdio.h>
#include "BST.h"

BST::BST() {
    data = 0;
    left = nullptr;
    right = nullptr;
}

BST::BST(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
}

BST* BST::insert(BST* root, int key) {
    if(root == nullptr) {
        return new BST(key);
    }

    if(key < root->data) {
        root->left = insert(root->right, key);
    }
    else if(key == root->data) {
        return root;
    }
    else {
        root->right = insert(root->right, key);
    }

    return root;
}

BST* BST::remove(BST* root, int key) {
    if(root == nullptr) {
        return root;
    }

    if(key < root->data) {
        root->left = remove(root->left, key);
        return root;
    }
    else if(key > root->data) {
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