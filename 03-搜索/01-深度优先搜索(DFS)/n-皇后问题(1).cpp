/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年08月15日 星期日 12时03分56秒
 *   题    目：AcWing 0843 n-皇后问题
 *   算    法：深度优先搜索
 *   描    述：使用排列组合的方法解决
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 10;
#define NEXTLINE puts("");
int n, path[maxn];
char g[maxn][maxn];
bool col[maxn], dg[2 * maxn], udg[2 * maxn];

void DFS(int u) {
    if (u == n) {
        for (int i = 0; i < n; ++i)
            printf("%s\n", g[i]);
        NEXTLINE;
        return ;
    }
    // 第u行第i列
    for (int i = 0; i < n; ++i)
        /**
         * 可以看成一个坐标轴 y = u + i, y = n - u + i;
         * ------------------>
         * |
         * |
         * |
         * |
         * |
         * |
         * |
         * V
         *
         */
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;  // 列，正对角线，反对角线标记
            DFS(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            g[i][j] = '.';
    DFS(0);
    return 0;
}
