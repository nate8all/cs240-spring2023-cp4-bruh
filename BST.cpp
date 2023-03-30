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

BST::insert(BST* root, int key) {
    if(root == nullptr) {
        return new BST(key);
    }

    if(key < root->data) {
        root->left = insert(root->right, key);
    }
    else {
        root->right = insert(root->right, key);
    }

    return root;
}