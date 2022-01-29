/*----------------------------------------------------------------
 * 文件名称：扩展欧几里德算法.cpp
 * 创建日期：2021年10月09日 星期六 19时18分35秒 
 * 题 目：AcWing 0877 扩展欧几里德算法 
 * 算 法：扩展欧几里德算法 
 * 描 述：求 ax + by = gcd(a, b) 任意一个解
 * ----------------------------------------------------------------*/

#include <cstdio>
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
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
        int a, b, x, y;
        scanf("%d %d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }
    return 0;
}
