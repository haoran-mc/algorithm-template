/*----------------------------------------------------------------
 *
 *   文件名称：quickSort
 *   创建日期：2021年05月30日 星期日 00时53分58秒
 *   题    目：AcWing 0785 快速排序
 *   算    法：快速排序
 *   描    述：去看笔记-首元素做基准
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
#define NEXTLINE puts("");
int n = 10;
int num[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

void quickSort(int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = num[(l + r) >> 1];
    while (i < j) {
        do i ++ ; while (num[i] < x);
        do j -- ; while (num[j] > x);
        if (i < j) swap(num[i], num[j]);
    }
    quickSort(l, j);
    quickSort(j + 1, r);
}

int main() {
    quickSort(0, 9);
    for (int i = 0; i < n; ++i)
        printf("%d ", num[i]);
    NEXTLINE;
    return 0;
}
