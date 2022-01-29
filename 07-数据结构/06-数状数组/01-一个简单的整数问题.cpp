/*----------------------------------------------------------------
 * 文件名称：一个简单的整数问题.cpp
 * 创建日期：2021年11月16日 星期二 16时34分00秒 
 * 题 目：AcWing 0242 一个简单的整数问题 
 * 算 法：树状数组 
 * 描 述：长度为 n 的数组，m 个指令 
 * - C l r d [l, r] 中的数都加上 d 
 *   - Q x 查询第 x 个数的值
 *
 * 区间修改，单点查询
 *
 ----------------------------------------------------------------*/
#include <cstdio>
const int maxn = 1e5 + 5;
int n, m;
int a[maxn];
typedef long long ll;
ll tr[maxn]; // 实际上是差分数组
#define lowbit(x) ((x) & -(x))
void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}
ll sum(int x) {
    ll res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++ i)
        scanf("%d", &a[i]);
    // 就是直接的初始化，在第i个位置放上(a[i] - a[i - 1]);
    // 是建树的过程
    for (int i = 1; i <= n; ++ i)
        add(i, a[i] - a[i - 1]);
    while (m -- ) {
        char op[2];
        int l;
        scanf("%s %d", op, &l);
        if (*op == 'C') {
            int r, d;
            scanf("%d %d", &r, &d);
            add(l, d);
            if (r + 1 <= n)
                add(r + 1, -d);
        }
        else if (*op == 'Q') {
            int x = l;
            printf("%lld\n", sum(x));
        }
    }
    return 0;
}
