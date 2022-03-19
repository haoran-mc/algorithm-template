#include <cstdio>
typedef long long ll;
ll mod;

ll binTimes(ll l1, ll l2) {
    ll res = 0;
    while (l2) {
        if (l2 & 1)
            res = (res + l1) % mod;
        l1 = (l1 * 2) % mod;
        l2 >>= 1;
    }
    return res;
}

int main() {
    ll a, b;
    scanf("%lld %lld %lld", &a, &b, &mod);
    ll res = binTimes(a, b);
    printf("%lld\n", res);
    return 0;
}
