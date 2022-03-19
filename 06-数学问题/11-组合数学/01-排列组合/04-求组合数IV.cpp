/*----------------------------------------------------------------
 * 文件名称：求组合数IV.cpp
 * 创建日期：2021年10月13日 星期三 17时44分06秒 
 * 题 目：AcWing 0888 求组合数IV
 * 算 法：组合数 
 * 描 述：输入 a, b，求 C_a^b 的值 
 * 注意结果可能很大，需要使用高精度计算。
 *
 * 1. 得到质数表
 * 2. 将结果分解质因子
 *
 * a! 中素因子 p 的个数是 cnt = a / p + a / p^2 + a / p^3 + ...
 *
 * 3. 高精度乘法
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 5000 + 5;
int primes[maxn], cnt;
int sum[maxn];
bool sifter[maxn];
#define NEXTLINE puts("");
void get_primes(int n) {
    for (int i = 2; i <= n; ++ i) {
        if (sifter[i] == false)
            primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; ++ j) {
            sifter[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}
// n! 中包含的素因子 p 的个数
int get(int n, int p) {
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}
vector<int> mul(vector<int> a, int b) {
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); ++ i) {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t) {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    get_primes(a);
    for (int i = 0; i < cnt; ++ i) {
        int p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a - b, p);
    }
    vector<int> res;
    res.push_back(1);
    for (int i = 0; i < cnt; ++ i)
        for (int j = 0; j < sum[i]; ++ j)
            res = mul(res, primes[i]);
    for (int i = res.size() - 1; i >= 0; -- i)
        printf("%d", res[i]);
    NEXTLINE;
    return 0;
}
