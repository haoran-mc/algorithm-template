/*----------------------------------------------------------------
 *
 *   文件名称：04-邻接表.cpp
 *   创建日期：2021年04月14日 ---- 16时30分
 *   题    目：算法竞赛
 *   算    法：邻接表
 *   描    述：这种的邻接表和一般的邻接表不一样，这个是按输入的倒序
 *      存储的
 *      如果从h[x]开始搜索，得到的是最后一次加入到链表x的边tot
 *      ve[tot]，ed[tot]存储的是与x相连的节点和权值，然后进行操作
 *      i = ne[i]，此时i是x结点上一次添加的边，所以是倒序打印
 *
 *      !一定要有memset(h, -1, sizeof h)，因为你的tot是从0开始的
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
const int maxn = 1e5 + 5;
int ve[maxn], ed[maxn], ne[maxn], h[maxn];
int tot;

//加入有向边(x, y)，权值为z
void add(int x, int y, int z) {
    ve[tot] = y;
    ed[tot] = z;
    ne[tot] = h[x];
    h[x] = tot++;
}

int main() {
    // freopen("in.txt", "r", stdin);
    int n, m;
    memset(h, -1, sizeof h);   // 这条链表的最后一个是-1
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        add(x, y, z);
    }
    printf("<-->\n");
    for (int x = 1; x <= n; ++x)
        //访问从x出发的所有边
        for (int i = h[x]; i != -1; i = ne[i]) {
            int y = ve[i];
            int z = ed[i];
            printf("%d %d %d\n", x, y, z);
        }
    return 0;
}
/*
6 7
4 3 1
4 6 1
3 6 1
3 2 1
1 2 1
6 1 1
6 5 1
*/
