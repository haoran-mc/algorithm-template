#include <cstdio>
typedef long long ll;
int mod;

/* 看题目会不会超过int，选择合适的参数类型
 * 这里还是尽量不要用T，显得很蠢，自己判断会不会超过int，决定使用ll还是int
 */
template<typename> T
T binPow(T base, T expo) {
    T res = 1;
    while (expo) {
        if (expo & 1)
            res = (1LL * res * base) % mod;
        base = (1LL * base * base) % mod;
        //也就是base分别是2, 4, 8, 16, ...
        expo >>= 1;
    }
    return res % mod;
}

int main() {
    int a, b;
    scanf("%d %d %d", &a, &b, &mod);
    int res = (int)binPow((ll)a, (ll)b);
    printf("%d\n", res % mod);
    return 0;
}
