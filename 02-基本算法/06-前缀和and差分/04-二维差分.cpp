#include <cstdio>
#define NEXTLINE puts("");
const int maxn = 1e3 + 5;
int g[maxn][maxn];
int diff[maxn][maxn];
int n, m, q;

void insert(int x1, int y1, int x2, int y2, int c) {
        diff[x1][y1] += c;
        diff[x2+1][y1] -= c;
        diff[x1][y2+1] -= c;
        diff[x2+1][y2+1] += c;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &g[i][j]);
            insert(i, j, i, j, g[i][j]);
        }
    while (q--) {
        int x1, y1, x2, y2, c;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            diff[i][j] = diff[i][j] + diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
            printf("%d ", diff[i][j]);
        }
        NEXTLINE;
    }
    return 0;
}
