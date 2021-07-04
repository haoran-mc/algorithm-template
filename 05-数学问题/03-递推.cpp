#include<cstdio>
int inv[100001];
int mod = 99991;

//在(mod 99991)的意义下，2 - 10000分别对应的逆元
void Inv() {
    inv[1] = 1;
    for (int i = 2; i < 10000; ++i) {
        inv[i] = - mod/i * inv[mod%i] % mod;
        inv[i] = (mod + inv[i]) % mod;
        /*inv[i] = (mod - mod/i) * inv[mod%i] % mod;*/ /*会溢出*/
    }
}

int main() {
    Inv();
    for (int i = 0; i < 20; ++i)
        printf("%d ", inv[i]);
    return 0;
}
