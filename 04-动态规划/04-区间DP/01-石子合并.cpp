/*----------------------------------------------------------------
 *
 *   文件名称：01-石子合并.cpp
 *   创建日期：2021年03月09日 ---- 17时08分
 *   题    目：石子合并
 *   算    法：区间DP
 *   描    述：每次只能合并相邻的两堆石子，合并的花费为这两堆石子的总数
 *      每组数据第一行是n个整数，接下来有n堆石子
 *      状态转移方程：dp[i][j] = min(dp[i][k] + dp[k+1][j]) + sum[i][j-i+1];
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 255;
const int inf  = 0x3f3f3f3f;
int n;
int sum[maxn]; //前i堆的和

int minval() {
    int dp[maxn][maxn]; //从第i堆石子到第j堆石子的最小花费
    for (int i = 1; i <= n; ++i)
        dp[i][i] = 0;
    for (int len = 1; len <= n; ++len) //len是i与j之间的距离，也就是说区间DP是从小区间到大区间DP
        for (int i = 1; i <= n-len; ++i) { //从第i堆开始
            int j = i + len;               //从第j堆结束
            dp[i][j] = inf;
            for (int k = i; k < j; ++k)    //i与j之间用k进行分割
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + (sum[j]-sum[i-1]));
        }
    return dp[1][n];
}

int main() {
    while (scanf("%d", &n)) {
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            sum[i] = sum[i-1] + x;
        }
        printf("%d\n", minval());
    }
    return 0;
}
