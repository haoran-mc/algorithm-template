/*----------------------------------------------------------------
 * 文件名称：01.cpp
 * 创建日期：2021年09月28日 星期二 21时24分53秒
 * 结束日期：2021年09月28日 星期二 22时37分59秒 
 * 题 目：AcWing 0970 约数个数 
 * 算 法：<++>
 * 描 述：给定 n 个正整数 ai，请你输出这些数的乘积的约数个数 
 * 答案对 1e9 + 7 取模
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
    for (auto prime : primes)
        res = res * (prime.second + 1) % MOD;
    printf("%lld\n", res);
    return 0;
}
