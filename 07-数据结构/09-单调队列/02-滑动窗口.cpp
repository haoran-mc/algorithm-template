/*----------------------------------------------------------------
 * 文件名称：01.cpp
 * 创建日期：2021年08月06日 星期五 20时19分44秒 
 * 题 目：AcWing 0154 滑动窗口 
 * 算 法：单调队列 
 * 描 述：给定一个1e6大小的数组，有一个大小为k的滑动窗口，它从 
 * 数组的最左边移动到最右边，输出窗口移动过程中的最大值与最小值 
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
        if (hh <= tt && quu[hh] < i - k + 1) // 超出窗口范围
            hh++;
        // 队列中一定是单调递增的，前面的比后面大，那就会删去前面的
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
    scanf("%d %d", &n, &k); // n个数，窗口大小为k
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    get_min();
    NEXTLINE
        get_max();
    return 0;
}
