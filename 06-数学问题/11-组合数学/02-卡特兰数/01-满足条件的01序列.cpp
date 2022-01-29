/*----------------------------------------------------------------
 * 文件名称：满足条件的01序列.cpp
 * 创建日期：2021年10月13日 星期三 22时19分09秒 
 * 题 目：AcWing 0889 满足条件的01序列 
 * 算 法：卡特兰数 
 * 描 述：给定 n 个 0 和 n 个 1，它们将按照某种顺序排成长度为 
 * 2n 的序列，求它们能排列成的所有序列中，
 * 能够满足任意前缀序列中 0 的个数都不少于 1 的个数的序列有多少个。
 *
 ----------------------------------------------------------------*/
#include <cstdio>
const int MOD = 1e9 + 7;
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
int main() {
    int n; scanf("%d", &n);
    int a = 2 * n, b = n;
    int res = 1;
    for (int i = a; i > a - b; -- i)
        res = 1LL * res * i % MOD;
    for (int i = 1; i <= b; ++ i)
        res = 1LL * res * inv(i) % MOD;
    res = 1LL * res * inv(n + 1) % MOD;
    printf("%d\n", res);
    return 0;
}
