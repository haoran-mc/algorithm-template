/*----------------------------------------------------------------
 *
 *   From OIwiki
 *   文件名称：treap.cpp
 *   创建日期：2021年03月06日 ---- 12时32分
 *   算    法：treap
 *   描    述：treap是一种简单的平衡二叉搜索树
 *   treap除了要满足二叉搜索树的性质之外，还需满足父节点的 priority大于等于两个儿子的priority
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <utility>
#include <cstdlib>
using namespace std;
struct Node{
    int data;
    int priority;
    Node* left;
    Node* right;
};

struct Tree{
    Node* root;
};

/**
 * 分裂
 * pair: 第一个元素存放分裂后的右子树，第二个元素存放分裂后的左子树
 */
pair<Node*, Node*> split(Node *root, int val) {
    if (root == nullptr)
        return make_pair(nullptr, nullptr);

    if (val < root->data) {
        pair<Node*, Node*> pir = split(root->left, val);
        root->left = pir.second;
        return make_pair(pir.first, root);
    }
    else {
        pair<Node*, Node*> pir = split(root->right, val);
        root->right = pir.first;
        return make_pair(root, pir.second);
    }
}

/**
 * 合并
 * 首先要满足rootR上结点值都大于rootL上的结点值
 * 其次，默认条件是每棵树上的根结点优先级最高
 * 通过比较priority合并两棵树
 * 所以合并时，rootR一定放在右边
 * 因为也要满足右结点 > 根结点 > 左结点，两者都要满足
 */
Node* merge(Node* rootL, Node* rootR) {
    if (rootR == nullptr)
        return rootL;
    if (rootL == nullptr)
        return rootR;

    if (rootR->priority > rootL->priority) {
        rootR->left = merge(rootL, rootR->left);
        return rootL;
    }
    else {
        rootL->right = merge(rootL->right, rootR);
        return rootR;
    }
}

void preorder(Node* node) {
    if (node != NULL) {
        printf("%d ", /* node.data */ node -> data);
        preorder(node -> left );
        preorder(node -> right);
    }
}

void inorder(Node* node) {
    if (node != NULL) {
        inorder(node -> left );
        printf("%d ", node -> data);
        inorder(node -> right);
    }
}

void postorder(Node* node) {
    if (node != NULL) {
        postorder(node -> left );
        postorder(node -> right);
        printf("%d ", node -> data);
    }
}

int main() {
    Tree tree;
    Node* node5 = (Node *)malloc(sizeof(Node));
    node5 -> data = 5;
    tree.root = node5;

    Node* node2 = (Node *)malloc(sizeof(Node));
    node2 -> data = 2;
    tree.root -> left = node2;

    Node* node1 = (Node *)malloc(sizeof(Node));
    node1 -> data = 1;
    tree.root -> left -> left = node1;

    Node* node4 = (Node *)malloc(sizeof(Node));
    node4 -> data = 4;
    tree.root -> left -> right = node4;

    Node* node7 = (Node *)malloc(sizeof(Node));
    node7 -> data = 7;
    tree.root -> right = node7;

    Node* node6 = (Node *)malloc(sizeof(Node));
    node6 -> data = 6;
    tree.root -> right -> left = node6;

    Node* node9 = (Node *)malloc(sizeof(Node));
    node9 -> data = 9;
    tree.root -> right -> right = node9;

    Node* node8 = (Node *)malloc(sizeof(Node));
    node8 -> data = 8;
    tree.root -> right -> right -> left = node8;

    pair<Node*, Node*> pir = split(tree.root, 3);

    preorder(pir.first);
    printf("\n");
    inorder(pir.first);
    printf("\n");

    preorder(pir.second);
    printf("\n");
    inorder(pir.second);
    printf("\n");
    return 0;
}
