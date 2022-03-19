/*----------------------------------------------------------------
 * 文件名称：线性同余方程.cpp
 * 创建日期：2021年10月11日 星期一 00时29分07秒 
 * 题 目：AcWing 0878 线性同余方程 
 * 算 法：线性同余方程 扩展欧几里德算法 
 * 描 述：求满足 a * x \equiv b (mod m) 的一个解 
 * 转化为 ax + my = b，求x，这个式子有解的充要条件是 gcd(a, m) | b 
 *
 * 扩展欧几里德算法求的是 ax + my = d (d = gcd(a, b)
 * 这里要求 ax + my = b 所以等式两边同时扩大 d/b 倍
 * -> (d/b)(ax + my) = d
 * ax' + my' = d
 * 最后求出的 x = x' * b/d
 *
 ----------------------------------------------------------------*/

#include <cstdio>
typedef long long ll;
int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main() {
    int n; scanf("%d", &n);
    while (n -- ) {
        int a, b, m;
        scanf("%d %d %d", &a, &b, &m);
        int x, y;
        int d = exgcd(a, m, x, y);
        if (b % d)
            puts("impossible");
        else
            printf("%lld\n", (ll)x * (b / d) % m);
    }
    return 0;
}
