/*----------------------------------------------------------------
 * 文件名称：红与黑.cpp
 * 创建日期：2021年11月26日 星期五 19时35分22秒 
 * 题 目：AcWing 1113 红与黑 
 * 算 法：深度优先搜索 洪泛法 
 * 描 述：把 @ 所在的 . 的区域大小输出 
 *
 * ....#.
 * .....#
 * ......
 * ......
 * ......
 * ......
 * ......
 * #@...#
 * .#..#.
 *
 ----------------------------------------------------------------*/
#include <cstdio>
const int maxn = 25;
int n, m;
char g[maxn][maxn];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int DFS(int x, int y) {
    int res = 1;
    g[x][y] = '#';
    for (int i = 0; i < 4; ++ i) {
        int nx = x + dx[i],
        ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == '.')
            res += DFS(nx, ny);
    }
    return res;
}
int main() {
    while (scanf("%d %d", &m, &n) && (n || m)) {
        for (int i = 0; i < n; ++ i)
            scanf("%s", g[i]);
        int x, y;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j)
                if (g[i][j] == '@') {
                    x = i, y = j;
                    break;
                }
        printf("%d\n", DFS(x, y));
    }
    return 0;
}
