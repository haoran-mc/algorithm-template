#include <cstdio>
typedef long long ll;
const int maxn = 1e7;
ll inv[maxn];
ll mod = 999983;

//生成一个表
void Inv() {
    inv[1] = 1;
    for (int i = 2; i < maxn; ++i)
        inv[i] = (mod - mod/i) % mod * inv[mod%i] % mod;
}

//求base的逆元
ll InvKB(ll base) {
    if (base == 1)
        return 1;
    return InvKB(mod%base) * (mod-mod/base) % mod;
}

int main() {
    Inv();
    for (int i = 0; i < 20; ++i)
        printf("%lld ", inv[i]);

    printf("%lld\n", InvKB(9));
    return 0;
}
