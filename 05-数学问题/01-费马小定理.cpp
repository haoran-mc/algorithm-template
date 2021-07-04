/*----------------------------------------------------------------
 *
 *   文件名称：费马小定理.cpp
 *   创建日期：2021年03月11日 ---- 20时07分
 *   算    法：费马小定理求逆元
 *   描    述：x^(mod-2)就是逆元
 *
 ----------------------------------------------------------------*/

#include<cstdio>
typedef long long  ll;
const int mod = 99991;

/*
 *ll binPow(ll base, ll expo, ll mod) {
 *    if (expo == 0) return 1;
 *
 *    if (expo % 2 == 1)
 *        return base * binPow(base, expo-1, mod) % mod;
 *    else {
 *        ll mul = binPow(base, expo/2, mod) % mod;
 *        return mul % mod * mul % mod;
 *    }
 *}
 */

ll binPow(ll base, ll expo, ll mod) {
    ll res = 1;
    while (expo != 0) {
        if (expo & 1)
            res = (1ll * res * base) % mod;

        base = (1ll * base * base) % mod;
        expo >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return binPow(x, mod-2, mod);
}

int main() {
    for (int i = 0; i < 20; ++i)
        printf("%lld ", inv((ll)i));
    return 0;
}
