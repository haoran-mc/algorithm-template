/*----------------------------------------------------------------
 *
 *   文件名称：数状数组.cpp
 *   创建日期：2021年03月07日 ---- 11时36分
 *   题    目：poj2182
 *   算    法：数状数组
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e6;
int tree[maxn];
int n;
#define lowbit(x) ((x) & -(x))

/*tree[x] += d*/
void add(int x, int d) {
    while (x <= n) {
        tree[x] += d;
        x += lowbit(x);
    }
}

/*sum(tree[1], tree[x])*/
int sum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int findpos(int x) {
    int L = 1;
    int R = n;
    while (L < R) {
        int mid = (L + R) >> 1;
        sum(mid) < x ? L = mid+1 : R = mid;
    }
    return L;
}

int main() {
    int pre[maxn];
    int ans[maxn];
    scanf("%d", &n);
    pre[1] = 0;
    for (int i = 2; i <= n; ++i)
        scanf("%d", &pre[i]);
    for (int i = 1; i <= n; ++i)
        tree[i] = lowbit(i);
    for (int i = n; i > 0; --i) {
        int x = findpos(pre[i] + 1);
        add(x, -1);
        ans[i] = x;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
