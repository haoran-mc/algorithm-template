/*----------------------------------------------------------------
 *
 *   文件名称：02-DP求整数划分.cpp
 *   创建日期：2021年03月12日 ---- 11时16分
 *   题    目：hud1028
 *   算    法：动态规划
 *   描    述：与递归的代码类似
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 200;
int dp[maxn][maxn];
void part() {
    for (int n = 1; n <= maxn; ++n)
        for (int m = 1; m <= maxn; ++m) {
            if (n == 1 || m == 1)
                dp[n][m] = 1;
            else if (n < m)
                dp[n][m] = dp[n][n];
            else if (n == m)
                dp[n][m] = dp[n][m-1] + 1;
            else
                dp[n][m] = dp[n][m-1] + dp[n-m][m];
        }
}

int main() {
    int n;
    part();
    while (scanf("%d", &n))
        printf("%d\n", dp[n][n]);
    return 0;
}
