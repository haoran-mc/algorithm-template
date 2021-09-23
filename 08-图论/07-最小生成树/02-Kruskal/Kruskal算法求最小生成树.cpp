/*----------------------------------------------------------------
 *   
 *   文件名称：Kruskal算法求最小生成树.cpp
 *   创建日期：2021年08月12日 星期四 23时59分12秒
 *   题    目：AcWing 0859 Kruskal算法求最小生成树
 *   算    法：Kruskal(稀疏图，点多边少)
 *   描    述：由于我们只需要知道边就可以进行Kruskal，所以用一个
 *      结构体存储就可以
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using std::sort;
const int maxn = 2e5 + 5;
int n, m;
int fa[maxn];

struct Edge {
    int a, b, c;
    bool operator < (const Edge &E) const {
        return c < E.c;
    }
} edge[maxn];

int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[i] = {a, b, c};
    }
    sort(edge, edge + m);
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    int res = 0, cnt = 0;  // 所有边权之和，加入到集合中边的个数
    for (int i = 0; i < m; ++i) {
        int a = edge[i].a, 
            b = edge[i].b,
            c = edge[i].c;
        int root_a = find(a),
            root_b = find(b);
        if (root_a != root_b) {
            fa[root_a] = root_b;
            res += c;
            cnt ++;
        }
    }
    if (cnt < n - 1)
        printf("impossible\n");
    else
        printf("%d\n", res);
    return 0;
}
