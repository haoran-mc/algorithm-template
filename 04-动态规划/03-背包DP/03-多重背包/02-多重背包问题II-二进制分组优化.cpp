/*----------------------------------------------------------------
 * 文件名称：多重背包问题II-二进制分组优化.cpp
 * 创建日期：2021年10月18日 星期一 18时46分46秒 
 * 题 目：AcWing 0005 多重背包问题II
 * 算 法：多重背包二进制优化 
 * 描 述：有n个物品，一个容量是m的背包 
 * 第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。 
 * 求解将哪些物品装入背包，可使物品体积总和不超过背包容量
 * 且价值总和最大。
 *
 * 0 < n < 1000
 * 0 < m < 2000
 * 0 < v, w, s < 2000
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1005;
int n, m;
int dp[10 * maxn];
struct Bone {
    int v, w; // 体积，价值
} bone[10 * maxn];
int main() {
    scanf("%d %d", &n, &m);
    int idx = 1;
    for (int i = 1; i <= n; ++ i) {
        int v, w, s;
        scanf("%d %d %d", &v, &w, &s);
        int b = 1; // 二进制分组优化, 1, 2, 4, 8, 16, ...
        while (s - b > 0) {
            s -= b;
            bone[idx].v = b * v;
            bone[idx].w = b * w;
            idx ++;
            b *= 2;
        }
        if (s) {
            bone[idx].v = s * v;
            bone[idx].w = s * w;
            idx ++;
        }
    }
    for (int i = 1; i < idx; ++ i)
        for (int j = m; j >= bone[i].v; -- j)
            dp[j] = max(dp[j], dp[j - bone[i].v] + bone[i].w);
    printf("%d\n", dp[m]);
    return 0;
}
