//
// Created by king on 2019/8/3.
//

#ifndef ALGORITHM_CPP_AVLTREE_HPP
#define ALGORITHM_CPP_AVLTREE_HPP

class TreeNode {
private:
    int val;
    TreeNode* left, right;
public:
    TreeNode(int n):val(n), left(nullptr), right(nullptr) {

    }
};

class AVLTree{
private:
    TreeNode* root;
public:
    AVLTree() {

    }

    TreeNode* insert(int v) {
        TreeNode* t = new TreeNode(v);
        if (!root) {
            root = t;
        } else if (v == root->val) {

        } else if (v < root->val) {
            root->left = nullptr;
        } else {
            root->right = nullptr;
        }
    }
};

#endif //ALGORITHM_CPP_AVLTREE_HPP
