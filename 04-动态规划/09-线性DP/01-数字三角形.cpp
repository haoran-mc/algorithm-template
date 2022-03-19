/*----------------------------------------------------------------
 * 文件名称：数字三角形.cpp
 * 创建日期：2021年10月25日 星期一 19时36分09秒 
 * 题 目：AcWing 0898 数字三角形 
 * 算 法：线性DP
 * 描 述：
 * 给定一个如下图所示的数字三角形，从顶部出发 9 * 在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点
 * 一直走到底层，要求找出一条路径，使路径上的数字的和最大。
 *
 * 7
 * 3 8
 * 8 1 0
 * 2 7 4 4
 * 4 5 2 6 5
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 500 + 5;
int a[maxn][maxn], dp[maxn][maxn];
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= i; ++ j)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; ++ i)
        dp[n][i] = a[n][i];
    for (int i = n - 1; i; -- i)
        for (int j = 1; j <= i; ++ j)
            dp[i][j] = max(dp[i + 1][j] + a[i][j], dp[i + 1][j + 1] + a[i][j]);
    printf("%d\n", dp[1][1]);
    return 0;
}
