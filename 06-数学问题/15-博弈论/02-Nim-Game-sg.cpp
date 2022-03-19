/*----------------------------------------------------------------
 *
 *   文件名称：02-Nim-Game-sg.cpp
 *   创建日期：2021年03月19日 ---- 14时46分
 *   题    目：hdu1848
 *   算    法：sg函数
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
const int maxn = 1005;
int sg[maxn];
int st[maxn];
int fibo[15] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987};

/*预计算每堆有0~1005石子时的sg函数*/
void SG() {
    for (int i = 0; i <= maxn; ++i) {
        sg[i] = i;
        memset(st, 0, sizeof(st));
        for (int j = 0; j < 15 && fibo[j] <= i; ++j) {
            st[sg[i-fibo[j]]] = 1;  //把i的后继结点(i-fibo[1], i-fibo[2], ... , i-fibo[j])放到集合st中
            for (int j = 0; j <= i; ++j)
                if (!st[j]) {
                    sg[i] = j;
                    break;
                }
        }
    }
}

int main() {
    SG();
    int n, m, p;
    while (scanf("%d %d %d", &n, &m, &p) && n + m + p) {
        if (sg[n] ^ sg[m] ^ sg[p])
            printf("Fibo\n");
        else
            printf("Nacci\n");
    }
    return 0;
}
