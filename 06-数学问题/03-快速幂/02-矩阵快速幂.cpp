#include <cstdio>
#include <cstring>
const int maxn = 2;  //定义矩阵的阶
const int mod  = 99991;
struct Matrix {
    int m[maxn][maxn];
    Matrix() {
        memset(m, 0, sizeof(m));
    }
};

/*矩阵乘法*/
Matrix Multi(Matrix a, Matrix b) {
    Matrix res;
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < maxn; ++j)
            for (int k = 0; k < maxn; ++k)
                res.m[i][j] = (res.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
    return res;
}

/*矩阵快速幂*/
Matrix fastm(Matrix a, int n) {
    Matrix res;
    for (int i = 0; i < maxn; ++i)
        res.m[i][i] = 1;
    while (n) {
        if (n & 1)
            res = Multi(res, a);
        a = Multi(a, a);
        n >>= 1;
    }
    return res;
}
