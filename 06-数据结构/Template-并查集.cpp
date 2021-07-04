//蓝书，本质是路径压缩
#include <cstdio>
const int maxn = 1e6 + 5;
int n, m;
int fa[maxn];
bool isroot[maxn];
int groups = 0;

void init() {
    for (int i = 0; i < n; ++i) {
        fa[i] = -1;
        isroot[i] = false;
    }
}

int root(int x) {
    if (fa[x] == -1)
        return x;
    return fa[x] = root(fa[x]);
}

void union_vert(int x, int y) {
    fa[root(x)] = root(y);
}

int main() {
    scanf("%d %d", &n, &m);
    init();
    for (int i = 0; i < m; ++i) {
        int ver1, ver2;
        scanf("%d %d", &ver1, &ver2);
        union_vert(ver1, ver2);
    }
    for (int i = 0; i < n; ++i)
        isroot[root(i)] = true;
    for (int i = 0; i < n; ++i)
        groups += isroot[i];
    printf("%d", groups);
    return 0;
}
