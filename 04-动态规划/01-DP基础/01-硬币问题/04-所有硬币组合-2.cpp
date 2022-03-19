/*----------------------------------------------------------------
 *
 *   文件名称：最少硬币问题.cpp
 *   创建日期：2021年03月08日 ---- 14时16分
 *   题    目：硬币问题
 *   算    法：动态规划
 *   描    述：有5种硬币，面值分别为1, 5, 10, 25, 50，数量无限，输入非负整数
 *      表示需要付的钱数，要求付钱时选择最少的硬币数
 *      而且打印出硬币组合
 *      硬币数量限制为100
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 251;
const int coin = 101;  //限制最多选择100个硬币
int type[5] = {1, 5, 10, 25, 50};
int dp[maxn][coin];
int ans[maxn];
void solve() {
    dp[0][0] = 1;
    for (int i = 0; i < 5; ++i)
        for (int j = 1; j < coin; ++j)
            for (int k = type[i]; k < maxn; ++k)
                dp[k][j] += dp[k-type[i]][j-1];
}

int main() {
    solve();
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < coin; ++j)
            ans[i] += dp[i][j];
    for (int i = 0; i < maxn; ++i)
        printf("ans[%d] = %d\n", i, ans[i]);
    return 0;
}
