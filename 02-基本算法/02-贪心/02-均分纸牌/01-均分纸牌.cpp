/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年06月02日 星期三 10时16分59秒
 *   题    目：AcWing 1536 均分纸牌
 *   算    法：<++>
 *   描    述：人都给我看傻了，太顶了
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 100 + 5;
int card[maxn];
int n, sum, res;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) { 
        scanf("%d", &card[i]);
        sum += card[i];
    }

    int avg = sum / n;

    for (int i = 0; i < n; i++)
        if (card[i] != avg) 
            card[i + 1] += card[i] - avg, 
                res++;

    printf("%d\n", res);
    return 0;
}
