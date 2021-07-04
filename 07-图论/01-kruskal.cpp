#include <cstdio>
#include <algorithm>
using namespace std;
struct Info {int x, y, z;} edge[500010];
int n, m;
int fa[100010];
int res;
bool operator <(Info a, Info b) {
    return a.z < b.z;
}

int root(int x) {
    if (fa[x] == -1)
        return x;
    return fa[x] = root(fa[x]);
}

void union_vert() {
    for (int i = 0; i < n; ++i) {
        int x_root = root(edge[i].x);
        int y_root = root(edge[i].y);
        if (x_root == y_root)
            continue;
        fa[x_root] = y_root;
        res += edge[i].z;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].z);
    sort(edge, edge+m);
    /*init*/
    for (int i = 0; i < n; ++i)
        fa[i] = -1;
    printf("%d\n", res);
    return 0;
}
