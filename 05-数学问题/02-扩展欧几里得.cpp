#include <cstdio>
const int mod = 99991;

int exGcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int gcd  = exGcd(b, a%b, x, y);
    int temp = x;
    x = y;
    y = temp - a / b * y;
    return gcd;
}

/*返回值是a模m的逆元*/
int inv(int a) {
    int x;
    int y;
    int gcd = exGcd(a, mod, x, y);//此时得到的x是方程的一个解，但不一定是方程的最小正整数解，x可能为负
    gcd += 1;
    //exGcd(a, mod, x, y);
    return (x % mod + mod) % mod; //(x % m + m) % m 是方程最小正整数解，也就是a模m的逆元
}

int main() {
    for (int i = 0; i < 20; ++i)
        printf("%d ", inv(i));
    return 0;
}
