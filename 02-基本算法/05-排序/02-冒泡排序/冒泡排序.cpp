/*----------------------------------------------------------------
 *
 *   文件名称：bubbleSort.cpp
 *   创建日期：2021年08月08日 星期日 23时51分18秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <stdio.h>
int n = 10;
int num[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

void bubbleSort() {
    for (int i = 0; i < n-1; ++i)
        for (int j = n-1; j > i; --j)
            if (num[j] < num[j-1]) {
                num[j] += num[j-1];
                num[j-1] = num[j] - num[j-1];
                num[j] -= num[j-1];
            }
}

int main() {
    scanf("%d", &n);
    printf("-- %d\n", n);

    bubbleSort();
    for (int i = 0; i < 10; ++i)
        printf("%d ", num[i]);
    printf("\n");
    return 0;
}
