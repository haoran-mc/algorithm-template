/*----------------------------------------------------------------
 *   
 *   文件名称：01-根据厚度将书分组.cpp
 *   创建日期：2021年05月28日 星期五 22时43分04秒
 *   题    目：<++>
 *   算    法：二分
 *   描    述：N本书排成一行，第i本厚度是book[i]，把它们分成连续的M组
 *          使T(厚度最大的一组的厚度)最小，最小值是多少
 *
 ----------------------------------------------------------------*/

#include <cstdio>
int n = 9, m = 3;
int book[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

//将n本书分成若干组，每组最大厚度不超过size，分成的组数是否小于m
bool valid(int size) {
    int thick = 0;
    int group = 1; //初始值要为1
    for (int i = 0; i < n; ++i) {
        if (size - thick >= book[i])
            thick += book[i];
        else {
            group++;
            thick = book[i];
        }
    }
    return group <= m;
}

int main() {
    int sum_thick = 0;
    for (int i = 0; i < n; ++i)
        sum_thick += book[i];

    int l = 0, r = sum_thick;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (valid(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
