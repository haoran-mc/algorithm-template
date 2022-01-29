/*----------------------------------------------------------------
 * 文件名称：最短Hamiton路径.cpp
 * 创建日期：2021年11月01日 星期一 20时06分05秒 
 * 题 目：AcWing 0091 最短Hamiton路径 
 * 算 法：状压DP
 * 描 述：给定一张 n 个点的带权无向图，点从 0 ~ n−1 标号，
 * 求起点 0 到终点 n−1 的最短 Hamilton 路径。
 * Hamilton 路径的定义是从 0 到 n−1 不重不漏地经过每个点恰好一次。
 *
 * 题目输入：一个数n，然后是 n * n 个整数，第 i 行第 j 列的整数表示
 * 点 i 到 j 的距离
 *
 * 1 <= n <= 20
 * 0 <= dist[i, j] <= 1e7
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 20 + 5, maxm = 1 << 20;
int dist[maxn][maxn];
int n;
int dp[maxm][maxn];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
            scanf("%d", &dist[i][j]);
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    for (int i = 0; i < 1 << n; ++ i) // 遍历当前状态
        for (int j = 0; j < n; ++ j) // 最后一个点是 j
            if (i >> j & 1) // 显然需要满足当前状态有 j 这个点
                for (int k = 0; k < n; ++ k) // 当前状态由当前状态去除最后一个点 j 且最后一个点是 k 的路径转移过 来
                    if (i - (1 << j) >> k & 1) // 显然需要满足这个状态有 k 这个点
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + dist[k][j]);
    printf("%d\n", dp[(1 << n) - 1][n - 1]);
    return 0;
}
