/*----------------------------------------------------------------
 * 文件名称：02-一维.cpp
 * 创建日期：2021年03月30日 ---- 16时20分 
 * 创建日期：2021年10月18日 星期一 11时53分17秒
 * 题 目：AcWing 0003 完全背包 
 * 算 法：动态规划 
 * 描 述：与01背包问题代码相差无几 
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 5;
int n, m;
int dp[maxn];
int v[maxn], w[maxn];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++ i)
        scanf("%d %d", &v[i], &w[i]);
    for (int i = 1; i <= n; ++ i)
        for (int j = v[i]; j <= m; ++ j)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    printf("%d\n", dp[m]);
    return 0;
}
