/*----------------------------------------------------------------
 *
 *   文件名称：Prim算法求最小生成树.cpp
 *   创建日期：2021年08月12日 星期四 19时52分32秒
 *   题    目：AcWing 0858 Prim算法求最小生成树
 *   算    法：prim(稠密图, 边多)
 *   描    述：注意：本题下标从1开始，本题可以解决自环、重环、边权为负数问题
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 500 + 5;
const int INF = 0x3f3f3f3f;
int n, m;
int g[maxn][maxn];
int dist[maxn];
bool used[maxn];

/**
 * 这里res存储的是最小生成树上所有边权之和
 * 如果确定有最小生成树，可以返回空void
 * 然后把所有的res删除，dist[]中是这棵树的所有边权
 */
int prim() {
    memset(dist, 0x3f, sizeof dist);
    memset(used, 0, sizeof used);
    int source = 1; dist[source] = 0;   // 设置源点，不然下面的判断语句要额外判断是否是源点
    int res = 0;
    for (int i = 0; i < n; ++i) {   // 这个循环只是为了将n个点都加入集合中，下标无所谓
        int vert = -1;  // 用vert找到集合外最近的点
        for (int j = 1; j <= n; ++j)   // 根据题目要求设置下标开始的位置
            if (!used[j] && (vert == -1 || dist[j] < dist[vert]))
                vert = j;
        used[vert] = true;   // 找到后标记true
        if (dist[vert] == INF)   // 如果不能形成最小生成树，一般不会，除非这个点不连通
            return INF;
        // 用新加入集合中的点vert更新未进入集合的点到集合的距离
        for (int j = 1; j <= n; ++j)
            if (!used[j])
                dist[j] = min(dist[j], g[vert][j]);
        res += dist[vert];
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &m);
    memset(g, 0x3f, sizeof g);
    while (m--) {
        int a, b, c; 
        scanf("%d %d %d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int res = prim();
    if (res >= INF)
        printf("impossible\n");
    else
        printf("%d\n", res);
    return 0;
}
