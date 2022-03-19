/*----------------------------------------------------------------
 * 文件名称：最短编辑距离.cpp
 * 创建日期：2021年10月27日 星期三 21时07分54秒 
 * 题 目：AcWing 0902 最短编辑距离 
 * 算 法：线性DP
 * 描 述：给定两个字符串 A 和 B 8 * 现在要将 A 经过若干操作变为 B，可进行的操作有：
 * 删除 – 将字符串 A 中的某个字符删除。
 * 插入 – 在字符串 A 的某个位置插入某个字符。
 * 替换 – 将字符串 A 中的某个字符替换为另一个字符。
 * 现在请你求出，将 A 变为 B 至少需要进行多少次操作。
 *
 * 0 <= n <= 1000, 0 <= m <= 1000
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
    scanf("%d %s", &n, a + 1);
    scanf("%d %s", &m, b + 1);
    // 初始化
    for (int i = 1; i <= n; ++ i)
        dp[i][0] = i; // 将a的前i个字符与b的前0个字符匹配，删i次
    for (int j = 1; j <= m; ++ j)
        dp[0][j] = j; // 将a的前0个字符与b的前j个字符匹配，增j次
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) {
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            if (a[i] == b[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    printf("%d\n", dp[n][m]);
    return 0;
}
