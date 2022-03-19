/*----------------------------------------------------------------
 *   
 *   文件名称：insertSort.cpp
 *   创建日期：2021年08月08日 星期日 23时51分03秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <stdio.h>
int num[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int n = 10;

void insertSort() {
    int insertNum;

    for (int i = 0; i < n; i++) {
        insertNum = num[i];
        int j;
        for (j = i; insertNum < num[j - 1]; j--) {
            num[j] = num[j - 1];
        }
        num[j] = insertNum;
    }
}

int main() {
    insertSort();
    for (int i = 0; i < n; i++)
        printf("%d ", num[i]);

    printf("\n");
    return 0;
}
