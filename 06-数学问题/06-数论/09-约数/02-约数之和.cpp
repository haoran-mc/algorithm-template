/*----------------------------------------------------------------
 * 文件名称：约数之和.cpp
 * 创建日期：2021年09月29日 星期三 16时24分18秒 
 * 题 目：AcWing 0871 约数之和 
 * 算 法：<++>
 * 描 述：给定 n 个正整数 ai，请你输出这些数的乘积的约数之和 
 * 答案对 109+7 取模。
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int main() {
    int n; scanf("%d", &n);
    unordered_map<int, int> primes;
    while (n --) {
        int a; scanf("%d", &a);
        for (int i = 2; i <= a / i; ++ i) {
            while (a % i == 0) {
                a /= i;
                primes[i] ++ ;
            }
        }
        if (a > 1)
            primes[a] ++ ;
    }
    ll res = 1;
    for (auto prime : primes) {
        int p = prime.first, a = prime.second;
        ll t = 1;
        while (a --)
            t = (t * p + 1) % MOD;
        res = res * t % MOD;
    }
    printf("%lld\n", res);
    return 0;
}
