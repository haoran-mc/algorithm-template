/*----------------------------------------------------------------
 * 文件名称：区间最大公约数.cpp
 * 创建日期：2021年10月02日 星期六 03时15分36秒 
 * 题 目：AcWing 0246 区间最大公约数 
 * 算 法：线段树 
 * 描 述：
 * C l r d，表示把[l, r]都加上 d。 
 * Q l r，表示询问[l, r]的最大公约数(GCD)。
 * gcd(a1, a2, a3, ..., an) = gcd(a1, a2-a1, a3-a2, ..., an-a(n-1))
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
int n, m; // 初始数组个数，操作数
ll arr[maxn];
struct Node {
    int l, r;
    ll diff, gcd;
} tr[maxn * 4];
// gcd(a, b) = gcd(b, a mod b)
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
void pushup(Node &u, Node &l, Node &r) {
    // 如果现在 u.l == 1，那么这个 u.diff 就是 arr[r];
    // 为了让我们后面求 a[l] 方便
    u.diff = l.diff + r.diff;
    // 这里的 gcd 是 gcd(a2 - a1, a3 - a2, a4 - a3, ... an - a(n-1))
    u.gcd = gcd(l.gcd, r.gcd);
}
void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
void build(int u, int l, int r) {
    if (l == r) {
        ll dif = arr[r] - arr[r - 1];
        tr[u] = {l, r, dif, dif};
    }
    else {
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int idx, ll val) {
    if (tr[u].l == idx && tr[u].r == idx) {
        ll b = tr[u].diff + val;
        tr[u] = {idx, idx, b, b};
    }
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (idx <= mid)
            modify(u << 1, idx, val);
        else
            modify(u << 1 | 1, idx, val);
        pushup(u);
    }
}
Node query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u];
    }
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (mid < l) {
            return query(u << 1 | 1, l, r);
        }
        else if (r <= mid) {
            return query(u << 1, l, r);
        }
        else {
            auto left = query(u << 1, l, r),
                 right = query(u << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++ i)
        scanf("%lld", &arr[i]);
    build(1, 1, n);
    while (m -- ) {
        char op[2];
        int l, r;
        scanf("%s %d %d", op, &l, &r);
        if (*op == 'C') {
            ll x; scanf("%lld", &x);
            modify(1, l, x);
            if (r + 1 <= n)
                modify(1, r + 1, -x);
        }
        else if (*op == 'Q') {
            auto left = query(1, 1, l),
                 right = query(1, l + 1, r);
            printf("%lld\n", abs(gcd(left.diff, right.gcd)));
        }
    }
    return 0;
}
