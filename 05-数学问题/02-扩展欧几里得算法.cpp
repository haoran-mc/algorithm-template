//可以使用扩展欧几里得算法对方程 ax + by = c 求解
#include<iostream>
using namespace std;

int exgcd(int a, int b, int &x, int &y /*使用引用*/ ) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
//欧几里得算法中直接return，而这里由于需要递归得到 x 与 y ，所以不能直接return
    int gcd = exgcd(b, a % b, x, y);
    int temp = x;   //为了得到 y_(n) 需要保存 x_(n+1)
    x = y;
    y = temp - a / b * y;
    return gcd;
}

int main() {
    int a, b, x, y;
    cin >> a >> b;
    int gcd = exgcd(a, b, x, y);

    cout << "a   = " << a << endl << "b   = " << b << endl;
    cout << "x   = " << x << endl << "y   = " << y << endl;
    cout << "gcd = " << gcd << endl;
    cout << "a * x + b * y = " << gcd << endl;
    cout << a << " * " << x << " + " << b << " * " << y << " = " << gcd << endl;

    return 0;
}
