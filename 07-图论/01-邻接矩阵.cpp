#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000;
int n; /*顶点个数*/
int m; /*边的个数*/
int source = 1;
int g[maxn][maxn];
int dist[maxn]; /*d数组，存放源点到各顶点的距离*/
bool used[maxn];
int pre[maxn]; /*表示从起点到顶点vert的最短路径上vert的前一个顶点*/

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; ++i)
        pre[i] = i; /*初始时，每个顶点的前驱为自身*/
    dist[source] = 0; /*源点到源点的距离为0，可更改*/
    for (int i = 0; i < n; ++i) { /*每次仅开放一个顶点，所以需要重复访问n-1次(源点不需重复访问)*/
        int vert = -1; /*特判源点*/
        for (int j = 0; j < n; ++j) /*找到未访问过的顶点中有路径可以到达的距离源点最短的顶点*/
            if (used[j] == false && (vert == -1 || dist[j] < dist[vert])) /*特判源点*/
                vert = j;
        used[vert] = true; /*标记已被访问*/
        for (int j = 0; j < n; ++j) /*更新能够被更新的顶点与距源点source的最短距离*/
            dist[j] = min(dist[j], dist[vert] + g[vert][j]);
        /*
         * //如果需要求出最短路径，选择这个for循环，删除上一个for循环
         *for (int j = 0; j < n; ++j) [>更新能够被更新的顶点与距源点的最短距离<]
         *    if (dist[vert] + g[vert][j] < dist[j]) {
         *        dist[j] = dist[vert] + g[vert][j];
         *        pre[j]  = vert;
         *    }
         */
    }
}

/*从源点到目标点vert的最短路径*/
void route(int source, int vert) {
    if (vert == source) {
        printf("%d ", source);
        return ;
    }
    route(source, pre[vert]);
    printf("%d ", vert);
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    scanf("%d", &m);
    source = 1; /*源点为1*/
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= n; ++i) /*没有0顶点*/
        g[i][i] = 0;
    for (int i = 1; i <= m; ++i) {
        int vert;
        int edge;
        int weig;
        scanf("%d", &vert);
        scanf("%d", &edge);
        scanf("%d", &weig);
        g[vert][edge] = min(g[vert][edge], weig);
    }
    dijkstra();
    for (int i = 1; i <= n; ++i)
        printf("%d\n", dist[i]);
    /*输出source到6的路径*/
    route(source, 6);
    return 0;
}
