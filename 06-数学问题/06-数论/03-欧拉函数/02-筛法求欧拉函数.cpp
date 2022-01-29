/*----------------------------------------------------------------
 * 文件名称：筛法求欧拉函数.cpp
 * 创建日期：2021年09月29日 星期三 17时58分25秒 
 * 题 目：AcWing 0874 筛法求欧拉函数 
 * 算 法：<++>
 * 描 述：给定一个正整数 n，求 1 ~ n 中每个数的欧拉函数之和 
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e6 + 5;
typedef long long ll;
int primes[maxn], cnt;
int phi[maxn];
bool sifter[maxn];
ll get_eulers(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; ++ i) {
        if (sifter[i] == false) {
            primes[cnt ++ ] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; ++ j) {
            sifter[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                /**
                 * i * primes[j] 比 i 多一个质因子 primes[j]
                 * 所以根据欧拉公式，N 变化了，且需要多乘一个 (1 - 1/primes[j])
                 * 但是，又因为 i % primes[j] == 0，所以，第一句是错的，看似多乘了
                 * 一个质因子，实际上，i 本身就有这个 primes[j] 的质因子
                 * 因为 N 由 i 变成 i * primes[j]
                 * 根据欧拉公式，phi[i * primes[j]] = primes[j] * phi[i];
                 */
                phi[i * primes[j]] = primes[j] * phi[i];
                break;
            }
            else {
                // 否则就多乘一个 1 - 1 / primes[j] 嘛
                // phi[i * primes[j]] = primes[j] * phi[i] / primes[j] * (primes[j] - 1);
                phi[i * primes[j]] = phi[i] * (primes[j] - 1);
            }
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; ++ i)
        res += phi[i];
    return res;
}
int main() {
    int n; scanf("%d", &n);
    printf("%lld\n", get_eulers(n));
    return 0;
}
