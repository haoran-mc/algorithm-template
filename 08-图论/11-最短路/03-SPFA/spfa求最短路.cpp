/*----------------------------------------------------------------
 *   
 *   文件名称：spfa求最短路.cpp
 *   创建日期：2021年08月13日 星期五 15时13分46秒
 *   题    目：AcWing 0851 spfa求最短路
 *   算    法：spfa
 *   描    述：Bellman-Ford算法是对每个点每条边都更新，而spfa只更新
 *      那些在第一次更新时变小的点，不可以操作有负权回路的图
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n, m;
int h[maxn], e[maxn], ne[maxn], w[maxn], idx;  // 邻接表，还要存权重
int dist[maxn];
bool used[maxn];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void spfa() {
    memset(dist, 0x3f, sizeof dist);
    int source = 1; dist[source] = 0;
    queue<int> quu;
    quu.push(source); used[source] = true;  // used表示当前元素是否在队列中，防止出现重复的点
    while (quu.size()) {
        int vert = quu.front();
        quu.pop();
        used[vert] = false;
        for (int i = h[vert]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[vert] + w[i]) {
                dist[j] = dist[vert] + w[i];
                if (!used[j]) {
                    quu.push(j);
                    used[j] = true;
                }
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
    spfa();
    if (dist[n] == INF)
        printf("impossible\n");
    else
        printf("%d\n", dist[n]);
    return 0;
}
