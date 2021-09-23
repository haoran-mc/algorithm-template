/*----------------------------------------------------------------
 *   
 *   文件名称：02.cpp
 *   创建日期：2021年08月08日 星期日 21时21分15秒
 *   题    目：AcWing 0240 食物链
 *   算    法：并查集
 *   描    述：AcWing视频
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 5e4 + 5;
int fa[maxn];  // 父节点
int d[maxn];   // 距离根节点的距离

// 并查集查询操作，维护一个d数组
int find(int x) {
    if (fa[x] != x) {
        int u = find(fa[x]);
        d[x] += d[fa[x]];
        fa[x] = u;
    }
    return fa[x];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    int res = 0;
    while (m--) {
        int s, x, y;
        scanf("%d %d %d", &s, &x, &y);
        if (x > n || y > n)
            res++;
        else {
            int rootx = find(x), rooty = find(y);
            if (s == 1) {
                if (rootx == rooty && (d[x] - d[y]) % 3)  // 说明都已经在集合中
                        res++;
                else if (rootx != rooty) {
                    fa[rootx] = rooty;
                    d[rootx] = d[y] - d[x];
                }
            }
            else {
                if (rootx == rooty && (d[x] - d[y] - 1) % 3)
                    res++;
                else if (rootx != rooty) {
                    fa[rootx] = rooty;
                    d[rootx] = d[y] + 1 - d[x];
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
