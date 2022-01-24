/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年08月06日 星期五 20时19分44秒
 *   题    目：AcWing 0154 滑动窗口
 *   算    法：单调队列
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e6 + 5;
#define NEXTLINE puts("");
int quu[maxn], a[maxn];
int n, k;

void get_min() {
    int hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
        if (hh <= tt && quu[hh] < i - k + 1)
            hh++;
        while (hh <= tt && a[quu[tt]] >= a[i])
            tt--;
        quu[++tt] = i;
        if (i >= k - 1)
            printf("%d ", a[quu[hh]]);
    }
}

void get_max() {
    int hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
        if (hh <= tt && quu[hh] < i - k + 1)
            hh++;
        while (hh <= tt && a[quu[tt]] <= a[i])
            tt--;
        quu[++tt] = i;
        if (i >= k - 1)
            printf("%d ", a[quu[hh]]);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    get_min();
    NEXTLINE 
    get_max();
    return 0;
}
