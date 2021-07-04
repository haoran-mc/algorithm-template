/*----------------------------------------------------------------
 *
 *   文件名称：04-邻接表.cpp
 *   创建日期：2021年04月14日 ---- 16时30分
 *   题    目：算法竞赛
 *   算    法：邻接表
 *   描    述：这种的邻接表和一般的邻接表不一样，这个是按输入的倒序
 *      存储的
 *      如果从head[x]开始搜索，得到的是最后一次加入到链表x的边tot
 *      vert[tot]，edge[tot]存储的是与x相连的节点和权值，然后进行操作
 *      i = next[i]，此时i是x结点上一次添加的边，所以是倒序打印
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e5 + 5;
int vert[maxn], edge[maxn], next[maxn], head[maxn];
int tot;

//加入有向边(x, y)，权值为z
void add(int x, int y, int z) {
    vert[++tot] = y;
    edge[tot]   = z;
    next[tot]   = head[x];
    head[x] = tot;
}

int main() {
    freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        add(x, y, z);
    }
    for (int x = 0; x < n; ++x)
        //访问从x出发的所有边
        for (int i = head[x]; i; i = next[i]) {
            int y = vert[i];
            int z = edge[i];
            printf("%d %d %d\n", x, y, z);
        }
    return 0;
}
