#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1e4; //顶点比1e3少的话，就可以使用邻接矩阵
int n, m; //顶点的个数
int vert[maxn], edge[maxn], nxet[maxn], head[maxn], tot;
int d[maxn]; //对于一张图来讲，d[x]被称为点x的层次(从起点１走到点x需要经过的最少点数)

//加入有向边(x, y)，权值为z
void add(int x, int y, int z) {
    vert[++tot] = y;
    edge[tot]   = z;
    nxet[tot]   = head[x];
    head[x] = tot;
}

void BFS() {
    memset(d, -1, sizeof(d));
    queue<int> quu;
    quu.push(0);
    d[0] = 0;
    while (!quu.empty()) {
        int x = quu.front();
        printf("%d\n", x);
        quu.pop();
        for (int i = head[x]; i; i = nxet[i]) {
            int y = vert[i];
            if (d[y] != -1) continue;
            d[y] = d[x] + 1;
            quu.push(y);
        }
    }
}

int main() {
    freopen("in-03.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    BFS();
    return 0;
}
