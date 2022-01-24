/*----------------------------------------------------------------
 *
 *   文件名称：1-二叉查找树.cpp
 *   创建日期：2020年09月22日 ---- 15时50分
 *   算    法：BST Binary Search Tree
 *   描    述：正月打灯笼
 *             未考虑负数
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstdlib>

struct Node {
    int data;
    Node* left;
    Node* right;
};
struct Tree {
    Node* root;
};

void insert(Tree* tree, int value) {
    Node* node = (Node *)malloc(sizeof(Node));
    node -> data  = value;
    node -> left  = NULL;
    node -> right = NULL;
    if (tree -> root == NULL)
        tree -> root = node;
    else {
        Node* temp = tree -> root;
        while (temp != NULL) {
            if (value < temp -> data) {
                if (temp -> left == NULL) {
                   temp -> left = node;
                    return ;
                }
                else
                    temp = temp -> left;
            }
            else {
               if (temp -> right == NULL) {
                    temp -> right = node;
                    return ;
                }
                else
                    temp = temp -> right;
            }
        }
    }
}

int get_height(Node* node) {
    if (node == NULL)
        return 0;
    else {
        int left_h  = get_height(node -> left);
        int right_h = get_height(node -> right);
        int max = left_h;
        if (right_h > max)
            max = right_h;
        return max + 1;
    }
}

int get_maximum(Node* node) {
    if (node == NULL)
        return -1;
    else {
        int m1 = get_maximum(node -> left);
        int m2 = get_maximum(node -> right);
        int m3 = node -> data;
        int max = m1;
        if (m2 > max) { max = m2; }
        if (m3 > max) { max = m3; }
        return max;
    }
}

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
    int arr[7] = {6, 3, 8, 2, 5, 1, 7};
    Tree tree;
    tree.root = NULL;

    for (int i = 0; i < 7; ++i)
        insert(&tree, arr[i]);

    preorder(tree.root);
    printf("\n");
    // inorder(tree.root);

    int h = get_height(tree.root);
    printf("h = %d\n", h);

    int m= get_maximum(tree.root);
    printf("max = %d\n", m);
    return 0;
}
