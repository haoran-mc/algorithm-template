/*----------------------------------------------------------------
 *
 *   文件名称：Floyd求最短路.cpp
 *   创建日期：2021年08月13日 星期五 16时23分01秒
 *   题    目：AcWing 0854 Floyd求最短路
 *   算    法：Floyd
 *   描    述：给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环
 *   边权可能为负数。再给定 k 个询问，每个询问包含两个整数 x 和 y，
 *   表示查询从点 x 到点 y 的最短距离，如果路径不存在，则输出 impossible
 *
 *   可以有负权边，不可有负权回路
 *
 *   算法过程：检查是否存在一个点k使得i与j之间的最短路能够更新
 *   基于动态规划理解：d[k, i, j]表示从i点只经过[i, k]这些点到达j的最短路径
 *                     d[k-1, i, j] = d[k-1, i, k] + d[k-1, k, j];
 *                     发现第一维可以去掉 d[i, j] = d[i, k] + d[k, j];
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 200 + 5;
const int INF = 0x3f3f3f3f;
int n, m, Q;
int d[maxn][maxn];   // 使用d数组而不是g数组，因为后面会更改里面的值，最后存的是距离

void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
    scanf("%d %d %d", &n, &m, &Q);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i == j)
                d[i][j] = 0;  // 防止出现自环
            else
                d[i][j] = INF;
    while (m --) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);  // 取消重边
    }
    floyd();
    while (Q --) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (d[a][b] > INF / 2)
            printf("impossible\n");
        else
            printf("%d\n", d[a][b]);
    }
    return 0;
}
