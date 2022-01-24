#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

template<typename T>
T Fibo0(T n) {
    if (n <= 1) return 1;
    else return Fibo(n-1) + Fibo(n-2);
}

template<typename T>
T Fibo1(T n) {
    if (n <= 1) return 1;

    std::vector<int> table(n + 1);
    table[0] = table[1] = 1;
    for (int i = 2; i <= n; ++i)
        table[i] = table[i-1] + table[i-2];
    return table.back();
}

template<typename T>
T Fibo2(T n) {
    const double sqrt5 = std::sqrt(5);
    const double phi = (1 + sqrt5) / 2;
    return (T)(std::pow(phi, n+1) / sqrt5 + 0.5);
}

template<typename T>
T Fibo3(T n) {
    static std::vector<T> arr;
    if (n <= 1) return 1;
    else if (n >= (T)arr.size())
        arr.resize(n+1);

    if (!arr[n])
        arr[n] = Fibo3(n-1) + Fibo3(n-2);
    return arr[n];
}

int main() {
    for (int i = 0; i < 10; ++i)
        printf("%d ", Fibo1(i));

    printf("\n");
    for (int i = 0; i < 10; ++i)
        printf("%d ", Fibo2(i));

    printf("\n");
    for (int i = 0; i < 10; ++i)
        printf("%d ", Fibo3(i));

    printf("\n");
    return 0;
}
