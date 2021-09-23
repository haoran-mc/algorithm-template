/*----------------------------------------------------------------
 *   
 *   文件名称：分解质因数.cpp
 *   创建日期：2021年08月04日 星期三 00时03分26秒
 *   题    目：AcWing 0867 分解质因数
 *   算    法：试除法分解质因数
 *   描    述：使用试除法分解质因数
 *      n中至多只包含一个大于sqrt(n)的质因子
 *
 ----------------------------------------------------------------*/

#include <cstdio>

void divide(int n) {
    // 从小到大枚举，i是底数，expo是指数
    for (int i = 2; i <= n / i; ++i)
        if (n % i == 0) {
            int expo = 0;
            while (n % i == 0) {
                n /= i;
                expo++;
            }
            printf("%d %d\n", i, expo);
        }

    if (n > 1)
        printf("%d %d\n", n, 1);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int num; scanf("%d", &num);
        divide(num);
        puts("");
    }
    return 0;
}
