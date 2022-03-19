/*----------------------------------------------------------------
 *
 *   文件名称：01-hdu1257.cpp
 *   创建日期：2021年03月09日 ---- 15时56分
 *   题    目：最少拦截系统
 *   算    法：最长递增子序列
 *   描    述：输入导弹总个数以及导弹依次飞来的高度
 *
----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 10005;
int n;
int high[maxn];
int LIS() {
    int res = 1;
    int dp[maxn];
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int maxHigh = 0;
        for (int j = 1; j < i; ++j) {
            if (dp[j] > maxHigh && high[j] < high[i])
                maxHigh = dp[j];
            dp[i] = maxHigh + 1;
            if (dp[i] > res)
                res = dp[i];
        }
    }
    return res;
}

int main() {
    while (scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &high[i]);
        printf("%d\n", LIS());
    }
    return 0;
}
