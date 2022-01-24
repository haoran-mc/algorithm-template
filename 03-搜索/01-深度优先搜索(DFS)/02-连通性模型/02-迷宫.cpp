/*----------------------------------------------------------------
 * 文件名称：迷宫.cpp
 * 创建日期：2021年11月26日 星期五 18时38分26秒 
 * 题 目：AcWing 1112 迷宫 
 * 算 法：深度优先搜索 
 * 描 述：
 * .....
 * ###.#
 * ..#..
 * ###..
 * ...#.
 *
 * 会给出 A 和 B 的坐标，问是否可以从 A 到 B
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <cstring>
const int maxn = 110;
int n, ax, ay, bx, by;
char g[maxn][maxn];
bool used[maxn][maxn];
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
bool DFS(int x, int y) {
    if (g[x][y] == '#')
        return false;
    if (x == bx && y == by)
        return true;
    used[x][y] = true;
    for (int i = 0; i < 4; ++ i) {
        int nx = x + dx[i],
        ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (used[nx][ny]) continue;
        if (g[nx][ny] == '#') continue;
        if (DFS(nx, ny))
            return true;
    }
    return false;
}
int main() {
    int t; scanf("%d", &t);
    while (t -- ) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i)
            scanf("%s", g[i]);
        memset(used, 0, sizeof used);
        scanf("%d %d %d %d", &ax, &ay, &bx, &by);
        if (DFS(ax, ay))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
