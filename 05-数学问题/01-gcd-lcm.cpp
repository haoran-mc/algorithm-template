#include <cstdio>
#include <algorithm>
using namespace std;

int Gcd(int num1, int num2) {
    return !num2 ? num1 : Gcd(num2, num1 % num2);
}

int LCM(int num1, int num2) {
    return num1 / Gcd(num1, num2) * num2;
}

int main() {
    printf("%d\n", Gcd(12, 32));
    int gcd = __gcd(12, 32);
    printf("%d\n", gcd);
    return 0;
}
