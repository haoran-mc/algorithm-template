/*----------------------------------------------------------------
 *
 *   文件名称：Dijkstra求最短路II.cpp
 *   创建日期：2021年08月13日 星期五 11时41分15秒
 *   题    目：AcWing 0850 Dijkstra求最短路II
 *   算    法：Dijkstra
 *   描    述：Dijkstra不可以有负边，堆优化的时间复杂度为O(mlogm)
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int maxn = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n, m;
int h[maxn], e[maxn], ne[maxn], w[maxn], idx;  // 邻接表，还要存权重
int dist[maxn];
bool used[maxn];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    memset(used, 0, sizeof used);
    int source = 1; dist[source] = 0;
    // 小根堆，优先队列会按结构体的第一位排序，所以将距离放在第一位，它就会把距离最小的放在最前面，得到最近的点
    priority_queue<PII, vector<PII>, greater<PII>> he;
    he.push({0, source});  // 距离：0, 源点：source
    while (he.size()) {
        auto t = he.top();  // t = top，小根堆的堆顶，距离集合最近的点
        he.pop();
        int d = t.first, vert = t.second;   // d = dist, 堆顶元素vert距离源点的距离
        if (used[vert])   // 冗余
            continue;
        used[vert] = true;
        // 用vert更新所有它邻接的点
        // 因为一个点可能同时被上一个vert和当前vert更新，就会压入堆中两次，所以就有了上面的消除冗余
        for (int i = h[vert]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > d + w[i]) {
                dist[j] = d + w[i];
                he.push({dist[j], j});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof h);  // 邻接表
    while (m --) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
    }
    dijkstra();
    if (dist[n] == INF)
        printf("-1\n");
    else
        printf("%d\n", dist[n]);
    return 0;
}
