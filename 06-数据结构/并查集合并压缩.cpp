//合并压缩是在'并'的过程压缩路径
//额外需要rank[]数组，储存当前树的高度
//需要分组数时，同样使用isroot[]数组
#include <cstdio>
const int maxn = 1e6;
int fa[maxn];
bool isroot[maxn];
int ranks[maxn];

void init(int vert) {
    for (int i = 0; i < vert; ++i) {
        fa[i] = -1;
        isroot[i] = false;
        ranks[i] = -1;
    }
}

int root1(int x) {
    if (fa[x] == -1)
        return x;
    else
        return root1(fa[x]);
}

int root2(int x) {
    int rootx = x;
    while (fa[rootx] != -1)
        rootx = fa[rootx];
    return rootx;
}

void union_vert(int x, int y) {
    int rootx = root1(x);
    int rooty = root1(y);

    if (rootx != rooty)
        return ;
    else {
        if (ranks[rootx] > ranks[rooty])
            fa[rooty] = rootx;
        else if (ranks[rooty] > ranks[rootx])
            fa[rootx] = rooty;
        else {
            fa[rootx] = rooty;
            ranks[rooty]++;
        }
    }
}

int main() {
    int vert;
    int groups;
    scanf("%d", &vert);
    init(vert);
    scanf("%d", &groups);
    while (groups--) {
        int ver1, ver2;
        scanf("%d %d", &ver1, &ver2);
        union_vert(ver1, ver2);
    }

    for (int i = 0; i < vert; ++i)
        isroot[root1(i)] = true;

    int ans = 0;
    for (int i = 0; i < vert; ++i)
        ans += isroot[i];
    printf("%d\n", ans);
    return 0;
}
