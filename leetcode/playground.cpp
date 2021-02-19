#include <iostream>
using namespace std;

typedef struct node {
    int val;
    struct node* next;
} node_t;

node* create_node(int v) {
    node_t* n = (node_t*)malloc(sizeof(node_t));
    if (!n) {
        return nullptr;
    }
    n->val = v;
    n->next = nullptr;

    return n;
}

// 4->3-> 2 -> 1
node_t* reverse(node_t* head) {
    node_t* prev = nullptr;
    node_t* curr = head;
    while (curr) {
        node_t* t = curr->next;
        curr->next = prev;
        prev = curr;
        curr = t;
    }
    return prev;
}

int main() {

    node_t* n = create_node(1);
    node_t* q = create_node(2);
    q->next = n;
    node_t* w = create_node(3);
    w->next = q;
    node_t* r = create_node(4);
    r->next = w;

    node_t* result = reverse(r);

    for (node_t* ptr = result; ptr; ptr = ptr->next) {
        cout << ptr->val << " ";
    }
    cout << endl;
    return 0;
}
