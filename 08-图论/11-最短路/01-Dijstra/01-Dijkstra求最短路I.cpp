/*----------------------------------------------------------------
 *
 *   文件名称：Dijkstra求最短路I.cpp
 *   创建日期：2021年08月13日 星期五 11时07分24秒
 *   题    目：AcWing 0849 Dijkstra求最短路I
 *   算    法：Dijkstra
 *   描    述：朴素版Dijkstra，可以解决重边，自环问题，但是不能解决负环问题
 *      因为没有负数，所以重边也就没有意义了，因为重边是正的，就不会更新这
 *      条边。
 *      本题是有向图，转化为无向图很容易，时间复杂度O(n^2)
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 500 + 5;
const int INF = 0x3f3f3f3f;
int n, m;
int g[maxn][maxn], dist[maxn];
bool used[maxn];

// dist[n]表示从源点到第n个点的最短路
void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    memset(used, 0, sizeof used);
    int source = 1; dist[source] = 0;  // 设置源点
    for (int i = 0; i < n; ++i) {
        int vert = -1;
        for (int j = 1; j <= n; ++j)
            if (!used[j] && (vert == -1 || dist[j] < dist[vert]))
                vert = j;
        used[vert] = true;
        for (int j = 1; j <= n; ++j)
            if (!used[j])
                dist[j] = min(dist[j], dist[vert] + g[vert][j]);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    memset(g, 0x3f, sizeof g);
    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    dijkstra();
    if (dist[n] == INF)
        printf("-1\n");
    else
        printf("%d\n", dist[n]);
    return 0;
}
