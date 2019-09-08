//
// Created by king on 2019/8/3.
//

#ifndef ALGORITHM_CPP_AVLTREE_HPP
#define ALGORITHM_CPP_AVLTREE_HPP

class AVLTree {
private:
    class Node {
    public:
        int key;
        int val;
        int height;
        int size;
        Node* left;
        Node* right;

        Node(int k, int x, int h, int s):key(k), val(x), height(h), size(s), left(nullptr), right(nullptr) {

        }
    };

    Node* root;

    int size(Node* x);

    int height(Node* x);

    Node* get(Node* x, int key);

    Node* put(Node* x, int key, int val);

public:
    AVLTree() {
        root = nullptr;
    }

    ~AVLTree() {

    }

    bool isEmpty();

    int size();

    int height();

    int get(int key);

    void put(int key, int val);


};


#endif //ALGORITHM_CPP_AVLTREE_HPP
