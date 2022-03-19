/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年07月31日 星期六 13时54分56秒
 *   题    目：luogu SP1805 HISTOGRA - LARGEST Rectangle in a Histogram
 *   算    法：单调栈
 *   描    述：Luogu题解
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;
const int maxn = 1e5 + 5;
int n, tt;
ll res;
// 直方体中矩形的高度，直方体中矩形的宽度
int a[maxn], width[maxn];
int stk[maxn];

int main() {
    while(scanf("%d", &n) && n) {
        res = 0; tt = 0;

        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        a[n+1] = 0;

        for (int i = 1; i <= n+1; i++) {
            if (a[i] > stk[tt]) {
                stk[++tt] = a[i];
                width[tt] = 1;
            }
            else {
                int cnt = 0;
                while (stk[tt] > a[i]) {
                    cnt += width[tt];
                    res = max(res, (ll)cnt * stk[tt]);
                    tt--;
                }
                stk[++tt] = a[i];
                width[tt] = cnt + 1;
            }

        }
        printf("%lld\n", res);
    }
    return 0;
}
