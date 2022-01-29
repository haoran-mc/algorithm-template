/*----------------------------------------------------------------
 * 文件名称：第k短路.cpp
 * 创建日期：2021年11月25日 星期四 10时41分54秒 
 * 题 目：AcWing 0178 第k短路 
 * 算 法：A* 
 * 描 述：n 个点，m 条边的有向图，求从起点 s 到终点 t 的第 k 
 * 短路的长度，路径允许重复经过点和边 
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1e3 + 5;
const int maxm = 2e5 + 5;
int n, m;
int h[maxn], rh[maxn], e[maxm], w[maxm], ne[maxm], idx;
int dist[maxn], f[maxn], used[maxn];
int S, T, K;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
void add(int *h, int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
void dijkstra() {
    priority_queue<PII, vector<PII>, greater<PII>> he;
    memset(dist, 0x3f, sizeof dist);
    dist[T] = 0;
    he.push({0, T});
    while (he.size()) {
        auto t = he.top(); he.pop();
        int ver = t.second;
        if (used[ver])
            continue;
        used[ver] = true;
        for (int i = rh[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                he.push({dist[j], j});
            }
        }
    }
    memcpy(f, dist, sizeof dist);
}
int astar() {
    priority_queue<PIII, vector<PIII>, greater<PIII>> he;
    he.push({f[S], {0, S}});
    memset(used, 0, sizeof used);
    while (he.size()) {
        auto t = he.top(); he.pop();
        int ver = t.second.second, distance = t.second.first;
        if (used[ver] >= K)
            continue;
        used[ver] ++ ;
        if (ver == T && used[ver] == K)
            return distance;
        for (int i = h[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if (used[j] < K)
                he.push({distance + w[i] + f[j], {distance + w[i], j}});
        }
    }
    return -1;
}
int main() {
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    for (int i = 0; i < m; ++ i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add(h, a, b, c), add(rh, b, a, c);
    }
    scanf("%d %d %d", &S, &T, &K);
    if (S == T)
        K ++ ;
    dijkstra(); // 求启发函数，每个点到终点的最短距离
    printf("%d\n", astar());
    return 0;
}
