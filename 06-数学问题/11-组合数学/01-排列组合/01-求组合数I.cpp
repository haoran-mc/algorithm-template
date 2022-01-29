/*----------------------------------------------------------------
 * 文件名称：求组合数I.cpp
 * 创建日期：2021年10月13日 星期三 14时25分48秒 
 * 题 目：AcWing 0885 求组合数I 
 * 算 法：组合数 
 * 描 述：给定 n 组询问，每组询问给定两个整数 a，b， 
 * 请你输出 C_a^b mod (1e9 +7) 的值 
 * 0 < n < 100000
 * 0 < a, b < 2000
 *
 ----------------------------------------------------------------*/
#include <cstdio>
const int maxn = 2000 + 5;
const int MOD = 1e9 + 7;
int c[maxn][maxn];
void init() {
    // 使用递推公式预处理组合数
    for (int a = 0; a < maxn; ++ a)
        for (int b = 0; b <= a; ++ b) {
            if (!b)
                c[a][b] = 1;
            else
                c[a][b] = (c[a - 1][b] + c[a - 1][b - 1]) % MOD;
        }
}
int main() {
    init();
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", c[a][b]);
    }
    return 0;
}
