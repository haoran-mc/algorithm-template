/*----------------------------------------------------------------
 * 文件名称：求组合数II.cpp
 * 创建日期：2021年10月13日 星期三 16时35分18秒 
 * 题 目：AcWing 0886 求组合数II
 * 算 法：组合数 
 * 描 述：给定 n 组询问，每组询问给定两个整数 a，b， 
 * 请你输出 C_a^b mod (1e9 +7) 的值 
 * 0 < n < 10000
 * 0 < a, b < 1e5
 *
 ----------------------------------------------------------------*/
// 同样是预处理，这次处理的是阶乘
// C_a^b = a! / ((a - b)! * b!)
#include <cstdio>
typedef long long ll;
typedef long long LL;
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 5;
int fact[maxn], inv_fact[maxn];
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
void init() {
    fact[0] = 1, inv_fact[0] = 1;
    for (int i = 1; i < maxn; ++ i) {
        fact[i] = (LL)fact[i - 1] * i % MOD;
        inv_fact[i] = (LL)inv_fact[i - 1] * inv(i) % MOD;
    }
}
int main() {
    init();
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", (LL)fact[a] * inv_fact[a - b] % MOD * inv_fact[b] % MOD);
    }
    return 0;
}
