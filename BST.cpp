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