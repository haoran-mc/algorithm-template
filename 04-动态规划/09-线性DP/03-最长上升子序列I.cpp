/*----------------------------------------------------------------
 * 文件名称：最长上升子序列.cpp
 * 创建日期：2021年10月25日 星期一 19时57分02秒 
 * 题 目：AcWing 0895 最长上升子序列 
 * 算 法：线性DP
 * 描 述：
 * 给一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少 
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
int sequ[maxn];
int dp[maxn];
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++ i)
        scanf("%d", &sequ[i]);
    for (int i = 1; i <= n; ++ i) {
        dp[i] = 1;
        for (int j = 1; j < i; ++ j)
            if (sequ[j] < sequ[i])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    int res = 0;
    for (int i = 1; i <= n; ++ i)
        res = max(res, dp[i]);
    printf("%d\n", res);
    return 0;
}
