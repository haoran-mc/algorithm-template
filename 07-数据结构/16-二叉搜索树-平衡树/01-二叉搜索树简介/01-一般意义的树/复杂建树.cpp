#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}Node;

void preorder(Node* node) {
    if (node != NULL) {
        printf("%d\n", /* node.data */ node -> data);
        preorder(node -> left );
        preorder(node -> right);
    }
}

void inorder(Node* node) {
    if (node != NULL) {
        inorder(node -> left );
        printf("%d\n", node -> data);
        inorder(node -> right);
    }
}

void postorder(Node* node) {
    if (node != NULL) {
        postorder(node -> left );
        postorder(node -> right);
        printf("%d\n", node -> data);
    }
}

int main() {
    struct node n1;
    struct node n2;
    Node n3;
    Node n4;

    n1.data = 5;
    n2.data = 6;
    n3.data = 7;
    n4.data = 8;

    n1.left  = &n2;
    n1.right = &n3;
    n2.left  = &n4;
    n2.right = NULL;
    n3.left  = NULL;
    n3.right = NULL;
    n4.left  = NULL;
    n4.right = NULL;

    preorder(&n1);
    inorder(&n1);
    postorder(&n1);

    return 0;
}
