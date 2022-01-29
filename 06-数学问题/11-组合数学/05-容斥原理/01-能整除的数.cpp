/*----------------------------------------------------------------
 * 文件名称：能被整除的数.cpp
 * 创建日期：2021年10月14日 星期四 17时55分02秒 
 * 题 目：AcWing 0890 能被整除的数 
 * 算 法：容斥原理 
 * 描 述：给定一个整数 n 和 m 个不同的质数 p1, p2, ..., pm
 * 求[1, n]中能被 p1, p2, ..., pm 中至少一个数整除的整数有多少个 
 * 1 <= m <= 16
 * 1 <= n, pi <= 1e9
 *
 ----------------------------------------------------------------*/
#include <cstdio>
const int maxn = 20;
int p[maxn];
typedef long long ll;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++ i)
        scanf("%d", &p[i]);
    int res = 0;
    // inclusion-exclusion principle
    // 使用二进制的方式枚举每种选法
    for (int i = 1; i < 1 << m; ++ i) {
        // t: 所有质数的乘积
        // cnt: 这个二进制数中位为1的个数
        int t = 1, cnt = 0;
        for (int j = 0; j < m; ++ j)
            if (i >> j & 1) {
                cnt ++ ;
                if ((ll)t * p[j] > n) {
                    t = -1;
                    break;
                }
                t *= p[j];
            }
        if (t != -1) {
            if (cnt % 2)
                res += n / t;
            else
                res -= n / t;
        }
    }
    printf("%d\n", res);
    return 0;
}
