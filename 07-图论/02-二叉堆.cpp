#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
const int N = 2000; //顶点数的最大值
const int M = 2000; //边数的最大值
int n, m;
int source;
int tot;
int head[N], vert[M], edge[M], nxet[M];
int dist[N]; //d数组，存放源点到各顶点的最短距离
bool used[N];
int pre[N]; //表示从起点到顶点vert的最短路径上vert的前一个顶点
// 大根堆(优先队列)，pair的第二维是顶点编号
// pair的第一维是dist的相反数(利用相反数变成小根堆)
priority_queue<pair<int, int>> pqu;

void add(int x, int y, int z) {
    // 输入的第tot条边的入边是y，权重为z
    vert[++tot] = y;
    edge[tot] = z;
    // nxet数组中存放上一次输入x时的tot值
    // 第一次输入x时，nxet[tot] == 0，也是下面循环结束的依据
    nxet[tot] = head[x];
    head[x] = tot;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; ++i)
        pre[i] = i; //初始时，每个顶点的前驱为自身
    dist[source] = 0; //源点到源点的最段距离为0
    pqu.push(make_pair(0, 1)); //将源点到源点的路径放入队列
    while (pqu.size()) {
        // 取出堆顶，x为未访问的顶点中路径最短的顶点
        int x = pqu.top().second;
        pqu.pop();
        // 如果x已经被标记了，cotinue
        if (used[x])
            continue;
        // 标记x
        used[x] = true;
        // 遍历x的所有出边，出边编号: y, 边权: z
        for (int i = head[x]; i; i = nxet[i]) {
            int y = vert[i];
            int z = edge[i];
            if (dist[y] > dist[x] + z) {
                dist[y] = dist[x] + z;
                pre[y] = x;
                //堆里面的是更新后的-dist[y]与y
                pqu.push(make_pair(-dist[y], y));
            }
        }
    }
}

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
    source = 1;  //源点为1
    for (int i = 1; i <= m; ++i) {
        int x, y, z; //顶点，顶点，边权
        scanf("%d %d %d", &x, &y, &z);
        add(x, y, z);
    }
    dijkstra();
    for (int i = 1; i <= n; ++i)
        printf("%d\n", dist[i]);
    // route(1, 6);
    return 0;
}
