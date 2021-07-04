#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
const LL maxn = 100;
const LL MOD = 1e9 + 9;
vector <long long> fact(maxn + 1, 1LL);
vector <long long> inv(maxn + 1, 1LL);
LL Catalan[maxn];

template<typename T>
/*快速冪*/
T binPow(T a, T n) {
    T res = 1;
    while (n) {
        if (n & 1) res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
        n >>= 1;
    }
    return res;
}

/*阶乘*/
void Factorial() {
    for (int i = 1; i <= maxn; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = binPow(fact[i], MOD - 2);
    }
}

/*组合数*/
LL C(int k, int n) {
    if (k > n) return 0;
    int multiply = (1LL * fact[n] * inv[k]) % MOD;
    multiply = (1LL * multiply * inv[n - k]) % MOD;
    return multiply;
}

/*用来求n较小的卡特兰数，相比较不容易溢出*/
void Catalan_Num() {
    Catalan[0] = Catalan[1] = 1;
    for (int i = 2; i <= 35; ++i) {
        for (int j = 0; j < i; ++j)
            Catalan[i] += Catalan[j] * Catalan[i-j-1];
        printf("%d -> %lld\n", i, Catalan[i]);
    }
}

/*用来求n非常大的卡特兰数，需要求模*/
LL Catalan_Num(int n) {
    return C(n, 2*n) / (n+1);
}

int main() {
    Catalan_Num();
    Factorial();
    printf("num = %lld\n", Catalan[10]);
    printf("num = %lld\n", Catalan_Num(10));
    return 0;
}
