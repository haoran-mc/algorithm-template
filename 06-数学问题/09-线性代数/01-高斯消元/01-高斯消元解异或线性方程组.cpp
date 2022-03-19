/*----------------------------------------------------------------
 * 文件名称：高斯消元解异或线性方程组.cpp
 * 创建日期：2021年10月13日 星期三 00时06分27秒 
 * 题 目：AcWing 0884 高斯消元解异或线性方程组 
 * 算 法：高斯消元 
 * 描 述：<++>
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 105;
int n;
int a[maxn][maxn];
int guass() {
    int r, c;
    for (r = c = 0; c < n; ++ c) {
        int temp = r;
        for (int i = r; i < n; ++ i)
            if (a[i][c]) {
                temp = i;
                break;
            }
        if (!a[temp][c])
            continue;
        for (int i = c; i < n + 1; ++ i)
            swap(a[r][i], a[temp][i]);
        for (int i = r + 1; i < n; ++ i)
            if (a[i][c])
                for (int j = c; j < n + 1; ++ j)
                    a[i][j] ^= a[r][j];
        r ++ ;
    }
    if (r < n) {
        for (int i = r; i < n; ++ i)
            if (a[i][n])
                return 2;
        return 1;
    }
    for (int i = n - 1; i >= 0; -- i)
        for (int j = i + 1; j < n; ++ j)
            a[i][n] ^= a[i][j] & a[j][n];
    return 0;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n + 1; ++ j)
            scanf("%d", &a[i][j]);
    int t = guass();
    if (t == 0)
        for (int i = 0; i < n; ++ i)
            printf("%d\n", a[i][n]);
    else if (t == 1)
        puts("Multiple sets of solutions");
    else
        puts("No solution");
    return 0;
}
