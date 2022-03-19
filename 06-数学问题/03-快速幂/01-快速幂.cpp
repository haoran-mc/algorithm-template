/*----------------------------------------------------------------
 * 文件名称：快速幂.cpp
 * 创建日期：2021年10月08日 星期五 22时59分30秒 
 * 题 目：AcWing 0875 快速幂 
 * 算 法：快速幂 
 * 描 述：<++>
 ----------------------------------------------------------------*/

#include <cstdio>
typedef long long ll;
int MOD;
int binpow(int base, int expo) {
    ll res = 1;
    while (expo) {
        if (expo & 1)
            res = (1LL * res * base) % MOD;
        base = (1LL * base * base) % MOD;
        // 也就是base分别是2, 4, 8, 16, ...
        expo >>= 1;
    }
    return res;
}
int main() {
    int n; scanf("%d", &n);
    while (n -- ) {
        int a, b, p;
        scanf("%d %d %d", &a, &b, &p);
        MOD = p;
        printf("%lld\n", binpow(a, b));
    }
    return 0;
}
