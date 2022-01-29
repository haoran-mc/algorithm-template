/*----------------------------------------------------------------
 * 文件名称：多重背包问题I-朴素.cpp
 * 创建日期：2021年04月10日 ---- 10时39分 
 * 创建日期：2021年10月18日 星期一 18时35分36秒 
 * 题 目：AcWing 0004 多重背包 
 * 算 法：多重背包 
 * 描 述：每种物品选ai次转化为有ai个物品选1次，即01背包 
 *
 * 0 < n, m < 100
 * 0 < v, w, s < 100
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 105;
int n, m;
int dp[maxn];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        int v, w, s;
        scanf("%d %d %d", &v, &w, &s);
        for (int j = m; j >= v; -- j)
            for (int k = 1; k <= s && k * v <= j; ++ k)
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
    }
    printf("%d\n", dp[m]);
    return 0;
}
