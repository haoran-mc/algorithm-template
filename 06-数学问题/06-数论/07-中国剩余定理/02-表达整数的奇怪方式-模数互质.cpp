/*----------------------------------------------------------------
 * 文件名称：表达整数的奇怪方式.cpp
 * 创建日期：2021年10月11日 星期一 17时08分43秒 
 * 题 目：AcWing 0204 表达整数的奇怪方式 
 * 算 法：中国剩余定理 
 * 算法描述：
 * x \equiv a1 (mod n1) 9 * x \equiv a2 (mod n2)
 * x \equiv a3 (mod n3)
 * ...
 * x \equiv ak (mod nk)
 *
 * 中国剩余定理：给出上面的 a1~ak，n1~nk，求出 x
 *
 * 由于 ni 不一定是素数，所以需要使用扩展欧几里德算法求逆元
 *
 * 算法流程：1. 计算所有模数的积 n = n1 * n2 * n3 * ... * nk
 * 2. 对于第 i 个方程：
 * 1. 计算 mi = n / ni
 * 2. 计算 mi 在模 ni 意义下的逆元 mi^-1
 * 3. 计算 ci = mi * mi^-1 (不要对 ni 取模)
 * 3. 方程组的唯一解为 x = a1*c1%n + a2*c2%n + ... + ak*ck%n;
 *
 * 题目描述：
 * 给定 2n 个整数，a1, a2, ... an 和 m1, m2, ... mn，求最小的
 * 非负整数 x 满足
 * x \equiv mi (mod ai)
 *
 * 输入样例：
 * 2
 * 8 7
 * 11 9
 *
 * x mod 8 = 7
 * x mod 11 = 9
 * -> x = 31
 *
 ----------------------------------------------------------------*/

#include <cstdio>
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
// k: k 方程个数
// n[]: n 数组(除数)
// a[]: a 数组(余数)
ll CRT(int k, ll n[], ll a[]) {
    ll prod_n = 1, res = 0;
    for (int i = 0; i < k; ++ i)
        prod_n *= n[i];
    for (int i = 0; i < k; ++ i) {
        ll mi = prod_n / n[i];
        // 计算 mi 在模 ni 意义下的逆元 inv_mi
        ll inv_mi, y;
        exgcd(mi, n[i], inv_mi, y);
        ll ci = mi * inv_mi;
        res = (res + a[i] * ci % prod_n) % prod_n;
    }
    return (res % prod_n + prod_n) % prod_n;
}
int main() {
    int n; scanf("%d", &n);
    ll a[maxn], m[maxn];
    for (int i = 0; i < n; ++ i)
        scanf("%lld %lld", &a[i], &m[i]);
    ll res = CRT(n, a, m);
    printf("%lld\n", res);
    return 0;
}
