/*----------------------------------------------------------------
 *   
 *   文件名称：02-悬线法.cpp
 *   创建日期：2021年08月02日 星期一 15时29分53秒
 *   题    目：AcWing 0131 直方图中最大矩形
 *   算    法：悬线法
 *   描    述：使用单调栈也可以做，但是悬线法更简单
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using std::max;
const int maxn = 1e5 + 5;
int h[maxn];
// l[i]: 表示i位置的悬线能达到的最左边的位置
// r[i]: 表示i位置的悬线能达到的最右边的位置
int l[maxn], r[maxn];
long long res;

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        res = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &h[i]);
            l[i] = r[i] = i;
        }

        // 得到这根线向左能达到的位置
        for (int i = 0; i < n; i++)
            // 首先不能越界，而且要比我高这根线才能继续向左前进
            while (l[i] > 0 && h[i] <= h[l[i] - 1])
                // 比我高的线都能通过，我也能
                l[i] = l[l[i] - 1];

        // 得到这根线向右能达到的位置
        for (int i = n-1; i >= 0; i--)
            while (r[i] < n-1 && h[i] <= h[r[i] + 1])
                r[i] = r[r[i] + 1];

        // 计算所有矩形面积
        for (int i = 0; i < n; i++)
            res = max(res, (long long)(r[i] - l[i] + 1) * h[i]);
        printf("%lld\n", res);
    }
    return 0;
}
