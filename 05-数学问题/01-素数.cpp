#include <cstdio>
#include <cmath>

bool isPrime1(int n) {
    if (n <= 1)
        return false;
    int sqr = (int)sqrt(1.0 * n);

    for (int i = 2; i <= sqr; i++)
        if (n % i == 0)
            return false;

    return true;
}

//如果n没有接近int型变量的上届
bool isPrime2(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int main() {
    int num;
    scanf("%d", &num);
    printf("%d\n", isPrime1(num));
    return 0;
}
