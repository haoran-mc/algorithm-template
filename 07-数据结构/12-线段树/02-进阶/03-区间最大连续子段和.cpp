/*----------------------------------------------------------------
 * 文件名称：区间最大连续子段和.cpp
 * 创建日期：2021年10月02日 星期六 02时10分51秒 
 * 题 目：AcWing 0245 你能回答这些问题吗
 * 算 法：线段树 
 * 描 述：
 * 开始给出数组 arr
 * 1 x y 查询区间[x, y]的最大连续子段和
 * 2 x y 把A[x] 修改为 y
 *
 *
 * 这里的pushup操作的是三个结点
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5e5 + 5;
int n, m;
int arr[maxn];
struct Node {
    int l, r;
    int sum; // 区间和
    int lmax; // 区间的最大前缀和
    int rmax; // 区间的最大后缀和
    int maxi; // 区间的最大连续子序列和
} tr[maxn * 4];
void pushup(Node &u, Node &l, Node &r) {
    u.sum = l.sum + r.sum;
    u.lmax = max(l.lmax, l.sum + r.lmax);
    u.rmax = max(r.rmax, r.sum + l.rmax);
    // |---------| |---------|
    // 新序列最大连续子序列可能跨区间
    u.maxi = max(max(l.maxi, r.maxi), l.rmax + r.lmax);
}
void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
void build(int u, int l, int r) {
    if (l == r)
        tr[u] = {l, r, arr[r], arr[r], arr[r], arr[r]};
    else {
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
void modify(int u, int x, int v) {
    if (tr[u].l == x && tr[u].r == x)
        tr[u] = {x, x, v, v, v, v};
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}
Node query(int u, int l, int r) {
    // tr[u] |-------------------------|
    // ^ l r ^
    if (l <= tr[u].l && tr[u].r <= r)
        return tr[u];
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        // |------------|------------|

        // <- ^ r
        if (r <= mid)
            return query(u << 1, l, r);
        // |------------|------------|
        // l ^ ->
        else if (l > mid)
            return query(u << 1 | 1, l, r);
        // |------------|------------|
        // ^ l r ^
        else {
            auto left = query(u << 1, l, r);
            auto right = query(u << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    // 线段树从1开始
    for (int i = 1; i <= n; ++ i)
        scanf("%d", &arr[i]);
    build(1, 1, n);
    while (m --) {
        int k, x, y;
        scanf("%d %d %d", &k, &x, &y);
        if (k == 1) {
            if (x > y) swap(x, y);
            printf("%d\n", query(1, x, y).maxi);
        }
        else
            modify(1, x, y);
    }
    return 0;
}
