//路径压缩是在'查'的过程压缩路径
//没有额外需要
//另外，isroot[]可以很好的与并查集结合，找到分组数
#include <cstdio>
const int maxn = 1e6;
int fa[maxn];
bool isroot[maxn];

void init(int vert) {
    for (int i = 0; i < vert; ++i) {
        fa[i] = -1;
        isroot[i] = false;
    }
}

//查，有返回值，为此结点的根结点
int root1(int x) {
    if (fa[x] == -1)
        return x;
    else {
        //这条语句只执行了一遍
        int rootx = root1(fa[x]);
        //路径压缩
        fa[x] = rootx;
        return rootx;
    }
}

int root2(int x) {
    int rootx = x;
    while (fa[rootx] != -1) {
        rootx = fa[rootx];
    }
//路径压缩
    while (fa[x] != -1) {
        int ano_x = x;
        fa[x] = rootx;
        x = fa[ano_x];
    }
    return rootx;
}

//根据题目有无返回值，isroot[]数组可找到分组数
//如果有返回值，根据返回值判断当前值是否在同一集合中
void union_vert(int x, int y) {
    int rootx = root1(x);
    int rooty = root1(y);

    if (rootx != rooty)
        fa[rootx] = rooty;
}

int main() {
    int n;
    int groups;
    scanf("%d", &n);
    init(n);
    scanf("%d", &groups);

    for (int i = 0; i < groups; ++i) {
        int ver1, ver2;
        scanf("%d %d", &ver1, &ver2);
        union_vert(ver1, ver2);
    }

    for (int i = 0; i < n; ++i)
        //默认编号从0到vert
        isroot[root1(i)] = true;

    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += isroot[i];
    printf("%d", ans);

    return 0;
}
