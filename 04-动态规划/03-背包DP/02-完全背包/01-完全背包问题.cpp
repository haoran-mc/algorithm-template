/*----------------------------------------------------------------
 * 文件名称：01.cpp
 * 创建日期：2021年03月30日 ---- 15时30分 
 * 创建日期：2021年10月18日 星期一 11时47分41秒 
 * 题 目：AcWing 0003 完全背包问题 
 * 算 法：动态规划 
 * 描 述：与01背包问题代码相差无几 
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 5;
int n, m;
int dp[maxn][maxn];
int v[maxn], w[maxn];
// dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i]);
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++ i)
        scanf("%d %d", &v[i], &w[i]);
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i])
                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
        }
    printf("%d\n", dp[n][m]);
    return 0;
}
