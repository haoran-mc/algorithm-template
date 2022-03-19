/*----------------------------------------------------------------
 * 文件名称：最大数.cpp
 * 创建日期：2021年09月24日 星期五 14时00分56秒 
 * 结束日期：2021年09月24日 星期五 23时00分19秒 
 * 题 目：AcWing 1257 最大数 
 * 算 法：线段树 
 * 描 述：给定一个正整数数列a1, a2, ..., an，每一个数都在 
 * 0 ~ p - 1 之间，两种操作：
 * 1. 添加操作：序列后添加一个数，序列长度变成n + 1
 * 2. 询问操作：询问这个序列最后L个数中最大的数是多少
 * 线段树，动态的修改一个数，动态的查询一个区间内的最大数
 *
 * 一共有 m 次操作
 *
 * ! 线段树的区间都是左闭右闭
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
struct Node {
    int l, r;
    int maxi; // 本题存储的是区间[l, r]最大值
} tr[maxn * 4];
// 由子结点的信息计算父结点的信息
void pushup(int u) {
    tr[u].maxi = max(tr[u << 1].maxi, tr[u << 1 | 1].maxi);
}
// 这里的u是l, r的一个表示，也就是每一个u一一映射一个区间
// 这棵树的所有叶子是原数组
// 左闭右闭
void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) // 叶结点
        return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}
// 从u结点开始查询，一般从根结点开始查询，查询[l, r]之间的最大值
// 这个函数的作用是找到既在结点u管理的区域又在在[l, r]区域中的最大值
// 左闭右闭
int query(int u, int l, int r) {
    // 要查询的区间把这个结点所管理的区间包含了，那就返回这个结点的最大值
    if (l <= tr[u].l && tr[u].r <= r)
        return tr[u].maxi;
    // 否则这个结点管理的一部分区域不在[l, r]中
    int mid = tr[u].l + tr[u].r >> 1;
    int maxi = 0;
    /*
     * l (先判断左边，右边r无所谓)
     * |---------------------------------------|
     * tr[u].l mid tr[u].r
     *
     */
    if (l <= mid)
        maxi = query(u << 1, l, r);
    /*
     * r (这是判断右边，左边l无所谓)
     * |---------------------------------------|
     * tr[u].l mid tr[u].r
     *
     */
    if (r > mid)
        maxi = max(maxi, query(u << 1 | 1, l, r));
    return maxi;
}
// update，左闭右闭
void modify(int u, int idx, int val) {
    // 这是叶子，所以是数组中的数
    // 是数组还不行，需要tr[u].l == idx才表明找到了这个下标的数
    if (tr[u].l == tr[u].r && tr[u].l == idx)
        tr[u].maxi = val;
    else { // 所以当前结点不是叶子结点，就需要判断往左还是往右递归
        int mid = tr[u].l + tr[u].r >> 1;
        if (idx <= mid)
            modify(u << 1, idx, val);
        else
            modify(u << 1 | 1, idx, val);
        pushup(u);
    }
}
int main() {
    int m, MOD;
    scanf("%d %d", &m, &MOD);
    build(1, 1, m);
    // idx是数的个数，last是上一个区间的答案
    int idx = 0, last = 0;
    while (m -- ) {
        char op[2]; int x;
        scanf("%s %d", op, &x);
        if (*op == 'Q') { // Query
            last = query(1, idx - x + 1, idx);
            printf("%d\n", last);
        }
        else if (*op == 'A') { // Append
            modify(1, ++ idx, ((long long)x + last) % MOD);
        }
    }
    return 0;
}
