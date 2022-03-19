#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 1e3;
int index = 0;
bool flag;
struct Node {
    int data;
    int left;
    int right;
}node[maxn];

int newNode(int value) {
    node[index].data  = value;
    node[index].left  = -1;
    node[index].right  = -1;
    return index++;
}

//找到数据域为x的结点，把它修改为newData
void search(int root, int x, int newData) {
    if (root == -1)
        return ;

    if (node[root].data == x)
        node[root].data = newData;

    search(node[root].left,  x, newData);
    search(node[root].right, x, newData);
}

void insert(int &root, int x) {
    if (root == -1) {
        root = newNode(x);
        return ;
    }
    if (/*由二叉树的性质，x需要插入到左子树*/flag)
        insert(node[root].left,  x);
    else
        insert(node[root].right, x);
}

int creatTree(int data[], int n) {
    int root = -1;
    for (int i = 0; i < n; i++)
        insert(root, data[i]);

    return root;
}

void preorder(int root) {
    if (root == -1)
        return ;

    printf("%d\n", node[root].data);
    preorder(node[root].left);
    preorder(node[root].right);
}

void inorder(int root) {
    if (root == -1)
        return ;

    printf("%d\n", node[root].data);
    preorder(node[root].left);
    preorder(node[root].right);
}

void postorder(int root) {
    if (root == -1)
        return ;

    printf("%d\n", node[root].data);
    preorder(node[root].left);
    preorder(node[root].right);
}

void layerorder(int root) {
    queue<int> quu;
    quu.push(root);
    while (quu.empty() == false) {
        int now = quu.front();
        quu.pop();
        printf("%d ", node[now].data);
        if (node[now].left != -1)
            quu.push(node[now].left);

        if (node[now].right != -1)
            quu.push(node[now].left);
    }
}
