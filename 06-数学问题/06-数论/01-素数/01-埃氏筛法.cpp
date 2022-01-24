/*----------------------------------------------------------------
 *
 *   文件名称：埃氏筛法.cpp
 *   创建日期：2021年08月04日 星期三 00时17分10秒
 *   题    目：AcWing 0868 筛质数
 *   算    法：<++>
 *   描    述：
 *      一个质数定理：[1, n]中有(n/lnn)个质数
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e6;
//存储1 ~ 1e6内的所有素数
int primes[maxn], cnt;
//对1 ~ 1e6内的数标记，未被筛掉的素数标记为false
bool sifter[maxn];

void get_primes(int n) {
    for (int i = 2; i <= n; ++i)
        if (sifter[i] == false) {
            primes[cnt++] = i;
            for (int j = i + i; j <= n; j += i)
                sifter[j] = true;
        }
}

int main() {
    int n; scanf("%d", &n);
    get_primes(n);
    printf("%d\n", cnt);
    return 0;
}
