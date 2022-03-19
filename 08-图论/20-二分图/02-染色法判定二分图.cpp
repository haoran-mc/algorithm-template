/*----------------------------------------------------------------
 * 文件名称：染色法判定二分图.cpp
 * 创建日期：2021年10月08日 星期五 16时32分49秒 
 * 题 目：AcWing 0860 染色法判定二分图 
 * 算 法：染色法 
 * 描 述：
 * 给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环。
 * 请你判断这个图是否是二分图。
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
const int maxn = 1e5 + 5, maxe = 2e5 + 5;
int h[maxn], e[maxe], ne[maxe], idx;
int n, m;
int color[maxn];
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
// 返回false表示有矛盾
bool DFS(int u, int c) {
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!color[j]) {
            if (!DFS(j, 3 - c))
                return false;
        }
        else if (color[j] == c) {
            return false;
        }
    }
    return true;
}
int main() {
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof h);
    while (m -- ) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b), add(b, a);
    }
    bool flag = true;
    for (int i = 1; i <= n; ++ i)
        if (!color[i])
            // 有两种颜色，1, 2
            if (!DFS(i, 1)) {
                flag = false;
                break;
            }
    if (flag) puts("Yes");
    else puts("No");
    return 0;
}
