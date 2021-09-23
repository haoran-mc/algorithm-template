/*----------------------------------------------------------------
 *
 *   文件名称：02-扩展欧几里德.cpp
 *   创建日期：2021年03月10日 ---- 22时25分
 *   算    法：扩展欧几里德
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;

/*ax + by = gcd(a, b)*/
/*有解的充分必要条件是gcd(a, b)可以整除n*/
void exgcd(int a, int b, int &x, int &y) {
    if (b ==0) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a%b, x, y);
    int tmp = x;
    x = y;
    y = tmp - (a/b) * y;
}

/**
 * cx + dy = 1
 * 其中c = a / gcd(a, b), d = b / gcd(a, b)
 * 通解：x = x0 + dt
 *       y = y0 - ct;
 * x0, y0是上面的x, y，t是任意整数
 **/
void simplyExgcd(int c, int d, int &x, int &y) {
    int tmpc = c;
    int tmpd = d;
    exgcd(c, d, x, y);
    int t = 1; //t可以是任何数
    x = x + tmpd * t;
    y = y - tmpc * t;
}

/**
 * ax + by = n
 * 有整数解的条件是gcd(a, b)可以整除n
 * 一个解：x0' = x0 * n / gcd(a, b)
 *         y0' = y0 * n / gcd(a, b)
 **/
void anyExgcd(int a, int b, int n, int &x, int &y) {
    exgcd(a, b, x, y);
    x = x * n / __gcd(a, b);
    y = y * n / __gcd(a, b);
}
