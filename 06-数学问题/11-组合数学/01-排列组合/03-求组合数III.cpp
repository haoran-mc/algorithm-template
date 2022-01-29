/*----------------------------------------------------------------
 * 文件名称：求组合数III.cpp
 * 创建日期：2021年10月13日 星期三 16时52分04秒 
 * 题 目：AcWing 0887 求组合数III
 * 算 法：组合数 
 * 描 述：给定 n 组询问，每组询问给定三个整数 a, b, p 
 * 其中 p 是质数，请你输出 C_a^b % p 的值。
 * 0 <= n <= 21
 * 1 <= b < a <= 1e18
 * 1 <= p <= 1e5
 *
 ----------------------------------------------------------------*/
/**
 * C_a^b % p = C_{a/p}^{b/p} * C_{a%p}^{b%p} % p;
 */
#include <cstdio>
typedef long long ll;
int p;
int MOD;
int binpow(int base, int expo) {
    int res = 1;
    while (expo) {
        if (expo & 1)
            res = (1LL * res * base) % MOD;
        base = (1LL * base * base) % MOD;
        expo >>= 1;
    }
    return res;
}
int inv(int x) {
    return binpow(x, MOD - 2);
}
int C(int a, int b) {
    int res = 1;
    for (int i = 1, j = a; i <= b; ++ i, -- j) {
        res = (ll)res * j % p;
        res = (ll)res * inv(i) % p;
    }
    return res;
}
int lucas(ll a, ll b) {
    if (a < p && b < p)
        return C(a, b);
    else
        return (ll)C(a % p, b % p) * lucas(a / p, b / p) % p;
}
int main() {
    int n; scanf("%d", &n);
    while (n -- ) {
        ll a, b;
        scanf("%lld %lld %d", &a, &b, &p);
        MOD = p;
        printf("%d\n", lucas(a, b));
    }
    return 0;
}
