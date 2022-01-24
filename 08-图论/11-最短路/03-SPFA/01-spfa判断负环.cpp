/*----------------------------------------------------------------
 *   
 *   文件名称：spfa判断负环.cpp
 *   创建日期：2021年08月13日 星期五 16时09分25秒
 *   题    目：AcWing 0852 spfa判断负环
 *   算    法：spfa
 *   描    述：给定一个n个点m条边的有向图，图中可能存在重边和自环，
 *        边权可能为负数，判断图中是否存在负权回路
 *        当有一个cnt[x] >= n时，就说明出现了负环
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
int dist[maxn], cnt[maxn];   // 这个cnt数组是多加的，cnt[x]记录从源点到节点x的最短路经过了多少条边
bool used[maxn];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

bool spfa() {
    // 有没有发现这里没有初始化了，因为我们不是求距离了
    // 也没有源点source了，这是因为我们需要找到负环，而不只是从源点到达的负环
    queue<int> quu;
    for (int i = 1; i <= n; ++i) {
        used[i] = true;
        quu.push(i);
    }
    while (quu.size()) {
        int vert = quu.front();
        quu.pop();
        used[vert] = false;
        for (int i = h[vert]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[vert] + w[i]) {
                dist[j] = dist[vert] + w[i];
                cnt[j] = cnt[vert] + 1;
                if (cnt[j] >= n)
                    return true;
                if (!used[j]) {
                    quu.push(j);
                    used[j] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof h);  // 邻接表
    while (m --) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
    }
    spfa() ? printf("Yes\n") : printf("No\n");
    return 0;
}
