/*----------------------------------------------------------------
 * 文件名称：楼兰图腾.cpp
 * 创建日期：2021年11月16日 星期二 13时46分47秒 
 * 题 目：AcWing 0241 楼兰图腾 
 * 算 法：树状数组 
 * 描 述：坐标轴上有 n 个点，
 * v : (i, yi), (j, yj), (k, yk) 满足 1 <= i < j < k <= n 且 yi > yj, yj < yk
 * ^ : (i, yi), (j, yj), (k, yk) 满足 1 <= i < j < k <= n 且 yi < yj, yj > yk
 *
 * 求出有多少个 v 和 ^
 *
 * [y1, yn] 是 [1, n] 的一个排列
 *
 * 实际上就是单点修改，区间查询
 *
 * a[x] += c
 * query(l, r);
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <cstring>
const int maxn = 2e5 + 5;
int n, y[maxn], tr[maxn];
#define lowbit(x) ((x) & -(x))
typedef long long ll;
// 在位置 x 上加上 c
void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}
// 返回 x 的前缀和
int sum(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}
// 在 [i] 的位置左边，有多少个数大于 y[i]
int greater[maxn], lower[maxn];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i)
        scanf("%d", &y[i]);
    for (int i = 1; i <= n; ++ i) {
        greater[i] = sum(n) - sum(y[i]);
        lower[i] = sum(y[i] - 1);
        add(y[i], 1);
    }
    memset(tr, 0, sizeof tr);
    ll res1 = 0, res2 = 0;
    for (int i = n; i; -- i) {
        res1 += greater[i] * (ll)(sum(n) - sum(y[i]));
        res2 += lower[i] * (ll)(sum(y[i] - 1));
        add(y[i], 1);
    }
    printf("%lld %lld\n", res1, res2);
    return 0;
}
