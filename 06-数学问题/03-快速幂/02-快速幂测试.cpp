/*----------------------------------------------------------------
 *
 *   文件名称：快速幂.cpp
 *   创建日期：2021年03月10日 ---- 21时43分
 *   算    法：快速幂
 *   描    述：使用了模板template
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int mod = 99991;

// 计算 a^b % m
// 1.17秒
long long binaryPow(long long a, long long b, long long m) {
    if (b == 0) return 1;

    if (b % 2 == 1)
        return a * binaryPow(a, b - 1, m) % m;
    else {
        long long mul = binaryPow(a, b / 2, m);
        return mul * mul % m;
    }
}

//0.45秒
long long binPow(long long base, long long expo) {
    long long res = 1;
    while (expo != 0) {
        if (expo & 1)
            res = (1LL * res * base) % mod;
        base = (1LL * base * base) % mod;
        expo >>= 1;
    }
    return res;
}

/*
 *template<typename T>
 *T binPow(T base, T expo) {
 *    if (!expo) return 1;
 *    if (expo % 2)
 *        return base * binPow(base, expo - 1) % mod;
 *    else
 *        return binPow(base, expo / 2) % mod * binPow(base, expo / 2) % mod;
 *}
 */

template<typename T>
T binPow(T base, T expo) {
    T res = 1;
    while (expo != 0) {
        if (expo & 1)
            res = (1LL * res * base) % mod;
        base = (1LL * base * base) % mod;
        expo >>= 1;
    }
    return res;
}

int main() {
    long long base = 23, expo = 19898283988388888;
    long long res;
    for (int i = 0; i < 1000000; ++i)
        //res = binaryPow(base, expo, mod);
        res = binPow(base, expo);
    printf("%lld\n", res);
    return 0;
}
