//
// Created by king on 2019/8/3.
//

#include "AvlTree.hpp"

TreeNode *AVLTree::insert(TreeNode *x, int val) {
    if (x == nullptr) {
        return new TreeNode(val);
    } else if (val < x->val) {
        x->left = insert(x->left, val);
    } else if (val > x->val) {
        x->right = insert(x->right, val);
    } else {
        x->val = val;
    }
    return x;
}

void AVLTree::insert(int val) {
    root = insert(root, val);
}
