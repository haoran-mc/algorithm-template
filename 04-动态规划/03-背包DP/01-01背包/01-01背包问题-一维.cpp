/*----------------------------------------------------------------
 * 文件名称：0043-01背包问题-一维.cpp
 * 创建日期：2021年10月15日 星期五 23时35分00秒
 * 题 目：AcWing 0002 01背包问题 
 * 算 法：动态规划 
 * 描 述：有N件物品，背包容积是V，第i件物品的体积是vi，价值wi
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 5;
int N, V;
int v[maxn], w[maxn];
int dp[maxn];
int main() {
    scanf("%d %d", &N, &V);
    for (int i = 1; i <= N; ++ i)
        scanf("%d %d", &v[i], &w[i]);
    for (int i = 1; i <= N; ++ i)
        for (int j = V; j >= v[i]; -- j)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    printf("%d\n", dp[V]);
    return 0;
}
