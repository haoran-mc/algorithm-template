/*----------------------------------------------------------------
 *   
 *   文件名称：欧拉筛法.cpp
 *   创建日期：2021年08月04日 星期三 00时44分47秒
 *   题    目：AcWing 0868 筛质数
 *   算    法：欧拉筛法
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e6;
//存储1 ~ n内的所有素数
int primes[maxn], cnt;
//最终为false的数是素数
bool sifter[maxn];

void get_primes(int n) {
    //从2开始，判断i是否为素数
    for (int i = 2; i <= n; ++i) {
        if (sifter[i] == false)
            primes[cnt++] = i;

        for (int j = 0; primes[j] <= n / i; ++j) {
            // 每一个倍数标记为不是素数
            sifter[primes[j] * i] = true;

            // primes[j]为i的最小素因子，分析下一个i
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main() {
    int n; scanf("%d", &n);
    get_primes(n);
    printf("%d\n", cnt);
    return 0;
}

/* *
 * n = 4;
 *
 * i = 2, 未筛去, primes[0] = 2
 *      j = 0, primes[j] = 2 <= 4 / 2，4被筛去, i % primes[j] == 2 % 2 == 0, break
 * i = 3, 未筛去, primes[1] = 3
 *      j = 0, primes[j] = 2 > 4 / 3，break
 * i = 4, 已筛去
 *
 * 这里为什么i % primes[j] == 0, 就要break呢？
 * 如果不break，4*3 = 12就要被筛去，实际上12会在i = 6, primes[j] = primes[1] = 2，6*2 = 12被筛去
 * 2是12的最小素因子，比如100的最小素因子是2，所以100会在50 * 2时筛选掉，避免重复筛选
 * 合数的所有最小因子都是素数，此算法用到这一点
 */
