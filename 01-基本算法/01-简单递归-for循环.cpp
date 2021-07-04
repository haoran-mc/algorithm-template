#include <cstdio>
const int maxn = 30;
#define NEXTLINE puts("");
int n, m;
int path[maxn];

//u表示层数，start表示从第几个数开始搜
void dfs(int u, int start) {
    if (u > m) {
        for (int i = 1; i <= m; ++i)
            printf("%d ", path[i]);
        NEXTLINE;
    }
    else {
        for (int i = start; i <= n; ++i) {
            path[u] = i;
            dfs(u + 1, i + 1);
            // path[u] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    dfs(1, 1);
    return 0;
}
