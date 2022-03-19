/*----------------------------------------------------------------
 * 文件名称：石子合并.cpp
 * 创建日期：2021年03月09日 ---- 17时08分 
 * 创建日期：2021年10月28日 星期四 16时13分02秒 
 * 题 目：AcWing 0282 石子合并 
 * 算 法：区间DP
 * 描 述：设有 N 堆石子排成一排，其编号为 1, 2, 3, ..., N 
 * 每堆石子有一定的质量，可以用一个整数来描述，现在要将这 N
 * 堆石子合并成为一堆。每次只能合并相邻的两堆，合并的代价为
 * 这两堆石子的质量之和，合并后与这两堆石子相邻的石子将和新堆相邻，
 * 合并时由于选择的顺序不同，合并的总代价也不相同。
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 300 + 5;
int preS[maxn], dp[maxn][maxn];
const int INF = 0x3f3f3f3f;
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d", &preS[i]);
        preS[i] += preS[i - 1];
    }
    for (int len = 2; len <= n; ++ len)
        for (int i = 1; i + len - 1 <= n; ++ i) {
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = i; k < j; ++ k)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + preS[j] - preS[i - 1]);
        }
    printf("%d\n", dp[1][n]);
    return 0;
}
