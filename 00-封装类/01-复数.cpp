#include <cstdio>
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

int main() {
    Complex c;
    c.real(10);
    printf("%f %f\n", c.r, c.i);
    printf("%f\n", c.real());
    Complex c1(5, 4);
    Complex c2(3, 2);

    c1 += c2;
    printf("%f %f\n", c1.r, c1.i);
    return 0;
}
