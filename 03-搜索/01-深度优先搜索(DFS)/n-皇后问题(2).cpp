/*----------------------------------------------------------------
 *
 *   文件名称：n-皇后问题(2).cpp
 *   创建日期：2021年08月15日 星期日 13时18分42秒
 *   题    目：AcWing 0843 n-皇后问题
 *   算    法：深度优先搜索
 *   描    述：这一种更加的暴力
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 10;
#define NEXTLINE puts("");
int n;
char g[maxn][maxn];
bool row[maxn], col[maxn], dg[2 * maxn], udg[2 * maxn];

void DFS(int x, int y, int s) {
    if (y == n)
        y = 0, x ++ ;
    if (x == n) {
        if (s == n) {
            for (int i = 0; i < n; ++i)
                printf("%s\n", g[i]);
            NEXTLINE;
        }
        return ;
    }
    // 不放皇后
    DFS(x, y + 1, s);

    // 放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[n - x + y]) {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[n - x + y] = true;
        DFS(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[n - x + y] = false;
        g[x][y] = '.';
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            g[i][j] = '.';
    DFS(0, 0, 0);   // 从左上角开始搜，记录当前有多少个皇后
    return 0;
}
