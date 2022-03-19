/*----------------------------------------------------------------
 * 文件名称：0058-一个简单的整数问题.cpp
 * 创建日期：2021年11月11日 星期四 13时28分11秒 
 * 题 目：AcWing 0243 一个简单的整数问题2 
 * 算 法：线段树 
 * 描 述：
 * 给定一个长度为 N 的数列 A，以及 M 条指令，每条指令可能是以下两种之一：
 * - C l r d，表示把 A[l], A[l+1], ..., A[r] 都加上 d。
 * - Q l r，表示询问数列中第 [l, r] 个数的和。
 * 对于每个询问，输出一个整数表示答案。
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e5 + 5;
typedef long long ll;
int arr[maxn];
struct Node {
    int l, r;
    ll sum, add;
} tr[maxn * 4];
void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r, arr[l], 0};
    }
    else {
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
void pushdown(int u) {
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add) {
        left.add += root.add, left.sum += (ll)(left.r - left.l + 1) * root.add;
        right.add += root.add, right.sum += (ll)(right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}
void modify(int u, int l, int r, int d) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].sum += (ll)(tr[u].r - tr[u].l + 1) * d;
        tr[u].add += d;
    }
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, d);
        if (r > mid)
            modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}
ll query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].sum;
    }
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        ll sum = 0;
        if (l <= mid)
            sum += query(u << 1, l, r);
        if (r > mid)
            sum += query(u << 1 | 1, l, r);
        return sum;
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++ i)
        scanf("%d", &arr[i]);
    build(1, 1, n);
    while (m -- ) {
        char op[2];
        int l, r;
        scanf("%s %d %d", op, &l, &r);
        if (*op == 'C') {
            int d; scanf("%d", &d);
            modify(1, l, r, d);
        }
        else if (*op == 'Q') {
            printf("%lld\n", query(1, l, r));
        }
    }
    return 0;
}
