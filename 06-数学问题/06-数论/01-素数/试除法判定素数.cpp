/*----------------------------------------------------------------
 *   
 *   文件名称：试除法判定素数.cpp
 *   创建日期：2021年08月03日 星期二 13时59分14秒
 *   题    目：AcWing 0866 试除法判定素数
 *   算    法：试除法判定素数
 *   描    述：给定 n 个正整数 ai，判定每个数是否是质数
 *
 ----------------------------------------------------------------*/

#include <cstdio>

bool is_prime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= n / i; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int num; scanf("%d", &num);
        if (is_prime(num))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
