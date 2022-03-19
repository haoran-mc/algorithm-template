#include <stdio.h>

int Fibonacci(int n) {
    if (n == 1 || n == 0)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    //n的值再高可能递归太深，出不来
    int n = 41;
    printf("%d\n", Fibonacci(n));
    return 0;
}
