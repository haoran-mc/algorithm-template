#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000;
int n, m;
int source;
int target;
int g[maxn][maxn];
int dist[maxn];
bool used[maxn];
int res;

void prim() {
    memset(dist, 0x3f, sizeof(dist));
    memset(used, 0, sizeof(used));
    dist[source] = 0;
    for (int i = 0; i < n; ++i) {
        int vert = -1;
        for (int j = 0; j < n; ++j)
            if (used[j] == false && (vert == -1 || dist[j] < dist[vert]))
                vert = j; /*筛选出未在集合中的距离集合最近的顶点，*/
        used[vert] = true; /*将vert加到集合中*/
        for (int j = 0; j < n; ++j)
            if (used[vert] == false)
                dist[j] = min(dist[j], g[vert][j]); /*更新顶点距离*/
    }
}

int main() {
    scanf("%d %d", &n, &m);
    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i < n; ++i)
        g[i][i] = 0;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x][y] = z;
        g[y][x] = z;
    }
    prim();
    for (int i = 0; i < n; ++i)
        res += dist[i]; /*i到源点的距离和*/
    printf("%d \n", res);
    return 0;
}
