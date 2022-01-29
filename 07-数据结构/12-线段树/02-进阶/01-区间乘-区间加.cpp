/*----------------------------------------------------------------
 * 文件名称：区间乘.cpp
 * 创建日期：2021年11月10日 星期三 19时17分03秒 
 * 题 目：AcWing 1277 维护序列 
 * 算 法：线段树 
 * 描 述：有长为 n 的数列 a1, a2, a3, ... an
 * 一共有 m 个操作 
 * 操作1：1 l r c，把 [l, r] 中的数 ai * c
 * 操作2：2 l r c, 把 [l, r] 中的数 ai + c
 * 操作3：3 l r, 询问所有 [l, r] 中的数的和模 MOD 的值
 *
 ----------------------------------------------------------------*/
#include <cstdio>
const int maxn = 1e5 + 5;
int n, m, MOD;
typedef long long ll;
int arr[maxn];

struct Node {
    int l, r;
    int sum , add, mul;
} tr[maxn * 4];
void pushup(int u) {
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % MOD;
}
void eval(Node &u, int mul, int add) {
    u.sum = ((ll)u.sum * mul + (ll)(u.r - u.l + 1) * add) % MOD;
    u.mul = (ll)u.mul * mul % MOD;
    u.add = ((ll)u.add * mul + add) % MOD;
}
void pushdown(int u) {
    eval(tr[u << 1], tr[u].mul, tr[u].add);
    eval(tr[u << 1 | 1], tr[u].mul, tr[u].add);
    tr[u].add = 0, tr[u].mul = 1;
}
void build(int u, int l, int r) {
    if (l == r)
        tr[u] = {l, r, arr[r], 0, 1};
    else {
        tr[u] = {l, r, 0, 0, 1};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
void modify(int u, int l, int r, int add, int mul) {
    if (l <= tr[u].l && tr[u].r <= r)
        eval(tr[u], mul, add);
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, add, mul);
        if (r > mid)
            modify(u << 1 | 1, l, r, add, mul);
        pushup(u);
    }
}
int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r)
        return tr[u].sum;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if (l <= mid)
        sum = query(u << 1, l, r);
    if (r > mid)
        sum = (sum + query(u << 1 | 1, l, r)) % MOD;
    return sum;
}
int main() {
    scanf("%d %d", &n, &MOD);
    for (int i = 1; i <= n; ++ i)
        scanf("%d", &arr[i]);
    build(1, 1, n);
    scanf("%d", &m);
    while (m -- ) {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) {
            int x; scanf("%d", &x);

            modify(1, l, r, 0, x);
        }
        else if (op == 2) {
            int x; scanf("%d", &x);
            modify(1, l, r, x, 1);
        }
        else
            printf("%d\n", query(1, l, r));
    }
    return 0;
}
