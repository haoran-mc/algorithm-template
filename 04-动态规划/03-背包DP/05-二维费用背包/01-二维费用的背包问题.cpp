/*----------------------------------------------------------------
 *
 *   文件名称：01-二维费用的背包问题.cpp
 *   创建日期：2021年04月28日 ---- 10时37分
 *   题    目：AcWing 0008 二维费用问题
 *   算    法：二维费用背包
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#define _max(a, b) (a > b ? a : b)
#define _min(a, b) (a < b ? a : b)
const int maxn = 1e3 + 5;
int N, V, M;//物品数量，背包体积，背包最大承重
int vo[maxn], we[maxn], va[maxn]; //第i件物品体积、重量和价值
int dp[maxn][maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    scanf("%d %d %d", &N, &V, &M);
    for (int i = 1; i <= N; ++i)
        scanf("%d %d %d", &vo[i], &we[i], &va[i]);
    for (int i = 1; i <= N; ++i)
        for (int j = V; j >= vo[i]; --j)
            for (int k = M; k >= we[i]; --k)
                dp[j][k] = _max(dp[j][k], dp[j-vo[i]][k-we[i]] + va[i]);//动态转移方程，01 背包的思路
    printf("%d\n", dp[V][M]);
    return 0;
}
