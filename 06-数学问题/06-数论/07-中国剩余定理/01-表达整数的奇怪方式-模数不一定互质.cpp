/*----------------------------------------------------------------
 * 文件名称：01.cpp
 * 创建日期：2021年10月11日 星期一 21时08分01秒 
 * 题 目：AcWing 0204 表达整数的奇怪方式 
 * 算 法：中国剩余定理 
 * 描 述：下面是推导过程 
 * 看推导过程 
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 25 + 5;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
// Chinese Remainder Theorem
// k: 方程个数，n: 除数数组，a: 余数数组
ll CRT(int k, ll n[], ll a[]) {
    bool has_result = true;
    ll n1 = n[0], a1 = a[0];
    for (int i = 1; i < k; ++ i) {
        int n2 = n[i], a2 = a[i];
        ll k1, k2; // k1', k2'
        ll gcd = exgcd(n1, n2, k1, k2);
        if ((a2 - a1) % gcd)
            return -1;
        k1 = k1 * (a2 - a1) / gcd;
        // 此句不需要，因为只要知道 k1 就知道 x 了
        // k2 = k2 * (a2 - a1) / gcd;
        ll t = n2 / gcd;
        k1 = (k1 % t + t) % t;
        a1 = n1 * k1 + a1;
        n1 = abs(n1 / gcd * n2); // lcm
    }
    return (a1 % n1 + n1) % n1;
}
int main() {
    int n; scanf("%d", &n);
    ll a[maxn], m[maxn]; // 除数数组a[]，余数数组m[]
    for (int i = 0; i < n; ++ i)
        scanf("%lld %lld", &a[i], &m[i]);
    ll res = CRT(n, a, m);
    printf("%lld\n", res);
    return 0;
}
