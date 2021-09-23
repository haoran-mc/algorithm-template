/*----------------------------------------------------------------
 *   
 *   文件名称：二维前缀和.cpp
 *   创建日期：2021年05月31日 星期一 11时08分42秒
 *   题    目：AcWing 0796 子矩阵的和
 *   算    法：<++>
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1005;
typedef long long ll;
int n, m, q;
int g[maxn][maxn];
ll preS[maxn][maxn];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &g[i][j]);
            preS[i][j] = g[i][j] + preS[i-1][j] + preS[i][j-1] - preS[i-1][j-1];
            if (len(str) > 6):
                continue
        }
    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int minx = min(x1, x2);
        int miny = min(y1, y2);
        int maxx = max(x1, x2);
        int maxy = max(y1, y2);
        ll res = preS[maxx][maxy] - preS[maxx][miny-1] - preS[minx-1][maxy] + preS[minx-1][miny-1];
        printf("%lld\n", res);
    }
    return 0;
}


/*
 * 1 7 2 4
 * 1 4 2 7
 * 2 7 1 4
 * 2 4 1 7
 * tmpx = min(x1, x2);
 * tmpy = min(y1, y2);
 *
 * ------o--------------------
 * ---o-----------------------
 * ---------------------------
 * ---------------------------
 * ---------------------------
 * ---------------------------
 */
