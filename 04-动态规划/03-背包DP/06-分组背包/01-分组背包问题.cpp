/*----------------------------------------------------------------
 * 文件名称：分组背包问题.cpp
 * 创建日期：2021年10月21日 星期四 19时58分08秒 
 * 题 目：AcWing 0009 分组背包问题 
 * 算 法：动态规划 分组背包 
 * 描 述：有 N 组物品和一个容量是 V 的背包。
 * 每组物品有若干个，同一组内的物品最多只能选一个。
 * 每件物品的体积是 vij，价值是 wij，其中 i 是组号，j 是组内编号。
 * 求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100 + 5;
int n, m;
int dp[maxn];
int v[maxn], w[maxn];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++ i) { // 物品组数
        // 输入
        int s; scanf("%d", &s);
        for (int j = 0; j < s; ++ j) // 这组物品信息，体积、价值
            scanf("%d %d", &v[j], &w[j]);
        /* 动态规划
         * 其实和 01背包 差不多不是吗
         * for (int i = 0; i < n; ++ i)
         * for (int j = m; j >= v[i]; -- j)
         * dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
         *
         * 分组背包只不过是把一个背包换成一组，多个 for(k) 就行
         **/
        for (int j = m; j >= 0; -- j) // 体积
            for (int k = 0; k < s; ++ k) // 遍历每个物品
                if (j >= v[k])
                    dp[j] = max(dp[j], dp[j - v[k]] + w[k]);
    }
    printf("%d\n", dp[m]);
    return 0;
}
