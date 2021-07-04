#include <cstdio>
const int maxn = 1e6;
int pnum = 0;
int prime[maxn]; //存储1 ~ 1e6内的所有素数
bool sifter[maxn] = { 0 }; //对1 ~ 1e6内的数标记，未被筛掉的素数标记为false

void findPrime() {
    for (int i = 2; i <= maxn; i++)
        if (sifter[i] == false) {
            prime[pnum++] = i;
            for (int j = i + i; j < maxn; j += i)
                sifter[j] = true;
        }
}

int main() {
    findPrime();
    //输出所有素数
    for (int i = 0; i < pnum; i++)
        printf("%d ", prime[i]);

    if (sifter[99991] == 0)
        printf("\n\n99991 is a prime number\n");
    else
        printf("\n\n99991 is not a prime number\n");

    printf("\n");
    return 0;
}
