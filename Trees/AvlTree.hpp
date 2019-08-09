//
// Created by king on 2019/8/3.
//

#ifndef ALGORITHM_CPP_AVLTREE_HPP
#define ALGORITHM_CPP_AVLTREE_HPP

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int n):val(n), left(nullptr), right(nullptr) {

    }
};

class AVLTree{
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* x, int val);

public:
    AVLTree():root(nullptr) {

    }

    void insert(int val);

};

#endif //ALGORITHM_CPP_AVLTREE_HPP
