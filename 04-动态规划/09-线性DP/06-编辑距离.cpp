/*----------------------------------------------------------------
 * 文件名称：编辑距离.cpp
 * 创建日期：2021年10月27日 星期三 21时54分18秒 
 * 题 目：AcWing 0899 编辑距离 
 * 算 法：线性DP
 * 描 述：给定 n 个长度不超过 10 的字符串以及 m 次询问 
 * 每次询问给出一个字符串和一个操作次数上限。
 * 对于每次询问，请你求出给定的 n 个字符串中有多少个字符串可以
 * 在上限操作次数内经过操作变成询问给出的字符串。
 * 每个对字符串进行的单个字符的插入、删除或替换算作一次操作。
 *
 * 0 <= n <= 1000, 0 <= m <= 1000
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10 + 5, maxm = 1e3 + 5;;
int n, m;
int dp[maxn][maxn];
char str[maxm][maxn];
int edit_distance(char a[], char b[]) {
    int len_a = strlen(a + 1),
        len_b = strlen(b + 1);
    for (int i = 0; i <= len_a; ++ i)
        dp[i][0] = i;
    for (int j = 0; j <= len_b; ++ j)
        dp[0][j] = j;
    for (int i = 1; i <= len_a; ++ i)
        for (int j = 1; j <= len_b; ++ j) {
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i] != b[j]));
        }
    return dp[len_a][len_b];
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++ i)
        scanf("%s", str[i] + 1);
    while (m -- ) {
        char s[maxn];
        int limit;
        scanf("%s %d", s + 1, &limit);
        int res = 0;
        for (int i = 0; i < n; ++ i)
            if (edit_distance(str[i], s) <= limit)
                res ++ ;
        printf("%d\n", res);
    }
    return 0;
}
