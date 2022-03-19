/*----------------------------------------------------------------
 *
 *   文件名称：01-树的深度优先搜索.cpp
 *   创建日期：2021年04月14日 ---- 19时53分
 *   题    目：算法竞赛
 *   算    法：树的深度优先搜索，链式前向星
 *   描    述：树的深度优先搜索，树的dfs序，树的深度，树的重心
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
const int inf  = 0x3f3f3f3f;
int n, m;
int vert[maxn], edge[maxn], nxet[maxn], head[maxn], tot;
int cnt, dfs[maxn]; //记录DFS序
bool used[maxn];
int d[maxn]; //记录结点深度
int size[maxn];
int res = inf, pos = -1; //res记录重心对应的max_part值，pos记录了重心

//加入有向边(x, y)，权值为z
void add(int x, int y, int z) {
    vert[++tot] = y;
    edge[tot]   = z;
    nxet[tot]   = head[x];
    head[x] = tot;
}

/*
 * 树的深度优先搜索
 *
 * 求树的dfs序
 * 但由于邻接表的倒序搜索
 * 所以dfs序也是倒序的
 *
 * 求树的深度
 */
void DFS(int x) {
    dfs[cnt++] = x;
    used[x] = true;
    for (int i = head[x]; i; i = nxet[i]) {
        int y = vert[i]; //因为链式前向星是倒序的，所以此处y = 是x的父结点
        if (used[y]) continue;
        d[y] = d[x] + 1;
        DFS(y);
    }
    dfs[cnt++] = x;
}

/*
 *        0
 *       /|\
 *      / | \
 *     1  6 [3]
 *    /|    / \
 *   / |   /   \
 *  7  4  2     5
 *        |
 *        |
 *        8
 */


//树的重心 --- 树的重心与边的权值无关
void gravity(int x) {
    used[x] = true;
    size[x] = 1;
    int max_part = 0;
    for (int i = head[x]; i; i = nxet[i]) { //遍历x的子结点
        int y = vert[i];
        if (used[y]) continue;
        gravity(y);  //这句很巧妙，没有返回值，而是递归结束条件是子结点的size为1
        size[x] += size[y];
        max_part = max(max_part, size[y]);  //比较所有子树的size
    }
    max_part = max(max_part, n-size[x]); //删去结点x后父结点处还有一棵树，size为n-size[x]
    if (max_part < res) {
        res = max_part;
        pos = x;
    }
}

int main() {
    freopen("in/in-01.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        add(x, y, z);
    }
    DFS(0);
    //DFS深度优先搜索
    for (int x = 0; x < n; ++x)
        for (int i = head[x]; i; i = nxet[i]) {
            int y = vert[i];
            // int z = edge[i];
            printf("%d %d\n", x, y);
        }

    //dfs序
    printf("dfs序: ");
    for (int i = 0; i < 2*n; ++i)
        printf("%d ", dfs[i]);
    printf("\n");

    //结点深度
    for (int i = 0; i < n; ++i)
        printf("depth[%d] = %d\n", i, d[i]);

    memset(used, 0, sizeof(used));
    gravity(0);
    printf("重心以及重心对应的max_part值: %d %d\n", pos, res);
    return 0;
}
