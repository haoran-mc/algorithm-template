/*----------------------------------------------------------------
 *   
 *   文件名称：02.cpp
 *   创建日期：2021年06月02日 星期三 17时14分12秒
 *   题    目：AcWing 0122 糖果传递
 *   算    法：推公式
 *   描    述：自己推了一遍，这个题目很好的，建议搞懂
 *      a1 --x1-> a2 --x2-> a3 --x3-> a4  ...  an
 *      ^                                      |
 *      |------------------xn-------------------
 *
 *      公式：x1 = x1
 *            x2 = abs(x1 - (avg - a2))
 *            x3 = abs(x1 - (2* avg - (a2 + a3))
 *            x4 = abs(x1 - (3* avg - (a2 + a3 + a4))
 *            x5 = abs(x1 - (4* avg - (a2 + a3 + a4 + a5))
 *            ......
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 5;
typedef long long ll;
int n;
ll I[maxn], x[maxn];

int main() {
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &I[i]);
        sum += I[i];
    }
    int avg = sum / n;
    x[1] = 0;
    for (int i = 2; i <= n; ++i)
        x[i] = x[i-1] + avg - I[i];

    sort(x + 1, x + n + 1);
    ll x1 = x[n / 2];
    ll res = 0;
    for (int i = 1; i <= n; ++i)
        res += abs(x[i] - x1);
    printf("%lld\n", res);
    return 0;
}
