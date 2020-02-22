#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

typedef struct node node_t;

node_t* create_node(int v) {
    node_t* t = (node_t*)malloc(sizeof(node_t));
    if (!t) {
        fprintf(stderr, "create_node");
        return NULL;
    }
    t->val = v;
    t->next = NULL;
    return t;
}

void destroy_node(node_t* n) {
    if (n) {
        free(n);
    }
}

node_t* add_node(node_t* n, int v) {
    node_t* t = create_node(v);
    t->next = n;
    return t;
}

void* reverse(node_t** n) {
    node_t* prev = NULL;
    node_t* curr = *n;
    node_t* t = NULL;
    while (curr) {
        t = curr->next;
        curr->next = prev;
        prev = curr;
        curr = t;
    }
    *n = prev;
}

node_t* recursive_reverse(node_t* n) {
    if (!n || !n->next) {
        return n;
    }
    node_t* t = recursive_reverse(n->next);
    n->next->next = n;
    n->next = NULL;
    return t;
}

int main() {
    node_t* n = create_node(1);
    n = add_node(n, 2);
    n = add_node(n, 3);
    n = add_node(n, 4);
    n = add_node(n, 5);
    for (node_t* ptr = n; ptr; ptr = ptr->next) {
        printf("%d ", ptr->val);
    }
    printf("\n");

    // reverse(&n);
    n = recursive_reverse(n);
    for (node_t* ptr = n; ptr; ptr = ptr->next) {
        printf("%d ", ptr->val);
    }
    printf("\n");

    return 0;
}
