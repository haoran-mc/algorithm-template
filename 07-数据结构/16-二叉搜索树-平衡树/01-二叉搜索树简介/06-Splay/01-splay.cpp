/*----------------------------------------------------------------
 *
 *   文件名称：splay.cpp
 *   创建日期：2021年03月06日 ---- 21时47分
 *   题    目：hdu1890
 *   算    法：splay
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int root;
int rev[maxn];  //标记i被翻转
int pre[maxn];  //i的父结点
int size[maxn]; //i的子树上结点的个数
int tree[maxn][2]; //tree[i][o],i的左儿子; tree[i][1],i的右儿子
struct Node{
    int data;
    int id;
    bool operator <(const Node &x)const {
        if (data == x.data)
            return id < x.id;
        return data < x.data;
    }
}node[maxn];

/*计算以x为根的子树包含了多少个子结点*/
void pushup(int x) {
    size[x] = size[tree[x][0]] + size[tree[x][1]] + 1;
}

void update_rev(int x) {
    if (!x)
        return;
    swap(tree[x][0], tree[x][1]);
    rev[x] ^= 1; //标记x被翻转
}

/*本题需要，处理机械臂的翻转*/
void pushdown(int x) {
    if (rev[x]) {
        update_rev(tree[x][0]);
        update_rev(tree[x][1]);
        rev[x] = 0;
    }
}

/*旋转，c = 0左旋; c = 1右旋*/
void rotate(int x, int c) {
    int y = pre[x];
    pushdown(y);
    pushdown(x);
    tree[y][!c] = tree[x][c];
    pre[tree[x][c]] = y;
    if (pre[y])
        tree[pre[y]][tree[pre[y]][1] == y] = x;
    pre[x] = pre[y];
    tree[x][c] = y;
    pre[y] = x;
    pushup(y);
}

/*把结点x旋转为goal的儿子，如果goal是0，则旋转到根*/
void splay(int x, int goal) {
    pushdown(x);
    while (pre[x] != goal) {        //一直旋转，直到x成为goal的儿子
        if (pre[pre[x]] == goal) {  //情况1: x的父结点是根，单旋一次就行
            pushdown(pre[x]);
            pushdown(x);
            rotate(x, tree[pre[x]][0] == x);
        }
        else {                      //x的父结点不是根
            pushdown(pre[pre[x]]);
            pushdown(pre[x]);
            pushdown(x);
            int y = pre[x];
            int c = (tree[pre[y]][0] == y);
            if (tree[y][c] == x) {  //情况2: x、x的父、x父的父不共线
                rotate(x, !c);
                rotate(x, c);
            }
            else {                  //情况3: x、x的父、x父的父共线
                rotate(y, c);
                rotate(x, c);
            }
        }
    }
    pushup(x);
    if (goal == 0)                 //如果goal是0，则将根结点更新为x
        root = x;
}

int get_max(int x) {
    pushdown(x);
    while (tree[x][1]) {
        x = tree[x][1];
        pushdown(x);
    }
    return x;
}

void del_root() {
    if (tree[root][0] == 0) {
        root = tree[root][1];
        pre[root] = 0;
    }
    else {
        int m = get_max(tree[root][0]);
        splay(m, root);
        tree[m][1] = tree[root][1];
        pre[tree[root][1]] = m;
        root = m;
        pre[root] = 0;
        pushup(root);
    }
}

void newnode(int &x, int fa, int val) {
    x = val;
    pre[x] = fa;
    size[x] = 1;
    rev[x] = 0;
    tree[x][0] = tree[x][1] = 0;
}

void buildtree(int &x, int L, int R, int fa) {
    if (L > R)
        return;
    int mid = (L + R) >> 1;
    newnode(x, fa, mid);
    buildtree(tree[x][0], L, mid-1, x);
    buildtree(tree[x][1], mid+1, R, x);
    pushup(x);
}

void init(int n) {
    root = 0;
    tree[root][0] = tree[root][1] = pre[root] = size[root] = 0;
    buildtree(root, 1, n, 0);
}

int main() {
    int n;
    while (~scanf("%d", &n) && n) {
        init(n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &node[i].data);
        sort(node+1, node+n+1);
        for (int i = 0; i < n; ++i) {
            splay(node[i].id, 0);
            update_rev(tree[root][0]);
            printf("%d", i + size[tree[root][0]]);
            del_root();
        }
        printf("%d\n", n);
    }
    return 0;
}
