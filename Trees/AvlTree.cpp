//
// Created by king on 2019/8/3.
//

#include <algorithm>
#include "AvlTree.hpp"

void AVLTree::put(int key, int val) {
    root = put(root, key, val);
}

int AVLTree::get(int key) {
    auto node = get(root, key);
    if (!node) {
        return -1;
    }
    return node->val;
}

int AVLTree::height() {
    return height(root);
}

int AVLTree::size() {
    return size(root);
}

bool AVLTree::isEmpty() {
    return root == nullptr;
}

AVLTree::Node *AVLTree::put(AVLTree::Node *x, int key, int val) {
    if (!x) {
        return new Node(key, val, 0, 1);
    }

    if (key < x->key) {
        x->left = put(x->left, key, val);
    } else if (key > x->key) {
        x->right = put(x->right, key, val);
    } else {
        x->val = val;
    }
    x->size = 1 + size(x->left) + size(x->right);
    x->height = 1 + std::max(height(x->left), height(x->right));
}

AVLTree::Node *AVLTree::get(AVLTree::Node *x, int key) {
    if (x == nullptr) {
        return nullptr;
    }
    if (key < x->key) {
        return get(x->left, key);
    } else if (key > x->key) {
        return get(x->right, key);
    }
    return x;
}

int AVLTree::height(AVLTree::Node *x) {
    if (!x) {
        return -1;
    }
    return x->height;
}

int AVLTree::size(AVLTree::Node *x) {
    if (!x) {
        return 0;
    }
    return x->size;
}
