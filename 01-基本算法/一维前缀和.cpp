/*----------------------------------------------------------------
 *   
 *   文件名称：一维前缀和.cpp
 *   创建日期：2021年05月31日 星期一 01时14分51秒
 *   题    目：AcWing 0795 前缀和
 *   算    法：前缀和
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e5 + 5;
int sequ[maxn];
int preS[maxn];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // 前缀和的题目从下标1开始读
    for (int i = 1; i <= n; ++i)
        scanf("%d", &sequ[i]);
    for (int i = 1; i <= n; ++i)
        preS[i] = preS[i-1] + sequ[i];
    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", preS[r] - preS[l - 1]);
    }
    return 0;
}
