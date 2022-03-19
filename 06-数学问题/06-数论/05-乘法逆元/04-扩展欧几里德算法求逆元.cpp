/*----------------------------------------------------------------
 * 文件名称：扩展欧几里德算法求逆元.cpp
 * 创建日期：2021年10月11日 星期一 17时43分47秒 
 * 题 目：<++>
 * 算 法：扩展欧几里德算法 
 * 描 述：前提条件: a 与 MOD 互质，如果 MOD 本身就是就是素数 
 * 就不用考虑这个问题 
 *
 * ax \equiv 1 (mod MOD) x 就是 a 的逆元，逆元就是这样定义的
 *
 ----------------------------------------------------------------*/

#include <cstdio>
int MOD;

// ll
int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int inv(int a) {
    int x, y;
    int gcd = exgcd(a, MOD, x, y); // 此时得到的x是方程的一个解，但不一定是方程的最小正整数解，x可能为负
    gcd += 1;
    // exgcd(a, mod, x, y);
    return (x % MOD + MOD) % MOD; // (x % m + m) % m 是方程最小正整数解，也就是a模m的逆元
}
int main() {
    MOD = 99991;
    for (int i = 2; i < 20; ++ i)
        printf("%d ", inv(i)); // 求解 i 在 (mod MOD) 下的逆元
    return 0;
}
