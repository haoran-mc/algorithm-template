/*----------------------------------------------------------------
 *
 * 文件名称：滑雪.cpp
 * 创建日期：2021年11月01日 星期一 22时21分50秒 
 * 题 目：AcWing 0901 滑雪 
 * 算 法：记忆化搜索 
 * 描 述：给定一个 R 行 C 列的矩阵，表示一个矩形网格滑雪场，
 * 矩阵中第 i 行第 j 列的点表示滑雪场第 i 行第 j 列区域的高度。
 * 一个人从滑雪场中的某个区域出发，每次可以向上下左右任意一个
 * 方向滑动一个单位距离。当然，一个人能够滑动到某相邻区域的前
 * 提是该区域的高度低于自己目前所在区域的高度。
 *
 * 1 2 3 4 5
 * 16 17 18 19 6
 * 15 24 25 20 7
 * 14 23 22 21 8
 * 13 12 11 10 9
 *
 * 在给定矩阵中，一条可行的滑行轨迹为 24 -> 17 -> 2 -> 1，
 * 最长的滑行轨迹为 25 -> 24 -> 23 -> ... -> 3 -> 2 -> 1
 * 沿途共经过 25 个区域。
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 300 + 5;
int n, m;
int h[maxn][maxn];
int dp[maxn][maxn];
int dirx[4] = {-1, 0, 1, 0}, diry[4] = {0, 1, 0, -1};
int work(int x, int y) {
    int &v = dp[x][y];
    if (v != -1)
        return v;
    v = 1;
    for (int i = 0; i < 4; ++ i) {
        int newx = x + dirx[i],
        newy = y + diry[i];
        if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && h[newx][newy] < h[x][y])
            v = max(v, work(newx, newy) + 1);
    }
    return v;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            scanf("%d", &h[i][j]);
    memset(dp, -1, sizeof dp);
    int res = 0;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            res = max(res, work(i, j));
    printf("%d\n", res);
    return 0;
}
