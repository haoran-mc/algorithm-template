/*----------------------------------------------------------------
 * 文件名称：马走日.cpp
 * 创建日期：2021年11月26日 星期五 19时55分53秒 
 * 题 目：AcWing 1116 马走日 
 * 算 法：深度优先搜索 
 * 描 述：在一个棋盘上，给出马的坐标，马可以有多少种途径遍历 
 * 棋盘上的 *所有点*
 ----------------------------------------------------------------*/

#include <cstdio>
int n, m;
const int maxn = 10;
int g[maxn][maxn];
bool used[maxn][maxn];
int res;
const int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
void DFS(int x, int y, int cnt) {
    if (cnt == n * m) {
        res ++ ;
        return;
    }
    used[x][y] = true;
    for (int i = 0; i < 8; ++ i) {
        int nx = x + dx[i],
        ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (used[nx][ny]) continue;
        DFS(nx, ny, cnt + 1);
    }
    used[x][y] = false;
}
int main() {
    int t; scanf("%d", &t);
    while (t -- ) {
        int x, y;
        scanf("%d %d %d %d", &n, &m, &x, &y);
        res = 0;
        DFS(x, y, 1);
        printf("%d\n", res);
    }
    return 0;
}
