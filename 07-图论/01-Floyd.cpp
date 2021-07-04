#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
int dist[305][305];

void Floyd() {
    /*Floyd求任意两点间最短路径*/
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
    scanf("%d %d", &n, &m);
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < n; ++i)
        dist[i][i] = 0; /*结点i到结点i的距离为0*/
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        dist[x][y] = min(dist[x][y], z); /*多重边*/
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", dist[i][j]);
        printf("\n");
    }
    return 0;
}
