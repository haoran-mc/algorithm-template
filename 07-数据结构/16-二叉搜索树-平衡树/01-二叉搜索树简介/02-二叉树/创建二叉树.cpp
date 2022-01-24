/*----------------------------------------------------------------
 *
 *   文件名称：1-创建二叉树.cpp
 *   创建日期：2020年09月22日 ---- 17时06分
 *   算    法：二叉树
 *   描    述：学习二叉搜索树的创建
 *
----------------------------------------------------------------*/

#include <cstdio>

bool flag = false;
struct Node {
    int data;
    Node* left;
    Node* right;
};

/*新建结点*/
Node* newNode(int value) {
    Node* node = new Node;
    node -> data = value;
    node -> left = node -> right = NULL;
    return node;
}

/*二叉树结点的查找与修改*/
void search(Node* root, int x, int newdata) {
    if (root == NULL)
        return ;
    if (root -> data == x)
        root -> data = newdata;

    search(root -> left,  x, newdata);
    search(root -> right, x, newdata);
}

/*二叉树结点的插入*/
/*必须使用引用*/
void insert(Node* &root, int x) {
    if (root == NULL) {
        root = newNode(x);
        return ;
    }
    if (/*根据题目，x插在左子树*/flag)
        insert(root -> left, x);
    else
        insert(root -> right, x);
}

/*二叉树的创建*/
Node* creatTree(int data[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++)
        insert(root, data[i]);
    return root;
}

int main() {
    int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* root = creatTree(data, 10);
    search(root, 4, 5);
    /*遍历*/
    return 0;
}
