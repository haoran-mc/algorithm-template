/*----------------------------------------------------------------
 * 文件名称：01-混合背包.cpp
 * 创建日期：2021年04月07日 ---- 17时56分 
 * 创建日期：2021年10月25日 星期一 08时30分20秒 
 * 题 目：AcWing 0007 混合背包问题 
 * 算 法：混合背包
 * 描 述：转化为多重背包二进制优化 
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
int dp[10 * maxn];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        int v, w, s; // 体积，价值，数量
        scanf("%d %d %d", &v, &w, &s);
        if (s == 0) { // 完全背包
            for (int j = v; j <= m; ++ j)
                dp[j] = max(dp[j], dp[j - v] + w);
        }
        else { // 多重背包或01背包
            if (s == -1) // 01背包是特殊的多重背包
                s = 1;
            int b = 1;
            while (s - b > 0) {
                for (int j = m; j >= b * v; -- j)
                    dp[j] = max(dp[j], dp[j - b * v] + b * w);
                s -= b;
                b *= 2;
            }
            if (s) {
                for (int j = m; j >= s * v; -- j)
                    dp[j] = max(dp[j], dp[j - s * v] + s * w);
            }
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}
