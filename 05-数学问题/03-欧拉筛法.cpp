#include <cstdio>

const int maxn = 5e8;
int seek = 0;
int prime[maxn];
//最终为false的数是素数
bool sifter[maxn];
//bool* sifter = (bool *)memset(sifter, 0, sizeof(sifter));

void sievePrime() {
    //从2开始，判断i是否为素数
    for (int i = 2; i <= maxn; i++) {
        if (sifter[i] == false)
            prime[seek++] = i;

        for (int j = 0; j < seek; j++) {
            //这里的循环就是为了标记当前素数i的倍数不是素数
            //不停止的话，就超界了
            if (i * prime[j] > maxn)
                break;

            //每一个倍数标记为不是素数
            sifter[i * prime[j]] = true;

            //当前素数为i的最小素因子，分析下一个i
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main() {
    sievePrime();
    for (int i = 0; i < seek; i++)
        printf("%d ", prime[i]);

    /*
     *if (sifter[99991] == 0)
     *    printf("\n\n99991 is a prime number\n");
     *else
     *    printf("\n\n99991 is not a prime number\n");
     */

    printf("\n");
    printf("seek = %d", seek);  //78498
    printf("\n");
    return 0;
}

/* *
 * i = 2, 未筛去, prime[1] = 2, j = 1, i*prime[j] = 2*2 = 4 < maxn, 4被筛去, i%prime[j] == 2%2 == 0, break
 * i = 3, 未筛去, prime[2] = 3, j = 1, i*prime[j] = 3*2 = 6 < maxn, 6被筛去, i%prime[j] == 3%2 == 1,
 *                              j = 2, i*prime[j] = 3*3 = 9 < maxn, 9被筛去, i%prime[j] == 3%3 == 0, break
 * i = 4, 已筛去,             , j = 1, i*prime[j] = 4*2 = 8 < maxn, 8被筛去, i%prime[j] == 4%2 == 0, break
 *
 * 这里为什么i % prime[j] == 0, 就要break呢？
 * 如果不break，4*3 = 12就要被筛去，实际上12会在i = 6, prime[j] = prime[1] = 2，6*2 = 12被筛去
 * 2是12的最小素因子，比如100的最小素因子是2，所以100会在50 * 2时筛选掉，避免重复筛选
 * 合数的所有最小因子都是素数，此算法用到这一点
 */
