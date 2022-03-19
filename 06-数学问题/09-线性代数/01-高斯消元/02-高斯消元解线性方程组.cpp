/*----------------------------------------------------------------
 * 文件名称：高斯消元解线性方程组.cpp
 * 创建日期：2021年10月12日 星期二 23时16分11秒 
 * 题 目：AcWing 0883 高斯消元解线性方程组 
 * 算 法：高斯消元 
 * 描 述：<++>
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 105;
int n;
double a[maxn][maxn]; // Augmented matrix 增广矩阵
const double eps = 1e-6;
inline int sgn(double x) { // 判断x是否等于0
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
/**
 * 枚举每一列
 * 1. 找到绝对值最大的一行
 * 2. 将该行换到最上面
 * 3. 将该行的第一个数变成1
 * 4. 将下面所有行的第 c 列清成0
 */
// 0: 唯一解，1: 无穷组解，2: 无解
int guess() {
    int r, c; // 枚举第 r(ow) 行，第 c(olumn) 列
    for (c = 0, r = 0; c < n; ++ c) {
        int temp = r;
        // 找到当前列绝对值最大的一行
        for (int i = r; i < n; ++ i)
            if (fabs(a[i][c]) > fabs(a[temp][c]))
                temp = i;
        // 如果找到的当前列最大的一行是0，表示这一列全是0，就不用将该行换到上面了
        if (sgn(fabs(a[temp][c])) == 0)
            continue;
        for (int i = c; i < n + 1; ++ i)
            swap(a[r][i], a[temp][i]);
        for (int i = n; i >= c; -- i)
            a[r][i] /= a[r][c];
        for (int i = r + 1; i < n; ++ i)
            if (sgn(abs(a[i][c])) != 0)
                for (int j = n; j >= c; -- j)
                    a[i][j] -= a[r][j] * a[i][c];
        r ++ ;
    }
    if (r < n) {
        for (int i = r; i < n; ++ i)
            if (sgn(fabs(a[i][n])) != 0)
                return 2;
        return 1;
    }
    for (int i = n - 1; i >= 0; -- i)
        for (int j = i + 1; j < n; ++ j)
            a[i][n] -= a[i][j] * a[j][n];
    return 0;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n + 1; ++ j) // n + 1
            scanf("%lf", &a[i][j]);
    int t = guess();
    if (t == 0)
        for (int i = 0; i < n; ++ i)
            printf("%.2lf\n", a[i][n]);
    else if (t == 1)
        puts("Infinite group solutions");
    else
        puts("No solution");
    return 0;
}
