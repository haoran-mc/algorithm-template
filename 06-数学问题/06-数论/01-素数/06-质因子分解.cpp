#include <cstdio>
#include <cmath>

struct Factor {
    int x;
    int cnt;
} factor[10];

const int maxn    = 1e4;
bool sifter[maxn] = {0};
int pnum = 0;
int j    = 0;
int prime[maxn];


void findPrime() {
    for (int i = 2; i <= maxn; i++) 
        //发现素数
        if (sifter[i] == false) {
            prime[pnum++] = i;
            for (int j = i + i; j < maxn; j += i)
                sifter[j] = true;
        }
}

void findFactor(int num) {
    int sqrnum = sqrt(1.0 * num);

    for (int i = 0; i < sqrnum; i++)
        if (num % prime[i] == 0) {
            factor[j].x   = prime[i];
            factor[j].cnt = 0;
            while (num % prime[i] == 0) {
                factor[j].cnt++;
                num /= prime[i];
            }
            j++;
        }
    if (num != 1) {
        factor[j].x   = num;
        factor[j].cnt = 1;
    }
}

int main() {
    int num = 12345;
    findPrime();
    findFactor(num);

    for (int i = 0; i <= j; i++)
        printf("%d^%d + ", factor[i].x, factor[i].cnt);

    printf("\b= ");
    printf("%d\n", num);
    return 0;
}
