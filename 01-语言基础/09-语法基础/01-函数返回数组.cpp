#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 要生成和返回随机数的函数 */
int * getRandom( ) {
    static int r[10];
    for (int i = 0; i < 10; ++ i) {
        r[i] = rand();
        printf( "r[%d] = %d\n", i, r[i]);
    }
    return r;
}

int main () {
    int *p;
    p = getRandom();
    for (int i = 0; i < 10; i++ )
        printf( "*(p + %d) : %d\n", i, *(p + i));
    return 0;
}
