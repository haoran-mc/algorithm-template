/*----------------------------------------------------------------
 * 文件名称：迷一样的牛.cpp
 * 创建日期：2021年11月16日 星期二 17时09分21秒 
 * 题 目：AcWing 0244 迷一样的牛 
 * 算 法：树状数组 
 * 描 述：n 头牛站成一列，输入的第一个数是牛的个数，下面 n - 1 
 * 行数代表的是第 i + 1 头牛前面有多少个比它矮的牛的个数，输出身高 
 *
 ----------------------------------------------------------------*/
#include <cstdio>
const int maxn = 1e5 + 5;
int n, h[maxn], res[maxn], tr[maxn];
#define lowbit(x) ((x) & -(x))
void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}
int sum(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        tr[i] = lowbit(i); // add(i, 1);
        if (i != 1)
            scanf("%d", &h[i]);
    }
    for (int i = n; i; -- i) {
        int k = h[i] + 1;
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (sum(mid) < k)
                l = mid + 1;
            else
                r = mid;
        }
        res[i] = l;
        add(l, -1);
    }
    for (int i = 1; i <= n; ++ i)
        printf("%d\n", res[i]);
    return 0;
}
