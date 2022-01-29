/*----------------------------------------------------------------
 * 文件名称：最长公共子序列.cpp
 * 创建日期：2021年10月26日 星期二 21时28分44秒 
 * 题 目：AcWing 0897 最长公共子序列 
 * 算 法：线性DP
 * 描 述：给定两个长度分别为 N 和 M 的字符串 A 和 B 
 * 求既是 A 的子序列又是 B 的子序列的字符串长度最长是多少。
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 5;
int n, m;
char a[maxn], b[maxn];
int dp[maxn][maxn];
int main() {
    scanf("%d %d", &n, &m);
    scanf("%s %s", a + 1, b + 1);
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    printf("%d\n", dp[n][m]);
    return 0;
}
