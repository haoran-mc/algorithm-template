/*----------------------------------------------------------------
 * 文件名称：抓住那头牛.cpp
 * 创建日期：2021年11月23日 星期二 23时43分17秒 
 * 题 目：AcWing 1100 抓住那头牛 
 * 算 法：最短路模型 
 * 描 述：农夫位于坐标轴的点 N，牛位于 K 
 * 农夫有两种移动方式：
 * 1. x - 1，x + 1
 * 2. 2 * x
 * 每种移动都花费一分种
 *
 * 农夫最少要花多少时间抓住牛,牛不动
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <cstring>
const int maxn = 1e5 + 5;
int n, k, q[maxn];
bool used[maxn];
int dist[maxn];
int BFS() {
    memset(dist, -1, sizeof dist);
    dist[n] = 0;
    int hh = 0, tt = -1;
    q[ ++ tt] = n;
    while (hh <= tt) {
        int t = q[hh ++ ];
        if (t == k)
            return dist[k];
        if (t + 1 < maxn && dist[t + 1] == -1) {
            dist[t + 1] = dist[t] + 1;
            q[ ++ tt] = t + 1;
        }
        if (t - 1 >= 0 && dist[t - 1] == -1) {
            dist[t - 1] = dist[t] + 1;
            q[ ++ tt] = t - 1;
        }
        if (t * 2 <= maxn && dist[t * 2] == -1) {
            dist[t * 2] = dist[t] + 1;
            q[ ++ tt] = t * 2;
        }
    }
    return -1;
}
int main() {
    scanf("%d %d", &n, &k);
    printf("%d\n", BFS());
    return 0;
}
