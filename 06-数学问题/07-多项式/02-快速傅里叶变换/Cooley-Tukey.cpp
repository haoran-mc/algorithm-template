/*----------------------------------------------------------------
 *   
 *   文件名称：Cooley-Tukey.cpp
 *   创建日期：2021年07月23日 星期五 12时07分52秒
 *   题    目：<++>
 *   算    法：快速傅里叶变换
 *   描    述：nlOgn的时间下得到两个序列的和的序列
 *       [2 3 4], [2 3 4]  -->  [4 5 5 6 6 6 7 7 8]
 *       如果是差的序列，那么先加上一个偏移量
 *       [2 3 4], [-4 -3 -2]   
 *          -- +5 -->  [2 3 4], [1, 2, 3]
 *          -------->  [3 4 4 5 5 5 6 6 7]
 *          -- -5 -->  [-2 -1 -1 0 0 0 1 1 2]
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1 << 10;   // 定义maxn时一定要让maxn是2的指数
const double PI = acos(-1.0);
int a[maxn], b[maxn];
#define bug printf("<-->");
#define NEXTLINE puts("");

struct Complex {
    double r, i;   // 一定注意，使用%f输出
    Complex() {}
    Complex(double _r, double _i) : r (_r), i (_i) {}
    inline void real(const double& x) {r = x;}
    inline double real() {return r;}
    inline Complex operator + (const Complex& rhs) const {
        return Complex (r + rhs.r, i + rhs.i) ;
    }
    inline Complex operator - (const Complex& rhs) const {
        return Complex (r - rhs.r, i - rhs.i);
    }
    inline Complex operator * (const Complex& rhs) const {
        return Complex (r*rhs.r - i*rhs.i, r*rhs.i + i*rhs.r);
    }
    inline void operator /= (const double& x) {
        r /= x, i /= x ;
    }
    inline void operator *= (const Complex& rhs) {
        *this = Complex (r*rhs.r - i*rhs.i, r*rhs.i + i*rhs.r);
    }
    inline void operator += (const Complex& rhs) {
        r += rhs.r, i += rhs.i;
    }
    inline Complex conj() {    // 共轭复数
        return Complex (r, -i) ;
    }
};

struct FastFourierTransform {
    // 自己封装的复数类
    Complex omega[maxn], omegaInverse[maxn];

    void init(const int& n) {
        for (int i = 0; i < n; ++i) {
            omega[i] = Complex(cos(2*PI / n*i), sin(2*PI / n*i));
            omegaInverse[i] = omega[i].conj();
        }
    }

    void transform(Complex *a, const int& n, const Complex* omega) {
        for (int i = 0, j = 0; i < n; ++i) {
            if (i > j)
                swap(a[i], a[j]);
            for (int l = n >> 1; (j ^= l) < l; l >>= 1);
        }

        for (int l = 2; l <= n; l <<= 1) {
            int m = l / 2;
            for (Complex *p = a; p != a + n; p += l)
                for (int i = 0; i < m; ++i) {
                    Complex t = omega[n / l * i] * p [m + i];
                    p[m + i] = p[i] - t;
                    p[i] += t;
                }
        }
    }

    // 由系数表达式离散为点值表达式
    void dft(Complex *a, const int& n) {
        transform(a, n, omega);
    }

    // 由点值表达式转化为系数表达式
    void idft(Complex *a, const int& n) {
        transform(a, n, omegaInverse);
        for (int i = 0; i < n; ++i)
            a[i] /= n;
    }
} fft;

int main() {
    /*
     * 这是两个多项式的系数：
     * A(x) = 5 + 2x + 3x^2
     * B(x) = 2 + 6x + x^2   
     * 下面的len1，len2分别是两个多项式最大项的最高次幂+1
     * FFT中len一定要是2^k这种形式，否则在进行分治时会左右不均失败
     */
    a[0] = 5; a[1] = 2; a[2] = 3;
    b[0] = 2; b[1] = 6; b[2] = 1;
    int len1 = 3, len2 = 3;
    int len = 1;
    while (len < len1 * 2 || len < len2 * 2)
        len <<= 1;
    fft.init(len);   // 初始化\omega

    Complex x1[maxn], x2[maxn];   // 存储两个多项式的系数，幂由低到高
    // 将原本的系数用复数表达，实部是0.0
    for (int i = 0; i < len; ++i) {
        x1[i].r = a[i]; x1[i].i = 0.0;
        x2[i].r = b[i]; x2[i].i = 0.0;
    }
    // 由系数表达式离散为点值表达式
    fft.dft(x1, len); fft.dft(x2, len);
    // O(n)时间算出结果的点值表达式
    for (int i = 0; i < len; ++i)
        x1[i] = x1[i] * x2[i];
    // 根据结果的点值表达式得到系数表达式
    fft.idft(x1, len);

    int res[maxn];   // 用不用这个存无所谓，存一下吧，和开头的系数也是数组统一
    for (int i = 0; i < len; ++i) 
        res[i] = (int)(x1[i].r + 0.5);
    // 可能高位上系数为0，我们给它预留的位置还是比较多的，它没用完
    while (len && res[len-1] == 0) 
        --len;
    // 结果就是C(x) = 10 + 34x + 23x^2 + 20x^3 + 3x^4
    for (int i = 0; i < len; ++i)
        printf("%d ", res[i]);
    NEXTLINE 
    return 0;
}
