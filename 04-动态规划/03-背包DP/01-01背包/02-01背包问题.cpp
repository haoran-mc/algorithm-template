/*----------------------------------------------------------------
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 * 文件名称：0042-01背包问题.cpp
 * 创建日期：2021年03月29日 ---- 22时18分 
 * 创建日期：2021年10月15日 星期五 23时16分05秒 
 * 题 目：AcWing 0002 01 背包问题 
 * 算 法：动态规划 01背包
 * 描 述：有N件物品，背包容积是V，第i件物品的体积是vi，价值wi
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 5;
int N; // N件物品
int V; // 背包容量
int dp[maxn][maxn];
int v[maxn], w[maxn];
int main() {
    scanf("%d %d", &N, &V);
    for (int i = 1; i <= N; ++ i)
        scanf("%d %d", &v[i], &w[i]);
    for (int i = 1; i <= N; ++ i)
        for (int j = 0; j <= V; ++ j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    printf("%d\n", dp[N][V]);
    return 0;
}
