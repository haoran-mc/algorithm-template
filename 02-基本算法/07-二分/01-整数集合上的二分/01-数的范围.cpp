/*----------------------------------------------------------------
 *   
 *   文件名称：01-lower-upper-bound.cpp
 *   创建日期：2021年08月17日 星期二 13时44分44秒
 *   题    目：AcWing 0789 数的范围
 *   算    法：二分
 *   描    述：对于每个查询，返回一个元素 k 的起始位置和终止位置(从0开始)
 *      如果数组中不存在该元素，则返回 -1 -1。
 *      也就是lowerBound和upperBound
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#define bug printf("<-->\n");
const int maxn = 1e5 + 5;
int n, q;
int num[maxn];

/*
 * 找到第一个大于等于val的数：
 * [l, r] --> [l, mid], [mid + 1, r]
 * 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
 */
int lowerBound(int l, int r, int val) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (num[mid] < val)
            l = mid + 1;
        else
            r = mid;
    }
    if (num[l] != val)
        return -1;
    else
        return l;
}

/*
 * 找到第一个小于等于val的数：
 * [l, r] --> [l, mid - 1], [mid, r]
 * 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
 */
int upperBound(int l, int r, int val) {
    while (l < r) {
        //这里要加一
        int mid = (l + r + 1) >> 1;
        if (num[mid] <= val)
            l = mid;
        else
            r = mid - 1;
    }
    if (num[l] != val)
        return -1;
    else
        return l;
}

int main() {
    scanf("%d %d", &n, &Q);
    for (int i = 0; i < n; ++i)
        scanf("%d", &num[i]);
    while (Q--) {
        int val;
        scanf("%d", &val);
        int lower = lowerBound(0, n-1, val);
        int upper = upperBound(0, n-1, val);
        printf("%d %d\n", lower, upper);
    }
    return 0;
}
