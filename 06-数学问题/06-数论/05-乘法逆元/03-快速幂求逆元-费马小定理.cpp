/*----------------------------------------------------------------
 * 文件名称：快速幂求逆元.cpp
 * 创建日期：2021年10月09日 星期六 17时54分32秒 
 * 题 目：AcWing 0876 快速幂求逆元 
 * 算 法：费马小定理，快速幂 
 * 描 述：不与 MOD 互质的数没有在 (mod MOD) 下的逆元 
 * 所以快速幂要求 MOD 一定是一个素数，而扩展欧几里德算法只要求 
 * gcd(a, MOD) = 1，两数互质，MOD 不一定是素数
 *
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
// 返回0表示无解
int inv(int x) {
    return binpow(x, MOD - 2);
}
int main() {
    int n; scanf("%d", &n);
    while (n -- ) {
        int a, p; // 求a在(mod p)下的逆元
        scanf("%d %d", &a, &p);
        MOD = p;
        int inverse = inv(a);
        // p = 2 情况特殊
        if (a % p) printf("%d\n", inverse);
        else puts("impossible");
    }
    return 0;
}
