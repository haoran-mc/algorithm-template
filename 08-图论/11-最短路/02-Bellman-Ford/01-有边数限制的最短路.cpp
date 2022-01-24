/*----------------------------------------------------------------
 *   
 *   文件名称：有边数限制的最短路.cpp
 *   创建日期：2021年08月13日 星期五 13时46分17秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：Bellman-Ford算法只要能够遍历到所有边就可以，所以
 *      存储时使用结构体就可以，Bellman-Ford可以存在负权边，也可以存在
 *      负权回路
 *            2            4             2
 *      1 ---------- 2 ---------- 3 ---------- 5
 *                    \         /
 *                     \       /
 *                  -2  \     /  -3
 *                       \   /
 *                         4
 *
 *  - 如果出现负权回路，就不存在从1到5的最短路，负权回路不是只有负边，
 *    还要这个回路是的权是负的
 *  - 但是如果存在负环，但是负环又不在我要求的最短路上，那就不影响最后结果
 *  本题只能使用Bellman-Ford算法来做，因为我们限制了这条最短路需要经过k条
 *  边
 *  时间复杂度O(nm)
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 500 + 5, M = 1e4 + 5;
const int INF = 0x3f3f3f3f;
int n, m, k;
int dist[N], backup[N];

struct Edge {
    int a, b, c;
} edge[M];

void bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    int source = 1; dist[source] = 0;
    for (int i = 0; i < k; ++i) {
        /**
         * 迭代k次，为什么要备份dist数组呢？
         * 假如输入:
         * 1 2 1
         * 2 3 1
         * 1 3 3
         * 又k = 1, 那么就有1到3的距离是3, 虽然可以先从1到2距离为1, 然后从2到3距离为1, 得出更短的距离 1 -> 3 = 2
         * 但是有限制k = 1, 即只能经过一条边从1到3, 如果我们不备份的话，更新了1 -> 2 = 1，然后循环继续更新2的出边
         * 就会发生串联，我们只希望第k次迭代dist[x]时使用的是第k-1次的dist
         */
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; ++ j) {
            int a = edge[j].a, b = edge[j].b, c = edge[j].c;
            dist[b] = min(dist[b], backup[a] + c);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[i] = {a, b, c};
    }
    bellman_ford();
    // 为什么除以2, 是因为可能有 t -> n 这条边是负权的，虽然源点到不了n，但是n会被别的点更新小一点
    if (dist[n] > INF / 2)
        printf("impossible\n");
    else
        printf("%d\n", dist[n]);
    return 0;
}
