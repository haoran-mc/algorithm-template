/*----------------------------------------------------------------
 * 文件名称：01.cpp
 * 创建日期：2021年10月05日 星期二 21时58分37秒 
 * 题 目：AcWing 0243 一个简单的整数问题 
 * 算 法：线段树 
 * 描 述：
 * 给定一个长度为 N 的数列 A，以及 M 条指令，每条指令可能是以下两种之一：
 * - C l r d，表示把 A[l],A[l+1],…,A[r] 都加上 d。
 * - Q l r，表示询问数列中第 l￾ r 个数的和。
 * 对于每个询问，输出一个整数表示答案。
 *
 * - 区间最大连续子段和 区间和
 * - 最大数 区间最大数
 * - 区间最大公约数 区间加
 * - 本题 区间加 + 区间和
 * - 区间加 ---> 差分
 *
 * 差分 diff[i]
 *
 * 第i个数 arr[i] = diff[1] + diff[2] + ... + diff[i]
 *
 * 前x项的和 sum = arr[1] + arr[2] + ... + arr[i]
 *
 * arr1 = diff1
 * arr2 = diff1 diff2
 * arr3 = diff1 diff2 diff3
 * ... = ...
 * arrx = diff1 diff2 diff3 ... diffx
 *
 * |
 * V
 *
 * |-------------------------------------|
 * | diff1 diff2 diff3 ... diffx | -> 这个矩形的左下三角形区域为所求
 * |-------| |
 * arr1 -> | diff1 | diff2 diff3 ... diffx |
 * | |-------| |
 * arr2 -> | diff1 diff2 | diff3 ... diffx |
 * | |-------| |
 * arr3 -> | diff1 diff2 diff3 | ... diffx |
 * | ... |
 * | ... |
 * | ... |
 * | diff1 diff2 diff3 ... | diffx |
 * | |-------|
 * arrx -> | diff1 diff2 diff3 ... diffx |
 * |-------------------------------------|
 *
 * 也就是说，整个矩形区域减去右上三角形区域为所求
 *
 * (diff1 + diff2 + ... diffx) * (x + 1) - (1*diff1 + 2*diff2 + ... x*diffx)
 *
 * 所以使用线段树维护一个差分 diffi 的前缀和
 * 和一个 i * diffi 的前缀和
 *
 ----------------------------------------------------------------*/
#include <cstdio>
int n, m;
const int maxn = 1e5 + 5;
int arr[maxn];
typedef long long ll;
ll tr1[maxn]; // 维护 diff[i] 的前缀和
ll tr2[maxn]; // 维护 diff[i] * i 的前缀和
int lowbit(int x) {
    return x & -x;
}
void add(ll tr[], int x, ll c) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}
ll sum(ll tr[], int x) {
    ll res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}
ll get_preS(int x) {
    return sum(tr1, x) * (x + 1) - sum(tr2, x);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++ i)
        scanf("%d", &arr[i]);
    for (int i = 1; i <= n; ++ i) {
        int diff = arr[i] - arr[i - 1];
        add(tr1, i, diff);
        add(tr2, i, (ll)diff * i);
    }
    while (m -- ) {
        char op[2];
        int l, r, d;
        scanf("%s", op);
        scanf("%d %d", &l, &r);
        if (*op == 'C') {
            scanf("%d", &d);
            // arr[l] += d;
            add(tr1, l, d), add(tr2, l, l * d);
            // arr[r + 1] -= d;
            add(tr1, r + 1, -d), add(tr2, r + 1, (r + 1) * -d);
        }
        else if (*op == 'Q') {
            printf("%lld\n", get_preS(r) - get_preS(l - 1));
        }
    }
    return 0;
}
